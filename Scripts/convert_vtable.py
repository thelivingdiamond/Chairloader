# Converts vtable definition from IDA to C++
# Usage:
#   1. Make file with vtable functions.
#   2. Run
#        python convert_vtable.py <your file name>
#   3. Prey it works
import sys

if len(sys.argv) != 2:
    print("Usage: convert_vtable <your file name>")
    exit(-1)

with open(sys.argv[1], 'r') as f:
    data = f.read()

    # Find the name of the class
    end = data.find('_vtbl')
    start = data.rfind(' ', 0, end)
    class_name = data[start + 1:end]
    print(f"Class name: '{class_name}'")

    fixed_data = data\
        .replace('struct /*VFT*/', 'class')\
        .replace('void (__fastcall *~', 'virtual ~')\
        .replace('(__fastcall *', '')\
        .replace(');', ') = 0;')\
        .replace(';\n  ', ';\n  virtual ')\
        .replace(f'{class_name} *this, ', '')\
        .replace(f'{class_name} *this', '')\
        .replace(')(', '(')\
        .replace('_vtbl', '')\
        .replace('{\n', '{\npublic:\n')

with open(sys.argv[1], 'w') as f:
    f.write(fixed_data)
