import 'dart:io';
import 'package:chairmanager_flutter/data/Mod.dart';
import 'package:chairmanager_flutter/panes/paneThemes.dart';
import 'package:chairmanager_flutter/states/ModManager.dart';
import 'package:flutter/material.dart' as material;
import 'package:fluent_ui/fluent_ui.dart';

import 'package:chairmanager_flutter/log/log.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';


class ModListPane extends ConsumerStatefulWidget {
  const ModListPane({super.key,});


  @override
  ConsumerState<ModListPane> createState() => _ModListPaneState();
}

class _ModListPaneState extends ConsumerState<ModListPane> {
  String _selectedMod = "";

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
                                    ref.read(modManagerProvider.notifier).addMod(Mod(modName: "mod$_testIndex", displayName: "aaAA", author: "ASDA", version: "1", dllName: "", loadOrder: 0, isLegacy: false));
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
                                      _selectedMod = "Mod $i";
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
                              // add a separator line
                              // const Divider(),
                              Container(
                                  padding: const EdgeInsets.all(10),
                                  child: Text("Selected Mod: $_selectedMod")
                              ),
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
                                      onPressed: (){},
                                      style: ButtonStyle(
                                        padding: ButtonState.all(const EdgeInsets.all(10)),
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
    this.shouldHaveBottomDragTarget, this.menuPressed});

  final void Function() tilePressed;
  final void Function()? updateUI;
  final void Function()? upPressed;
  final void Function()? downPressed;
  final void Function()? menuPressed;
  final FlyoutController controller;
  final bool? shouldHaveBottomDragTarget;

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
  const ModListTileBase({super.key, required this.mod, required this.tilePressed, this.updateUI, this.upPressed, this.downPressed, this.needsDecoration = true, this.menuPressed});

  final Mod mod;
  final void Function() tilePressed;
  final void Function()? updateUI;
  final void Function()? upPressed;
  final void Function()? downPressed;
  final void Function()? menuPressed;
  final bool needsDecoration;

  @override
  Widget build(BuildContext context) {
    return ListTile(
      leading:Button(onPressed: menuPressed,
          style: ButtonStyle(backgroundColor: ButtonState.all(Colors.transparent), border: ButtonState.all(BorderSide.none)),
          child:  needsDecoration ? Text("${mod.loadOrder}.", style: TextStyle(color: FluentTheme.of(context).activeColor,)
          ): Container(),
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
