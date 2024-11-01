import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:chairmanager_flutter_v2/controllers/SettingsController.dart';


class Settings extends StatelessWidget {
  const Settings({super.key});

  @override
  Widget build(BuildContext context) {
    PathController pathController = Get.find();
    return GetBuilder<SettingsController>(
      builder: (controller) {
        return Card(
          child: Container(
            padding: const EdgeInsets.all(16.0),
            child: Center(
              child: Column(
                children: [
                  Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      const Text('Theme Color:'),
                      DropdownButton(
                            padding: const EdgeInsets.symmetric(horizontal: 8.0),
                            value: controller.themeColor.value,
                            borderRadius: BorderRadius.circular(4.0),
                            items: [
                              ...ThemeColor.values.map((e) => DropdownMenuItem(
                                value: e,
                                child: Row(
                                  children: [
                                    Container(
                                      width: 16.0,
                                      height: 16.0,
                                      color: e.color,
                                    ),
                                    const SizedBox(width: 8.0),
                                    Text(e.name),
                                  ],
                                ),
                              ))
                            ],
                            onChanged: (value) {
                              controller.setThemeColor(value ?? ThemeColor.Blue);
                            },
                          ),
                    ],
                  ),
                  Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      const Text('Dynamic Scheme Variant:'),
                      DropdownButton(
                            padding: const EdgeInsets.symmetric(horizontal: 8.0),
                            value: controller.schemeVariant.value,
                            borderRadius: BorderRadius.circular(4.0),
                            items: [
                              ...DynamicSchemeVariant.values.map((e) => DropdownMenuItem(
                                value: e,
                                child: Row(
                                  children: [
                                    const SizedBox(width: 8.0),
                                    Text(e.name),
                                  ],
                                ),
                              ))
                            ],
                            onChanged: (value) {
                              controller.setSchemeVariant(value ?? DynamicSchemeVariant.tonalSpot);
                            },
                          ),
                    ],
                  ),
                  // bind to path controller preyPath
                  TextField(
                    controller: TextEditingController(text: pathController.preyPath.value),
                    onChanged: (value) {
                      pathController.setPreyPath(value);
                    },
                  ),
                ],
              ),
            ),
          ),
        );
      },
    );
  }
}
