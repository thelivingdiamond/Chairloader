# Legacy Mod Conversion

Chairloader has a command line tool to convert a legacy .pak mod into a Chairloader mod. This tool removes the need to manually find changes in the mod.

## Usage
1. Create two folders:
   - `legacy` - for original mod files
   - `chair` - for converted files
2. Unpack .pak into `legacy` folder.
3. If this was a `level.pak` file, you must move its contents to `legacy/Levels/Campaign/[xxxx]/[yyyy]/level`. Replace `[xxxx]/[yyyy]` with level path.
4. Open Command Prompt in ChairManager folder.
5. Type this command. Replace [path/to/legacy] and [path/to/chair] with paths to created folders.
   ```
   .\LegacyModConverter.exe --type-lib XmlTypeLibrary.xml --merging-lib MergingLibrary.xml --prey-files-dir PreyFiles --legacy-mod-dir [path/to/legacy] --out-dir [path/to/chair]
   ```
6. Check the log file and fix errors (if you have any)

## Limitations
This tool doesn't have full support for array nodes. Array nodes are copied as-is with `ch:action="replaceChildren"`.