import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:chairmanager_flutter_v2/controllers/SettingsController.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class WindowButtons extends StatefulWidget {
  const WindowButtons({super.key});

  @override
  State<WindowButtons> createState() => _WindowButtonsState();
}

class _WindowButtonsState extends State<WindowButtons> {
  void maximizeOrRestore() {
    setState(() {
      appWindow.maximizeOrRestore();
    });
  }

  WindowButtonColors getButtonColors(BuildContext context) {
    return WindowButtonColors(
        iconNormal: Theme.of(context).colorScheme.primary.withOpacity(0.6),
        mouseOver: Theme.of(context).colorScheme.primary.withOpacity(0.6),
        mouseDown: Theme.of(context).colorScheme.primary.withOpacity(0.9),
        iconMouseOver: Theme.of(context).colorScheme.onPrimary,
        iconMouseDown: Theme.of(context).colorScheme.onPrimary
    );
  }

  WindowButtonColors getCloseButtonColors(BuildContext context) {
    return WindowButtonColors(
        iconNormal: Theme.of(context).colorScheme.primary.withOpacity(0.8),
        mouseOver: const Color(0xFFD32F2F),
        mouseDown: const Color(0xFFB71C1C),
        iconMouseOver: Theme.of(context).colorScheme.onError,
        iconMouseDown: Theme.of(context).colorScheme.onError
    );
  }

  @override
  Widget build(BuildContext context) {
    SettingsController settingsController = Get.find();
    return Row(
      children: [
        Obx(() => IconButton(
            onPressed: settingsController.toggleDarkMode,
            icon: Icon(settingsController.darkMode.value ? Icons.dark_mode : Icons.light_mode, size: 16,)
        )),
        const SizedBox(width: 8.0),
        MinimizeWindowButton(colors: getButtonColors(context)),
        appWindow.isMaximized
            ? RestoreWindowButton(
          colors: getButtonColors(context),
          onPressed: maximizeOrRestore,
        )
            : MaximizeWindowButton(
          colors: getButtonColors(context),
          onPressed: maximizeOrRestore,
        ),
        CloseWindowButton(colors: getCloseButtonColors(context)),
      ],
    );
  }
}