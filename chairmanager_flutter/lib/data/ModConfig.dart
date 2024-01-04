import 'dart:io';

import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter/material.dart' as material;
import 'package:flutter/services.dart';
import 'package:get/get.dart';
import 'package:xml/xml.dart' as xml;

import '../log/log.dart';
import '../states/PathController.dart';

// this is a class for the config file of a mod
class ModConfig {
  ModConfig({required this.modName}) {
    PathController pathController = Get.find();
    configFile = File("${pathController.modConfigPath}/$modName.xml");
    defaultConfigFile = File("${pathController.modDirPath}/$modName/${modName}_default.xml");
    loadConfig();
  }
  List<ConfigEntry> entries = [];
  final String modName;
  late File configFile;
  late File defaultConfigFile;

  void loadConfig() async{
    // if the config file doesn't exist, create it from the default config file
    if(!await defaultConfigFile.exists()) {
      logger.v("Default config file for $modName does not exist!");
      return;
    }
    if (!await configFile.exists()) {
      await configFile.create();
      await configFile.writeAsString(await defaultConfigFile.readAsString());
      logger.i("Created config file for $modName");
    }
    // then load the config file
    var configString = await configFile.readAsString();
    var configDocument = xml.XmlDocument.parse(configString);
    var configElement = configDocument.rootElement;
    // then for each child of the root element, create a ConfigEntry from it
    for (var child in configElement.childElements) {
      entries.add(ConfigEntry.fromXml(child));
    }
    logger.v("Loaded config for $modName");
  }
}



enum ConfigEntryType {
  bool,
  int,
  unsignedInt,
  int64,
  unsignedInt64,
  float,
  string,
  enum_,
  xmlNode,
}

String configEntryTypeToString(ConfigEntryType type) {
  switch (type) {
    case ConfigEntryType.bool:
      return "bool";
    case ConfigEntryType.int:
      return "int";
    case ConfigEntryType.unsignedInt:
      return "uint";
    case ConfigEntryType.int64:
      return "int64";
    case ConfigEntryType.unsignedInt64:
      return "uint64";
    case ConfigEntryType.float:
      return "float";
    case ConfigEntryType.string:
      return "string";
    case ConfigEntryType.enum_:
      return "enum";
    case ConfigEntryType.xmlNode:
      return "xmlnode";
    default:
      return "xmlnode";
  }
}

ConfigEntryType stringToConfigEntryType(String typeString) {
  switch (typeString) {
    case "bool":
      return ConfigEntryType.bool;
    case "int":
      return ConfigEntryType.int;
    case "uint":
      return ConfigEntryType.unsignedInt;
    case "int64":
      return ConfigEntryType.int64;
    case "uint64":
      return ConfigEntryType.unsignedInt64;
    case "float":
      return ConfigEntryType.float;
    case "string":
      return ConfigEntryType.string;
    case "enum":
      return ConfigEntryType.enum_;
    case "xmlnode":
      return ConfigEntryType.xmlNode;
    default:
      return ConfigEntryType.xmlNode;
  }
}


/// Represents a single entry in a mod's config file
/// needs to be able to be converted to and from xml
/// it should be a tree structure
class ConfigEntry {
  ConfigEntry({
    required this.name,
    required this.type,
    required this.value,
    this.displayName,
    this.description,
    this.children,
  });

  final String name;
  final ConfigEntryType type;
  dynamic value;
  final String? description;
  final String? displayName;
  final List<ConfigEntry>? children;
  var uiExpanded = false.obs;
  // 	<name type="uint" display_name="YYY percent" description="Important number for stuff">4294967295</testUInt>
  // create a toXml method
  xml.XmlElement toXml() {
    // the first element should be named after the modName and have an attribute type="xmlnode", display_name="display_name", description="description"
    var entryElement = xml.XmlElement(xml.XmlName.fromString(name), [
      xml.XmlAttribute(
          xml.XmlName.fromString("type"), configEntryTypeToString(type))
    ]);
    if (displayName != null) {
      entryElement.attributes.add(xml.XmlAttribute(
          xml.XmlName.fromString("display_name"), displayName!));
    }
    if (description != null) {
      entryElement.attributes.add(xml.XmlAttribute(
          xml.XmlName.fromString("description"), description!));
    }
    // then for the value of the entry, it depends on the type. This goes inside the text of the element
    switch (type) {
      case ConfigEntryType.bool:
      case ConfigEntryType.int:
      case ConfigEntryType.unsignedInt:
      case ConfigEntryType.int64:
      case ConfigEntryType.unsignedInt64:
      case ConfigEntryType.float:
      case ConfigEntryType.string:
        entryElement.innerText = value.toString();
        break;
      case ConfigEntryType.enum_:
        entryElement = value.toXml(entryElement);
        break;
      case ConfigEntryType.xmlNode:
        for (var child in children!) {
          entryElement.children.add(child.toXml());
        }
        break;
    }
    // then for each child, call toXml on it and add it to the children of the entryElement
    if (children != null) {
      for (var child in children!) {
        entryElement.children.add(child.toXml());
      }
    }
    return entryElement;
  }

  // create a fromXml method
  static ConfigEntry fromXml(xml.XmlElement element) {
    // the first element should be named after the modName and have an attribute type="xmlnode", display_name="display_name", description="description"
    var name = element.name.toString();
    final typeString = element.getAttribute("type");
    var type = stringToConfigEntryType(typeString ?? "xmlnode");
    var displayName = element.getAttribute("display_name");
    var description = element.getAttribute("description");
    // then for the value of the entry, it depends on the type. This goes inside the text of the element
    var valueString = element.innerText;
    dynamic value;
    switch (type) {
      case ConfigEntryType.bool:
        value = valueString == "true";
        break;
      case ConfigEntryType.int:
      case ConfigEntryType.unsignedInt:
      case ConfigEntryType.int64:
        value = int.parse(valueString);
        break;
      case ConfigEntryType.unsignedInt64:
        value = BigInt.parse(valueString).toUnsigned(64);
        break;
      case ConfigEntryType.float:
        value = double.parse(valueString);
        break;
      case ConfigEntryType.string:
        value = valueString;
        break;
      case ConfigEntryType.enum_:
        value = ConfigEnumValue.fromXml(element);
        break;
      case ConfigEntryType.xmlNode:
        value = null;
        break;
    }
    // then for each child, call toXml on it and add it to the children of the entryElement
    var children = <ConfigEntry>[];
    for (var child in element.childElements) {
      children.add(fromXml(child));
    }
    return ConfigEntry(
      name: name,
      type: type,
      value: value,
      displayName: displayName,
      description: description,
      children: children,
    );
  }

  // have the context and a void callback function to update the ui
  TreeViewItem toTreeView(BuildContext context, Function updateUI, {int? index}) {
    final leadingWidget = Flexible(
        fit: FlexFit.tight,
        flex: 3,
        child: Container(
          padding: const EdgeInsets.symmetric(horizontal: 4),
          child: Text("${displayName ?? name}: ", style: FluentTheme.of(context).typography.body,),
        )
    );
    Widget inputWidget;
    switch (type) {
      case ConfigEntryType.bool:
        inputWidget =
          //   Flexible(
          // flex: 4,
          // child:
          ConstrainedBox(
            constraints: const BoxConstraints.tightFor(width: 35),
            child:
            Checkbox(
              content: const Text(""),
              checked: value as bool,
              onChanged: (value) {
                this.value = value ?? false;
                updateUI();
              },
            )
                // ),
        );
        break;
      case ConfigEntryType.int:
      case ConfigEntryType.unsignedInt:
      case ConfigEntryType.int64:
        inputWidget = Flexible(
            flex: 4,
            child:NumberBox(
              value: value as int,
              onChanged: (value) {
                this.value = value;
                // updateUI();
              },
              mode: SpinButtonPlacementMode.none,
            ));
        break;
      case ConfigEntryType.float:
        inputWidget = Flexible(
            flex: 4,
            child: NumberBox(
              value: value as double,
              onChanged: (value) {
                this.value = value;
                // updateUI();
              },
              mode: SpinButtonPlacementMode.none,
            ));
        break;
      case ConfigEntryType.unsignedInt64:
        inputWidget = Flexible(
            flex: 4,
            child: TextBox(
              controller: TextEditingController(text: value.toString()),
              onChanged: (value) {
                this.value = value;
                // updateUI();
              },
              inputFormatters: [
                TextInputFormatter.withFunction((oldValue, newValue) => FilteringTextInputFormatter.digitsOnly.formatEditUpdate(oldValue, newValue))
              ],
            ));
        break;
      case ConfigEntryType.string:
        inputWidget = Flexible(
            fit: FlexFit.tight,
            flex: 4,
            child: TextBox(
              controller: TextEditingController(text: value.toString()),
              onChanged: (value) {
                this.value = value;
                // updateUI();
              },
              maxLines: 4,
              minLines: 1,
            ));
        break;
      case ConfigEntryType.enum_:
        inputWidget = Flexible(
          fit: FlexFit.tight,
          flex: 4,
            child: ComboBox(
          items: (){
            var items = <ComboBoxItem>[];
            for (var option in (value as ConfigEnumValue).options) {
              items.add(ComboBoxItem(
                  value: option.value,
                  child: Tooltip(
                    message: option.description ?? option.displayName ?? option.value,
                    child: Text(option.displayName ?? option.value),
                  )
              ));
            }
            return items;
          }(),
          value: (value as ConfigEnumValue).selected,
          onChanged: (value) {
            (this.value as ConfigEnumValue).selected = value as String;
            updateUI();
          },
        ));
    //TODO: implement enum
      case ConfigEntryType.xmlNode:
        return TreeViewItem(
          value: this,
          lazy: true,
          content: ConstrainedBox(
              constraints: const BoxConstraints(minHeight: 32),
              child: Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    Text("${displayName ?? name}: ", style: FluentTheme.of(context).typography.body,),
                    Container(
                        padding: const EdgeInsets.symmetric(horizontal: 4),
                        child: Icon(material.Icons.folder)
                    )
                  ]
              )
          ),
          // onExpandToggle: (_, value) async{
          //   uiExpanded.value = value;
          //   // updateUI();
          // },
          // onInvoked: (_, __) async {
          //   uiExpanded.value = !uiExpanded.value;
          //   // updateUI();
          // },
          expanded: uiExpanded.value,
          children: [
            for (var child in children!)
              child.toTreeView(context, updateUI),
          ],
        );
    }
    return
      TreeViewItem(
        backgroundColor: index != null && index % 2 == 0 ? ButtonState.resolveWith(
                (states) => states.isHovering ? Colors.white.withOpacity(0.1) : Colors.white.withOpacity(0.05)
        ) : null,
        content:
        Tooltip(
            message: "${displayName ?? name}${description != null ? ":\n$description" : ""}",
            child: ConstrainedBox(
                constraints: const BoxConstraints(minHeight: 32),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.start,
                  children: [
                    leadingWidget,
                    inputWidget,
                  ],
                ))),
      );
  }
}

/// the enum value for a config entry
/// it must be able to store a name, description, display_name, current value, and a list of possible values
class ConfigEnumValue {
  ConfigEnumValue({
    required this.selected,
    required this.options,
  });

  String selected;
  final List<ConfigEnumOption> options;

  // create a toXml method, but this one returns a list of xml.XmlElement instead of just one, bc of selected and each option
  xml.XmlElement toXml(xml.XmlElement parentElement) {
    // the first element should be named after the modName and have an attribute type="xmlnode", display_name="display_name", description="description"
    // the list must contain a node called <selected> with the value of the selected option in the text of the node, and nothing else
    // then it must return a list of nodes, one for each option, with the optional name and description of the option,  and the value of the option in the text of the node
    // the selected node
    var selectedElement = xml.XmlElement(xml.XmlName.fromString("selected"), []);
    selectedElement.innerText = selected;
    parentElement.children.add(selectedElement);
    // the options
    for (var option in options) {
      parentElement.children.add(option.toXml());
    }
    return parentElement;
  }

  // create a fromXml method
  static ConfigEnumValue fromXml(xml.XmlElement element) {
    // get the selected child element
    var selectedElement = element.getElement("selected");
    var selected = selectedElement?.innerText ?? "";
    // get the options
    var options = <ConfigEnumOption>[];
    for (var optionElement in element.findElements("option")) {
      options.add(ConfigEnumOption.fromXml(optionElement));
    }
    return ConfigEnumValue(
      selected: selected,
      options: options,
    );
  }
}

class ConfigEnumOption {
  ConfigEnumOption({
    required this.value,
    this.description,
    this.displayName,
  });

  final String value;
  final String? displayName;
  final String? description;

  // create a toXml method
  xml.XmlElement toXml() {
    // the first element should be named after the modName and have an attribute type="xmlnode", display_name="display_name", description="description"
    var entryElement = xml.XmlElement(xml.XmlName.fromString("option"), []);
    if (displayName != null) {
      entryElement.attributes.add(xml.XmlAttribute(
          xml.XmlName.fromString("name"), displayName!));
    }
    if (description != null) {
      entryElement.attributes.add(xml.XmlAttribute(
          xml.XmlName.fromString("description"), description!));
    }
    // set the text of the element to the value
    entryElement.innerText = value;
    return entryElement;
  }

  // create a fromXml method
  static ConfigEnumOption fromXml(xml.XmlElement element) {
    // the first element should be named after the modName and have an attribute type="xmlnode", display_name="display_name", description="description"
    var displayName = element.getAttribute("name");
    var description = element.getAttribute("description");
    // then for the value of the entry, it depends on the type. This goes inside the text of the element
    var value = element.innerText;
    return ConfigEnumOption(
      value: value,
      displayName: displayName,
      description: description,
    );
  }
}
