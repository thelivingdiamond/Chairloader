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


class ConfigPane extends StatefulWidget {
  const ConfigPane({super.key});

  @override
  State<ConfigPane> createState() => _ConfigPaneState();
}

class _ConfigPaneState extends State<ConfigPane> {
  int _index = 0;
  String filter_text = "";
  TextEditingController filter_controller = TextEditingController();
  ScrollPosController scrollPosController = ScrollPosController();


  @override
  Widget build(BuildContext context) {
    ModListController modListController = Get.find();
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
                      currentIndex: _index,
                      scrollController: scrollPosController,
                      showScrollButtons: true,
                      tabWidthBehavior: TabWidthBehavior.sizeToContent,
                      tabs: (){
                        List<Tab> tabs = [];
                        //TODO: convert to getX mod list
                        for (Mod mod in modListController.mods) {
                          // only add the mod if it matches the filter text
                          // if (mod.modName.toLowerCase().contains(filter_text.toLowerCase())) {
                          if(mod.config != null && mod.config!.entries.isNotEmpty){
                            tabs.add(_buildTabFromMod(mod, (){setState(() {
                              // force a rebuild
                            });},filterText: filter_text));

                          }
                          // }
                        }
                        return tabs;
                      }(),
                      onChanged: (v) {
                        setState(() {
                          _index = v;
                        });
                      },
                      closeButtonVisibility: CloseButtonVisibilityMode.never,
                      // put a filter box in the header
                      header: SizedBox(
                        width: max(50, min(150, MediaQuery.of(context).size.width / 5)),
                        child: Row(
                          children: [
                            Expanded(
                              child: TextBox(
                                controller: filter_controller,
                                onChanged: (v) {
                                  setState(() {
                                    filter_text = v;
                                  });
                                },
                              ),
                            ),
                            const SizedBox(width: 8),
                          ],
                        ),
                      ),
                    ),
                )
            ),
          ],
        ),
      );
  }
}


Tab _buildTabFromMod(Mod mod, Function onChanged, {String? filterText}) {
  return Tab(
    text: Tooltip(
      child: Text(mod.displayName.isEmpty ? mod.modName : mod.displayName),
      message: mod.displayName.isEmpty ? mod.modName : mod.displayName,
    ),
    body: Container(
      decoration: const BoxDecoration(
        color: tileColor,
        borderRadius: BorderRadius.only(bottomLeft: Radius.circular(5), bottomRight: Radius.circular(5)),
      ),
      child: ModConfigTabBody(mod: mod, onChanged: onChanged, filterText: filterText,),
    ),
  );
}

XmlDocument doc = XmlDocument.parse("""
<TheChair.ExampleMod version="1.0.0">
	<testString type="string" display_name="Test String">The quick brown fox jumped over the lazy dog</testString>
	<testBool type="bool" description="This is a test boolean">true</testBool>
	<testInt type="int" display_name="XXX Value">-200</testInt>
	<testUInt type="uint" display_name="YYY percent" description="Important number for stuff">4294967295</testUInt>
	<testInt64 type="int64">-12369420000000000</testInt64>
	<testUInt64 type="uint64">18446744073709551615</testUInt64>
	<testFloat type="float">68.7199936</testFloat>
	<testXMLNode type="xmlnode">
		<node1 type="string" display_name="Child Node 1">I am a child node</node1>
		<node2 type="string" display_name="Child Node 2">Important Config Details</node2>
	</testXMLNode>
	<testEnum type="enum" display_name="Test Enum Value" description="Hello this is a description">
		<selected></selected>
		<option name="Option A" description="Description of this option">A</option>
		<option name="Option B" description="Description of this option">B</option>
		<option name="Option C" description="Description of this option">C</option>
	</testEnum>
	<testEnum1 type="enum" display_name="Test Enum Value" description="Hello this is a description">
		<selected></selected>
		<option name="Option A" description="Description of this option">A</option>
		<option name="Option B" description="Description of this option">B</option>
		<option name="Option C" description="Description of this option">C</option>
	</testEnum1>
	<testEnum2 type="enum" display_name="Test Enum Value" description="Hello this is a description">
		<selected></selected>
		<option name="Option A" description="Description of this option">A</option>
		<option name="Option B" description="Description of this option">B</option>
		<option name="Option C" description="Description of this option">C</option>
	</testEnum2>
</TheChair.ExampleMod>
""");



class ModConfigTabBody extends StatelessWidget {
  const ModConfigTabBody({super.key, required this.mod, required this.onChanged, this.filterText});

  final Mod mod;
  final Function onChanged;
  final String? filterText;

  @override
  Widget build(BuildContext context) {
    return Container(
      child: (){
        if(mod.config != null){
          return TreeView(
            // padding: const EdgeInsets.all(8),
            onItemExpandToggle: (item, expanded) {
              if (item.value is ConfigEntry) {
                (item.value as ConfigEntry).uiExpanded.value = expanded;
                item.expanded = expanded;
                onChanged();
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
          );
        } else {
          return const Text("This mod does not have a config file");
        }
      }(),
    );
  }
}

