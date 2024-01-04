import 'dart:io';

import 'package:chairmanager_flutter/data/Mod.dart';
import 'package:chairmanager_flutter/log/log.dart';
import 'package:chairmanager_flutter/panes/paneThemes.dart';
import 'package:chairmanager_flutter/panes/settingsPane.dart';
import 'package:chairmanager_flutter/states/ModListState.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter/material.dart' as material;
// import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:get/get.dart';


class ModListPane extends StatefulWidget {
  const ModListPane({super.key,});


  @override
  State<ModListPane> createState() => _ModListPaneState();
}

class _ModListPaneState extends State<ModListPane> {
  // Mod? _selectedMod;

  final FlyoutController _controller = FlyoutController();
  Offset _mousePosition = Offset.zero;

  int _testIndex = 0;

  @override
  Widget build(BuildContext context) {
    ModListController modList = Get.find();
    return Container(
        margin: const EdgeInsets.all(10),
        child: Row(
          children: [
            SizedBox(
                width: MediaQuery.sizeOf(context).width * 0.5,
                child: Container(
                    decoration: BoxDecoration(
                      color: tileColor,
                      borderRadius: BorderRadius.circular(5),
                    ),
                    margin: const EdgeInsets.only(right: 5),
                    child: MouseRegion(
                        onHover:(PointerEvent details){
                          setState(() {
                            _mousePosition = details.position;
                          });
                        },
                        child: Column(
                          mainAxisSize: MainAxisSize.min,
                          mainAxisAlignment: MainAxisAlignment.start,
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            Obx(() =>
                                Container(
                                    padding: const EdgeInsets.all(10),
                                    decoration: const BoxDecoration(
                                      color: titleColor,
                                      borderRadius: BorderRadius.only(topLeft: Radius.circular(5), topRight: Radius.circular(5)),
                                    ),
                                    alignment: Alignment.centerLeft,
                                    child: Row(
                                      children: [
                                        Text("Mod List", style: titleStyle,),
                                        Text(" ${modList.dirty.value ? "*" : ""}", style: titleStyle.copyWith(color: FluentTheme.of(context).accentColor),),
                                        const Spacer(),
                                        Tooltip(
                                          message: "Save Mod List",
                                          child: FilledButton(
                                              child: Icon(material.Icons.save, size: 20, color: modList.dirty.value ? Colors.white : material.Colors.grey,),
                                              onPressed: () {
                                                modList.saveModListToConfig();
                                              },
                                            style: modList.dirty.value ? ButtonStyle(
                                              backgroundColor: ButtonState.resolveWith((states) => states.isHovering ? material.Colors.deepPurpleAccent : material.Colors.deepPurple.toAccentColor()),
                                            ) :
                                            ButtonStyle(
                                              backgroundColor: ButtonState.resolveWith((states) => states.isHovering ? material.Colors.deepPurpleAccent : material.Colors.transparent),
                                            ),
                                          ),
                                        ),
                                        const SizedBox(width: 5,),
                                        // Tooltip(
                                        //   message: "Toggle All Mods",
                                        //   child: IconButton(
                                        //     onPressed: (){
                                        //       modList.toggleAllMods();
                                        //     },
                                        //     icon: const Icon(material.Icons.check_box_outlined, size: 20, color: Colors.white,),
                                        //   ),
                                        // ),
                                        // const SizedBox(width: 5,),
                                        Tooltip(
                                          message: "Install mod from zip file",
                                          child: FilledButton(
                                            onPressed: (){
                                              logger.dd("TODO: Install mod from zip file");
                                            },
                                            child: const Icon(material.Icons.download, size: 20, color: Colors.white,),
                                          ),
                                        ),
                                        const SizedBox(width: 5,),
                                        Tooltip(
                                          message: "Refresh mod list",
                                          child: IconButton(
                                              icon: const Icon(material.Icons.refresh, size: 20),
                                              onPressed: () {
                                                modList.detectMods();
                                                logger.ii("Refreshing Mod List");
                                              }
                                          ),
                                        ),
                                        const SizedBox(width: 5,),
                                        FlyoutTarget(
                                            controller: _controller,
                                            child: IconButton(
                                              icon: const Icon(material.Icons.more_vert, size: 20),
                                              onPressed: () {
                                                _controller.showFlyout(
                                                  position: _mousePosition,
                                                  autoModeConfiguration: FlyoutAutoConfiguration(
                                                    preferredMode: FlyoutPlacementMode.bottomCenter,
                                                  ),
                                                  barrierDismissible: true,
                                                  dismissOnPointerMoveAway: false,
                                                  dismissWithEsc: true,
                                                  navigatorKey: null,
                                                  builder: (context) {
                                                    return MenuFlyout(items: [
                                                      MenuFlyoutItem(
                                                        leading: const Icon(material.Icons.toggle_on_outlined),
                                                        text: const Text('Toggle All Mods'),
                                                        onPressed: (){
                                                          modList.toggleAllMods();
                                                          Flyout.of(context).close;
                                                        }
                                                      ),
                                                    ]);
                                                  },
                                                );
                                              },
                                            )
                                        ),
                                      ],
                                    )
                                ),
                            ),
                            // add a separator line
                            // const Divider(),
                            Flexible(
                              //TODO: getX mod list
                              // child: Container(),
                              child: ListView.builder(itemCount: modList.mods.length, itemBuilder: (context, i){
                                final mod = modList.mods[i];
                                return ModListTile(
                                  shouldHaveBottomDragTarget: i == modList.mods.length - 1 ? true : null,
                                  controller: _controller,
                                  menuPressed: (){
                                    _controller.showFlyout(
                                      position: _mousePosition,
                                      builder: (context){
                                        return MenuFlyout(
                                          items: [
                                            MenuFlyoutItem(text: Text("Test ${i.toString()}"), onPressed: (){
                                              logger.i("Test ${mod.modName} pressed");
                                            }),
                                            MenuFlyoutItem(text: Text("Super Test ${i.toString()}"), onPressed: (){
                                              logger.ii("Test ${mod.modName} pressed");
                                            }),
                                          ],
                                        );
                                      },
                                    );
                                  },
                                  mod: modList.mods[i],
                                  updateUI: (){
                                    setState(() {});
                                  },
                                );
                              }
                              ),
                            ),
                          ],
                        )
                    )
                )
            ),
            Expanded(
                child: Container(
                  margin: const EdgeInsets.only(left: 5),
                  decoration: BoxDecoration(
                    color: tileColor,
                    borderRadius: BorderRadius.circular(5),
                  ),
                  child: Column(
                    children: [
                      Flexible(
                        child: Obx(() =>
                            ListView(
                              children: [
                                Container(
                                    padding: const EdgeInsets.all(10),
                                    decoration: const BoxDecoration(
                                      color: titleColor,
                                      borderRadius: BorderRadius.only(topLeft: Radius.circular(5), topRight: Radius.circular(5)),
                                    ),
                                    child: const Text("Mod Details", style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),)
                                ),

                                // add a row of utility buttons to manage the mod
                                // stuff like open folder, open config file, uninstall,
                                Container(
                                  padding: const EdgeInsets.all(10),
                                  child: Row(
                                    mainAxisAlignment: MainAxisAlignment.start,
                                    children: [
                                      const SizedBox(width: 10,),
                                      Tooltip(
                                        style: FluentTheme.of(context).tooltipTheme,
                                        message: "Open mod folder",
                                        child: IconButton(
                                          icon: const Icon(material.Icons.folder, size: 30),
                                          onPressed: !modList.selectedMod.value.isEmpty() ?() {
                                            // Process.run('explorer.exe', ['/select,','${ref.watch(modManagerProvider).mods[0].modPath}']); // highlight/select the file/folder
                                            // Process.run('explorer.exe', ['${ref.watch(modManagerProvider).mods[0].modPath}']); // open the file/folder
                                            Process.run('explorer.exe', [r'C:\Users\theli\Documents']);
                                          } : null,
                                        ),
                                      ),
                                      Tooltip(
                                        message : "Open mod config file",
                                        child: IconButton(icon: const Icon(material.Icons.settings_applications, size: 30),
                                          onPressed: !modList.selectedMod.value.isEmpty() ? () {
                                            Process.run('explorer.exe', [r'C:\Users\theli\Documents']);
                                          } : null,
                                        ),
                                      ),
                                      Tooltip(
                                        message : "Uninstall mod",
                                        child: IconButton(icon: const Icon(material.Icons.delete, size: 30),
                                          onPressed: !modList.selectedMod.value.isEmpty() ? () {
                                            // TODO: add confirmation dialog and uninstall mod
                                            logger.dd("TODO: add confirmation dialog and uninstall mod");

                                          } : null,
                                        ),
                                      ),
                                    ],
                                  ),
                                ),
                                const Divider(),
                                ...(){
                                  List<Widget> widgets = [];
                                  if(!modList.selectedMod.value.isEmpty()){
                                    widgets = [
                                      Container(
                                          padding: const EdgeInsets.only(left: 10),
                                          child: Text(
                                            modList.selectedMod.value.displayName,
                                            style: const TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
                                          )
                                      ),
                                      Container(
                                          padding: const EdgeInsets.only(left: 10),
                                          child: Text(modList.selectedMod.value.modName,
                                            style: const TextStyle(fontSize: 16),
                                          )
                                      ),
                                      Container(
                                          padding: const EdgeInsets.only(left: 10, top: 5),
                                          child: Text("Author: ${modList.selectedMod.value.author}",
                                            style: const TextStyle(fontSize: 16),
                                          )
                                      ),
                                      Container(
                                          padding: const EdgeInsets.only(left: 10, top: 5),
                                          child: Text("Version: ${modList.selectedMod.value.version}",
                                            style: const TextStyle(fontSize: 16),
                                          )
                                      ),
                                    ];
                                  }

                                  return widgets;
                                }(),
                              ],
                            )
                        ),
                      ),
                      SizedBox(
                          height: 80,
                          child: Column(
                            children: [
                              const Divider(direction: Axis.horizontal,),
                              const Spacer(),
                              Row(
                                mainAxisAlignment: MainAxisAlignment.end,
                                children: [
                                  Container(
                                    padding: const EdgeInsets.all(10),
                                    margin: const EdgeInsets.only(right: 10),
                                    child:
                                    FilledButton(
                                      onPressed: (){
                                        logger.dd("TODO: Deploy mods");
                                      },
                                      style: ButtonStyle(
                                        padding: ButtonState.all(const EdgeInsets.all(10)),
                                        // backgroundColor: ButtonState.all(FluentTheme.of(context).accentColor),
                                      ),
                                      child: Text("Deploy Mods",
                                        style: TextStyle(
                                            color: FluentTheme.of(context).activeColor,
                                            fontSize: 16,
                                            fontWeight: FontWeight.bold
                                        ),
                                      ),
                                    ),
                                  )
                                ],
                              ),
                              const Spacer(),
                            ],)
                      ),
                    ],
                  ),
                )
            ),
          ],
        )
    );
  }
}


class ModListTile extends StatelessWidget {
  const ModListTile({super.key,
    required this.mod,
    this.updateUI,
    required this.controller,
    this.shouldHaveBottomDragTarget,
    this.menuPressed
  });

  final void Function()? updateUI;
  final void Function()? menuPressed;
  final FlyoutController controller;
  final bool? shouldHaveBottomDragTarget;

  final Mod mod;

  final double boxHeight = 50;

  @override
  Widget build(BuildContext context) {
    ModListController modList = Get.find();
    return FlyoutTarget(controller: controller,
        child: Draggable<Mod>(
            data: mod,
            feedback: SizedBox(
                width: MediaQuery.sizeOf(context).width * 0.5,
                height: boxHeight,
                child: Container(
                  color: FluentTheme.of(context).cardColor,
                  alignment: Alignment.center,
                  child: Row(
                    children: [
                      IconButton(icon: const Icon(material.Icons.drag_handle), onPressed: (){}),
                      const SizedBox(width: 10,),
                      Text(
                        "${mod.displayName.isEmpty ? mod.modName : mod.displayName}${mod.isLegacy ? " (Legacy)" : ""}",
                        style: mod.isLegacy ? FluentTheme.of(context).typography.bodyLarge!.copyWith(decoration: TextDecoration.none, color: FluentTheme.of(context).inactiveColor) : FluentTheme.of(context).typography.bodyLarge!.copyWith(decoration: TextDecoration.none),
                      ),
                    ],
                  ),
                )
            ),
            childWhenDragging: DefaultTextStyle(
              style: FluentTheme.of(context).typography.body!.copyWith(decoration: TextDecoration.none),
              child: ModListTileBase(
                mod:Mod.empty(),
                needsDecoration: false,
              ),
            ),
            child: Column(
              children: [
                SizedBox(
                  height:8,
                  child: DragTarget<Mod>(
                    builder: (context, candidateData, rejectedData) {
                      if(candidateData.isNotEmpty){
                        return Container(
                          color: FluentTheme.of(context).accentColor,
                        );
                      } else {
                        return Container();
                      }
                    },
                    onWillAccept: (data) {
                      return true;
                    },
                    onAccept: (data) {
                      //TODO: getX mod list
                      modList.setModLoadOrderAbove(data, mod);
                      updateUI?.call();
                    },
                  ),
                ),
                ModListTileBase(
                  mod: mod,
                  updateUI: updateUI,
                  menuPressed: menuPressed,
                ),
                    (){
                  if(shouldHaveBottomDragTarget == null){
                    return Container();
                  } else if (shouldHaveBottomDragTarget!){
                    return SizedBox(
                      height:8,
                      child: DragTarget<Mod>(
                        builder: (context, candidateData, rejectedData) {
                          if(candidateData.isNotEmpty){
                            return Container(
                              color: FluentTheme.of(context).accentColor,
                            );
                          } else {
                            return Container();
                          }
                        },
                        onWillAccept: (data) {
                          return true;
                        },
                        onAccept: (data) {
                          //TODO: getX mod list
                          modList.setModLoadOrderBelow(data, mod);
                          updateUI?.call();
                        },
                      ),
                    );
                  } else {
                    return Container();
                  }
                }()
              ],
            )
        )
    );
  }
}


class ModListTileBase extends StatelessWidget {
  const ModListTileBase({
    super.key,
    required this.mod,
    this.updateUI,
    this.needsDecoration = true,
    this.menuPressed,
  });

  final Mod mod;
  final void Function()? updateUI;
  final void Function()? menuPressed;
  final bool needsDecoration;

  @override
  Widget build(BuildContext context) {
    ModListController modList = Get.find();
    return ListTile(
      tileColor: (){
        return ButtonState.resolveWith((states) {
          if (states.contains(ButtonStates.hovering)) {
            return FluentTheme.of(context).activeColor.withAlpha(40);
          }
          if(modList.isModSelected(mod)){
            return FluentTheme.of(context).activeColor.withAlpha(20);
          }
          return tileColor;
        });
      }(),
      leading:
      Row(
        mainAxisAlignment: MainAxisAlignment.start,
        children: [
          // Container(
          //   width: 10,
          //   height: 50,
          //   decoration: BoxDecoration(
          //     borderRadius: BorderRadius.circular(5),
          //     color: modList.isModSelected(mod) ? FluentTheme.of(context).accentColor.withAlpha(100) : null,
          //   ),
          //   padding: const EdgeInsets.only(right: 10),
          // ),
          Container(
            child: Button(onPressed: menuPressed,
              style: ButtonStyle(backgroundColor: ButtonState.all(Colors.transparent), /*border: ButtonState.all(BorderSide.none)*/),
              child:  needsDecoration ? Text("${mod.loadOrder}.", style: TextStyle(color: FluentTheme.of(context).activeColor,)
              ): Container(),
            ),
          ),
          const SizedBox(width: 10,),
          Checkbox(checked: mod.enabled, onChanged: (v){
            modList.enableMod(mod, v ?? false);
            updateUI?.call();
          },),
        ],
      ),
      trailing: Row(
        children: [
          Container(
            padding: const EdgeInsets.only(right: 10),
            child: Text(mod.version, style: TextStyle(color: FluentTheme.of(context).inactiveColor),),
          ),
          Container(
            padding: const EdgeInsets.only(right: 10),
            child: IconButton(icon: const Icon(material.Icons.more_vert), onPressed: menuPressed),
          ),
          needsDecoration ? IconButton(icon: const Icon(material.Icons.arrow_upward), onPressed: (){modList.moveModUp(mod); updateUI?.call();}) : Container(),
          needsDecoration ? IconButton(icon: const Icon(material.Icons.arrow_downward), onPressed: (){modList.moveModDown(mod); updateUI?.call();}) : Container(),
        ],
      ),
      title: Row(
        children:[
          Text(
            mod.displayName.isEmpty ? mod.modName : mod.displayName,
            // style: mod.isLegacy ? TextStyle(color: FluentTheme.of(context).inactiveColor) : const TextStyle(),
          ),
          Text(
            mod.isLegacy ? " - Legacy" : "",
            style: TextStyle(color: material.Colors.grey),
          ),
        ],
      ),
      subtitle: mod.isLegacy ? null : Text(
        mod.author,
        style: TextStyle(color: FluentTheme.of(context).inactiveColor),
      ),
      onPressed: (){
        modList.selectMod(mod);
        updateUI?.call();
      },
    );
  }
}
