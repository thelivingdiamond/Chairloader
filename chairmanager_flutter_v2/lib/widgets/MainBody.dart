import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:chairmanager_flutter_v2/controllers/FocusController.dart';
import 'package:chairmanager_flutter_v2/controllers/NavigationController.dart';
import 'package:chairmanager_flutter_v2/widgets/WindowsButtons.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class MainBody extends StatelessWidget {
  const MainBody({super.key, required this.child, this.showThemeSwitcher = true});

  final Widget child;
  final bool showThemeSwitcher;

  @override
  Widget build(BuildContext context) {
    NavigationController navigationController = Get.find();
    FocusController focusController = Get.find();
    return Expanded(
      child: Container(
        decoration: BoxDecoration(
          gradient: LinearGradient(
              begin: Alignment.topCenter,
              end: Alignment.bottomCenter,
              colors: [ Theme.of(context).colorScheme.primaryContainer.withOpacity(0.2), Theme.of(context).colorScheme.primaryContainer.withOpacity(0.5)],
              stops: const [0.1, 0.9]),
        ),
        child: Column(children: [
          WindowTitleBarBox(
            child: Stack(
              children: [
                Container(
                  height: appWindow.titleBarHeight,
                  alignment: Alignment.centerLeft,
                  padding: const EdgeInsets.only(left: 16.0),
                  child: Obx( () => Text("Chair Manager", style: focusController.hasFocus.value ? Theme.of(context).textTheme.titleMedium : Theme.of(context).textTheme.titleMedium!.copyWith(color: Theme.of(context).disabledColor),)),
                ),
                Row(
                  children: [Expanded(child: MoveWindow()), WindowButtons(showThemeSwitcher: showThemeSwitcher,)],
                ),
              ],
            ),
          ),
          Expanded(
            child: child,
          ),
        ]),
      ),
    );
  }
}