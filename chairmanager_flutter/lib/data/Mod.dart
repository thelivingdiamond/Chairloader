import 'package:xml/xml.dart';

class Mod {
  Mod({required this.modName, required this.displayName, required this.author, required this.version, required this.dllName, required this.loadOrder, required this.isLegacy});

  Mod.empty() : modName = "", displayName = "", author = "", version = "", dllName = "", loadOrder = -1, isLegacy = false;

  final String modName;
  final String displayName;
  final String author;
  final String version;
  final String dllName;
  bool isLegacy = false;
  int loadOrder = -1;
  XmlDocument infoFile = XmlDocument();
  XmlDocument? configFile;
  List<String> dependencies = [];
  // < operator
  bool operator <(Mod other) {
    return loadOrder < other.loadOrder;
  }
  // > operator
  bool operator >(Mod other) {
    return loadOrder > other.loadOrder;
  }
}