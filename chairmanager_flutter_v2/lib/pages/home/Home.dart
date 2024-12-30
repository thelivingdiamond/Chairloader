import 'package:chairmanager_flutter_v2/controllers/LaunchController.dart';
import 'package:chairmanager_flutter_v2/controllers/ModController.dart';
import 'package:chairmanager_flutter_v2/dialogs/modInstallation/ModInstallationDialog.dart';
import 'package:chairmanager_flutter_v2/dialogs/modUninstallation/ModUninstallationDialog.dart';
import 'package:chairmanager_flutter_v2/pages/home/HomeController.dart';
import 'package:chairmanager_flutter_v2/widgets/Intents.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:get/get.dart';
import 'package:talker_flutter/talker_flutter.dart';
import 'package:flutter_markdown/flutter_markdown.dart';

class Home extends StatelessWidget {
  const Home({super.key});

  @override
  Widget build(BuildContext context) {
    final talker = Get.find<Talker>();
    return GetBuilder<HomeController>(
      init: HomeController(),
      builder: (homeController) {
        return GetBuilder<ModController>(
            builder: (modController) {
              return FocusableActionDetector(
                autofocus: true,
                enabled: true,
                shortcuts: {
                  LogicalKeySet(LogicalKeyboardKey.control, LogicalKeyboardKey.keyS): const SaveIntent(),
                },
                actions: {
                  SaveIntent: CallbackAction(onInvoke: (_) => modController.saveModList()),
                },
                child: Stack(
                    children: [
                      Row(
                        children: [
                          Expanded(
                            flex: 1,
                            child: _modListPane(context, homeController, modController, talker),
                          ),
                          Expanded(
                              flex: 1,
                              child: _modDetailsPane(context, homeController, modController, talker)
                          ),
                        ],
                      ),
                    ]
                ),
              );
            }
        );
      },
    );
  }

  Widget _modListPane(BuildContext context, HomeController homeController, ModController modController, Talker talker) {
    return Card(
      clipBehavior: Clip.antiAlias,
      child: Column(
        children: [
          Container(
            decoration: BoxDecoration(
              borderRadius: const BorderRadius.only(topLeft: Radius.circular(12.0), topRight: Radius.circular(12.0)),
              color: Theme.of(context).colorScheme.surface,
            ),
            child: LayoutBuilder(
              builder: (context, constraints) =>  Container(
                padding: const EdgeInsets.all(8.0),
                child: Row(
                  children: [
                    const SizedBox(width: 16.0),
                    Text("Mod List", style: Theme.of(context).textTheme.titleLarge),
                    const Spacer(),
                    Tooltip(
                        message: modController.modListDirty ? "Save Changes (Ctrl+S)" : "No Changes",
                        child: Animate(
                          target: modController.modListDirty ? 1.0 : 0.0,
                        ).custom(
                          builder: (context, value, child) => IconButton(
                            icon: const Icon(Icons.save),
                            style: IconButton.styleFrom(
                              backgroundColor: Color.lerp(Colors.transparent, Theme.of(context).colorScheme.primaryContainer, value),
                            ),
                            color: Theme.of(context).colorScheme.onSurface,
                            onPressed: () => {
                              modController.saveModList()
                            },
                          ),
                          curve: Curves.fastOutSlowIn,
                          duration: 500.ms,
                        )
                      //
                    ),
                    if(constraints.maxWidth >= 280)
                      ...[
                        Tooltip(
                          message: "Install Mod",
                          child: IconButton(
                            icon: const Icon(Icons.create_new_folder),
                            onPressed: () => {
                              showDialog(context: context, builder: (context) => const ModInstallationDialog(), barrierDismissible: false),
                              // Get.dialog(const ModInstallationDialog(), barrierDismissible: false)
                            },
                          ),
                        ),
                        Tooltip(
                          message: "Refresh Mod List",
                          child: IconButton(
                            icon: const Icon(Icons.refresh),
                            onPressed: () async => await homeController.refreshMods(),
                          ),
                        ),
                      ],
                    MenuAnchor(
                      menuChildren: [
                        MenuItemButton(
                          leadingIcon: const Icon(Icons.check_box),
                          child: const Text("Enable All Mods"),
                          onPressed: () => modController.enableAllMods(true),
                        ),
                        MenuItemButton(
                          leadingIcon: const Icon(Icons.check_box_outline_blank),
                          child: const Text("Disable All Mods"),
                          onPressed: () => modController.enableAllMods(false),
                        ),
                        if(constraints.maxWidth < 280)
                          ...[
                            MenuItemButton(
                              leadingIcon: const Icon(Icons.create_new_folder),
                              onPressed: () => {
                                showDialog(context: context, builder: (context) => const ModInstallationDialog(), barrierDismissible: false),
                                // Get.dialog(const ModInstallationDialog(), barrierDismissible: false)
                              },
                              child: const Text("Install Mod"),
                            ),
                            MenuItemButton(
                              leadingIcon: const Icon(Icons.refresh),
                              onPressed: () async => await homeController.refreshMods(),
                              child: const Text("Refresh Mod List"),
                            ),
                          ],
                      ],
                      builder: (context, controller, child) => IconButton(
                        icon: child!,
                        onPressed: () {
                          if(controller.isOpen) {
                            controller.close();
                          } else {
                            controller.open();
                          }
                        },
                      ),
                      child: const Icon(Icons.more_vert),
                    ),
                  ],
                ),
              ),
            ),
          ),
          Expanded(
            child: ReorderableListView.builder(
              onReorder: (int oldIndex, int newIndex) {
                modController.reorderMods(oldIndex, newIndex);
              },
              itemCount: modController.mods.length,
              physics: const BouncingScrollPhysics(),
              itemBuilder: (context, index) {
                final mod = modController.mods[index];
                return ListTile(
                  dense: true,
                  selected: homeController.selectedMod == mod,
                  selectedTileColor: Theme.of(context).colorScheme.primary.withOpacity(0.2),
                  isThreeLine: false,
                  key: ValueKey(mod.modName),
                  title: RichText(
                      text: TextSpan(
                        style: Theme.of(context).textTheme.bodyMedium,
                        text: mod.displayName.isNotEmpty ? mod.displayName : mod.modName,
                        children: mod.isLegacy ? [
                          TextSpan(text: ' - Legacy', style: TextStyle(color: Theme.of(context).disabledColor)),
                        ] : null,
                      )
                  ),
                  subtitle: mod.author.isNotEmpty ? Text(mod.author) : null,
                  trailing: Container(
                      padding: const EdgeInsets.symmetric(horizontal: 12.0, vertical: 2.0),
                      child: Text(mod.version.toString(), style: TextStyle(color: Theme.of(context).disabledColor))
                  ),
                  leading: Container(
                      padding: const EdgeInsets.symmetric(horizontal: 8.0, vertical: 2.0),
                      child: Row(
                        mainAxisSize: MainAxisSize.min,
                        children: [
                          Checkbox(
                            value: mod.enabled,
                            onChanged: (bool? value) => modController.enableMod(mod, value),
                          ),
                          const SizedBox(width: 8.0),
                          Text('${mod.loadOrder.toString()}.'),
                        ],
                      )
                  ),
                  onTap: () => {
                    homeController.selectMod(mod)
                  },
                );
              },
            ),
          ),
        ],
      ),
    );
  }

  Widget _modDetailsPane(BuildContext context, HomeController homeController, ModController modController, Talker talker){
    LaunchController launchController = Get.find();
    return Card(
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Container(
            height: 48.0,
            alignment: Alignment.center,
            decoration: BoxDecoration(
              borderRadius: const BorderRadius.only(topLeft: Radius.circular(12.0), topRight: Radius.circular(12.0)),
              color: Theme.of(context).colorScheme.surface,
            ),
            child: Text("Mod Details", style: Theme.of(context).textTheme.titleLarge),
          ),
          if(homeController.selectedMod != null)
            ...[
              Row(
                children: [
                  Tooltip(
                    message: "Uninstall Mod",
                    child: IconButton(
                      icon: const Icon(Icons.delete),
                      onPressed: () {
                        showDialog(context: context, builder: (context) =>  ModUninstallationDialog(selectedMod: homeController.selectedMod!), barrierDismissible: false);
                        // Get.dialog(const ModUninstallationDialog(), arguments: homeController.selectedMod);
                        },
                    ),
                  ),
                  Tooltip(
                    message: "Open Mod Folder",
                    child: IconButton(
                      icon: const Icon(Icons.folder_open),
                      onPressed: () async => await homeController.openSelectedModFolder(),
                    ),
                  ),
                  Tooltip(
                    message: homeController.selectedMod?.config == null ? "" : "Open Mod Config File",
                    child: IconButton(
                      icon: const Icon(Icons.settings_applications_outlined),
                      onPressed: homeController.selectedMod?.config == null ? null : () async => await homeController.openSelectedModConfig(),
                    ),
                  ),
                ],
              ),
              const Divider(height: 1.0),
              Expanded(
              child: Container(
                padding: const EdgeInsets.all(8.0),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    if(homeController.selectedMod!.displayName.isNotEmpty)
                      ...[
                        Text(homeController.selectedMod!.displayName, style: Theme.of(context).textTheme.titleMedium),
                        Text(homeController.selectedMod!.modName, style: Theme.of(context).textTheme.titleSmall),
                      ]
                    else
                      Text(homeController.selectedMod!.modName, style: Theme.of(context).textTheme.titleMedium),
                    Text("Version: ${homeController.selectedMod!.version}", style: Theme.of(context).textTheme.bodyMedium),
                    Text("Author: ${homeController.selectedMod!.author}", style: Theme.of(context).textTheme.bodyMedium),
                    // expansion panel for dependencies (TODO: implement dependency checking)
                    const SizedBox(height: 8.0),
                    const ExpansionTile(
                        title: Text("Dependencies"),
                        visualDensity: VisualDensity.compact,
                        children: [
                          ListTile(
                            visualDensity: VisualDensity.compact,
                            title: Text("TODO: Implement Dependency Checking"),
                          )
                        ]),
                    const SizedBox(height: 8.0),
                    // render the description as markdown
                    if(homeController.selectedMod!.description != null)
                      Expanded(
                        child: Container(
                            alignment: Alignment.topLeft,
                            padding: const EdgeInsets.all(8.0),
                            decoration: BoxDecoration(
                                borderRadius: BorderRadius.circular(8.0),
                                border: Border.all(color: Theme.of(context).colorScheme.primaryContainer.withOpacity(0.3), width: 1.0)
                            ),
                            child: SingleChildScrollView(
                              child: Container(
                                  alignment: Alignment.topLeft,
                                  child: MarkdownBody(data: homeController.selectedMod!.description!)
                              ),
                            )
                        ),
                      ),
                  ],
                ),
              ),
            )
            ]
          else
            Expanded(child: Center(child: Text("Select a mod to view details", style: Theme.of(context).textTheme.bodyMedium))),
          Container(
            alignment: Alignment.bottomRight,
            padding: const EdgeInsets.all(8.0),
            child: Wrap(
              spacing: 4.0,
              runSpacing: 4.0,
              alignment: WrapAlignment.start,
              crossAxisAlignment: WrapCrossAlignment.center,
              children: [
                Tooltip(
                  message: "Deploy Mods",
                  child: FilledButton.tonal(
                    onPressed: () async => await homeController.openDeployDialog(context),
                    child: const Text("Deploy Mods"),
                  ),
                ),
                Tooltip(
                  message: "Launch Options",
                  child: IconButton(
                    icon: const Icon(Icons.settings),
                    // backgroundColor: Theme.of(context).colorScheme.primaryContainer.withOpacity(0.9),
                    onPressed: () async => await homeController.openLaunchOptionsDialog(context),
                  ),
                ),
                Obx(() {
                      if(launchController.isRunning.value) {
                        return Tooltip(
                          message: "Stop Game",
                          child: FloatingActionButton.small(
                            backgroundColor: Colors.red,
                            child: const Icon(Icons.stop, color: Colors.white),
                            onPressed: () => launchController.stopGame(),
                          ),
                        );
                      } else {
                        return Tooltip(
                          message: "Launch Game",
                          child: FloatingActionButton.small(
                            child: const Icon(Icons.play_arrow),
                            onPressed: () async => await launchController.launchGame(),
                          ),
                        );
                      }
                    }
                ),
              ],
            ),
          )
        ],
      ),
    );
  }
}


