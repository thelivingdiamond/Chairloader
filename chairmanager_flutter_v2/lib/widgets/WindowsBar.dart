import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class WindowsBar extends StatefulWidget {
  const WindowsBar({super.key, required this.title});

  final String title;

  @override
  State<WindowsBar> createState() => _WindowsBarState();
}

class _WindowsBarState extends State<WindowsBar> {
  void maximizeOrRestore() {
    setState(() {
      appWindow.maximizeOrRestore();
    });
  }


  @override
  Widget build(BuildContext context) {
    return WindowTitleBarBox(
      child:
      Container(
        color: Theme.of(context).primaryColor,
        child: Row(
          children: [
            Expanded(
              child: MoveWindow(
                child: Container(
                  padding: const EdgeInsets.only(left: 12.0),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.spaceAround,
                    crossAxisAlignment: CrossAxisAlignment.center,
                    children: [
                      // const Image(image: AssetImage("assets/ChairManager_Icon_64.png"), width: 20.0, height: 20.0,),
                      const SizedBox(width: 4.0),
                      Text(
                        widget.title,
                        style: const TextStyle(
                          fontSize: 16.0,
                          fontWeight: FontWeight.w600,
                        ),
                      ),
                      const Spacer(),
                      Row(
                        children: [
                          MinimizeWindowButton(
                              colors: WindowButtonColors(iconNormal: Theme.of(context).disabledColor, mouseOver: Colors.black.withAlpha(50))
                          ),
                          appWindow.isMaximized ?
                          RestoreWindowButton(
                            colors: WindowButtonColors(iconNormal: Theme.of(context).disabledColor, mouseOver: Colors.black.withAlpha(50)),
                          )
                              :
                          MaximizeWindowButton(
                            colors: WindowButtonColors(iconNormal: Theme.of(context).disabledColor, mouseOver: Colors.black.withAlpha(50)),
                          ),
                          CloseWindowButton(
                              colors: WindowButtonColors(iconNormal: Theme.of(context).disabledColor, mouseOver: Colors.red)
                          ),
                        ],
                      )
                    ],
                  ),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}