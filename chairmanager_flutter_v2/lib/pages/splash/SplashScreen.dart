import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:chairmanager_flutter_v2/controllers/FocusController.dart';
import 'package:chairmanager_flutter_v2/pages/config/Config.dart';
import 'package:chairmanager_flutter_v2/pages/splash/SplashScreenController.dart';
import 'package:chairmanager_flutter_v2/widgets/WindowsButtons.dart';
import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:get/get.dart';

class SplashScreen extends StatelessWidget {
  const SplashScreen({super.key});

  @override
  Widget build(BuildContext context) {
    FocusController focusController = Get.find();
    return GetBuilder<SplashScreenController>(
      init: SplashScreenController(),
      builder: (controller) => Scaffold(
        extendBodyBehindAppBar: false,
        body: Container(
          decoration: BoxDecoration(
            gradient: LinearGradient(
                begin: Alignment.topCenter,
                end: Alignment.bottomCenter,
                colors: [ Theme.of(context).colorScheme.primaryContainer.withOpacity(0.2), Theme.of(context).colorScheme.primaryContainer.withOpacity(0.5)],
                stops: const [0.1, 0.9]),
          ),
          child: Column(children: [
            WindowTitleBarBox(
              child: Stack(
                children: [
                  Container(
                    height: appWindow.titleBarHeight,
                    alignment: Alignment.centerLeft,
                    padding: const EdgeInsets.only(left: 16.0),
                    child: Obx( () => Text("Chair Manager", style: focusController.hasFocus.value ? Theme.of(context).textTheme.titleMedium : Theme.of(context).textTheme.titleMedium!.copyWith(color: Theme.of(context).disabledColor),)),
                  ),
                  Row(
                    children: [Expanded(child: MoveWindow()), const WindowButtons()],
                  ),
                ],
              ),
            ),
            Expanded(
              child: Container(
                  padding: const EdgeInsets.all(8.0),
                  // switch the widget being rendered based on the selected index
                  child: Stack(
                    children: [
                      Center(
                        child: Transform.scale(
                          scale: 0.5,
                          child: const Image(image: AssetImage('assets/ChairManager_Icon.png')
                          )
                              .animate(onComplete: (animationController) => controller.goHome(),)
                              .slideY(begin: 1.5, end: 0, duration: const Duration(milliseconds: 2000), curve: Curves.easeInOutCubic)
                          // .rotate()
                              .fadeIn(duration: const Duration(milliseconds: 1000), curve: Curves.easeInOutCubic)
                              .then()
                              .scale(begin: const Offset(1, 1), end: const Offset(2, 2), duration: const Duration(milliseconds: 1000), curve: Curves.easeInOutCubic)
                              .then(),
                        ),
                      ),
                      Positioned(
                          bottom: 0,
                          width: MediaQuery.of(context).size.width,
                          child: Container(
                            alignment: Alignment.center,
                            child: Column(
                              crossAxisAlignment: CrossAxisAlignment.center,
                              children: [
                                const Text("Chair Manager", style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold), textAlign: TextAlign.left,),
                                const Text("Loading...", style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold), textAlign: TextAlign.left,),
                              ],
                            ),
                          )
                      ),
                    ],
                  )
              ),
            ),
          ]),
        ),
      ),
    );
  }
}
