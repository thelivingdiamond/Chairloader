import 'package:chairmanager_flutter_v2/controllers/DeployController.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

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
              Expanded(
                child: ListView.builder(
                  itemCount: controller.mergerOutput.length,
                  itemBuilder: (context, index) {
                    return Container(
                      color: index.isEven ? Colors.grey[600]?.withOpacity(0.1) : null,
                      child: Text(controller.mergerOutput[index]),
                    );
                  },
                ),
              ),
              if(controller.mergingFinished)
                ElevatedButton(
                  onPressed: () {
                    Get.back();
                  },
                  child: const Text("Close"),
                ),
            ],
          ),
        )
      ),
    );
  }
}
