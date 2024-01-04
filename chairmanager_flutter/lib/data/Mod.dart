import 'package:chairmanager_flutter/data/ModConfig.dart';
import 'package:xml/xml.dart' as xml;

class Mod {
  Mod({
    required this.modName,
    required this.displayName,
    required this.author,
    required this.version,
    required this.dllName,
    required this.loadOrder,
    required this.isLegacy,
    required this.enabled,
  }) {
    // if the modName is empty, then this is an empty mod
    if (modName == "") {
      return;
    }
    // otherwise, load the config file
    if(!isLegacy){
      config = ModConfig(modName: modName);
    }
  }

  Mod.empty() : modName = "", displayName = "", author = "", version = "", dllName = "", loadOrder = -1, isLegacy = false, enabled = false;

  final String modName;
  final String displayName;
  final String author;
  final String version;
  final String dllName;
  bool enabled;
  bool isLegacy = false;
  int loadOrder = -1;
  ModConfig? config;

  List<String> dependencies = [];
  // < operator
  bool operator <(Mod other) {
    return loadOrder < other.loadOrder;
  }
  // > operator
  bool operator >(Mod other) {
    return loadOrder > other.loadOrder;
  }


  bool isEmpty() {
    return modName == "";
  }

  // create a toXml method
  xml.XmlElement toXml() {
    // the first element should be named after the modName and have an attribute type="xmlnode"
    var modElement = xml.XmlElement(xml.XmlName.fromString(modName), [xml.XmlAttribute(xml.XmlName.fromString("type"), "xmlnode")]);
    // then for each property, create an element with the name of the property and the value of the property, and an attribute indicating the type of the property, i.e. type="string"
    // modName
    modElement.children.add(xml.XmlElement(xml.XmlName.fromString("modName"), [xml.XmlAttribute(xml.XmlName.fromString("type"), "string")], [xml.XmlText(modName)]));
    // loadOrder
    modElement.children.add(xml.XmlElement(xml.XmlName.fromString("loadOrder"), [xml.XmlAttribute(xml.XmlName.fromString("type"), "int")], [xml.XmlText(loadOrder.toString())]));
    // enabled
    modElement.children.add(xml.XmlElement(xml.XmlName.fromString("enabled"), [xml.XmlAttribute(xml.XmlName.fromString("type"), "bool")], [xml.XmlText(enabled.toString())]));
    // legacy
    modElement.children.add(xml.XmlElement(xml.XmlName.fromString("legacy"), [xml.XmlAttribute(xml.XmlName.fromString("type"), "bool")], [xml.XmlText(isLegacy.toString())]));
    return modElement;
  }

}