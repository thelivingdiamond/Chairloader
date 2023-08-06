import 'package:fluent_ui/fluent_ui.dart';
import 'package:chairmanager_flutter/log/log.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';

import '../states/SettingsManager.dart';


class SettingsPane extends ConsumerStatefulWidget {
  const SettingsPane({super.key});

  @override
  ConsumerState<ConsumerStatefulWidget> createState() => _SettingsPaneState();
}

class _SettingsPaneState extends ConsumerState<SettingsPane> {
  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.all(10),
      child: Column(
        children: [
          Checkbox(
            checked: ref.watch(settingsManagerProvider).test,
            onChanged: (value) {
              ref.read(settingsManagerProvider.notifier).test = value!;
            },
          ),
          ToggleSwitch(
            checked: ref.watch(settingsManagerProvider).mooncrashMode,
            onChanged: (v) {
              ref.read(settingsManagerProvider.notifier).mooncrashMode = v;
            },
            thumb: Container(
              width: 20,
              height: 20,
              decoration: BoxDecoration(
                color: Colors.white,
                borderRadius: BorderRadius.circular(10),
              ),
            ),
            leadingContent: true,
            content: const Text("Mooncrash"),
          )
        ],
      ),
    );
  }
}
