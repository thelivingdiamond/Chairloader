import 'package:chairmanager_flutter_v2/controllers/LaunchController.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class LaunchOptionsDialog extends StatelessWidget  {
  const LaunchOptionsDialog({super.key});

  @override
  Widget build(BuildContext context) {
    return GetBuilder<LaunchController>(
      builder: (controller) {
        return Dialog(
            child: Container(
                padding: const EdgeInsets.all(16.0),
                child: Column(
                  mainAxisSize: MainAxisSize.min,
                  children: [
                    Text("Launch Options", style: Theme.of(context).textTheme.titleLarge,),
                    const SizedBox(height: 16.0,),
                    Column(
                      mainAxisSize: MainAxisSize.min,
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        // load chairloader (default true)
                        // load trainers (default false)
                        // load editor (default false)
                        // Dev Mode (default false) I think?
                        // No Random (default false)
                        // custom options (string default "")
                        Row(
                          mainAxisSize: MainAxisSize.min,
                          children: [
                            Checkbox(value: controller.args.loadChairloader, onChanged: (value) {
                              controller.setLoadChairloader(value ?? false);
                            }),
                            Text("Load Chairloader", style: Theme.of(context).textTheme.bodyLarge,),
                          ],
                        ),
                        Row(
                          mainAxisSize: MainAxisSize.min,
                          children: [
                            Checkbox(value: controller.args.loadTrainers, onChanged: (value) {
                              controller.setLoadTrainers(value ?? false);
                            }),
                            Text("Load Trainers", style: Theme.of(context).textTheme.bodyLarge,),
                          ],
                        ),
                        Row(
                          mainAxisSize: MainAxisSize.min,
                          children: [
                            Checkbox(value: controller.args.loadEditor, onChanged: (value) {
                              controller.setLoadEditor(value ?? false);
                            }),
                            Text("Load Editor", style: Theme.of(context).textTheme.bodyLarge,),
                          ],
                        ),
                        Row(
                          mainAxisSize: MainAxisSize.min,
                          children: [
                            Checkbox(value: controller.args.devMode, onChanged: (value) {
                              controller.setDevMode(value ?? false);
                            }),
                            Text("Dev Mode", style: Theme.of(context).textTheme.bodyLarge,),
                          ],
                        ),
                        Row(
                          mainAxisSize: MainAxisSize.min,
                          children: [
                            Checkbox(value: controller.args.noRandom, onChanged: (value) {
                              controller.setNoRandom(value ?? false);
                            }),
                            Text("No Random", style: Theme.of(context).textTheme.bodyLarge,),
                          ],
                        ),
                        ConstrainedBox(
                          constraints: const BoxConstraints(maxWidth: 400),
                          child: Row(
                            mainAxisSize: MainAxisSize.min,
                            children: [
                              Text("Custom Options", style: Theme.of(context).textTheme.bodyLarge,),
                              const SizedBox(width: 8.0,),
                              Expanded(
                                child: TextFormField(
                                  initialValue: controller.args.customOptions,
                                  onChanged: (value) {
                                    controller.setCustomOptions(value);
                                  },
                                ),
                              ),
                            ],
                          ),
                        ),
                      ],
                    ),
                    const SizedBox(height: 16.0,),
                    Row(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        FilledButton.tonal(
                          onPressed: () => controller.cancel(),
                          child: const Text("Ok"),
                        ),
                      ],
                    )
                  ],
                )
            )
        );
      }
    );
  }
}
