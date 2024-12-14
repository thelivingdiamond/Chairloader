import 'dart:math';

import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployDialog.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:go_router/go_router.dart';

class SplashScreenController extends GetxController {
  SplashScreenController();

  bool gachaMode = false;
  bool gachaBegin = false;
  int gachaRarity = 0;
  bool gachaFinished = false;

  final commonRarity = 40;
  final uncommonRarity = 30;
  final rareRarity = 20;
  final epicRarity = 8;
  final legendaryRarity = 2;

  Future<void> triggerGacha(BuildContext context) async {
    gachaMode = true;
    update();
  }

  Future<void> endOfSplashScreen(BuildContext context) async {
    if(gachaMode) {
      await beginGacha();
    } else {
      context.go("/");
    }
  }

  Future<void> beginGacha() async {
    gachaBegin = true;

    final random = Random().nextInt(101);
    if(random < commonRarity) {
      gachaRarity = 0;
    } else if(random < commonRarity + uncommonRarity) {
      gachaRarity = 1;
    } else if(random < commonRarity + uncommonRarity + rareRarity) {
      gachaRarity = 2;
    } else if(random < commonRarity + uncommonRarity + rareRarity + epicRarity) {
      gachaRarity = 3;
    } else {
      gachaRarity = 4;
    }
    update();
  }

  Future<void> finishGacha() async {
    gachaFinished = true;
    update();
  }

  Color getGachaColor() {
    switch(gachaRarity) {
      case 0:
        return Colors.grey;
      case 1:
        return Colors.lightGreen;
      case 2:
        return Colors.lightBlueAccent;
      case 3:
        return Colors.deepPurple;
      case 4:
        return Colors.orange;
      default:
        return Color(0xFF000000);
    }
  }

  String getGachaText() {
    switch(gachaRarity) {
      case 0:
        return "Common\nChair";
      case 1:
        return "Uncommon\nChair";
      case 2:
        return "Rare\nChair";
      case 3:
        return "Epic\nChair";
      case 4:
        return "Legendary\nChair";
      default:
        return "Error\nChair";
    }
  }
}