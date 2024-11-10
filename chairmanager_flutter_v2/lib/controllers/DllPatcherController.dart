import 'dart:convert';
import 'dart:io';
import 'dart:isolate';

import 'package:chairmanager_flutter_v2/algorithms/AsyncHashCalculator.dart';
import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:chairmanager_flutter_v2/models/PreyVersion.dart';

import 'package:get/get.dart';
import 'package:xml/xml.dart' as xml;
import 'package:crypto/crypto.dart';



class DllPatcherController extends GetxController with TalkerMixin {
  var patcherOutput = <String>[].obs;
  Process? patcherProcess;
  var patcherRunning = false.obs;
  var patcherFinished = false.obs;
  var patcherSuccess = false.obs;

  List<DLLVersionInformation> knownDllVersions = [];
  late Digest currentDllHash;
  DLLVersionInformation? currentDllVersion;

  bool verifyCurrentDllRunning = false;

  @override
  void onInit() {
    super.onInit();
  }

  Future<void> load() async {
    await loadDllVersions();
    await verifyCurrentDll();
  }

  Future<void> verifyCurrentDll() async {
    PathController pathController = Get.find();
    final String path = pathController.preyDllPath;
    final dllFile = File(path);
    verifyCurrentDllRunning = true;
    update();

    if(await dllFile.exists()) {
      currentDllHash = await AsyncHashCalculator.calculateHash(path);

      if (currentDllHash.isBlank == false) {
        currentDllVersion =
            knownDllVersions.firstWhereOrNull((element) => element.sha256Hash == currentDllHash.toString());
        if (currentDllVersion != null) {
          talker.info("Current detected DLL version is: ${currentDllVersion!
              .type}. It is ${currentDllVersion!.isSupported == true
              ? 'supported'
              : 'not supported'} and ${currentDllVersion!.isOutdated == true
              ? 'outdated'
              : 'up to date'}");
        } else {
          talker.error(
              "Current DLL version is not recognized, we are unable to patch it.");
        }
      }
    }

    verifyCurrentDllRunning = false;
    update();
  }

  Future<void> _getDllHash(SendPort port) async {
    ReceivePort receivePort = ReceivePort();
    port.send(receivePort.sendPort);
    receivePort.listen((message) async {
      final String path = message as String;
      final File dllFile = File(path);
      final List<int> bytes = await dllFile.readAsBytes();
      final Digest hash = sha256.convert(bytes);
      port.send(hash.bytes);
    });
  }

  Future<void> patchGame() async {
    final PathController pathController = Get.find();
    int? exitCode;
    try {
      patcherOutput.clear();
      patcherRunning.value = true;
      update();
      patcherProcess = await Process.start(pathController.dllPatcherExePath, [pathController.preyDllPath, currentDllHash.toString(), pathController.preyDllBackupPath], workingDirectory: pathController.dataPath.value);
      patcherProcess!.stdout.transform(utf8.decoder).listen((data) {
        patcherOutput.add(data);
        update();
      });
      patcherProcess!.stderr.transform(utf8.decoder).listen((data) {
        patcherOutput.add(data);
        update();
      });
      exitCode = await patcherProcess!.exitCode;
    } catch (e) {
      patcherOutput.add("Error: $e");
    } finally {
      patcherRunning.value = false;
      patcherFinished.value = true;
      patcherSuccess.value = exitCode == 0;
      update();
    }
  }

  void resetPatcher() {
    patcherOutput.clear();
    patcherProcess = null;
    patcherRunning.value = false;
    patcherFinished.value = false;
    patcherSuccess.value = false;
    update();
  }

  Future<void> loadDllVersions() async {
    final PathController pathController = Get.find();
    final File dllVersionsFile = File(pathController.dllVersionsXmlPath);
    if(await dllVersionsFile.exists()){
      final xml.XmlDocument doc = xml.XmlDocument.parse(await dllVersionsFile.readAsString());
      final xml.XmlElement root = doc.rootElement;
      for(var child in root.childElements){
        knownDllVersions.add(DLLVersionInformation.fromXml(child));
      }
    } else {
      talker.error("DLL versions file not found at ${dllVersionsFile.path}");
    }
  }
}

class DLLVersionInformation {
  late String sha256Hash;
  late DateTime releaseDate;
  late PreyVersion type;
  String? steamManifest;
  bool? isSupported;
  bool? isOutdated;

  DLLVersionInformation.fromXml(xml.XmlElement element){
    final sha256Element = element.getElement('SHA256');
    final releaseDateElement = element.findElements('ReleaseDate').firstOrNull;
    final versionElement = element.findElements('Type').firstOrNull;
    final steamManifestElement = element.findElements('SteamManifest').firstOrNull;
    final isSupportedElement = element.findElements('IsSupported').firstOrNull;
    final isOutdatedElement = element.findElements('IsOutdated').firstOrNull;

    sha256Hash = sha256Element != null ? sha256Element.innerText : '';
    releaseDate = releaseDateElement != null ? DateTime.parse(releaseDateElement.innerText) : DateTime.now();
    final typeString = versionElement?.innerText;
    switch(typeString){
      case 'Steam':
        type = PreyVersion.Steam;
        break;
      case 'GOG':
        type = PreyVersion.GOG;
        break;
      case 'EGS':
        type = PreyVersion.Epic;
        break;
      case 'MS':
        type = PreyVersion.MicrosoftStore;
        break;
      default:
        type = PreyVersion.Unknown;
    }
    steamManifest = steamManifestElement?.innerText;
    isSupported = isSupportedElement != null ? isSupportedElement.innerText == 'True' : null;
    isOutdated = isOutdatedElement != null ? isOutdatedElement.innerText == 'True' : null;

  }
}

