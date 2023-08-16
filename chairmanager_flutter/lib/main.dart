import 'dart:io';

import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:chairmanager_flutter/panes/assetPane.dart';
import 'package:chairmanager_flutter/panes/configPane.dart';
import 'package:chairmanager_flutter/panes/logPane.dart';
import 'package:chairmanager_flutter/panes/settingsPane.dart';
import 'package:chairmanager_flutter/states/SettingsManager.dart';
import 'package:flutter/material.dart' as material;
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter_acrylic/flutter_acrylic.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:logger/logger.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'package:file_picker/file_picker.dart';
import 'package:chairmanager_flutter/log/log.dart';
import 'package:window_manager/window_manager.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';

import 'panes/modListPane.dart';




Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Window.initialize();
  await WindowManager.instance.ensureInitialized();
  await WindowManager.instance.setTitle('Chair Manager');
  await WindowManager.instance.setTitleBarStyle(TitleBarStyle.normal, windowButtonVisibility: false);
  WindowOptions windowOptions = const WindowOptions(
    // size: Size(800, 600),
    center: true,
    backgroundColor: Colors.transparent,
    skipTaskbar: false,
    titleBarStyle: TitleBarStyle.hidden,
  );
  await WindowManager.instance.setMinimumSize(const Size(400, 300));
  windowManager.waitUntilReadyToShow(windowOptions, () async {
    await windowManager.show();
    await windowManager.focus();
  });
  runApp(const ProviderScope(child: MyApp()));
}

class MyApp extends ConsumerWidget {
  const MyApp({Key? key}) : super(key: key);
  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return  FluentApp(
      theme: FluentThemeData(
          brightness: Brightness.dark,
          accentColor: material.Colors.deepPurple.toAccentColor(),
          scaffoldBackgroundColor: const Color.fromARGB(255, 30, 30, 30),
          // acrylicBackgroundColor: Colors.transparent,
          navigationPaneTheme: const NavigationPaneThemeData(
            backgroundColor: Color.fromARGB(255, 30, 30, 30),
            // backgroundColor: Colors.transparent,
          ),
          buttonTheme: ButtonThemeData(
              outlinedButtonStyle: ButtonStyle(
                border: ButtonState.all(BorderSide(color: Colors.purple, width: 3.0)),
                shape: ButtonState.all(const RoundedRectangleBorder(borderRadius: BorderRadius.all(Radius.circular(8.0)))),
              )
          )
      ),
      home: const Home(),
    );
  }
}

class Home extends ConsumerStatefulWidget {
  const Home({Key? key}) : super(key: key);



  @override
  ConsumerState<ConsumerStatefulWidget> createState() {
    return _HomeState();
  }
}


class _HomeState extends ConsumerState<Home> with WindowListener{
  int _index = 0;
  Color _titleBarColor = Colors.purple;

  final FlyoutController _flyoutController = FlyoutController();
  final ContextMenuController _contextMenuController = ContextMenuController();

  @override
  initState() {
    super.initState();
    WindowManager.instance.addListener(this);
  }

  @override
  void dispose() {
    WindowManager.instance.removeListener(this);
    super.dispose();
  }

  @override
  void onWindowFocus() {
    setState(() {
      _titleBarColor = FluentTheme.of(context).accentColor;
    });
  }

  @override
  void onWindowBlur(){
    setState(() {
      _titleBarColor = FluentTheme.of(context).accentColor.darkest;
    });
  }

  @override
  Widget build(BuildContext context) {
    return FluentTheme(
      data: FluentTheme.of(context),
      child: Column(
        children: [
          WindowTitleBarBox(
            child:Container(
              color: _titleBarColor,
              child: Row(
                children: [
                  Expanded(
                    child: MoveWindow(
                      child: Container(
                        padding: const EdgeInsets.only(left: 12.0),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.spaceAround,
                          children: [
                            const SizedBox(width: 4.0),
                            const Text(
                              'Chairloader Mod Manager',
                              style: TextStyle(
                                fontSize: 16.0,
                                fontWeight: FontWeight.w600,
                              ),
                            ),
                            const Spacer(),
                            Row(
                              children: [
                                MinimizeWindowButton(
                                    colors: WindowButtonColors(iconNormal: FluentTheme.of(context).inactiveColor, mouseOver: Colors.black.withAlpha(50))
                                ),
                                MaximizeWindowButton(
                                  colors: WindowButtonColors(iconNormal: FluentTheme.of(context).inactiveColor, mouseOver: Colors.black.withAlpha(50)),
                                ),
                                CloseWindowButton(
                                    colors: WindowButtonColors(iconNormal: FluentTheme.of(context).inactiveColor, mouseOver: Colors.red.dark)
                                ),
                              ],
                            )
                          ],
                        ),
                      ),
                    ),
                  ),
                ],
              ),
            ),
          ),
          Expanded(child:
          NavigationView(
            transitionBuilder: (child, animation) {
              return FadeTransition(
                opacity: animation,
                child: child,
              );
            },
            pane: NavigationPane(
                displayMode: PaneDisplayMode.top,
                selected: _index,
                leading: FlyoutTarget(
                  controller: _flyoutController,
                  child: IconButton(
                    icon: const Icon(material.Icons.menu_open_rounded, size: 18),
                    onPressed: () {
                      _flyoutController.showFlyout(builder: (context) {
                        return MenuFlyout(
                          items: [
                            MenuFlyoutSubItem(
                              text: const Text('File'),
                              items: (context) {
                                return [
                                  MenuFlyoutItem(
                                    text: const Text('Install Mod'),
                                    onPressed: (){
                                      FilePicker.platform.pickFiles().then((value) {
                                        if (value != null) {
                                          logger.i(value.files.first.path);
                                        }
                                      }
                                      );
                                    },
                                  ),
                                  const MenuFlyoutSeparator(),
                                  MenuFlyoutItem(
                                    text: const Text('Uninstall Chairloader'),
                                    onPressed: Flyout.of(context).close,
                                  ),
                                ];
                              },
                            ),
                            MenuFlyoutSubItem(
                              text: const Text('Mods'),
                              items: (context) {
                                return [
                                  MenuFlyoutItem(
                                    text: const Text('Refresh Mod List'),
                                    onPressed: Flyout.of(context).close,
                                  ),
                                  MenuFlyoutItem(
                                    text: const Text('Save Config'),
                                    onPressed: Flyout.of(context).close,
                                  ),
                                  MenuFlyoutItem(
                                    text: const Text('Deploy Mods'),
                                    onPressed: Flyout.of(context).close,
                                  ),
                                ];
                              },
                            ),
                            MenuFlyoutSubItem(
                              text: const Text('Utilities'),
                              items: (context) {
                                return [
                                  MenuFlyoutItem(
                                    text: const Text('Remove Intro Videos'),
                                    onPressed: Flyout.of(context).close,
                                  ),
                                  MenuFlyoutItem(
                                    text: const Text('Restore Intro Videos'),
                                    onPressed: Flyout.of(context).close,
                                  ),
                                ];
                              },
                            ),
                            MenuFlyoutSubItem(
                              text: const Text('Help'),
                              items: (context) {
                                return [
                                  MenuFlyoutItem(
                                    text: const Text('About'),
                                    onPressed: Flyout.of(context).close,
                                  ),
                                  const MenuFlyoutSeparator(),
                                  MenuFlyoutItem(
                                    text: const Text('Check for Updates'),
                                    onPressed: Flyout.of(context).close,
                                  ),
                                ];
                              },
                            ),
                            const MenuFlyoutSeparator(),
                            MenuFlyoutItemBuilder(
                              builder: (context) {
                                return Container(
                                    padding: const EdgeInsets.all(10),
                                    child: ToggleSwitch(
                                      checked: ref.watch(settingsManagerProvider.notifier).mooncrashMode,
                                      onChanged: (v) {
                                        Flyout.of(context).setState(() {
                                          ref.read(settingsManagerProvider.notifier).mooncrashMode = v;
                                        });
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
                                );
                              },
                            ),
                          ],
                        );
                      });
                    },
                  ),
                ),
                onChanged: (i) => setState(() => _index = i),
                items: [
                  PaneItem(
                    icon: const Icon(material.Icons.list, size: 18,),
                    title: const Text("Mod List"),
                    body: const ModListPane(),
                  ),
                  PaneItem(
                    icon: const Icon(material.Icons.display_settings_sharp, size: 18,),
                    title: const Text("Mod Config"),
                    body: const ConfigPane(),
                  ),
                  // TODO: Make Asset Viewer Usable
                  // PaneItem(
                  //   icon: const Icon(material.Icons.folder, size: 18,),
                  //   title: const Text("Asset Viewer"),
                  //   body: Container(
                  //     child: const AssetPane(),
                  //   ),
                  // ),
                  PaneItem(
                    icon: const Icon(material.Icons.edit_note, size: 18,),
                    title: const Text("Log"),
                    body: const LogPane(),
                  ),
                  PaneItem(
                    icon: const Icon(material.Icons.settings, size: 18,),
                    title: const Text("Settings"),
                    body: SettingsPane(),
                  )
                ]
            ),
          ),
          ),
        ],
      ),
    );
  }
}
