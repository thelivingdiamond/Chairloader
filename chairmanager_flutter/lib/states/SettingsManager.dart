import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';


final settingsManagerProvider = StateNotifierProvider<SettingsManager, SettingsState>((ref) => SettingsManager());


@immutable
class SettingsState {
  const SettingsState({
    required this.test,
    required this.mooncrashMode,
  });

  final bool test;
  final bool mooncrashMode;


  SettingsState copyWith({
    bool? test,
    bool? mooncrashMode,
  }) {
    return SettingsState(
      test: test ?? this.test,
      mooncrashMode: mooncrashMode ?? this.mooncrashMode,
    );
  }
}




class SettingsManager extends StateNotifier<SettingsState> {
  SettingsManager() : super(const SettingsState(test: false, mooncrashMode: false));

  bool get test => state.test;
  set test(bool value) {
    state = state.copyWith(test: value);
  }

  bool get mooncrashMode => state.mooncrashMode;
  set mooncrashMode(bool value) {
    state = state.copyWith(mooncrashMode: value);
  }
}

