import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class NavigationController extends GetxController with TalkerMixin {
  var selectedIndex = 0.obs;

  void changeTabIndex(int index) {
    selectedIndex.value = index;
  }

  List<Destination> destinations = [
    Destination("Home", Icons.home_outlined, Icons.home),
    Destination("Mod Config", Icons.ballot_outlined, Icons.ballot),
    Destination("Log", Icons.subject_outlined, Icons.subject),
    Destination("Settings", Icons.settings_outlined, Icons.settings),
    Destination("Debug", Icons.bug_report_outlined, Icons.bug_report),
  ];
}

class Destination {
  final String title;
  final IconData icon;
  final IconData selectedIcon;

  Destination(this.title, this.icon, this.selectedIcon);
}