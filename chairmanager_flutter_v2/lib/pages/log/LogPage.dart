import 'package:flutter/material.dart';

import 'package:get/get.dart';
import 'package:talker_flutter/talker_flutter.dart';

class LogPage extends StatelessWidget {
  const LogPage({super.key});

  static Color logLevelColor(LogLevel? level, BuildContext context) {
    switch (level) {
      case LogLevel.error:
        return Theme.of(context).colorScheme.error;
      case LogLevel.critical:
        return Theme.of(context).colorScheme.error;
      case LogLevel.info:
        return Colors.blue;
      case LogLevel.debug:
        return Colors.green;
      case LogLevel.verbose:
        return Colors.grey;
      case LogLevel.warning:
        return Colors.orange;
      default:
        return Theme.of(context).colorScheme.onSurface;
    }
  }

  static IconData logLevelIcon(LogLevel? level) {
    switch (level) {
      case LogLevel.error:
        return Icons.error;
      case LogLevel.critical:
        return Icons.error;
      case LogLevel.info:
        return Icons.info;
      case LogLevel.debug:
        return Icons.bug_report;
      case LogLevel.verbose:
        return Icons.more_horiz;
      case LogLevel.warning:
        return Icons.warning;
      default:
        return Icons.info;
    }
  }

  @override
  Widget build(BuildContext context) {
    return Card(
      child: TalkerScreen(
        talker: Get.find(),
        appBarLeading: const Icon(Icons.description_outlined),
        appBarTitle: 'Log Page',
        theme: TalkerScreenTheme(
          backgroundColor: Theme.of(context).colorScheme.surfaceContainerLow,
          cardColor: Theme.of(context).cardColor,
        ),
      ),
    );
  }
}
