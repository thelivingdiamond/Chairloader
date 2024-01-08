import 'package:chairmanager_flutter/states/ThemeController.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:get/get.dart';

import 'DialogController.dart';

class DialogPage extends StatelessWidget {
  const DialogPage({super.key, required this.child, this.nextEnabled = true, this.backEnabled = true, this.cancelEnabled = true, this.showButtons = true});

  final Widget child;
  final bool showButtons;
  final bool nextEnabled;
  final bool backEnabled;
  final bool cancelEnabled;

  @override
  Widget build(BuildContext context) {
    DialogPageViewController controller = Get.find();
    ThemeController themeController = Get.find();
    return AnimatedFluentTheme(data: FluentTheme.of(context),
        child: Padding(
          padding: const EdgeInsets.all(8.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              child,
              if(showButtons)
                Obx(()=> Row(
                  mainAxisAlignment: MainAxisAlignment.end,
                  children: [
                    Padding(
                      padding: const EdgeInsets.only(right: 8.0),
                      child: Button(
                        onPressed: controller.pageIndex.value > 0 && backEnabled? controller.previousPage : null,
                        child: const Text("Back"),
                      ),
                    ),
                    if(cancelEnabled)
                      Padding(
                        padding: const EdgeInsets.only(right: 8.0),
                        child: Button(
                          onPressed: controller.back,
                          child: const Text("Cancel"),
                        ),
                      ),
                    Padding(
                      padding: const EdgeInsets.only(right: 8.0),
                      child: Button(
                        onPressed: controller.pageIndex.value == controller.pageCount - 1 || !nextEnabled ? null : controller.nextPage,
                        child: const Text("Next"),
                      ),
                    ),
                  ],
                ),
                ),
            ],
          ),
        )
    );
  }

}