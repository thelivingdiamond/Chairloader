import 'package:chairmanager_flutter_v2/dialogs/GamePathSelection/GamePathSelectionDialog.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class DebugPage extends StatelessWidget {
  const DebugPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Card(
      child: ListView(
        padding: const EdgeInsets.all(16.0),
        children: [
          Center(child: Text("Debug Page", style: Theme.of(context).textTheme.titleLarge,)),
          const SizedBox(height: 16.0,),
          Center(
            child: FilledButton(
                onPressed: () {
                  Get.dialog(const GamePathSelectionDialog(), barrierDismissible: false);
                },
                child: const Text("Open Game Path Selection Dialog")
            ),
          ),
        ],
      ),
    );
  }
}
