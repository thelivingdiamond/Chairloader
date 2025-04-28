import 'package:chairmanager_flutter_v2/controllers/DeployController.dart';
import 'package:chairmanager_flutter_v2/dialogs/installation/InstallationDialog.dart';
import 'package:chairmanager_flutter_v2/widgets/GenericLogView.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:go_router/go_router.dart';

class DeployDialog extends StatelessWidget {
  const DeployDialog({super.key});


  @override
  Widget build(BuildContext context) {
    return GetBuilder<DeployController>(
      builder: (controller) => Dialog(
        child: Container(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            children: [
              Text("Deploying", style: Theme.of(context).textTheme.titleLarge,),
              if(!controller.mergingFinished)
                Padding(
                  padding: const EdgeInsets.symmetric( vertical: 8.0),
                  child: LinearProgressIndicator(
                    color: Theme.of(context).colorScheme.primary,
                  ),
                ),
              Expanded(
                child: GenericLogView(
                    messages: controller.mergerOutput,
                  itemPadding: const EdgeInsets.symmetric(vertical: 2.0),
                ),
              ),
              if(controller.mergingFinished)
                Padding(
                  padding: const EdgeInsets.only(top: 16.0),
                  child: ElevatedButton(
                    onPressed: () {
                      context.pop();
                    },
                    child: const Text("Close"),
                  ),
                ),
            ],
          ),
        )
      ),
    );
  }
}
