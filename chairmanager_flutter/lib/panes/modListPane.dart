import 'dart:io';

import 'package:chairmanager_flutter/data/Mod.dart';
import 'package:chairmanager_flutter/log/log.dart';
import 'package:chairmanager_flutter/panes/paneThemes.dart';
import 'package:chairmanager_flutter/states/ModManager.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter/material.dart' as material;
import 'package:flutter_riverpod/flutter_riverpod.dart';


class ModListPane extends ConsumerStatefulWidget {
  const ModListPane({super.key,});


  @override
  ConsumerState<ModListPane> createState() => _ModListPaneState();
}

class _ModListPaneState extends ConsumerState<ModListPane> {
  Mod? _selectedMod;

  final FlyoutController _controller = FlyoutController();
  Offset _mousePosition = Offset.zero;

  int _testIndex = 0;

  @override
  Widget build(BuildContext context) {
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
                            Container(
                                padding: const EdgeInsets.all(10),
                                decoration: const BoxDecoration(
                                  color: titleColor,
                                  borderRadius: BorderRadius.only(topLeft: Radius.circular(5), topRight: Radius.circular(5)),
                                ),
                                alignment: Alignment.centerLeft,
                                child: const Text("Mod List", style: titleStyle,)
                            ),
                            Container(
                                child: IconButton(
                                  icon: const Icon(material.Icons.add),
                                  onPressed: () {
                                    ref.read(modManagerProvider.notifier).addMod(Mod(modName: "mod$_testIndex", displayName: "This is a MOD", author: "ASDA", version: "1", dllName: "", loadOrder: 0, isLegacy: false, enabled: false));
                                    _testIndex++;
                                    ref.read(modManagerProvider.notifier).serializeLoadOrder();
                                  },
                                )
                            ),
                            // add a separator line
                            // const Divider(),
                            Flexible(
                              child: ListView.builder(itemCount: ref.watch(modManagerProvider).mods.length, itemBuilder: (context, i){
                                return ModListTile(
                                  shouldHaveBottomDragTarget: i == ref.watch(modManagerProvider).mods.length - 1 ? true : null,
                                  controller: _controller,
                                  tilePressed: () {
                                    // check for right click
                                    setState(() {
                                      _selectedMod = ref.watch(modManagerProvider).mods[i];
                                    });
                                  },
                                  menuPressed: (){
                                    _controller.showFlyout(
                                      position: _mousePosition,
                                      builder: (context){
                                        return MenuFlyout(
                                          items: [
                                            MenuFlyoutItem(text: Text("Test ${i.toString()}"), onPressed: (){
                                              logger.i("Test ${i.toString()} pressed");
                                            }),
                                            MenuFlyoutItem(text: Text("Super Test ${i.toString()}"), onPressed: (){
                                              logger.ii("Test ${i.toString()} pressed", context);
                                            }),
                                          ],
                                        );
                                      },
                                    );
                                  },
                                  mod: ref.watch(modManagerProvider).mods[i],
                                  upPressed: () {
                                    setState(() {
                                      ref.read(modManagerProvider.notifier).moveModUp(ref.watch(modManagerProvider).mods[i]);
                                    });
                                  },
                                  downPressed: () {
                                    setState(() {
                                      ref.read(modManagerProvider.notifier).moveModDown(ref.watch(modManagerProvider).mods[i]);
                                    });
                                  },
                                  updateUI: () {
                                    setState(() {});
                                  },
                                  isSelected: _selectedMod == ref.watch(modManagerProvider).mods[i] ? true : false,
                                  onEnable: (v){
                                    setState(() {
                                      ref.read(modManagerProvider.notifier).enableMod(ref.watch(modManagerProvider).mods[i], v ?? false);
                                    });
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
                          child:
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
                                      message: "Open mod folder",
                                      child: IconButton(
                                        icon: const Icon(material.Icons.folder, size: 30),
                                        onPressed: _selectedMod != null ?() {
                                          // Process.run('explorer.exe', ['/select,','${ref.watch(modManagerProvider).mods[0].modPath}']); // highlight/select the file/folder
                                          // Process.run('explorer.exe', ['${ref.watch(modManagerProvider).mods[0].modPath}']); // open the file/folder
                                          Process.run('explorer.exe', [r'C:\Users\theli\Documents']);
                                        } : null,
                                      ),
                                    ),
                                    Tooltip(
                                      message : "Open mod config file",
                                      child: IconButton(icon: const Icon(material.Icons.settings_applications, size: 30),
                                        onPressed: _selectedMod != null ? () {
                                          Process.run('explorer.exe', [r'C:\Users\theli\Documents']);
                                        } : null,
                                      ),
                                    ),
                                    Tooltip(
                                      message : "Uninstall mod",
                                      child: IconButton(icon: const Icon(material.Icons.delete, size: 30),
                                        onPressed: _selectedMod != null ? () {
                                          // TODO: add confirmation dialog and uninstall mod
                                          logger.dd("TODO: add confirmation dialog and uninstall mod", context);

                                        } : null,
                                      ),
                                    )
                                  ],
                                ),
                              ),
                              const Divider(),
                              ...(){
                                List<Widget> widgets = [];
                                if(_selectedMod != null){
                                  widgets = [
                                    Container(
                                        padding: const EdgeInsets.only(left: 10),
                                        child: Text(
                                          _selectedMod!.displayName,
                                          style: const TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
                                        )
                                    ),
                                    Container(
                                        padding: const EdgeInsets.only(left: 10),
                                        child: Text("${_selectedMod!.modName}",
                                          style: const TextStyle(fontSize: 16),
                                        )
                                    ),
                                    Container(
                                        padding: const EdgeInsets.only(left: 10, top: 5),
                                        child: Text("Author: ${_selectedMod!.author}",
                                          style: const TextStyle(fontSize: 16),
                                        )
                                    ),
                                    Container(
                                        padding: const EdgeInsets.only(left: 10, top: 5),
                                        child: Text("Version: ${_selectedMod!.version}",
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
                                        logger.dd("TODO: Deploy mods", context);
                                      },
                                      style: ButtonStyle(
                                        padding: ButtonState.all(const EdgeInsets.all(10)),
                                        backgroundColor: ButtonState.all(FluentTheme.of(context).accentColor),
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


class ModListTile extends ConsumerWidget {
  const ModListTile({super.key,
    required this.mod,
    required this.tilePressed,
    this.updateUI,
    this.upPressed,
    this.downPressed,
    required this.controller,
    this.shouldHaveBottomDragTarget, this.menuPressed, required this.isSelected, this.onEnable});

  final void Function() tilePressed;
  final void Function()? updateUI;
  final void Function()? upPressed;
  final void Function(bool?)? onEnable;
  final void Function()? downPressed;
  final void Function()? menuPressed;
  final FlyoutController controller;
  final bool? shouldHaveBottomDragTarget;
  final bool isSelected;

  final Mod mod;

  final double boxHeight = 50;

  @override
  Widget build(BuildContext context, WidgetRef ref) {
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
                        "${mod.modName}${mod.isLegacy ? " (Legacy)" : ""}",
                        style: TextStyle(color: mod.isLegacy ? FluentTheme.of(context).disabledColor : null, fontSize: 16),
                      ),
                    ],
                  ),
                )
            ),
            childWhenDragging: ModListTileBase(
              mod:Mod.empty(),
              needsDecoration: false,
              isSelected: false,
              tilePressed: (){  },
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
                      ref.read(modManagerProvider.notifier).setModLoadOrderAbove(data, mod);
                      updateUI?.call();
                    },
                  ),
                ),
                ModListTileBase(
                  mod: mod,
                  tilePressed: tilePressed,
                  updateUI: updateUI,
                  upPressed: upPressed,
                  downPressed: downPressed,
                  menuPressed: menuPressed,
                  isSelected: isSelected,
                  onEnable: onEnable,
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
                          ref.read(modManagerProvider.notifier).setModLoadOrderBelow(data, mod);
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
    required this.tilePressed,
    this.updateUI,
    this.upPressed,
    this.downPressed,
    this.needsDecoration = true,
    this.menuPressed,
    required this.isSelected,
    this.onEnable,
  });

  final Mod mod;
  final void Function() tilePressed;
  final void Function()? updateUI;
  final void Function()? upPressed;
  final void Function(bool?)? onEnable;
  final void Function()? downPressed;
  final void Function()? menuPressed;
  final bool needsDecoration;
  final bool isSelected;

  @override
  Widget build(BuildContext context) {
    return ListTile(
      leading:
      Row(
        children: [
          Container(
            width: 10,
            height: 50,
            decoration: BoxDecoration(
              borderRadius: BorderRadius.circular(5),
              color: isSelected ? FluentTheme.of(context).accentColor.withAlpha(100) : null,
            ),
          ),
          Container(
            child: Button(onPressed: menuPressed,
              style: ButtonStyle(backgroundColor: ButtonState.all(Colors.transparent), border: ButtonState.all(BorderSide.none)),
              child:  needsDecoration ? Text("${mod.loadOrder}.", style: TextStyle(color: FluentTheme.of(context).activeColor,)
              ): Container(),
            ),
          ),
          const SizedBox(width: 10,),
          Checkbox(checked: mod.enabled, onChanged: onEnable)
        ],
      ),
      trailing: Row(
        children: [
          Container(
            padding: const EdgeInsets.only(right: 10),
            child: Text(mod.version, style: TextStyle(color: FluentTheme.of(context).disabledColor),),
          ),
          Container(
            padding: const EdgeInsets.only(right: 10),
            child: IconButton(icon: const Icon(material.Icons.more_vert), onPressed: menuPressed),
          ),
          needsDecoration ? IconButton(icon: const Icon(material.Icons.arrow_upward), onPressed: upPressed ?? (){}) : Container(),
          needsDecoration ? IconButton(icon: const Icon(material.Icons.arrow_downward), onPressed: downPressed ?? (){}): Container(),
        ],
      ),
      title: Row(
        children:[
          Text(
            "${mod.modName}${mod.isLegacy ? " (Legacy)" : ""}",
            style: mod.isLegacy ? TextStyle(color: FluentTheme.of(context).disabledColor) : null,
          ),
        ],
      ),
      subtitle: mod.isLegacy ? null : Text(
        mod.author,
        style: TextStyle(color: FluentTheme.of(context).disabledColor),
      ),
      onPressed: tilePressed,
    );
  }
}
