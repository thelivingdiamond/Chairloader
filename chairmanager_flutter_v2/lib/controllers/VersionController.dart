import 'dart:convert';
import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:chairmanager_flutter_v2/storage/StorageMixin.dart';
import 'package:ffi/ffi.dart';
import 'package:get/get.dart';
import 'package:version/version.dart';
import 'package:win32/win32.dart';
import 'dart:ffi';
import 'package:anyhow/anyhow.dart';
import 'package:http/http.dart' as http;

const String chairloaderUpdateUrl = "https://api.github.com/repos/thelivingdiamond/Chairloader/releases/latest";



class VersionController extends GetxController with TalkerMixin, StorageMixin {
  String etag = "";
  bool get downloadUpdateAvailable => downloadedVersion > installedVersion;
  bool get installUpdateAvailable => availableVersion > installedVersion;

  Version installedVersion = Version.parse("0.0.0");
  Version downloadedVersion = Version.parse("0.0.0");
  Version availableVersion = Version.parse("0.0.0");

  DateTime? lastGithubCheck;
  // only ever check for updates every hour (to avoid rate limiting)
  static const Duration githubCheckInterval = Duration(hours: 1);

  PathController pathController = Get.find();


  Future<void> init() async {

    final lastGithubCheckString = await storage.getOrInit<String>("lastGithubCheck", '2000-01-01T00:00:00.000Z');
    lastGithubCheck = DateTime.parse(lastGithubCheckString);

    var installedResult = await getInstalledVersion();
    if(installedResult.isErr()){
      talker.error("Failed to get installed version: ${installedResult.unwrapErr()}");
    } else {
      var unwrapped = installedResult.unwrap();
      if(unwrapped != null){
        installedVersion = unwrapped;
        talker.info("Installed version: $installedVersion");
      } else {
        talker.info("No installed version found");
      }
    }

    var downloadedResult = await getDownloadedVersion();
    if(downloadedResult.isErr()){
      talker.error("Failed to get downloaded version: ${downloadedResult.unwrapErr()}");
    } else {
      var unwrapped = downloadedResult.unwrap();
      if(unwrapped != null){
        downloadedVersion = unwrapped;
        talker.info("Downloaded version: $downloadedVersion");
      } else {
        talker.info("No downloaded version found");
      }
    }

    etag = await storage.getOrInit<String>("etag", "");
    etag = etag.replaceAll("W/", "");
    talker.verbose("etag: $etag");

    if(DateTime.now().difference(lastGithubCheck!) > githubCheckInterval){
      var githubVersionResult = await getGithubVersion();
      lastGithubCheck = DateTime.now();
      await storage.set("lastGithubCheck", lastGithubCheck?.toIso8601String());
      if(githubVersionResult.isErr()){
        talker.error("Failed to get github version: ${githubVersionResult.unwrapErr()}");
      } else {
        var githubVersion = githubVersionResult.unwrap();
        if(githubVersion != null){
          await storage.set("availableVersion", githubVersion.toString());
        }
        availableVersion = githubVersion ?? Version.parse(storage.get("availableVersion") as String? ?? "0.0.0");
        talker.info("Available version on github: $availableVersion");
      }
    } else {
      availableVersion = Version.parse(storage.get("availableVersion") as String? ?? "0.0.0");
      talker.verbose("Not checking for update, last check was ${DateTime.now().difference(lastGithubCheck!).inMinutes} minutes ago");
      talker.info("Available version on github: $availableVersion");
    }
  }

  Future<Result<Version?>> getInstalledVersion() async {
    if(await File("${pathController.binaryPath}\\${pathController.chairloaderDllName}").exists()){
      return getDLLVersion("${pathController.binaryPath}\\${pathController.chairloaderDllName}");
    } else {
      return const Ok(null);
    }
  }

  Future<Result<Version?>> getDownloadedVersion() async {
    if(await File("Release\\${pathController.chairloaderDllName}").exists()){
      return getDLLVersion("Release\\${pathController.chairloaderDllName}");
    } else {
      return const Ok(null);
    }
  }


  Future<Result<Version?>> getGithubVersion({bool force = false}) async{
    // make the header
    Result<Version?> result;
    Map<String, String> headers = {};
    if(etag.isNotEmpty && !force){
      headers["If-None-Match"] = etag;
    }
    headers["User-Agent"] = "ChairManagerAutoUpdateCheck";

    String responseString = "";
    // make the request
    final response = await http.get(Uri.parse(chairloaderUpdateUrl), headers: headers);
    if(response.statusCode == 304){
      talker.verbose("eTag matches, no new version available");
      // no update
      result = const Ok(null);
    } else if(response.statusCode == 200){
      talker.verbose("got a new response${force ? " (forced)" : ""}");
      // get the etag from the response
      etag = response.headers["etag"] ?? "";
      // remove the W/ from the etag
      etag = etag.replaceAll("W/", "");
      // save the etag to storage
      await storage.set("etag", etag);
      responseString = response.body;

      try {
        Map<String, dynamic> responseJson = jsonDecode(responseString);
        String tagName = responseJson["tag_name"] ?? "0.0.0";
        final version = Version.parse(tagName);
        result = Ok(version);
      } catch (e) {
        result = bail(e);
      }
    } else {
      // check for the 'retry-after' header and the 'x-ratelimit-remaining' header and the 'x-ratelimit-reset' header
      // log the headers
      response.headers.forEach((key, value) {
        talker.verbose("$key: $value");
      });


      // something went wrong
      result = bail("Failed to check for update, status code: ${response.statusCode}, body: ${response.body}");
    }
    return result;
  }



  // derived from https://github.com/dart-windows/win32/blob/main/example/filever.dart
  Result<Version> getDLLVersion(String dllPath) {

    final lpFilename = TEXT(dllPath);

    var fviSize = 0;
    try{
      fviSize = getVersionBlockSize(lpFilename);
    } catch (e) {
      return bail(e);
    }

    final pBlock = calloc<BYTE>(fviSize);
    final lpProductVersion = calloc<Pointer>();
    final uLen = calloc<UINT>();
    final subBlock = TEXT(r'\StringFileInfo\040904E4\ProductVersion');

    int major = 0, minor = 0, patch = 0, build = 0;

    Result<Version> result;

    try {
      var result = GetFileVersionInfo(lpFilename, 0, fviSize, pBlock);
      if (result == 0) {
        throw Exception('GetFileVersionInfo failed.');
      }

      result = VerQueryValue(pBlock, subBlock, lpProductVersion, uLen);
      if (result == 0) {
        throw Exception('VerQueryValue failed.');
      }

      // convert the lpProductVersion pointer to a Dart string
      final lpFixedFileVersionInfo = lpProductVersion.value.cast<Utf16>();
      final versionString = lpFixedFileVersionInfo.toDartString();

      // parse the version string into a list of integers
      final versionList = versionString.split('.').map(int.parse).toList();

      // assign the version numbers
      major = versionList[0];
      minor = versionList[1];
      patch = versionList[2];
      if(versionList.length > 3){ // always false for Chairloader
        build = versionList[3];
      }
    } catch (e) {
      result = bail(e);
      // ignore e
    } finally {
      free(lpFilename);
      free(pBlock);
      free(lpProductVersion);
      free(uLen);
      free(subBlock);
    }
    result = Ok(Version(major, minor, patch));
    return result;
  }

  int getVersionBlockSize(Pointer<Utf16> lpFilename) {
    int fviSize;

    // dwDummy isn't used; it's a historical vestige.
    final dwDummy = calloc<DWORD>();

    try {
      fviSize = GetFileVersionInfoSize(lpFilename, dwDummy);
      if (fviSize == 0) {
        throw Exception('GetFileVersionInfoSize failed.');
      }

      return fviSize;
    } finally {
      free(dwDummy);
    }
  }
}