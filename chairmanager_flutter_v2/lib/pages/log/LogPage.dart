import 'package:chairmanager_flutter_v2/controllers/LogController.dart';
import 'package:flutter/material.dart';

import 'package:chairmanager_flutter_v2/logger/LogMixin.dart';
import 'package:get/get.dart';
import 'package:logger/logger.dart';

class LogPage extends StatelessWidget {
  const LogPage({super.key});

  static Color logLevelColor(Level level, BuildContext context) {
    switch (level) {
      case Level.debug:
        return Colors.blue;
      case Level.info:
        return Theme.of(context).colorScheme.onSurface;
      case Level.warning:
        return Colors.orange;
      case Level.error:
        return Colors.red;
      case Level.fatal:
        return Colors.purple;
      default:
        return Colors.grey;
    }
  }

  static IconData logLevelIcon(Level level) {
    switch (level) {
      case Level.trace:
        return Icons.filter_none_outlined;
      case Level.debug:
        return Icons.bug_report_outlined;
      case Level.info:
        return Icons.info_outline;
      case Level.warning:
        return Icons.warning_amber_rounded;
      case Level.error:
        return Icons.error_outline;
      case Level.fatal:
        return Icons.error_outline_rounded;
      default:
        return Icons.filter_none_outlined;
    }
  }

  @override
  Widget build(BuildContext context) {
    return GetBuilder<LogController>(
        builder: (controller) {
          return Card(
            clipBehavior: Clip.antiAlias,
            child: Column(
              children: [
                Container(
                  alignment: Alignment.center,
                  color: Theme.of(context).colorScheme.surface,
                    height:50,
                    child: Stack(
                      alignment: Alignment.center,
                      fit: StackFit.expand,
                      children: [
                        Center(
                          child:
                        Text('Log Page', style: Theme.of(context).textTheme.titleMedium,),
                        ),
                        Container(
                          padding: const EdgeInsets.symmetric(horizontal: 16),
                          child: Row(
                            children: [
                              DropdownButton(
                                value: controller.filterLevel,
                                onChanged: (value) {
                                  controller.filterLevel = value as Level;
                                },
                                items: LogController.filterLevels.map((e) => DropdownMenuItem(
                                  value: e,
                                  child: Text(e.toString().split('.').last),
                                )).toList(),
                              ),
                              IconButton(onPressed: () => controller.clearLogs(), icon: const Icon(Icons.delete_outline))
                            ],
                          ),
                        )
                      ],
                    )
                ),
                Expanded(
                    child: ListView.builder(
                      itemExtent: 30,
                      itemCount: controller.filteredLogs.length,
                      reverse: true,
                      padding: const EdgeInsets.all(4),
                      itemBuilder: (context, index) {
                        var item = controller.filteredLogs[index];
                        return Container(
                          padding: const EdgeInsets.symmetric(horizontal: 8),
                          margin: const EdgeInsets.symmetric(vertical: 1),
                          decoration: BoxDecoration(
                            color: Theme.of(context).colorScheme.surface,
                            borderRadius: BorderRadius.circular(8),
                            border: Border.all(color: Theme.of(context).colorScheme.surface),
                          ),
                          child: Row(
                            children: [
                              Icon(
                                logLevelIcon(item.origin.level),
                                color: logLevelColor(item.origin.level, context),
                                size: 20,
                              ),
                              const SizedBox(width: 8),
                              Expanded(
                                child: Text(item.origin.message, style: TextStyle(color: logLevelColor(item.origin.level, context)),),
                              ),
                            ],
                          ),
                        );
                        //   ListTile(
                        //   dense: true,
                        //   shape: RoundedRectangleBorder(
                        //     borderRadius: BorderRadius.circular(8),
                        //   ),
                        //   tileColor: Theme.of(context).colorScheme.surface,
                        //   visualDensity: VisualDensity.comfortable,
                        //   // leading: Icon(
                        //   //   logLevelIcon(item.origin.level),
                        //   //   color: logLevelColor(item.origin.level),
                        //   //   size: 20,
                        //   // ),
                        //   textColor: logLevelColor(item.origin.level),
                        //   title: Text(item.origin.message),
                        // );
                      },

                    ))
              ],
            ),
          );
        }
    );
  }
}
