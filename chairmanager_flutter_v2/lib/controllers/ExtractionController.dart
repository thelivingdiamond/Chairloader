import 'dart:convert';
import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:get/get.dart';

class ExtractionController extends GetxController {
  List<String> preditorOutput = [];
  Process? extractionProcess;
  bool? extractionRequired;
  bool extractionRunning = false;
  bool extractionFinished = false;
  bool extractionSuccess = false;


  @override
  void onInit() {
    super.onInit();
    extractionNeeded().then((value) {
      extractionRequired = value;
      update();
    });
  }

  Future<void> extractGameFiles() async {
    final PathController pathController = Get.find();
    try {
      preditorOutput.clear();
      extractionRunning = true;
      update();
      extractionProcess = await Process.start(pathController.preditorExePath, ["--extract", "--game-path", pathController.preyPath.value, "--output-path", pathController.preyFilesPath], workingDirectory: pathController.dataPath.value);
      extractionProcess!.stdout.transform(utf8.decoder).listen((data) {
        preditorOutput.add(data);
        update();
      });
      extractionProcess!.stderr.transform(utf8.decoder).listen((data) {
        preditorOutput.add(data);
        update();
      });
      await extractionProcess!.exitCode;
    } catch (e) {
      preditorOutput.add("Error: $e");
    } finally {
      extractionRunning = false;
      extractionFinished = true;
      extractionSuccess = !await extractionNeeded();
      update();
    }

  }

  Future<bool> extractionNeeded() async {
    // check for .../PreyFiles/FilesExtracted.dat
    final PathController pathController = Get.find();
    final File filesExtracted = File("${pathController.preyFilesPath}/FilesExtracted.dat");
    return !await filesExtracted.exists();
  }

  void resetExtraction() {
    preditorOutput.clear();
    extractionProcess = null;
    extractionRunning = false;
    extractionFinished = false;
    extractionSuccess = false;
    update();
  }
}