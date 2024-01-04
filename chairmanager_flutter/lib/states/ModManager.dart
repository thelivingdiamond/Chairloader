import 'package:flutter/material.dart';
import 'package:chairmanager_flutter/data/Mod.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';

final modManagerProvider = StateNotifierProvider<ModManager, ModList>((ref) => ModManager());


@immutable
class ModList {
  final List<Mod> mods = [];
  ModList();

  ModList copyWith({
    List<Mod>? mods,
    List<String>? legacyMods,
  }) {
    return ModList()
      ..mods.addAll(mods ?? this.mods);
  }
}


class ModManager extends StateNotifier<ModList> {
  ModManager() : super(ModList());

  void addMod(Mod mod) {
    state = state.copyWith(mods: [mod, ...state.mods]);
  }

  void removeMod(Mod mod) {
    state = state.copyWith(mods: state.mods.where((element) => element.modName != mod.modName).toList());
  }

  void clear() {
    state = ModList();
  }

  void sort() {
    state.mods.sort();
  }

  void serializeLoadOrder() {
    for (var element in state.mods) {
      element.loadOrder = state.mods.indexOf(element);
    }
  }

  void setModLoadOrderAbove(Mod mod, Mod above) {
    if (mod == above) return;
    state.mods.remove(mod);
    state.mods.insert(state.mods.indexOf(above), mod);
    serializeLoadOrder();
  }

  void setModLoadOrderBelow(Mod mod, Mod below) {
    if (mod == below) return;
    state.mods.remove(mod);
    state.mods.insert(state.mods.indexOf(below) + 1, mod);
    serializeLoadOrder();
  }

  Mod getMod(String modName) {
    for (var element in state.mods) {
      if (element.modName == modName) {
        return element;
      }
    }
    return Mod.empty();
  }

  Mod getModByIndex(int index) {
    return state.mods[index];
  }

  void moveModUp(Mod mod) {
    if (mod.loadOrder == 0) return;
    setModLoadOrderAbove(mod, getModByIndex(mod.loadOrder - 1));
  }

  void moveModDown(Mod mod) {
    if (mod.loadOrder == state.mods.length - 1) return;
    setModLoadOrderBelow(mod, getModByIndex(mod.loadOrder + 1));
  }

  void enableMod(Mod mod, bool enabled){
    // get mod from the list
    Mod modToEnable = getMod(mod.modName);
    // set enabled to true
    modToEnable.enabled = enabled;
  }

}