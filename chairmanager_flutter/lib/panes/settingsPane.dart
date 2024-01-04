import 'package:chairmanager_flutter/panes/paneThemes.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:chairmanager_flutter/log/log.dart';
import 'package:flutter/material.dart' as material;
import 'package:get/get.dart';
// import 'package:flutter_riverpod/flutter_riverpod.dart';

import '../states/SettingsController.dart';


class SettingsPane extends StatefulWidget {
  const SettingsPane({super.key});

  @override
  State<SettingsPane> createState() => _SettingsPaneState();
}

class _SettingsPaneState extends State<SettingsPane> {
  @override
  Widget build(BuildContext context) {
    SettingsController settingsController = Get.find();
    return Container(
      decoration: BoxDecoration(
        color: tileColor,
        borderRadius: BorderRadius.circular(8),
      ),
      margin: const EdgeInsets.all(8),
      child:
      Obx( () =>
          Column(
            children: [
              Container(
                padding: const EdgeInsets.all(8.0),
                alignment: Alignment.centerLeft,
                decoration: const BoxDecoration(
                  color: titleColor,
                  borderRadius: BorderRadius.only(topLeft: Radius.circular(5), topRight: Radius.circular(5)),
                ),
                child: const Text("Settings", style: titleStyle,),
              ),
              TextBox(
                prefix: const Text("Prey Path: "),
                controller: TextEditingController(text: settingsController.preyPath.value),
                onChanged: (value) {
                  settingsController.preyPath.value = value;
                },
                // value: context.read(settingsManagerProvider).test.toString(),
              ),
              Text("Prey Version: ${settingsController.preyVersion.value.name}"),
              ComboBox(items: const [
                ComboBoxItem<PreyVersion>(value: PreyVersion.Steam, child: Text("Steam")),
                ComboBoxItem<PreyVersion>(value: PreyVersion.GOG, child: Text("GOG")),
                ComboBoxItem<PreyVersion>(value: PreyVersion.Epic, child: Text("Epic")),
                ComboBoxItem<PreyVersion>(value: PreyVersion.MicrosoftStore, child: Text("Microsoft Store")),
              ],
                onChanged: (value) {
                  settingsController.preyVersion.value = value ?? PreyVersion.Unknown;
                },
                value: settingsController.preyVersion.value,
              ),
            ],
          ),
      ),
    );
  }
}
