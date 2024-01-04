import 'package:fluent_ui/fluent_ui.dart';
import 'package:get/get.dart';
import 'package:logger/logger.dart';
import 'package:flutter/foundation.dart';
import 'package:get_storage/get_storage.dart';

class LogController extends GetxController {
  RxList<LogEvent> log = <LogEvent>[].obs;
  LogController(){
  }

  toFilterLevelString(Level level) {
    switch (level) {
      case Level.verbose:
        return "Verbose";
      case Level.debug:
        return "Debug";
      case Level.info:
        return "Info";
      case Level.warning:
        return "Warning";
      case Level.error:
        return "Error";
      case Level.wtf:
        return "WTF";
      default:
        return "Unknown";
    }
  }

  toLogLevel(String levelString) {
    switch (levelString) {
      case "Verbose":
        return Level.verbose;
      case "Debug":
        return Level.debug;
      case "Info":
        return Level.info;
      case "Warning":
        return Level.warning;
      case "Error":
        return Level.error;
      case "WTF":
        return Level.wtf;
      default:
        return Level.verbose;
    }
  }

  @override
  void onInit() {
    super.onInit();
    var storage = GetStorage("ChairManagerConfig");
    if(storage.hasData("logFilterLevel")) {
      setFilterLevel(toLogLevel(storage.read("logFilterLevel")));
    } else {
      if (kDebugMode) {
        setFilterLevel(Level.verbose);
      } else {
        setFilterLevel(Level.info);
      }
    }

    ever(filterLevel, (value) {
      storage.write("logFilterLevel", toFilterLevelString(value));
    });
  }

  final maxLogLength = 100;
  var filterLevel = Level.verbose.obs;

  void add(LogEvent event) {
    log.add(event);
    if(log.length > maxLogLength) {
      log.removeAt(0);
    }
  }

  void setFilterLevel(Level level) {
    filterLevel.value = level;
  }

  void clear() {
    log.clear();
  }

  bool isMessageFiltered(LogEvent event) {
    return event.level.index <= (filterLevel.value.index-1);
  }
}