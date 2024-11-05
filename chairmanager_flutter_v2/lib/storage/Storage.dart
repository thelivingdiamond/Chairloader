


// this is a custom implementation of a storage class that will be used to store the configuration of the application
// it stores it in a local json file, with immediate synchronous access to data and asynchronous writethrough
import 'dart:convert';
import 'dart:io';

import 'package:get/get.dart';
import 'package:mutex/mutex.dart';

class Storage extends GetxController {
  // In-memory cache of the config
  Map<String, dynamic> _cache = {};

  // File path for storing the JSON file
  late File _storageFile;

  final String path;

  Storage({required this.path});

  Mutex mutex = Mutex();

  JsonEncoder encoder = JsonEncoder.withIndent('' * 4);
  JsonDecoder decoder = const JsonDecoder();



  @override
  void onInit() {
    super.onInit();
  }

  // Initialize storage by finding the app's directory and loading data from the file
  Future<void> init() async {
    _storageFile = File(path);  // Set the file path

    // Load the initial configuration data from the file
    await _load();
  }

  // Synchronously get a value from in-memory cache
  dynamic get(String key) {
    return _cache[key];
  }

  Future<T> getOrInit<T>(String key, T defaultValue) async {
    if (_cache[key] == null) {
      _cache[key] = defaultValue;
      await _save();
    }
    return _cache[key] as T;
  }

  // Synchronously set a value in the in-memory cache and automatically save to file
  Future<void> set(String key, dynamic value) async {
    _cache[key] = value;  // Update the in-memory cache
    await _save();         // Asynchronously save the updated cache to the file
  }

  // Asynchronously load data from the JSON file into memory
  Future<void> _load() async {
    if (await _storageFile.exists()) {
      String fileContent = await _storageFile.readAsString();
      _cache = decoder.convert(fileContent);
    } else {
      // If file doesn't exist, initialize with an empty map or some default values
      _cache = {};
      await _save();
    }
  }

  // Asynchronously save the current in-memory data to the JSON file
  Future<void> _save() async {
    // mutex is probably overkill here, but it saves us headaches later
    await (mutex.protect(() async {
      String jsonString = encoder.convert(_cache);
      // check if we need to create the file and/or the directories
      if (!await _storageFile.exists()) {
        await _storageFile.create(recursive: true);
      }
      await _storageFile.writeAsString(jsonString, flush: true, mode: FileMode.write);
    }));
  }

  @override
  void onClose() {
    // Save the configuration data to the file before closing the app
    _save();
    super.onClose();
  }
}