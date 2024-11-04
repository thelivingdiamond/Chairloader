import 'package:chairmanager_flutter_v2/controllers/ModController.dart';
import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/controllers/VersionController.dart';
import 'package:chairmanager_flutter_v2/pages/config/Config.dart';
import 'package:chairmanager_flutter_v2/pages/debug/DebugPage.dart';
import 'package:chairmanager_flutter_v2/pages/log/LogPage.dart';
import 'package:chairmanager_flutter_v2/pages/splash/SplashScreen.dart';
import 'package:chairmanager_flutter_v2/widgets/WindowsButtons.dart';
import 'package:flutter/material.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:get/get.dart';

import 'package:chairmanager_flutter_v2/controllers/FocusController.dart';
import 'package:chairmanager_flutter_v2/controllers/NavigationController.dart';
import 'package:chairmanager_flutter_v2/controllers/SettingsController.dart';
import 'package:chairmanager_flutter_v2/pages/home/Home.dart';
import 'package:chairmanager_flutter_v2/pages/settings/Settings.dart';
import 'package:talker_flutter/talker_flutter.dart';

import 'controllers/LaunchController.dart';



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

  var launchController = Get.put(LaunchController());
  await launchController.init();

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

  try{
    await modController.detectMods();
  } catch(e, stackTrace){
    talker.error("Error detecting mods", e, stackTrace);
  }
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
      // routes: {
      //   '/splash': (context) => const SplashScreen(),
      // },
      // initialRoute: '/splash',

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
                label: Text("Update\nAvailable", textAlign: TextAlign.center,),
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
                    case 4:
                      return const DebugPage();
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