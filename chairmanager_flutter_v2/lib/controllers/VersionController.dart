import 'dart:convert';
import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:ffi/ffi.dart';
import 'package:get/get.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'package:version/version.dart';
import 'package:win32/win32.dart';
import 'dart:ffi';
import 'package:anyhow/anyhow.dart';
import 'package:http/http.dart' as http;

const String chairloaderUpdateUrl = "https://api.github.com/repos/thelivingdiamond/Chairloader/releases/latest";



class VersionController extends GetxController with TalkerMixin {
  String etag = "";
  bool get downloadUpdateAvailable => downloadedVersion > installedVersion;
  bool get installUpdateAvailable => availableVersion > installedVersion;

  Version installedVersion = Version.parse("0.0.0");
  Version downloadedVersion = Version.parse("0.0.0");
  Version availableVersion = Version.parse("0.0.0");

  PathController pathController = Get.find();


  Future<void> init() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
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

    etag = prefs.getString("etag") ?? "";
    talker.verbose("etag: $etag");

    var githubVersionResult = await getGithubVersion();
    if(githubVersionResult.isErr()){
      talker.error("Failed to get github version: ${githubVersionResult.unwrapErr()}");
    } else {
      var githubVersion = githubVersionResult.unwrap();
      if(githubVersion != null){
        prefs.setString("availableVersion", githubVersion.toString());
      }
      availableVersion = githubVersion ?? Version.parse(prefs.getString("availableVersion") ?? "0.0.0");
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
    SharedPreferences prefs = await SharedPreferences.getInstance();
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
      // no update
      result = const Ok(null);
    } else if(response.statusCode == 200){
      talker.verbose("got a new response${force ? " (forced)" : ""}");
      // get the etag from the response
      etag = response.headers["etag"] ?? "";
      // save the etag to storage
      prefs.setString("etag", etag);
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
      // something went wrong
      result = bail("Failed to check for update, status code: ${response.statusCode}");
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