import argparse
import distutils.dir_util
import os
import shutil
import subprocess
import json
import zipfile
from pathlib import Path, PurePath

CHAIRMANAGER_FILES_PATH = PurePath('ChairManager/Data')
CONFIG_NAME = PurePath('_PackageConfig.json')


class Args:
    repo_path: Path
    build_path: Path
    build_config: str
    output_dir_path: Path | None = None
    temp_path: Path

    def __init__(self):
        parser = argparse.ArgumentParser(description='Builds a ChairManager and Chairloader ZIP from build artifacts.')
        parser.add_argument('--repo-path', action='store', required=True, help='Path to the Chairloader repo root.')
        parser.add_argument('--build-path', action='store', required=True, help='Path to CMake build directory.')
        parser.add_argument('--build-config', action='store', required=True, help='Build configuration name.')
        parser.add_argument('--output-dir-path', action='store', required=False, help='Path to the directory to put the ZIP to.')
        parser.add_argument('--temp-path', action='store', required=True, help='Path to the temporary directory.')
        parser_args = parser.parse_args()
        self.repo_path = Path(parser_args.repo_path).absolute()
        self.build_path = Path(parser_args.build_path).absolute()
        self.build_config = parser_args.build_config

        if parser_args.output_dir_path:
            self.output_dir_path = Path(parser_args.output_dir_path).absolute()

        self.temp_path = Path(parser_args.temp_path).absolute()

        self.temp_path.mkdir(parents=True, exist_ok=True)

        # Change work dir to repo root
        os.chdir(self.repo_path)


# Returns the short Git commit hash.
def get_commit_hash() -> str:
    commit_hash = subprocess \
        .Popen(['git', 'rev-parse', '--short', 'HEAD'], stdout=subprocess.PIPE) \
        .communicate()[0].rstrip().decode('utf-8')
    return commit_hash


# Reads the package config file.
def read_config() -> dict:
    with open(CHAIRMANAGER_FILES_PATH / CONFIG_NAME, 'r') as f:
        config_dict = json.load(f)
        return config_dict


args = Args()
config = read_config()

output_name = f'Chairloader-{get_commit_hash()}-{args.build_config}'
output_name_symbols = f'Chairloader-{get_commit_hash()}-{args.build_config}-Symbols'
output_dir_path = args.temp_path / output_name
if output_dir_path.exists():
    shutil.rmtree(output_dir_path)
output_dir_path.mkdir(exist_ok=False)

# Copy artifacts
for target_name, files in config['artifacts'].items():
    target_name: str
    files: dict[str, str]

    print(f'Copy artifacts: {target_name}')
    target_files_path = args.build_path / target_name / args.build_config

    for src_file, dst_file in files.items():
        src_file_path = target_files_path / src_file
        dst_file_path = output_dir_path / dst_file

        # TODO: Ignore missing files. Some only exist in Debug builds, others in Release
        # if not src_file_path.exists():
        #     raise ValueError(f"An artifact doesn't exist.\nFull path: {src_file_path}")

        if src_file_path.exists():
            print(f'- {src_file_path} -> {dst_file_path}')
            dst_file_path.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(src_file_path, dst_file_path)
        else:
            print(f'- SKIPPED {src_file_path}')

# Copy ChairManager files
print(f'Copy ChairManager files')
for file_name in config['file_list']:
    src_file_path = args.repo_path / CHAIRMANAGER_FILES_PATH / file_name
    dst_file_path = output_dir_path / file_name

    if not src_file_path.exists():
        raise ValueError(f"A file doesn't exist.\nFull path: {src_file_path}")

    print(f'- {src_file_path} -> {dst_file_path}')
    dst_file_path.parent.mkdir(parents=True, exist_ok=True)

    if src_file_path.is_dir():
        distutils.dir_util.copy_tree(str(src_file_path), str(dst_file_path))
    else:
        shutil.copy2(src_file_path, dst_file_path)

if args.output_dir_path:
    # Package into a ZIP
    zip_path = args.output_dir_path / f'{output_name}.zip'
    zip_path_symbols = args.output_dir_path / f'{output_name_symbols}.zip'
    print(f'Making an archive: {zip_path}')
    print(f'Making an archive with symbols: {zip_path_symbols}')
    with (
        zipfile.ZipFile(zip_path, 'w', zipfile.ZIP_DEFLATED) as zipf,
        zipfile.ZipFile(zip_path_symbols, 'w', zipfile.ZIP_DEFLATED) as zipf_symbols,
    ):
        for root, dirs, files in os.walk(output_dir_path):
            for file in files:
                path = os.path.join(root, file)
                if file.endswith('.pdb'):
                    zipf_symbols.write(path, os.path.relpath(path, args.temp_path))
                else:
                    zipf.write(path, os.path.relpath(path, args.temp_path))

GITHUB_OUTPUT = 'GITHUB_OUTPUT'

if GITHUB_OUTPUT in os.environ:
    # Set artifact name on GitHub Actions
    with open(os.environ[GITHUB_OUTPUT], 'a') as f:
        def set_output(name, value):
            print(f'GitHub Actions: Setting {name} = {value}')
            f.write(f'{name}={value}\n')


        set_output('artifact_name', output_name)
        set_output('artifact_name_symbols', output_name_symbols)
