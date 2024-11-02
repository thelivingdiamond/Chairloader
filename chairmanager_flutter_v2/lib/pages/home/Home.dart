import 'package:chairmanager_flutter_v2/controllers/ModController.dart';
import 'package:chairmanager_flutter_v2/pages/home/HomeController.dart';
import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:get/get.dart';
import 'package:talker_flutter/talker_flutter.dart';

class Home extends StatelessWidget {
  const Home({super.key});

  @override
  Widget build(BuildContext context) {
    final talker = Get.find<Talker>();
    return GetBuilder<HomeController>(
      init: HomeController(),
      builder: (homeController) {
        return Stack(
            children: [
              Row(
                children: [
                  GetBuilder<ModController>(
                      builder: (modController) {
                        return Expanded(
                          flex: 1,
                          child: Card(
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
                                          if(constraints.maxWidth >= 280)
                                            ...[
                                              Tooltip(
                                                  message: modController.configDirty ? "Save Changes" : "No Changes",
                                                  child: Animate(
                                                    target: modController.configDirty ? 1.0 : 0.0,
                                                  ).custom(
                                                    builder: (context, value, child) => IconButton(
                                                      icon: const Icon(Icons.save),
                                                      style: IconButton.styleFrom(
                                                        backgroundColor: Color.lerp(Colors.transparent, Theme.of(context).colorScheme.primaryContainer, value),
                                                      ),
                                                      color: Theme.of(context).colorScheme.onSurface,
                                                      onPressed: () => {
                                                        modController.saveModListToConfig()
                                                      },
                                                    ),
                                                    curve: Curves.fastOutSlowIn,
                                                    duration: 500.ms,
                                                  )
                                                //
                                              ),
                                              Tooltip(
                                                message: "Install Mod",
                                                child: IconButton(
                                                  icon: const Icon(Icons.create_new_folder),
                                                  onPressed: () => {
                                                    talker.error("Install Mod: This feature is not yet implemented", "AAAAAAAAAAAA")
                                                  },
                                                ),
                                              ),
                                              Tooltip(
                                                message: "Refresh Mod List",
                                                child: IconButton(
                                                  icon: const Icon(Icons.refresh),
                                                  onPressed: () async => {
                                                    await modController.detectMods()
                                                  },
                                                ),
                                              ),
                                            ],
                                          PopupMenuButton(
                                            icon: const Icon(Icons.more_vert),
                                            onSelected: (value) {
                                              switch(value) {
                                                case 0:
                                                  modController.enableAllMods(true);
                                                  break;
                                                case 1:
                                                  modController.enableAllMods(false);
                                                  break;
                                                case 2:
                                                  break;
                                                case 3:
                                                  break;
                                                case 4:
                                                  modController.detectMods();
                                                  break;
                                              }
                                            },
                                            itemBuilder: (context) => [
                                              if(constraints.maxWidth < 280)
                                                ...[
                                                  const PopupMenuItem(
                                                    value: 2,
                                                    child: Text("Save"),
                                                  ),
                                                  const PopupMenuItem(
                                                    value: 3,
                                                    child: Text("Install Mod"),
                                                  ),
                                                  const PopupMenuItem(
                                                    value: 4,
                                                    child: Text("Refresh Mod List"),
                                                  ),
                                                ],
                                              const PopupMenuItem(
                                                value: 0,
                                                child: Text("Enable All Mods"),
                                              ),
                                              const PopupMenuItem(
                                                value: 1,
                                                child: Text("Disable All Mods"),
                                              ),
                                            ],
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
                                        title: Text(mod.displayName.isNotEmpty ? mod.displayName : mod.modName),
                                        // subtitle: Text(mod.author),
                                        trailing: Container(
                                            padding: const EdgeInsets.symmetric(horizontal: 12.0, vertical: 2.0),
                                            child: Text(mod.version, style: TextStyle(color: Theme.of(context).disabledColor))
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
                          ),
                        );
                      }
                  ),
                  Expanded(flex: 1, child: Card(
                    child: Column(
                      children: [
                        Text("Mod Details", style: Theme.of(context).textTheme.bodyLarge),
                        if(homeController.selectedMod != null)
                          Column(
                            children: [
                              Text(homeController.selectedMod!.modName, style: Theme.of(context).textTheme.titleMedium),
                              Text("Version: ${homeController.selectedMod!.version}", style: Theme.of(context).textTheme.bodyMedium),
                              Text("Author: ${homeController.selectedMod!.author}", style: Theme.of(context).textTheme.bodyMedium),
                            ],
                          )
                        else
                          const Text("Select a mod to view details")
                      ],
                    ),
                  )),
                ],
              ),
              Positioned(
                  bottom: 16.0,
                  right: 16.0,
                  child: Row(
                    children: [
                      Tooltip(
                        message: "Deploy Mods",
                        child: FloatingActionButton(
                          onPressed: () {
                            Get.dialog(
                              AlertDialog(
                                title: const Text("Deploy Mods"),
                                content: const Text("This feature is not yet implemented"),
                                actions: [
                                  TextButton(
                                    onPressed: () {
                                      Get.back();
                                    },
                                    child: const Text("Close"),
                                  ),
                                ],
                              ),
                            );
                          },
                          shape: const CircleBorder(),
                          backgroundColor: Theme.of(context).colorScheme.primary,
                          splashColor: Theme.of(context).colorScheme.inversePrimary.withOpacity(0.3),
                          child: Icon(Icons.local_shipping, color: Theme.of(context).colorScheme.onPrimary),
                        ),
                      ),
                      const SizedBox(height: 8.0, width: 8.0),
                      Tooltip(
                        message: "Launch Game",
                        child: FloatingActionButton(
                          onPressed: () {
                            Get.dialog(
                              AlertDialog(
                                title: const Text("Launch Game"),
                                content: const Text("This feature is not yet implemented"),
                                actions: [
                                  TextButton(
                                    onPressed: () {
                                      Get.back();
                                    },
                                    child: const Text("Close"),
                                  ),
                                ],
                              ),
                            );
                          },
                            child: const Icon(Icons.play_arrow),
                        ),
                      ),
                    ],
                  )
              ),
            ]
        );
      },
    );
  }
}
