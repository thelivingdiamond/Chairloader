import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:shared_preferences/shared_preferences.dart';


final settingsManagerProvider = StateNotifierProvider<SettingsManager, SettingsState>((ref) => SettingsManager());


@immutable
class SettingsState {
  const SettingsState({
    required this.test,
    required this.mooncrashMode,
    required this.isLoaded,
  });

  const SettingsState.defaults() :
        test = false,
        mooncrashMode = false,
        isLoaded = false;

  final bool test;
  final bool mooncrashMode;
  final bool isLoaded;


  SettingsState copyWith({
    bool? test,
    bool? mooncrashMode,
    bool? isLoaded,
  }) {
    return SettingsState(
      test: test ?? this.test,
      mooncrashMode: mooncrashMode ?? this.mooncrashMode,
      isLoaded: isLoaded ?? this.isLoaded,
    );
  }
}




class SettingsManager extends StateNotifier<SettingsState> {
  SettingsManager() : super(const SettingsState.defaults()) {
    load();
  }

  void load() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    state = state.copyWith(
      test: prefs.getBool("test") ?? false,
      mooncrashMode: prefs.getBool("mooncrashMode") ?? false,
      isLoaded: true,
    );
  }

  void resetToDefaults() {
    state = const SettingsState.defaults();
    SharedPreferences.getInstance().then((prefs) {
      prefs.setBool("test", state.test);
      prefs.setBool("mooncrashMode", state.mooncrashMode);
    });
    state = state.copyWith(isLoaded: true);
  }

  bool get test => state.test;
  set test(bool value) {
    state = state.copyWith(test: value);
    SharedPreferences.getInstance().then((prefs) => prefs.setBool("test", value));
  }

  bool get mooncrashMode => state.mooncrashMode;
  set mooncrashMode(bool value) {
    state = state.copyWith(mooncrashMode: value);
    SharedPreferences.getInstance().then((prefs) => prefs.setBool("mooncrashMode", value));
  }


}

