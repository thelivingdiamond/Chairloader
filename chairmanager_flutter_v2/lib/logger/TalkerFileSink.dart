import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:get/get.dart';
import 'package:intl/intl.dart';

import 'package:talker_flutter/talker_flutter.dart';

class TalkerFileSink extends GetxController with TalkerMixin {

  late File logFile;
  DateFormat logFileNameFormat = DateFormat('yyyy-MM-dd--HH-mm-ss');
  DateFormat timeFormat = DateFormat('HH:mm:ss');

  final int maxHistoricalLogs = 10;

  @override
  void onInit() {
    super.onInit();
    PathController pathController = Get.find();

    final String logFileName = "${logFileNameFormat.format(DateTime.now())}_ChairManager.log";
    logFile = File("${pathController.logsPath}\\$logFileName");
    if(!logFile.existsSync()){
      logFile.createSync(recursive: true);
    }

    // if there are more than 10 logs, delete the oldest one with the .log extension
    final logs = Directory(pathController.logsPath).listSync().where((element) => element.path.endsWith('.log')).toList();
    if(logs.length > maxHistoricalLogs){
      logs.sort((a, b) => a.statSync().modified.compareTo(b.statSync().modified));
      logs.first.deleteSync();
    }

    talker.stream.listen((event) {
      logFile.writeAsStringSync("${timeFormat.format(event.time)} | [${event.logLevel?.name ?? 'Other'}] | ${event.displayMessage}\n", mode: FileMode.append);
    });
  }
}