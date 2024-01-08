import 'package:fluent_ui/fluent_ui.dart';
import 'package:get/get.dart';
import 'package:flutter/material.dart' as material;
import 'package:window_manager/window_manager.dart';

import '../states/ThemeController.dart';
import 'DialogController.dart';
import '../widgets/WindowsBar.dart';

class DialogPageView extends StatelessWidget with WindowListener{
  const DialogPageView({Key? key, required this.pages,  this.title}) : super(key: key);

  final List<Widget> pages;
  final String? title;

  @override
  void onWindowFocus() {
    ThemeController themeController = Get.find();
    themeController.titleBarColor.value = themeController.accentColor.value;
  }

  @override
  void onWindowBlur(){
    ThemeController themeController = Get.find();
    themeController.titleBarColor.value = themeController.accentColor.value.darkest;
  }

  @override
  void onWindowRestore() {
    ThemeController themeController = Get.find();
    themeController.titleBarColor.value = themeController.accentColor.value;
  }

  @override
  Widget build(BuildContext context) {
    return AnimatedFluentTheme(data: FluentTheme.of(context),
        child: Column(
          children: [
            const WindowsBar(),
            Expanded(
                child: ScaffoldPage(
                  header: title == null ? null : PageHeader(
                    title: Text(title!, style: FluentTheme.of(context).typography.title!.copyWith(decoration: TextDecoration.underline),),
                  ),
                  content: GetBuilder<DialogPageViewController>(
                    init: DialogPageViewController(pageCount: pages.length),
                    builder: (controller) => PageView(
                      controller: controller.pageController.value,
                      children: pages,
                    ),
                  ),
                )
            ),
          ],
        )
    );
  }
}