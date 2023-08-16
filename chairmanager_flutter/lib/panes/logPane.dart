import 'package:chairmanager_flutter/panes/paneThemes.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter/foundation.dart';
import 'package:logger/logger.dart';
import 'package:chairmanager_flutter/log/log.dart';

class LogPane extends StatefulWidget {
  const LogPane({super.key});

  @override
  State<LogPane> createState() => _LogPaneState();
}

class _LogPaneState extends State<LogPane> {

  Level _filterLevel = Level.verbose;

  bool _isMessageFiltered(OutputEvent event) {
    return event.level.index <= (_filterLevel.index-1);
  }

  @override
  void initState() {
    super.initState();
    // if debug mode, log everything, otherwise, only log info and above
    if (kDebugMode) {
      _filterLevel = Level.verbose;
    } else {
      _filterLevel = Level.info;
    }
  }

  @override
  Widget build(BuildContext context) {
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
                  _filterLevel = value!;
                });
              },
              value: _filterLevel,
            ),
          ),
          Row(
            children: [
              Button(child: const Text("Info Bar"), onPressed: (){
                setState(() {
                  logger.ii("Info Message", context);
                });
              }),
              Button(child: const Text("Warning Bar"), onPressed: (){
                logger.ww("Warning Message", context);
              }),
              Button(child: const Text("Error Bar"), onPressed: (){
                logger.ee("Error Message", context);
              }),
              Button(child: const Text("Debug Bar"), onPressed: (){
                logger.dd("Debug Message", context);
              }),
              Button(child: const Text("Debug Bar"), onPressed: (){
                logger.vv("Verbose Message", context);
              }),
              Button(child: const Text("WTF Bar"), onPressed: (){
                logger.wtff("WTF Message", context);
              }),
            ],
          ),
          const Divider(),
          Expanded(
              child: ListView(
                  children: [
                    // Button(
                    //   onPressed: () {
                    //     logger.i("Info Log");
                    //     logger.e("Error Log");
                    //     logger.w("Warning Log");
                    //     logger.d("Debug Log");
                    //     logger.v("Verbose Log");
                    //     logger.wtf("WTF Log");
                    //     setState(() {});
                    //   },
                    //   child: const Text("Test Log"),
                    // ),
                    // // super long log message
                    // Button(
                    //   onPressed: () {
                    //     logger.i("I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG, and I said that's disgusting. So I'm making a callout post on my Twitter.com. Shadow the Hedgehog, you got a small dick. It's the size of this walnut except WAY smaller. And guess what? Here's what my dong looks like. That's right, baby. Tall points, no quills, no pillows, look at that, it looks like two balls and a bong. He fucked my wife, so guess what, I'm gonna fuck the earth. That's right, this is what you get! My SUPER LASER PISS! Except I'm not gonna piss on the earth. I'm gonna go higher. I'm pissing on the MOOOON! How do you like that, OBAMA? I PISSED ON THE MOON, YOU IDIOT! You have twenty-three hours before the piss DROPLETS hit the fucking earth, now get out of my fucking sight before I piss on you too! ");
                    //     logger.i("I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG, and I said that's disgusting. So I'm making a callout post on my Twitter.com. Shadow the Hedgehog, you got a small dick. It's the size of this walnut except WAY smaller. And guess what? Here's what my dong looks like. That's right, baby. Tall points, no quills, no pillows, look at that, it looks like two balls and a bong. He fucked my wife, so guess what, I'm gonna fuck the earth. That's right, this is what you get! My SUPER LASER PISS! Except I'm not gonna piss on the earth. I'm gonna go higher. I'm pissing on the MOOOON! How do you like that, OBAMA? I PISSED ON THE MOON, YOU IDIOT! You have twenty-three hours before the piss DROPLETS hit the fucking earth, now get out of my fucking sight before I piss on you too! ");
                    //     logger.i("I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG, and I said that's disgusting. So I'm making a callout post on my Twitter.com. Shadow the Hedgehog, you got a small dick. It's the size of this walnut except WAY smaller. And guess what? Here's what my dong looks like. That's right, baby. Tall points, no quills, no pillows, look at that, it looks like two balls and a bong. He fucked my wife, so guess what, I'm gonna fuck the earth. That's right, this is what you get! My SUPER LASER PISS! Except I'm not gonna piss on the earth. I'm gonna go higher. I'm pissing on the MOOOON! How do you like that, OBAMA? I PISSED ON THE MOON, YOU IDIOT! You have twenty-three hours before the piss DROPLETS hit the fucking earth, now get out of my fucking sight before I piss on you too! ");
                    //     logger.i("I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG, and I said that's disgusting. So I'm making a callout post on my Twitter.com. Shadow the Hedgehog, you got a small dick. It's the size of this walnut except WAY smaller. And guess what? Here's what my dong looks like. That's right, baby. Tall points, no quills, no pillows, look at that, it looks like two balls and a bong. He fucked my wife, so guess what, I'm gonna fuck the earth. That's right, this is what you get! My SUPER LASER PISS! Except I'm not gonna piss on the earth. I'm gonna go higher. I'm pissing on the MOOOON! How do you like that, OBAMA? I PISSED ON THE MOON, YOU IDIOT! You have twenty-three hours before the piss DROPLETS hit the fucking earth, now get out of my fucking sight before I piss on you too! ");
                    //     logger.i("I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG, and I said that's disgusting. So I'm making a callout post on my Twitter.com. Shadow the Hedgehog, you got a small dick. It's the size of this walnut except WAY smaller. And guess what? Here's what my dong looks like. That's right, baby. Tall points, no quills, no pillows, look at that, it looks like two balls and a bong. He fucked my wife, so guess what, I'm gonna fuck the earth. That's right, this is what you get! My SUPER LASER PISS! Except I'm not gonna piss on the earth. I'm gonna go higher. I'm pissing on the MOOOON! How do you like that, OBAMA? I PISSED ON THE MOON, YOU IDIOT! You have twenty-three hours before the piss DROPLETS hit the fucking earth, now get out of my fucking sight before I piss on you too! ");
                    //     logger.i("I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG, and I said that's disgusting. So I'm making a callout post on my Twitter.com. Shadow the Hedgehog, you got a small dick. It's the size of this walnut except WAY smaller. And guess what? Here's what my dong looks like. That's right, baby. Tall points, no quills, no pillows, look at that, it looks like two balls and a bong. He fucked my wife, so guess what, I'm gonna fuck the earth. That's right, this is what you get! My SUPER LASER PISS! Except I'm not gonna piss on the earth. I'm gonna go higher. I'm pissing on the MOOOON! How do you like that, OBAMA? I PISSED ON THE MOON, YOU IDIOT! You have twenty-three hours before the piss DROPLETS hit the fucking earth, now get out of my fucking sight before I piss on you too! ");
                    //     logger.i("I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG, and I said that's disgusting. So I'm making a callout post on my Twitter.com. Shadow the Hedgehog, you got a small dick. It's the size of this walnut except WAY smaller. And guess what? Here's what my dong looks like. That's right, baby. Tall points, no quills, no pillows, look at that, it looks like two balls and a bong. He fucked my wife, so guess what, I'm gonna fuck the earth. That's right, this is what you get! My SUPER LASER PISS! Except I'm not gonna piss on the earth. I'm gonna go higher. I'm pissing on the MOOOON! How do you like that, OBAMA? I PISSED ON THE MOON, YOU IDIOT! You have twenty-three hours before the piss DROPLETS hit the fucking earth, now get out of my fucking sight before I piss on you too! ");
                    //     logger.i("I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG, and I said that's disgusting. So I'm making a callout post on my Twitter.com. Shadow the Hedgehog, you got a small dick. It's the size of this walnut except WAY smaller. And guess what? Here's what my dong looks like. That's right, baby. Tall points, no quills, no pillows, look at that, it looks like two balls and a bong. He fucked my wife, so guess what, I'm gonna fuck the earth. That's right, this is what you get! My SUPER LASER PISS! Except I'm not gonna piss on the earth. I'm gonna go higher. I'm pissing on the MOOOON! How do you like that, OBAMA? I PISSED ON THE MOON, YOU IDIOT! You have twenty-three hours before the piss DROPLETS hit the fucking earth, now get out of my fucking sight before I piss on you too! ");
                    //
                    //
                    //     setState(() {});
                    //   },
                    //   child: const Text("Test Log"),
                    // ),
                    for (var i in logger.events.reversed)
                      if(!_isMessageFiltered(i))
                        Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            for (var line in i.lines)
                              Container(
                                  color: (){
                                    if(i.level == Level.error) {
                                      return Colors.red.withAlpha(50);
                                    } else if(i.level == Level.warning) {
                                      return Colors.yellow.withAlpha(50);
                                    } else if(i.level == Level.info) {
                                      return Colors.blue.withAlpha(50);
                                    } else if(i.level == Level.debug) {
                                      return Colors.green.withAlpha(50);
                                    } else if (i.level == Level.wtf){
                                      return Colors.purple.withAlpha(50);
                                    } else if (i.level == Level.verbose){
                                      return Colors.grey.withAlpha(50);
                                    } else {
                                      return Colors.transparent;
                                    }
                                  }(),
                                  padding: const EdgeInsets.all(4.0),
                                  child: Tooltip(
                                    message: i.origin.time.toLocal().toString(),
                                    child: Text(line),

                                  )
                              ),
                            const Divider(),
                          ],
                        )
                  ]
              )
          ),
        ],
      ),
    );
  }
}
