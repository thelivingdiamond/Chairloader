import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployDialogController.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class DeployDialog extends StatelessWidget {
  const DeployDialog({super.key});

  @override
  Widget build(BuildContext context) {
    return GetBuilder<DeployDialogController>(
      init: DeployDialogController(),
      builder: (controller) => const Dialog(
        child: Center(child: Text("It's deployin' time!")),
      ),
    );
  }
}
