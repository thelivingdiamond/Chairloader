import 'dart:io';

import 'package:flutter/material.dart' as material;
import 'package:flutter/services.dart';
import 'package:get/get.dart';
import 'package:xml/xml.dart' as xml;

// this is a class for the config file of a mod


enum ConfigEntryType {
  bool("bool"),
  int("int"),
  unsignedInt("uint"),
  int64("int64"),
  unsignedInt64("uint64"),
  float("float"),
  string("string"),
  enum_("enum"),
  xmlNode("xmlnode");

  final String value;
  const ConfigEntryType(this.value);
}

class ModConfig {
  List<IConfigNode> config = [];
  var loaded = false;
  var dirty = false;
  final String modName;
  final String version;

  ModConfig({required this.modName, required this.version});

  ModConfig.fromXml(xml.XmlElement element, {required String configPath, required String modDirPath, required this.modName}) :
    version = element.getAttribute("version") ?? "1.0" {
    for (var child in element.childElements) {
      config.add(IConfigNode.fromXml(child));
    }
    loaded = true;
    dirty = false;
  }

  xml.XmlElement toXml() {
    var configElement = xml.XmlElement(xml.XmlName.fromString(modName), [
      xml.XmlAttribute(xml.XmlName.fromString("version"), version),
    ], [
      ...config.map((entry) => entry.toXml())
    ]);
    return configElement;
  }
}

abstract interface class IConfigNode {
  String get name;
  String? get displayName;
  String? get description;
  ConfigEntryType get type;
  dynamic value;
  List<IConfigNode> get children;

  xml.XmlElement toXml();
  factory IConfigNode.fromXml(xml.XmlElement element) {
    // check if the element is a group or a leaf
    final typeString = element.getAttribute("type");
    final type = ConfigEntryType.values.firstWhereOrNull((element) => element.value == typeString);
    switch (type){
      case ConfigEntryType.xmlNode:
        return ConfigGroup.fromXml(element);
      case ConfigEntryType.enum_:
        return ConfigLeafEnum.fromXml(element);
      case null:
        throw Exception("Invalid config entry type: could not parse type '$typeString'");
      default:
        return ConfigLeaf.fromXml(element);
    }
  }
}

class ConfigGroup implements IConfigNode {
  @override
  late List<IConfigNode> children;

  @override
  late String? description;

  @override
  late String? displayName;

  @override
  late String name;

  @override
  ConfigEntryType get type => ConfigEntryType.xmlNode;

  @override
  // this is always null for a group
  dynamic value = null;

  ConfigGroup({required this.name, required this.displayName, required this.description, required this.children});

  ConfigGroup.fromXml(xml.XmlElement element){
    name = element.name.toString();
    displayName = element.getAttribute("display_name");
    description = element.getAttribute("description");
    children = element.childElements.map((element) => IConfigNode.fromXml(element)).toList();
  }

  @override
  xml.XmlElement toXml() {
    var groupElement = xml.XmlElement(xml.XmlName.fromString(name), []);
    if (displayName != null) {
      groupElement.attributes.add(xml.XmlAttribute(
          xml.XmlName.fromString("display_name"), displayName!));
    }
    if (description != null) {
      groupElement.attributes.add(xml.XmlAttribute(
          xml.XmlName.fromString("description"), description!));
    }
    groupElement.attributes.add(xml.XmlAttribute(
        xml.XmlName.fromString("type"), type.value));
    for (var child in children) {
      groupElement.children.add(child.toXml());
    }
    return groupElement;
  }
}

class ConfigLeaf implements IConfigNode {
  @override
  late String? description;

  @override
  late String? displayName;

  @override
  late String name;

  @override
  late ConfigEntryType type;

  @override
  late dynamic value;

  ConfigLeaf({required this.name, required this.displayName, required this.description, required this.type, required this.value});

  ConfigLeaf.fromXml(xml.XmlElement element){
    name = element.name.toString();
    displayName = element.getAttribute("display_name");
    description = element.getAttribute("description");
    type = ConfigEntryType.values.firstWhereOrNull((type) => type.value == element.getAttribute("type")) ?? ConfigEntryType.string;
    switch (type){
      case ConfigEntryType.bool:
        value = (element.innerText == "true");
        break;
      case ConfigEntryType.int:
      case ConfigEntryType.unsignedInt:
      case ConfigEntryType.int64:
        value = int.parse(element.innerText);
        break;
      case ConfigEntryType.unsignedInt64:
        value = BigInt.parse(element.innerText).toUnsigned(64);
        break;
      case ConfigEntryType.float:
        value = double.parse(element.innerText);
        break;
      case ConfigEntryType.string:
        value = element.innerText;
        break;
      case ConfigEntryType.enum_:
      // how did we get here?
        value = null;
      case ConfigEntryType.xmlNode:
        value = null;
        break;
    }
  }

  @override
  List<IConfigNode> get children => [];

  @override
  xml.XmlElement toXml() {
    var entryElement = xml.XmlElement(xml.XmlName.fromString(name), []);
    if (displayName != null) {
      entryElement.attributes.add(xml.XmlAttribute(
          xml.XmlName.fromString("display_name"), displayName!));
    }
    if (description != null) {
      entryElement.attributes.add(xml.XmlAttribute(
          xml.XmlName.fromString("description"), description!));
    }
    entryElement.attributes.add(xml.XmlAttribute(
        xml.XmlName.fromString("type"), type.value));
    // then for the value of the entry, write to the text of the element
    entryElement.innerText = value.toString();
    return entryElement;
  }
}

class ConfigEnumOption {
  late final String value;
  late final String? displayName;
  late final String? description;

  ConfigEnumOption({required this.value, this.displayName, this.description});

  xml.XmlElement toXml() {
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

  ConfigEnumOption.fromXml(xml.XmlElement element){
    value = element.innerText;
    displayName = element.getAttribute("name");
    description = element.getAttribute("description");
  }
}

class ConfigLeafEnum implements IConfigNode {
  @override
  String get value => options.firstWhere((element) => element.value == selected).value;

  @override
  set value(dynamic newValue){
    if(newValue is String){
      selected = newValue;
    } else {
      throw Exception("Invalid value type for ConfigLeafEnum");
    }
  }

  List<ConfigEnumOption> options = [];

  String selected = "";

  @override
  List<IConfigNode> get children => [];

  @override
  late String? description;

  @override
  late String? displayName;

  @override
  late String name;

  @override
  ConfigEntryType get type => ConfigEntryType.enum_;

  ConfigLeafEnum({required this.name, required this.displayName, required this.description});

  ConfigLeafEnum.fromXml(xml.XmlElement element){
    // get the selected child element
    name = element.name.toString();
    displayName = element.getAttribute("display_name");
    description = element.getAttribute("description");
    var selectedElement = element.getElement("selected");
    selected = selectedElement?.innerText ?? "";
    // get the options
    for (var optionElement in element.findElements("option")) {
      options.add(ConfigEnumOption.fromXml(optionElement));
    }
  }

  @override
  xml.XmlElement toXml() {
    var entryElement = xml.XmlElement(xml.XmlName.fromString(name), []);
    if (displayName != null) {
      entryElement.attributes.add(xml.XmlAttribute(
          xml.XmlName.fromString("display_name"), displayName!));
    }
    if (description != null) {
      entryElement.attributes.add(xml.XmlAttribute(
          xml.XmlName.fromString("description"), description!));
    }
    entryElement.attributes.add(xml.XmlAttribute(
        xml.XmlName.fromString("type"), type.value));
    // the selected node
    var selectedElement = xml.XmlElement(xml.XmlName.fromString("selected"), []);
    selectedElement.innerText = selected;
    entryElement.children.add(selectedElement);
    // the options
    for (var option in options) {
      entryElement.children.add(option.toXml());
    }
    return entryElement;
  }
}
