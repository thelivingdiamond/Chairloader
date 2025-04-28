import 'dart:convert';
import 'dart:io';
import 'dart:isolate';

import 'package:archive/archive_io.dart';
import 'package:chairmanager_flutter_v2/controllers/ModController.dart';
import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:chairmanager_flutter_v2/models/Mod.dart';
import 'package:file_picker/file_picker.dart';
import 'package:get/get.dart';
import 'package:io/io.dart';
import 'package:version/version.dart';
import 'package:xml/xml.dart' as xml;
import 'package:xml/xpath.dart';
import 'package:collection/collection.dart';


class ModInstallCandidate {
  // we need the archive file path
  // the path within the archive
  // the mod name
  // if it's a legacy mod

  String archivePath;
  String modPath;
  String modName;
  String? displayName;
  Version? modVersion;
  bool isLegacy;
  bool inArchive;
  bool selected = false;
  ModInstallConflict conflict = ModInstallConflict.newMod;

  ModInstallCandidate({
    required this.archivePath,
    required this.modPath,
    required this.modName,
    required this.isLegacy,
    this.inArchive = true,
    this.modVersion,
    this.displayName
  });
}

enum ModInstallConflict {
  // no existing mod, no conflict
  newMod('New Mod'),
  // existing mod is the same version
  reInstall('Reinstall'),
  // new mod is a higher version
  update('Update'),
  // new mod is a lower version
  downgrade('Downgrade');

  final String displayName;
  const ModInstallConflict(this.displayName);
}

class ModInstallationController extends GetxController with TalkerMixin {
  List<String> selectedModFiles = [];
  List<ModInstallCandidate> candidates = [];
  bool busy = false;

  ModController modController = Get.find();
  PathController pathController = Get.find();


  Future<void> selectModFiles() async {
    final files = await FilePicker.platform.pickFiles(allowMultiple: true);
    if(files == null) return;
    selectedModFiles = files.files.where((e) => e.path != null).map((e) => e.path!).toList();
    busy = true;
    update();
    candidates = await _ModFileFinder.enumerateModsInSelectedFilesIsolate(selectedModFiles);
    // check for conflicts in each candidate
    for(var candidate in candidates){
      candidate.conflict = checkForConflicts(candidate);
    }
    // go through and select the candidates that don't have conflicts and aren't already selected
    for(var candidate in candidates){
      if((candidate.conflict == ModInstallConflict.newMod || candidate.conflict == ModInstallConflict.update)
          && !anotherCandidateSelected(candidate)){
        candidate.selected = true;
      }
    }
    busy = false;
    update();
  }

  void selectCandidate(ModInstallCandidate candidate, bool selected) {
    candidate.selected = selected;
    update();
  }

  // this needs to check both the candidate list and the existing mods for conflicts and return the appropriate conflict type
  ModInstallConflict checkForConflicts(ModInstallCandidate candidate){
    final existingMod = modController.mods.firstWhereOrNull((m) => m.modName == candidate.modName);
    if(existingMod == null) return ModInstallConflict.newMod;
    if(existingMod.version == candidate.modVersion) return ModInstallConflict.reInstall;
    if(existingMod.version! < candidate.modVersion!) return ModInstallConflict.update;
    if(existingMod.version! > candidate.modVersion!) return ModInstallConflict.downgrade;
    return ModInstallConflict.newMod;
  }

  bool anotherCandidateSelected(ModInstallCandidate candidate){
    return candidates.any((c) => c.selected && c.modName == candidate.modName && c != candidate);
  }


  Future<void> installMods() async {
    final tempDir = await Directory.systemTemp.createTemp("mod_install");
    final modLegacyDirPath = pathController.modLegacyDirPath;
    final modDirPath = pathController.modDirPath;
    busy = true;
    update();
    try{
      await _installMods(candidates, modDirPath, modLegacyDirPath, tempDir.path);
    } catch (e) {
      talker.error("Error while installing mods: $e");
    }
    finally {
      await tempDir.delete(recursive: true);
    }
    busy = false;
    update();
    await modController.detectMods();
  }

  Future<void> _installMods(List<ModInstallCandidate> candidates, String modDirPath, String modLegacyDirPath, String tempDir) async {
    final candidatesInArchives = candidates.where((c) => c.inArchive).groupListsBy((c) => c.archivePath);
    final nonArchiveCandidates = candidates.where((c) => !c.inArchive);
    for(var candidate in nonArchiveCandidates){
      if(candidate.selected){
        if(candidate.isLegacy){
          final modDir = Directory(
              "$modLegacyDirPath\\${candidate.modName}");
          final fileStream = InputFileStream(candidate.archivePath);
          try {
            final archive = ZipDecoder().decodeBuffer(fileStream);
            // we have to remove the contents of the archive path from the mod path before extracting
            // delete the contents recursively
            if(await modDir.exists()){
              await modDir.delete(recursive: true);
              await modDir.create(recursive: true);
            } else {
              await modDir.create(recursive: true);
            }
            await extractArchiveToDiskAsync(archive, modDir.absolute.path);
          } catch (e) {
            talker.error("Error while processing ${candidate.archivePath}: $e");
          }
          finally {
            await fileStream.close();
          }
          // copy the .pak file to the mods directory
        } else {
          // this is an error but doesn't really matter
          talker.error("Error while processing ${candidate.archivePath}: Registered mods should always be in an archive");
        }
      }
    }

    candidatesInArchives.forEach((archivePath, listOfCandidates) async {
      final fileStream = InputFileStream(archivePath);
      try{
        // begin by extracting the archive
        final archive = ZipDecoder().decodeBuffer(fileStream);
        await extractArchiveToDiskAsync(archive, tempDir);
        for (var candidate in listOfCandidates) {
          if (!candidate.selected) continue;
          if (!candidate.isLegacy) {
            // copy the mod to the mods directory
            final modDir = Directory(
                "$modDirPath\\${candidate.modName}");
            final modTempDir = Directory("$tempDir\\${candidate.modPath}");
            // we have to remove the contents of the archive path from the mod path before extracting
            if (await modDir.exists()) {
              await modDir.delete(recursive: true);
              await modDir.create(recursive: true);
            } else {
              await modDir.create(recursive: true);
            }
            await copyPath(modTempDir.path, modDir.path);
          } else {
            // extract the .pak file to the mods directory
            final modDir = Directory(
                "$modLegacyDirPath\\${candidate.modName}");
            // now we get the file, read the bytes, and extract it to the mods directory
            final fileStream = InputFileStream("$tempDir\\${candidate.modPath}");
            try{
              final archive = ZipDecoder().decodeBuffer(fileStream);
              // we need to remove the contents of the mod directory before extracting
              // this is important because the mod may have been updated and the old files need to be removed
              if (await modDir.exists()) {
                await modDir.delete(recursive: true);
                await modDir.create(recursive: true);
              } else {
                await modDir.create(recursive: true);
              }
              await extractArchiveToDiskAsync(archive, modDir.absolute.path);
            } catch (e) {
              talker.error("Error while processing ${candidate.archivePath}: $e");
            }
            finally {
              await fileStream.close();
            }
          }
        }
      } catch (e) {
        talker.error("Error while processing $archivePath: $e");
      }
      finally {
        await fileStream.close();
      }
    });
  }
}

class _ModFileFinder {
  // stupid workaround because passing 'this' to an isolate from a controller requires passing unserializable data
  // so we have to make this pure class for this static method
  static Future<List<ModInstallCandidate>> enumerateModsInSelectedFilesIsolate(List<String> files) async {
    return await Isolate.run<List<ModInstallCandidate>>(() => enumerateModsInSelectedFiles(files));
    // return await _enumerateModsInSelectedFiles(files);
  }


  static Future<List<ModInstallCandidate>> enumerateModsInSelectedFiles(List<String> files) async {
    List<ModInstallCandidate> candidates = [];
    for (var file in files) {
      try {
        // pak files are assumed to be legacy mods, and are added as such
        if (file.endsWith(".pak")) {
          // extract the file
          ModInstallCandidate candidate = ModInstallCandidate(
            archivePath: file,
            modPath: file.replaceAll('\\', '/').split("/").last,
            modName: file.replaceAll('\\', '/').split("/").last.replaceAll(".pak", ""),
            isLegacy: true,
            inArchive: false
          );
          candidates.add(candidate);
        }
        else if(file.endsWith(".zip")) {
          final archiveInputStream = InputFileStream(file);
          final archive = ZipDecoder().decodeBuffer(archiveInputStream);
          for (var archiveFile in archive) {
            if(archiveFile.name.endsWith(".pak")) {
              ModInstallCandidate candidate = ModInstallCandidate(
                  archivePath: file,
                  modPath: archiveFile.name,
                  modName: archiveFile.name.split("/").last.replaceAll(".pak", ""),
                  isLegacy: true,
                  inArchive: true
              );
              candidates.add(candidate);
            }
            else if(archiveFile.name.endsWith("ModInfo.xml")) {
              try {
                final modInfo = utf8.decode(archiveFile.content);
                final document = xml.XmlDocument.parse(modInfo);
                final modName = document
                    .xpathEvaluate("/Mod/@modName")
                    .string;
                final displayName = document
                    .xpathEvaluate("/Mod/@displayName")
                    .string;
                final versionString = document
                    .xpathEvaluate("/Mod/@version")
                    .string;
                Version? version;
                try {
                  version = Version.parse(versionString);
                } on FormatException {
                  version = null;
                }
                // get everything before the last / in the archive file name as the path
                // i.e. a/b/c/ModInfo.xml -> a/b/c
                final modPath = archiveFile.name.split("/").sublist(0, archiveFile.name.split("/").length - 1).join("/");
                if (modName.isEmpty) continue;

                ModInstallCandidate candidate = ModInstallCandidate(
                    archivePath: file,
                    modPath: modPath,
                    modName: modName,
                    isLegacy: false,
                    inArchive: true,
                    modVersion: version,
                    displayName: displayName
                );
                candidates.add(candidate);
              } on xml.XmlParserException  {
                print("Error while parsing ModInfo.xml in $file");
                continue;
              } on xml.XmlTagException {
                print("Error while parsing ModInfo.xml in $file");
                continue;
              }
            }
          }
        }
      } catch (e) {
        print("Error while processing $file: $e");
        continue;
      }
    }

    return candidates;
  }
}