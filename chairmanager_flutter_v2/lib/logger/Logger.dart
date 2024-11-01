
import 'dart:io';

import 'package:chairmanager_flutter_v2/logger/LoggerMemoryOutput.dart';
import 'package:logger/logger.dart';

class Log extends Logger{
  static final Log _singleton = Log._internal();
  static const String logFileName = "chairmanager.log";

  factory Log() {
    return _singleton;
  }

  Log._internal() : super(
    output: MultiOutput([
      ConsoleOutput(),
      FileOutput(file: File(logFileName), overrideExisting: true),
      LoggerMemoryOutput(),
    ]),
    printer: LogfmtPrinter(),
    // PrettyPrinter(
    //   methodCount: 0,
    //   errorMethodCount: 5,
    //   lineLength: 50,
    //   colors: false,
    //   printEmojis: false,
    //   excludeBox: {
    //     Level.trace: true,
    //     Level.info: true,
    //     Level.debug: true,
    //     Level.warning: true,
    //     Level.error: true,
    //   },
    // ),
  );
}