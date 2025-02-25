import 'package:chairmanager_flutter_v2/dialogs/GamePathSelection/GamePathSelectionDialogController.dart';
import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployDialog.dart';
import 'package:file_picker/file_picker.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:go_router/go_router.dart';

class GamePathSelectionDialog extends StatelessWidget {
  const GamePathSelectionDialog({super.key});

  @override
  Widget build(BuildContext context) {
    return GetBuilder<GamePathSelectionDialogController>(
      init: GamePathSelectionDialogController(),
      builder:(controller) => Dialog(
        clipBehavior: Clip.antiAlias,
        child: Column(
          children: [
            Container(
              padding: const EdgeInsets.all(16.0),
              decoration: BoxDecoration(
                color: Theme.of(context).colorScheme.primaryContainer,
              ),
              alignment: Alignment.centerLeft,
              child: Text("Game Path Selection Dialog", style: Theme.of(context).textTheme.titleLarge?.copyWith(color: Theme.of(context).colorScheme.onPrimaryContainer),),
            ),
            Expanded(
              child: Container(
                padding: const EdgeInsets.all(16.0),
                child: ListView(
                  children: [
                    // const SizedBox(height: 16.0,),
                    if(controller.gamePathError != null && !controller.gamePathValid)
                      Center(
                          child: Text(controller.gamePathError!,
                              style: Theme.of(context).textTheme.bodyLarge?.copyWith(color: Colors.red)
                          )
                      )
                    else if(controller.gamePathValid)
                      Center(
                        child: Column(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            Text("Game Path is valid", textAlign: TextAlign.center, style: Theme.of(context).textTheme.bodyLarge?.copyWith(color: Colors.green),),
                            Text("Game Version: ${controller.gameVersion?.name}", textAlign: TextAlign.center, style: Theme.of(context).textTheme.bodyLarge,),
                          ],
                        ),
                      ),
                    TextFormField(
                      decoration: const InputDecoration(
                        labelText: "Game Path",
                      ),
                      readOnly: true,
                      controller: controller.gamePathController,
                      // onChanged: controller.trySetGamePath,
                    ),
                    const SizedBox(height: 16.0,),
                    Center(
                      child: ElevatedButton(
                        onPressed: () async {
                          var result = await FilePicker.platform.pickFiles(type: FileType.custom, allowedExtensions: ["exe"], dialogTitle: "Select Game Executable", initialDirectory: r"C:\Program Files (x86)\Steam\steamapps\common\Prey");
                          if(result != null){
                            controller.trySetGamePath(result.files.single.path);
                          }
                        },
                        child: const Text("Select Game Executable"),
                      ),
                    ),
                  ],
                ),
              ),
            ),
            Padding(
              padding: const EdgeInsets.all(16.0),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.end,
                children: [
                  FilledButton(
                    onPressed: () {
                      Navigator.pop(context);
                    },
                    child: const Text("Cancel"),
                  ),
                  const SizedBox(width: 8.0),
                  FilledButton(
                    onPressed: controller.gamePathValid ? () {
                      controller.finish();
                      context.pop(controller.gamePath);
                    } : null,
                    child: const Text("Finish"),
                  ),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}
