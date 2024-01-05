import 'dart:math';

import 'package:chairmanager_flutter/data/Mod.dart';
import 'package:chairmanager_flutter/panes/paneThemes.dart';
import 'package:chairmanager_flutter/states/ModListState.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter/material.dart' as material;
import 'package:flutter/services.dart';
import 'package:get/get.dart';
// import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:xml/xml.dart';

import '../data/ModConfig.dart';
import '../log/log.dart';
import '../states/ConfigController.dart';


class ConfigPane extends StatelessWidget {
  const ConfigPane({super.key});

  // int _index = 0;
  // // String filter_text = "";
  // // TextEditingController filter_controller = TextEditingController();
  // ScrollPosController scrollPosController scrollPosController= ScrollPosController();


  @override
  Widget build(BuildContext context) {
    ModListController modListController = Get.find();
    ConfigController configController = Get.find();
    return
      Container(
        decoration: BoxDecoration(
          color: titleColor,
          borderRadius: BorderRadius.circular(8),
        ),
        margin: const EdgeInsets.all(8),
        child:
        Column(
          children: [
            Container(
              alignment: Alignment.centerLeft,
              margin: const EdgeInsets.only(top: 8, bottom: 8, left: 8),
              decoration: const BoxDecoration(
                color: titleColor,
                borderRadius: BorderRadius.only(topLeft: Radius.circular(5), topRight: Radius.circular(5)),
              ),
              child: const Text("Mod Configs", style: titleStyle,),
            ),
            Expanded(
              child: Obx(() =>
                  TabView(
                    currentIndex: configController.tabIndex.value,
                    scrollController: configController.tabScrollPosController.value,
                    showScrollButtons: true,
                    tabWidthBehavior: TabWidthBehavior.sizeToContent,
                    closeButtonVisibility: CloseButtonVisibilityMode.never,
                    tabs: (){
                      List<Tab> tabs = [];
                      configController.indexToModName.clear();
                      for (Mod mod in modListController.mods) {
                        if(mod.config == null){
                          continue;
                        }
                        if(mod.config!.entries.isEmpty){
                          continue;
                        }
                        tabs.add(
                            Tab(
                              text: Obx( () => Tooltip(
                                message: mod.displayName.isEmpty ? mod.modName : mod.displayName,
                                child: Text(
                                  "${mod.displayName.isEmpty ? mod.modName : mod.displayName}"
                                      "${mod.config!.dirty.value ? " *" : ""}",
                                  style: FluentTheme.of(context).typography.bodyStrong,
                                ),
                              )
                              ),
                              body: Container(
                                decoration: const BoxDecoration(
                                  color: tileColor,
                                  borderRadius: BorderRadius.only(bottomLeft: Radius.circular(5), bottomRight: Radius.circular(5)),
                                ),
                                child: ModConfigTabBody(mod: mod, onChanged: (){}),
                              ),
                            ));
                        configController.indexToModName[tabs.length-1] = mod.modName;
                      }
                      return tabs;
                    }(),
                    onChanged: (v) {
                      configController.tabIndex.value = v;
                      // configController.tabScrollPosController.value.jumpTo(0);
                    },
                    // put some save button and reload button here
                    header: Container(
                      height: 35,
                      child: Row(
                        children: [
                          Tooltip(
                            message: "Save Config",
                            child: FilledButton(
                                onPressed:() {
                                  Mod mod = modListController.getMod(configController.getCurrentModName());
                                  mod.config?.saveConfig(callback: (){
                                    logger.ii("Saved config for ${mod.modName}");
                                  });

                                },
                              style:  modListController.getMod(configController.getCurrentModName()).config!.dirty.value ? ButtonStyle(
                                backgroundColor: ButtonState.resolveWith((states) => states.isHovering ? material.Colors.deepPurpleAccent : material.Colors.deepPurple.toAccentColor()),
                              ) :
                              ButtonStyle(
                                backgroundColor: ButtonState.resolveWith((states) => states.isHovering ? material.Colors.deepPurpleAccent : material.Colors.transparent),
                              ),
                                child: Icon(material.Icons.save, size: 20, color: modListController.getMod(configController.getCurrentModName()).config!.dirty.value ? Colors.white : material.Colors.grey,),
                            ),
                          ),
                          // reload config button
                          Tooltip(
                            message: "Reload Config",
                            child: IconButton(
                                icon: const Icon(material.Icons.refresh, size: 25,),
                                onPressed:() {
                                  Mod mod = modListController.getMod(configController.getCurrentModName());
                                  mod.config?.loadConfig(callback: (){
                                    logger.ii("Reloaded config for ${mod.modName}");
                                  });
                                }
                            ),
                          ),
                        ],
                      ),
                    ),
                  ),
              ),
            )
          ],
        ),
      );
  }
}




class ModConfigTabBody extends StatelessWidget {
  const ModConfigTabBody({super.key, required this.mod, required this.onChanged});

  final Mod mod;
  final Function onChanged;

  @override
  Widget build(BuildContext context) {
    ConfigController configController = Get.find();
    return Container(
      child: (){
        if(mod.config != null){
          return Column(
            children: [
              // Divider(),
              Expanded(child: Obx( () => TreeView(
                // padding: const EdgeInsets.all(8),
                onItemExpandToggle: (item, expanded) {
                  if (item.value is ConfigEntry) {
                    (item.value as ConfigEntry).uiExpanded.value = expanded;
                    item.expanded = expanded;
                  }
                  return Future<void>.value();
                },
                onItemInvoked: (item, _) {
                  if (item.value is ConfigEntry) {
                    (item.value as ConfigEntry).uiExpanded.value = !(item.value as ConfigEntry).uiExpanded.value;
                    item.expanded = !(item.value as ConfigEntry).uiExpanded.value;
                    onChanged();
                  }
                  return Future<void>.value();
                },
                items: [
                  for(ConfigEntry entry in mod.config!.entries)
                    entry.toTreeView(context, onChanged, index: mod.config!.entries.indexOf(entry)),
                ],
                // scrollController: configController.treeScrollPosController.value,
                narrowSpacing: configController.narrowSpacing.value,

              ))),
            ],
          );
        } else {
          return const Text("This mod does not have a config file");
        }
      }(),
    );
  }
}

