import 'dart:math';

import 'package:chairmanager_flutter_v2/pages/config/ConfigController.dart';
import 'package:chairmanager_flutter_v2/controllers/ModController.dart';
import 'package:chairmanager_flutter_v2/pages/config/ConfigTreeWidget.dart';
import 'package:flutter/gestures.dart';
import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:get/get.dart';

class Config extends StatelessWidget {
  const Config({super.key});

  @override
  Widget build(BuildContext context) {
    return GetBuilder<ConfigController>(
      init: ConfigController(),
      builder: (configController) {
        return GetBuilder<ModController>(
          builder: (modController) {
            return Card(
              clipBehavior: Clip.antiAlias,
              child: Stack(
                children: [
                  Column(
                    children: [
                      Row(
                        mainAxisAlignment: MainAxisAlignment.end,
                        children: [
                          Expanded(
                            child: TabBar(
                              tabAlignment: TabAlignment.start,
                              controller: configController.tabController,
                              isScrollable: true,
                              dragStartBehavior: DragStartBehavior.down,
                              tabs: modController.modsWithConfig.map(
                                      (mod) => Tab(text: '${mod.displayName.isEmpty ? mod.modName : mod.displayName}${mod.config?.dirty == true ? '*' : ''}')
                              ).toList(),
                              physics: const BouncingScrollPhysics(),
                            ),
                          ),
                          Row(
                            children: [
                              IconButton(
                                icon: const Icon(Icons.arrow_left),
                                onPressed: configController.tabController.index == 0 ? null :
                                    () {
                                  configController.tabController.animateTo(max(configController.tabController.index - 1, 0));
                                },
                              ),
                              IconButton(
                                icon: const Icon(Icons.arrow_right),
                                onPressed: configController.tabController.index == configController.tabController.length - 1 ? null :
                                    () {
                                  configController.tabController.animateTo(min(configController.tabController.index + 1, configController.tabController.length - 1));
                                },
                              ),
                            ],
                          )
                        ],
                      ),
                      Expanded(
                          child: TabBarView(
                              controller: configController.tabController,
                              children: modController.modsWithConfig.map((mod){
                                ScrollController scrollController = ScrollController();
                                if(mod.config == null) {
                                  return Center(
                                    child: Text("No config found for ${mod.modName}")
                                  );
                                } else {
                                  return ListView.builder(
                                    itemCount: mod.config!.config.length,
                                    itemBuilder: (context, index) {
                                      return ConfigTreeWidget(node: mod.config!.config[index], mod: mod);
                                    },
                                  );
                                }
                              }).toList()
                          )
                      )
                    ],
                  ),
                  Positioned(
                    bottom: 16,
                    right: 16,
                      child: FloatingActionButton(
                        onPressed: () {
                          configController.saveAll();
                        },
                        child: const Icon(Icons.save),
                      ).animate(target: configController.anyConfigDirty ? 1 : 0)
                          .slide(duration: const Duration(milliseconds: 500), curve: Curves.easeInOut, begin: const Offset(0, 2), end: const Offset(0, 0))
                  )
                ],
              )
            );
          }
        );
      }
    );
  }
}
