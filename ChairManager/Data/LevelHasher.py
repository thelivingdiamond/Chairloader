import zipfile
import io
import hashlib
import os
import xml.etree.ElementTree as ET


# Specify the path to the zip file


root = ET.Element('files')

def HashArchiveUncompressed(zip_path, sha256):
    # Open the zip file in read mode
    with zipfile.ZipFile(zip_path, "r") as zip_file:

        # Iterate over the files in the zip file
        for file_name in zip_file.namelist():

            # Read the contents of the file into memory
            with zip_file.open(file_name, "r") as file:
                uncompressed_data = io.BytesIO(file.read())

            # Update the hash object with the uncompressed data
            sha256.update(uncompressed_data.getvalue())
    return sha256


# This is a recursive function that will traverse the directory tree, find all level.pak archives, and hash them
def HashAllLevelPaks(path):
    # Iterate over all files in the directory
    global root
    for file_name in os.listdir(path):

        # Create the full path to the file
        file_path = os.path.join(path, file_name)

        # If the file is a directory, recurse into it
        if os.path.isdir(file_path):
            HashAllLevelPaks(file_path)

        # If the file is a zip file and the name is 'level.pak', hash it
        elif os.path.isfile(file_path) and file_name == "level.pak":
            # Create a new hash object
            sha256 = hashlib.sha256()

            # Hash the archive
            HashArchiveUncompressed(file_path, sha256)
            file_element = ET.SubElement(root, 'file', {'path': file_path, 'hash': sha256.hexdigest(), 'type':"level"})
            # Print the final hash to the console
            print("SHA-256 hash of " + file_path + ": " + sha256.hexdigest())


def HashLocalizationPak(path):
    global root
    if os.path.exists(path):
        sha256 = hashlib.sha256()
        HashArchiveUncompressed(path, sha256)
        file_element = ET.SubElement(root, 'file', {'path': path, 'hash': sha256.hexdigest(), 'type': "localization"})
        # Print the final hash to the console
        print("SHA-256 hash of " + path + ": " + sha256.hexdigest())

HashAllLevelPaks("LevelOutput")
print(HashArchiveUncompressed("Testing/Hashing/level.pak", hashlib.sha256()).hexdigest())
HashLocalizationPak("English_xml_patch.pak")
tree = ET.ElementTree(root)
tree.write("HashesOutput.xml")

# Print the final hash to the console
# print("SHA-256 hash of all files: " + sha256.hexdigest())