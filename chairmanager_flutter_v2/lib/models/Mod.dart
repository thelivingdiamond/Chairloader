
import 'package:chairmanager_flutter_v2/models/ModConfig.dart';
import 'package:chairmanager_flutter_v2/extensions/VersionExtensions.dart';
import 'package:version/version.dart';
import 'package:xml/xml.dart' as xml;
import 'package:get/get.dart';
import 'package:xml/xpath.dart';

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
  });

  Mod.empty() : modName = "", displayName = "", author = "", version = null, dllName = "", loadOrder = -1, isLegacy = false, enabled = false;

  final String modName;
  final String displayName;
  final String author;
  final Version? version;
  final String dllName;
  bool enabled;
  bool isLegacy = false;
  int loadOrder = -1;
  ModConfig? config;
  String? description;
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


  Mod.fromModInfo(xml.XmlDocument modInfo, {this.loadOrder = -1, this.enabled = true}) :
        modName = modInfo.xpathEvaluate("/Mod/@modName").string,
        displayName = modInfo.xpathEvaluate("/Mod/@displayName").string,
        author = modInfo.xpathEvaluate("/Mod/@author").string,
        version = modInfo.xpathEvaluate("/Mod/@version").string.tryParseVersion(),
        dllName = modInfo.xpathEvaluate("/Mod/@dllName").string,
        isLegacy = false;

  Mod.legacy(String path, {this.loadOrder = -1, this.enabled = true}) :
        modName = path.split("\\").last,
        displayName = "",
        author = "",
        version = null,
        dllName = "",
        isLegacy = true;
}