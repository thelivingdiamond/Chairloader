import 'dart:async';
import 'dart:collection';

import 'package:chairmanager_flutter_v2/logger/LogMixin.dart';
import 'package:chairmanager_flutter_v2/logger/LoggerMemoryOutput.dart';
import 'package:flutter/foundation.dart';
import 'package:get/get.dart';
import 'package:logger/logger.dart';
import 'package:shared_preferences/shared_preferences.dart';

class LogController extends GetxController with LogMixin{
  static const int maxLogs = 10000;
  final List<OutputEvent> logs = <OutputEvent>[].obs;

  late StreamSubscription<OutputEvent> _subscription;

  List<OutputEvent> get filteredLogs => logs.reversed.where((element) => element.level.index >= filterLevel.index).toList();

  static const  filterLevels = [
    Level.trace,
    Level.debug,
    Level.info,
    Level.warning,
    Level.error,
    Level.fatal,
  ];

  Level _filterLevel = Level.info;

  Level get  filterLevel => _filterLevel;
  set filterLevel(Level value) {
    _filterLevel = value;
    SharedPreferences.getInstance().then((prefs) {
      prefs.setInt("logFilterLevel", value.index);
    });
    update();
  }

  @override
  void onInit() {
    SharedPreferences.getInstance().then((prefs) {
      _filterLevel = Level.values[prefs.getInt("logFilterLevel") ?? Level.info.index];
      update();
    });
    super.onInit();
    _subscription = LoggerMemoryOutput().stream.listen((event) {
      logs.add(event);
      if (logs.length > maxLogs) {
        logs.removeRange(0, logs.length - maxLogs);
      }
      update();
    });
  }

  @override
  void onClose() {
    _subscription.cancel();
    super.onClose();
  }

  void clearLogs() {
    logs.clear();
    update();
  }
}