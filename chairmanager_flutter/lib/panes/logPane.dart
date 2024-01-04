import 'dart:io';

import 'package:chairmanager_flutter/panes/paneThemes.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter/foundation.dart';
import 'package:get/get.dart';
import 'package:logger/logger.dart';
import 'package:chairmanager_flutter/log/log.dart';
import 'package:flutter/material.dart' as material;

import '../states/LogState.dart';

class LogPane extends StatefulWidget {
  const LogPane({super.key});

  @override
  State<LogPane> createState() => _LogPaneState();
}

class _LogPaneState extends State<LogPane> {





  // @override
  // void initState() {
  //   super.initState();
  //
  // }

  @override
  Widget build(BuildContext context) {
    LogController logController = Get.find();
    return Container(
      margin: const EdgeInsets.all(10.0),
      decoration: BoxDecoration(
        color: tileColor,
        borderRadius: BorderRadius.circular(5.0),
      ),
      child: Column(
        children: [
          Container(
            padding: const EdgeInsets.all(8.0),
            alignment: Alignment.centerLeft,
            decoration: const BoxDecoration(
              color: titleColor,
              borderRadius: BorderRadius.only(topLeft: Radius.circular(5), topRight: Radius.circular(5)),
            ),
            child: const Text("Log", style: titleStyle,),
          ),
          Row(
            children: [
              Container(
                padding: const EdgeInsets.symmetric(vertical: 8.0, horizontal: 4.0),
                alignment: Alignment.centerLeft,
                // combo box for log level
                child: ComboBox<Level>(
                  items: const [
                    ComboBoxItem<Level>(value: Level.verbose, child: Text("Verbose")),
                    ComboBoxItem<Level>(value: Level.debug, child: Text("Debug")),
                    ComboBoxItem<Level>(value: Level.info, child: Text("Info")),
                    ComboBoxItem<Level>(value: Level.warning, child: Text("Warning")),
                    ComboBoxItem<Level>(value: Level.error, child: Text("Error")),
                    ComboBoxItem<Level>(value: Level.wtf, child: Text("WTF")),
                  ],
                  onChanged: (value) {
                    setState(() {
                      logController.setFilterLevel(value!);
                    });
                  },
                  value: logController.filterLevel.value,
                ),
              ),
              Spacer(),
              // clear log button
              Container(
                padding: const EdgeInsets.symmetric(vertical: 8.0, horizontal: 4.0),
                child: Button(
                  child: const Text("Clear Log"),
                  onPressed: () {
                    logController.clear();
                  },
                ),
              ),
            ],
          ),
          // current working directory
          Text("Current Working Directory: ${Directory.current.path.toString()}"),
          // Row(
          //   children: [
          //     Button(child: const Text("Info Bar"), onPressed: (){
          //       // setState(() {
          //       logger.i("Info Message");
          //       // });
          //     }),
          //     Button(child: const Text("Warning Bar"), onPressed: (){
          //       logger.ww("Warning Message");
          //       setState(() {});
          //     }),
          //     Button(child: const Text("Error Bar"), onPressed: (){
          //       logger.ee("Error Message");
          //       setState(() {});
          //
          //     }),
          //     Button(child: const Text("Debug Bar"), onPressed: (){
          //       logger.dd("Debug Message");
          //       setState(() {});
          //
          //     }),
          //     Button(child: const Text("Verbose Bar"), onPressed: (){
          //       logger.vv("Verbose Message");
          //       setState(() {});
          //
          //     }),
          //     Button(child: const Text("WTF Bar"), onPressed: (){
          //       logger.wtff("WTF Message");
          //       setState(() {});
          //     }),
          //     Button(child: const Text("LOOOOOONG LOOOOONG MAN"), onPressed: (){
          //       logger.ii(
          //           """The FitnessGram™ Pacer Test is a multistage aerobic capacity test that progressively gets more difficult as it continues. The 20 meter pacer test will begin in 30 seconds. Line up at the start. The running speed starts slowly, but gets faster each minute after you hear this signal. [beep] A single lap should be completed each time you hear this sound. [ding] Remember to run in a straight line, and run as long as possible. The second time you fail to complete a lap before the sound, your test is over. The test will begin on the word start. On your mark, get ready, start."""
          //       );
          //       setState(() {});
          //     })
          //   ],
          // ),
          const Divider(),
          Expanded(
              child: Container(
                  padding: const EdgeInsets.all(8.0),
                  child: Obx( () => ListView(
                      children: [
                        for (var i in logController.log.reversed)
                          if(!logController.isMessageFiltered(i))
                            Column(
                              crossAxisAlignment: CrossAxisAlignment.start,
                              children: [
                                Container(
                                  padding: const EdgeInsets.symmetric(horizontal: 5, vertical: 1),
                                  // color: getLevelColor(i.level).withOpacity(0.2),
                                  decoration: BoxDecoration(
                                    // borderRadius: BorderRadius.all(Radius.circular(4)),
                                    border: BorderDirectional(
                                      start: BorderSide(color: logger.getLevelColor(i.level), width: 4),
                                      bottom: BorderSide(color: logger.getLevelColor(i.level), width: 1),
                                      end: BorderSide(color: logger.getLevelColor(i.level), width: 1),
                                    ),
                                    // color: getLevelColor(i.level).withOpacity(0.2),
                                  ),
                                  child: Row(
                                    children: [
                                      Icon(logger.getLevelIcon(i.level), color: logger.getLevelColor(i.level).withOpacity(0.8),size: 16),
                                      const SizedBox(width: 5,),
                                      Expanded(child:
                                      Tooltip(
                                        message: i.time.toLocal().toString(),
                                        child: Text(
                                          i.message.toString(),
                                          style: const TextStyle(fontFamily: "RobotoMono", fontSize: 12),
                                        ),
                                      ),
                                      ),
                                    ],
                                  ),
                                ),
                                const Divider(),
                              ],
                            )
                      ]
                  ),
                  )
              )
          ),
        ],
      ),
    );
  }
}
