import 'package:chairmanager_flutter_v2/controllers/ModController.dart';
import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/controllers/VersionController.dart';
import 'package:chairmanager_flutter_v2/pages/config/Config.dart';
import 'package:chairmanager_flutter_v2/pages/log/LogPage.dart';
import 'package:flutter/material.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:get/get.dart';

import 'package:chairmanager_flutter_v2/controllers/FocusController.dart';
import 'package:chairmanager_flutter_v2/controllers/NavigationController.dart';
import 'package:chairmanager_flutter_v2/controllers/SettingsController.dart';
import 'package:chairmanager_flutter_v2/pages/home/Home.dart';
import 'package:chairmanager_flutter_v2/pages/settings/Settings.dart';
import 'package:talker_flutter/talker_flutter.dart';



void main() async {
  var talker = Get.put(TalkerFlutter.init(
      settings: TalkerSettings(
        useHistory: true,
        useConsoleLogs: true,
        enabled: true,
        maxHistoryItems: 1000,
        timeFormat: TimeFormat.yearMonthDayAndTime,
      )
  ));

  Get.put(NavigationController());
  Get.put(FocusController());

  var settingsController = Get.put(SettingsController());
  await settingsController.load();

  var pathController = Get.put(PathController());
  await pathController.load();

  var versionController = Get.put(VersionController());
  await versionController.init();

  var modController = Get.put(ModController());

  runApp(const MyApp());
  talker.stream.listen((event) {
    if(event.logLevel == LogLevel.error || event.logLevel == LogLevel.critical){
      Get.snackbar(
        "Error",
        event.displayMessage,
        backgroundColor: Colors.red.shade900.withOpacity(0.8),
        snackPosition: SnackPosition.BOTTOM,
        colorText: Colors.white,
        animationDuration: const Duration(milliseconds: 300),
        icon: const Icon(Icons.error),
        shouldIconPulse: event.logLevel == LogLevel.critical,
        onTap: (snack) => Get.closeCurrentSnackbar(),
        snackStyle: SnackStyle.FLOATING,
      );
    }
  });

  await modController.detectMods();
  doWhenWindowReady(() {
    const initialSize = Size(1000, 600);
    appWindow.minSize = const Size(600, 400);
    appWindow.size = initialSize;
    appWindow.alignment = Alignment.center;
    appWindow.show();
  });
}

const borderColor = Color(0xFF550680);


class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    SettingsController settingsController = Get.find();
    return Obx( () => GetMaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'UniFlutter',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: settingsController.themeColor.value.color, brightness: settingsController.darkMode.value ? Brightness.dark : Brightness.light, dynamicSchemeVariant: settingsController.schemeVariant.value),
        useMaterial3: true,
      ),
      navigatorObservers: [
        TalkerRouteObserver(Get.find()),
      ],
      home:  Scaffold(
        body: WindowBorder(
          color: borderColor,
          width: 1,
          child: const Row(
            children: [LeftSide(), RightSide()],
          ),
        ),
      ),
    )
    );
  }
}


class LeftSide extends StatelessWidget {
  const LeftSide({super.key});
  @override
  Widget build(BuildContext context) {
    NavigationController navigationController = Get.find();
    VersionController versionController = Get.find();
    return Obx(
          () => NavigationRail(
          backgroundColor: Theme.of(context).colorScheme.primaryContainer.withOpacity(0.5),
          selectedIndex: navigationController.selectedIndex.value,
          onDestinationSelected: (int index) {
            navigationController.changeTabIndex(index);
          },
          labelType: NavigationRailLabelType.all,
          destinations: [
            ...navigationController.destinations
              .map((e) => NavigationRailDestination(
              icon: Icon(e.icon),
              selectedIcon: Icon(e.selectedIcon),
              label: Text(e.title))),
            if(versionController.downloadUpdateAvailable || versionController.installUpdateAvailable)
              const NavigationRailDestination(
                icon: Icon(Icons.update, color: Colors.green,),
                selectedIcon: Icon(Icons.update, color: Colors.green,),
                label: Text("Update Available"),
              )
          ]
      ),
    );
  }
}

class RightSide extends StatelessWidget {
  const RightSide({super.key});
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
                  children: [Expanded(child: MoveWindow()), const WindowButtons()],
                ),
              ],
            ),
          ),
          Expanded(
            child: Container(
                padding: const EdgeInsets.all(8.0),
                // switch the widget being rendered based on the selected index
                child: Obx(() {
                  switch (navigationController.selectedIndex.value) {
                    case 0:
                      return const Home();
                    case 1:
                      return const Config();
                    case 2:
                      return const LogPage();
                    case 3:
                      return const Settings();
                    default:
                      return const Card(child: Placeholder(),);
                  }
                })
            ),
          ),
        ]),
      ),
    );
  }
}


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