#
# This script prints disk usage on Windows.
# Used to debug space usage issues on GitHub Actions.
#
import shutil
import string
from ctypes import windll


# https://stackoverflow.com/a/1094933
def sizeof_fmt(num, suffix="B"):
    for unit in ("", "Ki", "Mi", "Gi", "Ti", "Pi", "Ei", "Zi"):
        if abs(num) < 1024.0:
            return f"{num:3.1f}{unit}{suffix}"
        num /= 1024.0
    return f"{num:.1f}Yi{suffix}"


# https://stackoverflow.com/a/827398
def get_drives():
    drives = []
    bitmask = windll.kernel32.GetLogicalDrives()
    for letter in string.ascii_uppercase:
        if bitmask & 1:
            drives.append(letter)
        bitmask >>= 1

    return drives


drives = get_drives()
for i in drives:
    usage = shutil.disk_usage(f'{i}:')
    print(f'{i}: total = {sizeof_fmt(usage.total)}; used = {sizeof_fmt(usage.used)}; free = {sizeof_fmt(usage.free)}')
