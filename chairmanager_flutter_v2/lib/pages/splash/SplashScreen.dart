import 'dart:math';

import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:chairmanager_flutter_v2/controllers/FocusController.dart';
import 'package:chairmanager_flutter_v2/main.dart';
import 'package:chairmanager_flutter_v2/pages/config/Config.dart';
import 'package:chairmanager_flutter_v2/pages/splash/SplashScreenController.dart';
import 'package:chairmanager_flutter_v2/widgets/WindowsButtons.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:get/get.dart';
import 'package:go_router/go_router.dart';
import 'package:particles_flutter/component/particle/particle.dart';
import 'package:particles_flutter/particles_engine.dart';

class SplashScreen extends StatelessWidget {
  const SplashScreen({super.key, this.forceAnimation = false});

  final bool forceAnimation;

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
                      if(!kDebugMode || forceAnimation)
                        Container(
                          child:   Particles(
                            awayRadius: 150,
                            particles: createParticles(150, 25.0, 10.0, Theme.of(context).colorScheme.primaryContainer.withOpacity(0.5)),
                            height: MediaQuery.of(context).size.height,
                            width: MediaQuery.of(context).size.width,
                            onTapAnimation: true,
                            awayAnimationDuration: const Duration(milliseconds: 100),
                            awayAnimationCurve: Curves.linear,
                            enableHover: false,
                            hoverRadius: 5,
                            connectDots: true,
                          )
                        ),
                      if(kDebugMode && !forceAnimation)
                        Center(
                          child: Column(
                            mainAxisAlignment: MainAxisAlignment.center,
                            children: [
                              Text("Debug Mode", style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold), textAlign: TextAlign.left,),
                              Text("This is a debug build of the application", style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold), textAlign: TextAlign.left,)
                                  .animate(onComplete: (animationController) => context.go("/"),).fadeIn(duration: 1.ms).then(),
                            ],
                          ),
                        )
                      else
                      Center(
                        child: Transform.scale(
                          scale: 0.5,
                          child: Container(
                            decoration: BoxDecoration(
                              color: Theme.of(context).colorScheme.primaryContainer,
                              borderRadius: BorderRadius.circular(40),
                            ),
                              child: const Image(image: AssetImage('assets/ChairManager_Icon.png'))
                          )
                              .animate(onComplete: (animationController) => context.go("/"),)
                              .slideY(begin: 1.5, end: 0, duration: 2000.ms, curve: Curves.easeInOutCubic)
                              .blur(duration: 2000.ms, curve: Curves.easeInOutCubic, begin: const Offset(20, 20), end: Offset.zero)
                              .fadeIn(duration: 2000.ms, curve: Curves.easeInOutCubic)
                              .then()
                              .shake(duration: 900.ms, curve: Curves.easeInOutCubic, hz: 5)
                              .scale(begin: const Offset(1, 1), end: const Offset(2, 2), duration: 1000.ms, curve: Curves.elasticIn)
                              .fadeOut(delay: 800.ms, duration: 150.ms, curve: Curves.easeInOut)
                              .then(),
                        ),
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

  List<Particle> createParticles(int count, double velocityScale, double sizeScale, Color color) {
    var rng = Random();
    List<Particle> particles = [];
    for (int i = 0; i < count; i++) {
      particles.add(Particle(
        color: color,
        size: rng.nextDouble() * sizeScale + 1, // min size = 1
        velocity: Offset(rng.nextDouble() * velocityScale * randomSign(),
            rng.nextDouble() * velocityScale * randomSign()),
      ));
    }
    return particles;
  }

  double randomSign() {
    var rng = Random();
    return rng.nextBool() ? 1 : -1;
  }
}
