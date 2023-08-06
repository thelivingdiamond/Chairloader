import 'dart:math';

import 'package:chairmanager_flutter/data/Mod.dart';
import 'package:chairmanager_flutter/panes/paneThemes.dart';
import 'package:chairmanager_flutter/states/ModManager.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter/material.dart' as material;
import 'package:flutter/services.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:xml/xml.dart';


class ConfigPane extends ConsumerStatefulWidget {
  const ConfigPane({super.key});

  @override
  ConsumerState<ConfigPane> createState() => _ConfigPaneState();
}

class _ConfigPaneState extends ConsumerState<ConfigPane> {
  int _index = 0;
  String filter_text = "";
  TextEditingController filter_controller = TextEditingController();


  @override
  Widget build(BuildContext context) {
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
              child:
              TabView(
                currentIndex: _index,
                tabs: (){
                  List<Tab> tabs = [];
                  for (Mod mod in ref.watch(modManagerProvider).mods) {
                    // only add the mod if it matches the filter text
                    // if (mod.modName.toLowerCase().contains(filter_text.toLowerCase())) {
                    tabs.add(_buildTabFromMod(mod, (){setState(() {
                      // force a rebuild
                    });},filterText: filter_text));
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
            ),
          ],
        ),
      );
  }
}


Tab _buildTabFromMod(Mod mod, Function onChanged, {String? filterText}) {
  return Tab(
    text: Text(mod.modName),
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
        child:  mod.configFile == null ? TreeView(
          shrinkWrap: false,
          itemExtent: 36,
          items: (){
            List<TreeViewItem> items = [];
            for(XmlNode node in mod.configFile!.children){
              if(node.nodeType == XmlNodeType.ELEMENT) {
                final item = recursiveTreeViewItemFromXmlNode(node as XmlElement, onChanged, context, filterText: filterText);
                if(item != null){
                  items.add(item);
                }
              }
            }
            if(items.isEmpty){
              items.add(TreeViewItem(
                content: const Text("No Matching Nodes Found"),
              ));
            }
            return items;
          }(),
        ) : const Center(
          child: Text("No Config File Found"),
        ),
    );
  }
}




class RecursiveXmlTreeItem extends StatelessWidget {
  const RecursiveXmlTreeItem({super.key});

  @override
  Widget build(BuildContext context) {
    return const Placeholder();
  }
}



TreeViewItem? recursiveTreeViewItemFromXmlNode(XmlNode node, Function onChanged, BuildContext context, {String? filterText}){
  // print("Recursing");
  if(node.nodeType != XmlNodeType.ELEMENT){
    return null;
  }

  final element = node as XmlElement;

  final type = node.getAttribute("type");
  final displayName = node.getAttribute("display_name");
  final description = node.getAttribute("description");
  final name = element.name.local;


  final matchFilter = filterText == null || filterText.isEmpty || name.toLowerCase().contains(filterText.toLowerCase()) || (displayName != null && displayName.toLowerCase().contains(filterText.toLowerCase()));

  List<TreeViewItem?> children = [];
  if(node.children.isNotEmpty){
    for(XmlNode child in node.children){
      if(child.nodeType == XmlNodeType.ELEMENT) {
        final item = recursiveTreeViewItemFromXmlNode(child as XmlElement, onChanged, context, filterText: filterText);
        if(item != null){
          children.add(item);
        }
      }
    }
  }

  List<TreeViewItem> nonNullChildren = [];
  for(TreeViewItem? child in children){
    if(child != null){
      nonNullChildren.add(child);
    }
  }

  if(!matchFilter && nonNullChildren.isEmpty){
    return null;
  }



  switch(type){
    case "string":
      return TreeViewItem(
        content:
        // Row(
        //   children: [
        //     Text(displayName ?? name),
        //     const SizedBox(width: 8),
        //     Expanded( child:
        TextBox(
          controller: TextEditingController(text: element.innerText),
          onChanged: (v) {
            element.innerText = v;
          },
          prefix: Container(
            padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
            color: FluentTheme.of(context).accentColor,
            child: Text(displayName ?? name),
          ),
        ),
        //     ),
        //   ],
        // ),
        children: nonNullChildren,
      );
    case "bool":
      return TreeViewItem(
        content:
        Row(
          children: [
            Container(
              padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
              color: FluentTheme.of(context).accentColor,
              child: Text(displayName ?? name),
            ),
            const SizedBox(width: 8),
            Checkbox(
              checked: element.innerText == "true",
              onChanged: (v) {
                element.innerText == "true" ? element.innerText = "false" : element.innerText = "true";
                onChanged();
              },
            ),
          ],
        ),
        // leading: const Icon(material.Icons.check_box),
        children: nonNullChildren,
      );
    case "int":
      return TreeViewItem(
        content:  NumberBox<int>(
          value: (){
            try{
              return int.parse(element.innerText);
            }catch(e){
              return 0;
            }
          }(),
          onChanged: (v){
            element.innerText = v.toString();
            onChanged();
          },
          inputFormatters: [
            // allow a leading minus sign and numbers
            FilteringTextInputFormatter.allow(RegExp(r'^-?\d+')),
          ],
          allowExpressions: true,
          clearButton: false,
          leadingIcon: Container(
            padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
            color: FluentTheme.of(context).accentColor,
            child: Text(displayName ?? name),
          ),
          mode: SpinButtonPlacementMode.inline,
        ),
        // leading: const Icon(material.Icons.numbers),
        children: nonNullChildren,
      );
    case "uint":
      return TreeViewItem(
        content: NumberBox<int>(
          value: (){
            try{
              return int.parse(element.innerText);
            }catch(e){
              return 0;
            }
          }(),
          onChanged: (v){
            element.innerText = v?.abs().toString() ?? "0";
            onChanged();
          },
          inputFormatters: [
            // allow a leading minus sign and numbers
            FilteringTextInputFormatter.allow(RegExp(r'[0-9]')),
          ],
          clearButton: false,
          leadingIcon: Container(
            padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
            color: FluentTheme.of(context).accentColor,
            child: Text(displayName ?? name),
          ),
          mode: SpinButtonPlacementMode.inline,
        ),
        // leading: const Icon(material.Icons.numbers),
        children: nonNullChildren,
      );
    case "int64":
      return TreeViewItem(
        content: TextBox(
          controller: TextEditingController(text: element.innerText),
          onChanged: (v) {
            element.innerText = v;
          },
          inputFormatters: [
            // allow a leading minus sign and numbers
            FilteringTextInputFormatter.allow(RegExp(r'^-?\d+')),
          ],
          onEditingComplete: () {
            onChanged();
          },
          prefix: Container(
            padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
            color: FluentTheme.of(context).accentColor,
            child: Text(displayName ?? name),
          ),
        ),
        // leading: const Icon(material.Icons.arrow_right),
        children: nonNullChildren,
      );
    case "uint64":
      return TreeViewItem(
        content: TextBox(
          controller: TextEditingController(text: element.innerText),
          onChanged: (v) {
            element.innerText = v;
          },
          inputFormatters: [
            FilteringTextInputFormatter.allow(RegExp(r'[0-9]')),
          ],
          onEditingComplete: () {
            onChanged();
          },
          prefix: Container(
            padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
            color: FluentTheme.of(context).accentColor,
            child: Text(displayName ?? name),
          ),
        ),
        // leading: const Icon(material.Icons.arrow_right),
        children: nonNullChildren,
      );
    case "float":
      return TreeViewItem(
        content: NumberBox<double>(
          value: (){
            try{
              return double.parse(element.innerText);
            }catch(e){
              return 0.0;
            }
          }(),
          onChanged: (v){
            element.innerText = v.toString();
            onChanged();
          },
          inputFormatters: [
            // allow a leading minus sign and numbers and a single decimal point
            FilteringTextInputFormatter.allow(RegExp(r'^-?\d+\.?\d*')),
          ],
          allowExpressions: true,
          clearButton: false,
          leadingIcon: Container(
            padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
            color: FluentTheme.of(context).accentColor,
            child: Text(displayName ?? name),
          ),
          mode: SpinButtonPlacementMode.inline,
        ),
        // leading: const Icon(material.Icons.looks_5),
        children: nonNullChildren,
      );
    case "xmlnode":
      return TreeViewItem(
        content: Text(displayName ?? name),
        // leading: const Icon(material.Icons.looks_6),
        children: nonNullChildren,
        // expanded: filterText == null || filterText.isNotEmpty,
        expanded: true,
      );
    case "enum":
    // the selected value is stored in the <selected> child node
    // all possible values are stored in <option> child nodes
    // this xml library requires that we cast nodes to elements if we want to access their attributes and names
      String selected = "";
      List<ComboBoxItem<String>> options = [];
      for(XmlNode node in element.children){
        if(node is XmlElement){
          if(node.name.local == "selected"){
            selected = node.innerText;
          }else if(node.name.local == "option"){
            // see if there is a name attribute, if not, use the text
            String name = node.getAttributeNode("name")?.value ?? node.innerText;
            final item = ComboBoxItem<String>(value: node.innerText, onTap: (){},child: Text(name));
            options.add(item);
          }
        }
      }
      return TreeViewItem(
        content:
        Container(
            alignment: Alignment.centerLeft,
            child:
            Row(
              mainAxisAlignment: MainAxisAlignment.start,
              crossAxisAlignment: CrossAxisAlignment.start,
              children:[
                Container(
                  padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
                  color: FluentTheme.of(context).accentColor,
                  child: Text(displayName ?? name),
                ),
                const SizedBox(width: 8,),
                Expanded(
                  child:
                OverflowBox(
                  maxHeight: double.infinity,
                  child:
                  ComboboxFormField(items: options,
                    // alignment: Alignment.centerLeft,
                    placeholder: Text("Select a value", style: TextStyle(color: FluentTheme.of(context).disabledColor),),
                    value: selected,
                    onChanged: (v){
                      // find the selected node and set its text
                      for(XmlNode node in element.children){
                        if(node is XmlElement){
                          if(node.name.local == "selected"){
                            node.innerText = v ?? "";
                          }
                        }
                      }
                      onChanged();
                    },),
                ),
                ),
              ],
            )
        ),
        // leading: const Icon(material.Icons.looks_6),
      );
    default:
      return TreeViewItem(
        content: Text(displayName ?? name),
        // leading: const Icon(material.Icons.more_horiz),
        children: nonNullChildren,
      );
  }
}

