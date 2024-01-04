import 'dart:collection';
import 'dart:io';

import 'package:chairmanager_flutter/data/Mod.dart';
import 'package:chairmanager_flutter/panes/paneThemes.dart';
import 'package:chairmanager_flutter/states/AssetPanePersistentState.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter/material.dart' as material;

import 'package:chairmanager_flutter/log/log.dart';


class AssetPane extends StatefulWidget {
  const AssetPane({super.key});

  @override
  State<AssetPane> createState() => _AssetPaneState();
}

class _AssetPaneState extends State<AssetPane> {


  @override
  void initState() {
    super.initState();
    // ref.read(assetPanePersistentStateProvider.notifier).addListener((state){setState(() {});});
  }

  @override
  Widget build(BuildContext context) {
    return Container(
        decoration: BoxDecoration(
          color: titleColor,
          borderRadius: BorderRadius.circular(8),
        ),
        margin: const EdgeInsets.all(8),
        child:
        Column(
            children: [
              Container(
                padding: const EdgeInsets.all(8.0),
                alignment: Alignment.centerLeft,
                decoration: const BoxDecoration(
                  color: titleColor,
                  borderRadius: BorderRadius.only(topLeft: Radius.circular(5), topRight: Radius.circular(5)),
                ),
                child: const Text("Asset Viewer", style: titleStyle,),
              ),
              // Container(
              //   child: Text("Currently Selected Directory: ${ref.watch(assetPanePersistentStateProvider).selectedDirectory.path} \nCurrently Selected File: ${ref.watch(assetPanePersistentStateProvider).selectedFile.path}"),
              // ),
              // Text("Index: ${ref.watch(assetPanePersistentStateProvider).index}"),
              // Text("Directory Expansion Map: ${ref.watch(assetPanePersistentStateProvider).directoryExpansionMap}"),
              Expanded(
                child: TabView(
                  currentIndex: /*ref.watch(assetPanePersistentStateProvider).index,*/ 0,
                  closeButtonVisibility: CloseButtonVisibilityMode.never,
                  tabs: (){
                    List<Tab> tabs = [];
                    tabs.add(
                        Tab(
                          text: const Text("Vanilla Assets"),
                          icon: const Icon(material.Icons.folder),
                          body: Container(
                              decoration: BoxDecoration(
                                color: tileColor,
                                borderRadius: BorderRadius.circular(8),
                              ),
                              child: TreeView(
                                selectionMode: TreeViewSelectionMode.single,
                                scrollController: ScrollController(),
                                onItemExpandToggle: (item, isOpen) async {
                                  final value = item.value;
                                  if(value is Directory) {
                                      // if (ref.watch(assetPanePersistentStateProvider).directoryExpansionMap[value] != null) {
                                      //   ref.read(assetPanePersistentStateProvider.notifier).directoryExpansionMap.update(value, (value) => isOpen);
                                      // } else {
                                      //   ref.read(assetPanePersistentStateProvider.notifier).directoryExpansionMap[value] = isOpen;
                                      // }
                                      // logger.d("Directory Expansion Map: ${ref.watch(assetPanePersistentStateProvider).directoryExpansionMap}");
                                  }
                                },
                                onSelectionChanged: (item) async {
                                  logger.d("Items: $item");
                                  // for(var i in item) {
                                  //   if (i.value is File) {
                                  //       ref.read(assetPanePersistentStateProvider.notifier).selectedFile = i.value;
                                  //       ref.read(assetPanePersistentStateProvider.notifier).selectedDirectory = Directory("");
                                  //     break;
                                  //   } else if (i.value is Directory) {
                                  //       ref.read(assetPanePersistentStateProvider.notifier).selectedDirectory = i.value;
                                  //       ref.read(assetPanePersistentStateProvider.notifier).selectedFile = File("");
                                  //     break;
                                  //   }
                                  // }
                                },
                                items: [
                                  // DirectoryView(
                                  //     Directory(r"C:\Users\theli\Documents\Modding\Prey Modding\Learning2Hack\ChairLoader\ChairManager\Data\PreyFiles"),
                                  //     0,
                                  //     (p1){
                                  //       return ref.watch(assetPanePersistentStateProvider).directoryExpansionMap[p1] ?? false;
                                  //     },
                                  //     (p1){
                                  //       return ref.watch(assetPanePersistentStateProvider).selectedDirectory == p1;
                                  //     },
                                  //     (p1){
                                  //       return ref.watch(assetPanePersistentStateProvider).selectedFile == p1;
                                  //     },
                                  // ),

                                ],
                              )
                          ),
                        )
                    );
                    // for (Mod mod in ref.watch(modManagerProvider).mods) {
                    //   // only add the mod if it matches the filter text
                    //   // if (mod.modName.toLowerCase().contains(filter_text.toLowerCase())) {
                    //   tabs.add(
                    //       Tab(
                    //         text: Text(mod.modName),
                    //         body: Container(
                    //           decoration: BoxDecoration(
                    //             color: tileColor,
                    //             borderRadius: BorderRadius.circular(8),
                    //           ),
                    //           child: Placeholder(),
                    //         ),
                    //       )
                    //   );
                    //   // }
                    // }
                    return tabs;
                  }(),
                  onChanged: (v) {
                    // if(v != ref.watch(assetPanePersistentStateProvider).index){
                    //   ref.read(assetPanePersistentStateProvider.notifier).selectedFile = File("");
                    //   ref.read(assetPanePersistentStateProvider.notifier).selectedDirectory = Directory("");
                    //   ref.read(assetPanePersistentStateProvider.notifier).directoryExpansionMap = HashMap<Directory, bool>();
                    // }
                    // ref.read(assetPanePersistentStateProvider.notifier).index = v;
                  },
                ),
              )
            ]
        )
    );
  }
}


TreeViewItem DirectoryView(Directory directory, int directoryDepth, bool Function(Directory) isDirectoryExpanded, bool Function(Directory) isDirectorySelected, bool Function(File) isFileSelected) {
  final fileName = directory.path.split("\\").last;
  return TreeViewItem(
    leading: const Icon(material.Icons.folder),
    content: Text(fileName),
    children: [],
    value: directory,
    selected: isDirectorySelected(directory),
    expanded: isDirectoryExpanded(directory),
    lazy: true,
    onExpandToggle: (item, getsExpanded) async{
      if (item.children.isNotEmpty) return;
      var directoryList = await item.value.list().toList();
      for (var fileSystemEntity in directoryList) {
        if (fileSystemEntity is Directory) {
          item.children.add(DirectoryView(fileSystemEntity, directoryDepth + 1, isDirectoryExpanded, isDirectorySelected, isFileSelected));
        } else if (fileSystemEntity is File) {
          item.children.add(
            TreeViewItem(
              content: Text(fileSystemEntity.path.split("\\").last),
              value: fileSystemEntity,
              leading: const Icon(material.Icons.insert_drive_file_rounded),
              selected: isFileSelected(fileSystemEntity),
            ),
          );
        }
      }
    },
    onInvoked: (item, reason) async {
      logger.i(reason.name);
    }
  );
}