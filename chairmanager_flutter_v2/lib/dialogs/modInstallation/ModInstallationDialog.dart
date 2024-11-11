import 'package:chairmanager_flutter_v2/dialogs/modInstallation/ModInstallationController.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';


class ModInstallationDialog extends StatelessWidget {
  const ModInstallationDialog({super.key});

  @override
  Widget build(BuildContext context) {
    return GetBuilder<ModInstallationController>(
      init: ModInstallationController(),
      builder: (controller) => Dialog(
        child: Container(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            children: [
              Text("Install Mods", style: Theme.of(context).textTheme.titleLarge,),
              const SizedBox(height: 16.0,),
              if(controller.busy)
                const LinearProgressIndicator(),
              Expanded(
                child: ListView.builder(
                  itemCount: controller.candidates.length,
                  itemBuilder: (context, index) {
                    var candidate = controller.candidates[index];
                    return CheckboxListTile(
                      title: Row(
                        mainAxisAlignment: MainAxisAlignment.spaceBetween,
                        children: [
                          Text('${candidate.displayName != null && candidate.displayName!.isNotEmpty ? candidate.displayName! : candidate.modName} ${candidate.modVersion != null ? candidate.modVersion!.toString() : ""}'),
                          Text(candidate.conflict.displayName)
                        ],
                      ),
                      subtitle: Text(candidate.modPath),
                      value: candidate.selected,
                      onChanged: controller.anotherCandidateSelected(candidate) ? null : (value) {
                        controller.selectCandidate(candidate, value ?? false);
                      },
                    );
                  },
                ),
              ),
              Padding(
                padding: const EdgeInsets.only(top: 16.0),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    ElevatedButton(
                      onPressed: () {
                        Get.back();
                      },
                      child: const Text("Cancel"),
                    ),
                    FilledButton(
                        child: const Text("Select Mods"),
                        onPressed: () async {
                          await controller.selectModFiles();
                        }
                    ),
                    FilledButton(
                      onPressed: !controller.candidates.any((c) => c.selected) ? null : () async {
                        await controller.installMods();
                        Get.back();
                      },
                      child: const Text("Install"),
                    ),
                  ],
                ),
              ),
            ],
          ),
        )
      ),
    );
  }
}


