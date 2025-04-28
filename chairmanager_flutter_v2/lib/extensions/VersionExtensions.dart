import 'package:version/version.dart';

extension VersionStringExtensions on String {
  Version? tryParseVersion() {
    try {
      return Version.parse(this);
    } catch (e) {
      return null;
    }
  }
}