import 'dart:async';
import 'dart:collection';

import 'package:chairmanager_flutter_v2/models/GenericLogMessage.dart';
import 'package:chairmanager_flutter_v2/storage/StorageMixin.dart';
import 'package:chairmanager_flutter_v2/widgets/GenericLogView.dart';
import 'package:flutter/material.dart';

import 'package:get/get.dart';
import 'package:talker_flutter/talker_flutter.dart';
import 'package:intl/intl.dart';

class LogPage extends StatefulWidget {
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
  State<LogPage> createState() => _LogPageState();
}

class _LogPageState extends State<LogPage> with StorageMixin {
  // default log level filter
  HashSet<LogLevel> logLevelFilter = HashSet.of([LogLevel.info, LogLevel.warning, LogLevel.error, LogLevel.critical]);
  Talker talker = Get.find<Talker>();

  StreamSubscription<TalkerData>? talkerSubscription;

  String filter = '';
  TextEditingController filterController = TextEditingController();
  DateFormat dateFormat = DateFormat('HH:mm:ss');


  @override
  void initState() {
    super.initState();
    loadLogLevelFilter();
    talkerSubscription = talker.stream.listen((event) {
      if (logLevelFilter.contains(event.logLevel)) {
        if(mounted){
          setState(() {});
        }
      }
    });
  }


  @override
  void dispose() {
    talkerSubscription?.cancel();
    super.dispose();
  }

  List<GenericLogMessage> get filteredMessages {
    return talker.history.where((e) => logLevelFilter.contains(e.logLevel) && e.displayMessage.toLowerCase().contains(filter.toLowerCase()))
        .map((e) => GenericLogMessage('${dateFormat.format(e.time.toLocal())} | ${e.displayMessage}', e.logLevel ?? LogLevel.info)).toList();
  }

  Future<void> setLogLevel(LogLevel level, bool enabled) async {
    if (enabled) {
      logLevelFilter.add(level);
    } else {
      logLevelFilter.remove(level);
    }
    await saveLogLevelFilter(logLevelFilter);
    setState(() {});
  }

  Future<void> saveLogLevelFilter(HashSet<LogLevel> logLevelFilter) async {
    await storage.set('logLevelFilter', logLevelFilter.map((e) => e.toString()).toList());
  }

  void loadLogLevelFilter() {
    final List<dynamic>? logLevelFilterStrings = storage.get('logLevelFilter');
    if (logLevelFilterStrings != null) {
      logLevelFilter = HashSet.of(logLevelFilterStrings.map((e) => LogLevel.values.firstWhere((element) => element.toString() == e)));
    }
  }

  @override
  Widget build(BuildContext context) {
    return Card(
      child: Padding(
        padding: const EdgeInsets.all(8.0),
        child: Column(
          children: [
            Row(
              children: [
                Text("Log", style: Theme.of(context).textTheme.titleLarge),
                // search filter
                const Spacer(),
                Expanded(
                  child: Padding(
                    padding: const EdgeInsets.symmetric(horizontal: 8.0),
                    child: TextField(
                      controller: filterController,
                      onChanged: (value) {
                        setState(() {
                          filter = value;
                        });
                      },
                      decoration: const InputDecoration(
                        hintText: 'Filter',
                        prefixIcon: Icon(Icons.search),
                      ),
                    ),
                  ),
                ),
              ],
            ),
            const SizedBox(height: 8.0),
            // filter log level selection bubbles
            Container(
              alignment: Alignment.centerLeft,
              child: Wrap(
                alignment: WrapAlignment.start,
                children: [
                  for (var level in logLevelPriorityList.reversed)
                    Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 4.0),
                      child: ChoiceChip(
                        label: Text(level.toString().split('.').last),
                        selected: logLevelFilter.contains(level),
                        onSelected: (selected) async {
                          await setLogLevel(level, selected);
                        },
                      ),
                    ),
                ],
              ),
            ),
            const SizedBox(height: 8.0),
            Expanded(
              child: GenericLogView(
                messages: filteredMessages,
                itemPadding: const EdgeInsets.symmetric(vertical: 4.0),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
