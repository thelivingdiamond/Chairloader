import 'package:chairmanager_flutter/data/Mod.dart';
import 'package:chairmanager_flutter/panes/paneThemes.dart';
import 'package:chairmanager_flutter/states/ModManager.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:flutter/material.dart' as material;

class AssetPane extends ConsumerStatefulWidget {
  const AssetPane({super.key});

  @override
  ConsumerState<AssetPane> createState() => _AssetPaneState();
}

class _AssetPaneState extends ConsumerState<AssetPane> {
  int _index = 0;

  @override
  Widget build(BuildContext context) {
    return Container(
        decoration: BoxDecoration(
          color: titleColor,
          borderRadius: BorderRadius.circular(8),
        ),
        margin: const EdgeInsets.all(8),
        child:
        Column(
            children: [
              Container(
                padding: const EdgeInsets.all(8.0),
                alignment: Alignment.centerLeft,
                decoration: const BoxDecoration(
                  color: titleColor,
                  borderRadius: BorderRadius.only(topLeft: Radius.circular(5), topRight: Radius.circular(5)),
                ),
                child: const Text("Asset Viewer", style: titleStyle,),
              ),
              Expanded(
                child: TabView(
                  currentIndex: _index,
                  closeButtonVisibility: CloseButtonVisibilityMode.never,
                  tabs: (){
                    List<Tab> tabs = [];
                    tabs.add(_vanillaAssetTab((){setState(() {
                      // force a rebuild
                    });},));
                    for (Mod mod in ref.watch(modManagerProvider).mods) {
                      // only add the mod if it matches the filter text
                      // if (mod.modName.toLowerCase().contains(filter_text.toLowerCase())) {
                      tabs.add(_buildTabFromMod(mod, (){setState(() {
                        // force a rebuild
                      });},));
                      // }
                    }
                    return tabs;
                  }(),
                  onChanged: (v) {
                    setState(() {
                      _index = v;
                    });
                  },
                ),
              )
            ]
        )
    );
  }
}


Tab _buildTabFromMod(Mod mod, Function onChanged, {String? filterText}) {
  return Tab(
    text: Text(mod.modName),
    body: Container(
      decoration: BoxDecoration(
        color: tileColor,
        borderRadius: BorderRadius.circular(8),
      ),
      child: const Placeholder(),
    ),
  );
}

Tab _vanillaAssetTab(Function onChanged){
  return Tab(
    text: const Text("Vanilla Assets"),
    icon: const Icon(material.Icons.folder),
    body: Container(
      decoration: BoxDecoration(
        color: tileColor,
        borderRadius: BorderRadius.circular(8),
      ),
      child: const Placeholder(),
    ),
  );
}