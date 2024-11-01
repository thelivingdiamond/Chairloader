import 'dart:async';

import 'package:chairmanager_flutter_v2/logger/LogMixin.dart';
import 'package:get/get.dart';
import 'package:logger/logger.dart';

class LoggerMemoryOutput extends LogOutput {
  static final LoggerMemoryOutput _instance = LoggerMemoryOutput._internal();
  factory LoggerMemoryOutput() {
    return _instance;
  }

  LoggerMemoryOutput._internal();
  final StreamController<OutputEvent> _controller = StreamController.broadcast();
  Stream<OutputEvent> get stream => _controller.stream;

  @override
  void output(OutputEvent event) {
    _controller.add(event);
  }

}