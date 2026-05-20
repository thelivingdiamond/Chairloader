import 'package:flutter/material.dart';
import 'package:talker_flutter/talker_flutter.dart';

class GenericLogMessage {
  final String message;
  final LogLevel level;

  Color get logColor {
    switch (level) {
      case LogLevel.verbose:
        return Colors.grey;
      case LogLevel.debug:
        return Colors.green;
      case LogLevel.info:
        return Colors.blue;
      case LogLevel.warning:
        return Colors.orange;
      case LogLevel.error:
      case LogLevel.critical:
        return Colors.red;
    }
  }

  GenericLogMessage(this.message, this.level);
}