import 'dart:io';
import 'dart:isolate';

import 'package:crypto/crypto.dart';

class AsyncHashCalculator{
  static Future<Digest> calculateHash(String path) async {
    return Isolate.run<Digest>(() async {
      final File file = File(path);
      final List<int> bytes = await file.readAsBytes();
      return sha256.convert(bytes);
    });
  }
}