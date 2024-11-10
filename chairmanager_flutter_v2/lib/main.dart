import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/ChairloaderFileInstallController.dart';
import 'package:chairmanager_flutter_v2/controllers/DllPatcherController.dart';
import 'package:chairmanager_flutter_v2/controllers/ExtractionController.dart';
import 'package:chairmanager_flutter_v2/controllers/LaunchController.dart';
import 'package:chairmanager_flutter_v2/controllers/DeployController.dart';
import 'package:chairmanager_flutter_v2/controllers/ModController.dart';
import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/controllers/VersionController.dart';
import 'package:chairmanager_flutter_v2/pages/config/Config.dart';
import 'package:chairmanager_flutter_v2/pages/debug/DebugPage.dart';
import 'package:chairmanager_flutter_v2/pages/log/LogPage.dart';
import 'package:chairmanager_flutter_v2/pages/splash/SplashScreen.dart';
import 'package:chairmanager_flutter_v2/storage/Storage.dart';
import 'package:chairmanager_flutter_v2/widgets/MainBody.dart';
import 'package:chairmanager_flutter_v2/widgets/WindowsButtons.dart';
import 'package:chairmanager_flutter_v2/controllers/FocusController.dart';
import 'package:chairmanager_flutter_v2/controllers/NavigationController.dart';
import 'package:chairmanager_flutter_v2/controllers/SettingsController.dart';
import 'package:chairmanager_flutter_v2/pages/home/Home.dart';
import 'package:chairmanager_flutter_v2/pages/settings/Settings.dart';

import 'package:flutter/material.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:talker_flutter/talker_flutter.dart';
import 'package:get/get.dart';





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

  WidgetsFlutterBinding.ensureInitialized();

  var storage = Get.put(Storage(path: ".\\Config\\ChairManager.config"));
  await storage.init();

  Get.put(NavigationController());
  Get.put(FocusController());

  var settingsController = Get.put(SettingsController());
  await settingsController.load();

  var pathController = Get.put(PathController());
  await pathController.init();

  var versionController = Get.put(VersionController());
  await versionController.init();

  Get.put(DeployController());
  Get.put(ExtractionController());
  Get.put(ChairloaderFileInstallController());

  var patcherController = Get.put(DllPatcherController());
  await patcherController.load();

  var launchController = Get.put(LaunchController());
  await launchController.init();

  var modController = Get.put(ModController());

  runApp(const MyApp());

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

const borderColor = Color(0xFF252325);


class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    SettingsController settingsController = Get.find();
    NavigationController navigationController = Get.find();
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
          child: Row(
            children: [const LeftSide(),
              MainBody(
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
              )
            ],
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
        ],

        trailing: IconButton(
          icon: const Icon(Icons.more_vert),
          onPressed: () {
          },
        ),
      ),
    );
  }
}

