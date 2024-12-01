import 'package:chairmanager_flutter_v2/controllers/DllPatcherController.dart';
import 'package:chairmanager_flutter_v2/controllers/ExtractionController.dart';
import 'package:chairmanager_flutter_v2/dialogs/GamePathSelection/GamePathSelectionDialogController.dart';
import 'package:chairmanager_flutter_v2/dialogs/installation/InstallationDialogController.dart';
import 'package:chairmanager_flutter_v2/widgets/MainBody.dart';
import 'package:file_picker/file_picker.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:go_router/go_router.dart';
import 'package:intl/intl.dart';

class InstallationDialog extends StatelessWidget {
  const InstallationDialog({super.key});

  static DateFormat _dateFormat = DateFormat("yyyy-MM-dd");


  @override
  Widget build(BuildContext context) {
    return GetBuilder<InstallationDialogController>(
      init: InstallationDialogController(
          pageCount: 5
      ),
      builder: (controller) => Dialog.fullscreen(
          child: Column(
            children: [
              MainBody(
                showThemeSwitcher: false,
                child: Card(
                  margin: const EdgeInsets.all(16.0),
                  clipBehavior: Clip.antiAlias,
                  child: Stepper(
                      currentStep: controller.currentPage,

                      // onStepTapped: (index){
                      //   controller.setCurrentPage(index);
                      // },

                      type: StepperType.vertical,
                      onStepContinue: controller.nextPageFunction,
                      onStepCancel: controller.previousPageFunction,
                      controlsBuilder: (context, details) => Padding(
                        padding: const EdgeInsets.symmetric(vertical: 16.0),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.spaceBetween,
                          children: [
                            Row(
                              children: [
                                if(controller.currentPage == 0 || controller.currentPage == InstallationStep.confirm.index)
                                  ...[
                                    FilledButton(
                                      style: FilledButton.styleFrom(
                                        backgroundColor: Colors.red,
                                        foregroundColor: Colors.white,
                                      ),
                                      onPressed: () => context.pop(),
                                      child: const Text("Cancel"),
                                    ),
                                    const SizedBox(width: 16.0,),
                                  ],
                                if(details.onStepCancel != null)
                                  FilledButton.tonal(
                                    onPressed: details.onStepCancel,
                                    child: const Text("Back"),
                                  ),
                              ],
                            ),
                            if(details.onStepContinue != null)
                              FilledButton(
                                onPressed: details.onStepContinue,
                                child: const Text("Next"),
                              ),
                          ],
                        ),
                      ),
                      steps: [
                        Step(
                            title: const Text("Welcome"),
                            isActive: controller.currentPage == 0,
                            content: Column(
                              children: [
                                RichText(text: TextSpan(
                                  // text: "This wizard will guide you through the installation process of the ChairManager software.\n\n",
                                    style: Theme.of(context).textTheme.bodyLarge,
                                    children: const [
                                      // the following will occur in the next steps
                                      TextSpan(text: "Before using Chairloader, the game must be modified to add support for advanced modding features. It will be done in the following steps:", style: TextStyle(fontWeight: FontWeight.bold)),
                                      TextSpan(text: "\n\n1. Select the game path and determine if your version of the game is supported."),
                                      TextSpan(text: "\n\n2. If the game version is not supported, patch the DLL file to a supported version"),
                                      TextSpan(text: "\n\n3. Install Chairloader files to the game"),
                                      TextSpan(text: "\n\n4. Extract game asset files for use in merging"),
                                      TextSpan(text: "\n\nPlease press 'Next' to continue.", style: TextStyle(fontWeight: FontWeight.bold)),
                                    ]
                                )),
                              ],
                            )
                        ),
                        Step(
                          title: const Text("Select Game Path"),
                          isActive: controller.currentPage == 1,
                          content:  Column(
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
                              if(controller.gamePathOperationInProgress)
                                const CircularProgressIndicator()
                              else
                                Center(
                                  child: FilledButton(
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
                        Step(
                            title: const Text("Game Version Check"),
                            isActive: controller.currentPage == 2,
                            content: GetBuilder<DllPatcherController>(
                              builder: (patcherController) => Column(
                                children: [
                                  RichText(
                                      textAlign: TextAlign.center,
                                      text: TextSpan(
                                        style: Theme.of(context).textTheme.bodyLarge,
                                        children: [
                                          TextSpan(text: "DLL Version: ${patcherController.currentDllVersion?.type.name ?? 'Unknown'}\n"),
                                          TextSpan(text:
                                          "Release Date: ${patcherController.currentDllVersion != null ? _dateFormat.format(patcherController.currentDllVersion!.releaseDate) : 'Unknown'}\n",),
                                          if(patcherController.currentDllVersion?.isSupported == true)
                                            const TextSpan(text:"Game version is supported, no patching required", style: TextStyle(color: Colors.green),)
                                          else if (patcherController.currentDllVersion?.isOutdated == true)
                                            const TextSpan(text:"Game version is outdated, please update the game and retry the installation process", style: TextStyle(color: Colors.red),)
                                          else if (patcherController.currentDllVersion != null)
                                              const TextSpan(text: "Game version is not supported, but it can be patched to a supported version. This will be done in the next steps", style: TextStyle(color: Colors.orange),)
                                            else
                                              const TextSpan(text:"Game version is not supported, and it cannot be patched. Please report this to the developers so that we can add support for this version.", style: TextStyle(color: Colors.red),),
                                        ],
                                      )
                                  ),
                                  const SizedBox(height: 16.0,),
                                  if(patcherController.verifyCurrentDllRunning)
                                    const CircularProgressIndicator()
                                  else
                                    FilledButton(
                                      onPressed: () async => await patcherController.verifyCurrentDll(),
                                      child: const Text("Recheck Game Version"),
                                    ),
                                ],
                              ),
                            )
                        ),
                        Step(
                            title: const Text("Confirm"),
                            isActive: controller.currentPage == 3,
                            content: Container(
                                alignment: Alignment.center,
                                height: 150,
                                child: Text(
                                  "This is your last chance to cancel the installation process. Press 'Next' to begin.",
                                  style: Theme.of(context).textTheme.bodyLarge,
                                )
                            )
                        ),
                        Step(
                          title: const Text("Installing..."),
                          isActive: controller.currentPage == 4,
                          content: Column(
                            children: [
                              ProgressTile(
                                title: "Patching Game",
                                subtitle: "Patching the game DLL to a supported version",
                                currentProgress: controller.currentProgress,
                                targetProgress: InstallationProgress.patchGame,
                                isError: controller.isError,
                              ),
                              if(controller.currentProgress == InstallationProgress.patchGame)
                                GetBuilder<DllPatcherController>(
                                  builder: (dllPatcherController) =>
                                      Container(
                                        decoration: BoxDecoration(
                                          border: Border.all(color: Colors.grey),
                                          borderRadius: BorderRadius.circular(4.0),
                                        ),
                                        height:150,
                                        child: ListView.builder(
                                            itemCount: dllPatcherController.patcherOutput.length,
                                            itemBuilder: (context, index) => Container(
                                              padding: const EdgeInsets.all(4.0),
                                              child: Text(dllPatcherController.patcherOutput[index]),
                                            )
                                        ),
                                      ),
                                ),
                              ProgressTile(
                                title: "Extracting Files",
                                subtitle: "Extracting game files for merging, please follow the instructions on the Preditor window that will open",
                                currentProgress: controller.currentProgress,
                                targetProgress: InstallationProgress.extractFiles,
                                isError: controller.isError,
                              ),
                              ProgressTile(
                                title: "Installing Chairloader Files",
                                subtitle: "Installing Chairloader files to the game",
                                currentProgress: controller.currentProgress,
                                targetProgress: InstallationProgress.installChairloaderFiles,
                                isError: controller.isError,
                              ),
                              ProgressTile(
                                title: "Deploying Chairloader Files",
                                subtitle: "Deploying Chairloader files to the game",
                                currentProgress: controller.currentProgress,
                                targetProgress: InstallationProgress.deployChairloaderFiles,
                                isError: controller.isError,
                              ),
                              if(controller.isError)
                                ...[
                                  Text("An error occurred during the installation process. Please check the logs for more information.", style: Theme.of(context).textTheme.bodyLarge?.copyWith(color: Colors.red),),
                                  const SizedBox(height: 16.0,),
                                  Text(controller.errorMessage, style: Theme.of(context).textTheme.bodyLarge?.copyWith(color: Colors.red),),
                                  const SizedBox(height: 16.0,),
                                ],
                              if(controller.currentProgress == InstallationProgress.finish)
                                ...[
                                  const ListTile(
                                    title: Text("Installation Complete"),
                                    subtitle: Text("The installation process is complete. You can now close this dialog."),
                                    leading: Icon(Icons.check, color: Colors.green,),
                                  ),
                                  const SizedBox(height: 16.0,),
                                ],
                              if(controller.isError || controller.currentProgress == InstallationProgress.finish)
                                Center(
                                  child: ElevatedButton(
                                    style: ElevatedButton.styleFrom(
                                      backgroundColor: controller.isError ? Colors.red : Colors.green,
                                      foregroundColor: Colors.white,
                                    ),
                                    onPressed: () => context.pop(controller.isError),
                                    child: const Text("Close"),
                                  ),
                                ),
                            ],
                          ),
                        ),
                      ]),
                ),
              ),
            ],
          )
      ),
    );
  }

}

class ProgressTile extends StatelessWidget {
  const ProgressTile({super.key, required this.currentProgress, required this.targetProgress, required this.isError, required this.title, required this.subtitle});

  final InstallationProgress currentProgress;
  final InstallationProgress targetProgress;
  final bool isError;
  final String title;
  final String subtitle;

  @override
  Widget build(BuildContext context) {
    return ListTile(
      title: Text(title),
      subtitle: (){
        if(currentProgress == targetProgress && !isError){
          return Text(subtitle);
        } else if(currentProgress.index > targetProgress.index){
          return const Text("Completed");
        } else if (currentProgress == targetProgress && isError) {
          return const Text("Failed");
        } else {
          return const Text("Pending");
        }
      }(),
      leading: (){
        if(currentProgress == targetProgress && !isError){
          return const CircularProgressIndicator();
        } else if(currentProgress.index > targetProgress.index){
          return const Icon(Icons.check, color: Colors.green,);
        } else if (currentProgress == targetProgress && isError) {
          return const Icon(Icons.close, color: Colors.red,);
        } else {
          return const Icon(Icons.pending, color: Colors.grey,);
        }
      }(),
    );
  }
}


