import 'dart:collection';
import 'dart:io';

import 'package:flutter_riverpod/flutter_riverpod.dart';

final assetPanePersistentStateProvider = StateNotifierProvider<AssetPaneStateManager, AssetPanePersistentState>((ref) => AssetPaneStateManager());
class AssetPanePersistentState {
  AssetPanePersistentState({
    required this.index,
    required this.selectedDirectory,
    required this.selectedFile,
    required this.directoryExpansionMap,
  });
  AssetPanePersistentState.initial() :
        index = 0,
        selectedDirectory = Directory(""),
        selectedFile = File(""),
        directoryExpansionMap = HashMap<Directory, bool>();

  final int index;
  final Directory selectedDirectory;
  final File selectedFile;
  final Map<Directory, bool> directoryExpansionMap;


  AssetPanePersistentState copyWith({
    int? index,
    Directory? selectedDirectory,
    File? selectedFile,
    Map<Directory, bool>? directoryExpansionMap,
  }) {
    return AssetPanePersistentState(
      index: index ?? this.index,
      selectedDirectory: selectedDirectory ?? this.selectedDirectory,
      selectedFile: selectedFile ?? this.selectedFile,
      directoryExpansionMap: directoryExpansionMap ?? this.directoryExpansionMap,
    );
  }
}


class AssetPaneStateManager extends StateNotifier<AssetPanePersistentState> {
  AssetPaneStateManager() : super(AssetPanePersistentState.initial());

  int get index => state.index;
  set index(int value) {
    state = state.copyWith(index: value);
  }

  Directory get selectedDirectory => state.selectedDirectory;
  set selectedDirectory(Directory value) {
    state = state.copyWith(selectedDirectory: value);
  }

  File get selectedFile => state.selectedFile;
  set selectedFile(File value) {
    state = state.copyWith(selectedFile: value);
  }

  Map<Directory, bool> get directoryExpansionMap => state.directoryExpansionMap;
  set directoryExpansionMap(Map<Directory, bool> value) {
    state = state.copyWith(directoryExpansionMap: value);
    ();
  }
}