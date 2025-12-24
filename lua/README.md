Lua package

## Purpose
Create 2D diagrams using Lua code, building up modules using simple primitives

Two types of output files are generated: HGL and PNG

---
## Usage

- build the project targets into directory BLD_DIR

### macOS
- Go ti where your lua script is

        $ cd lua
        $ ln -s $BLD_DIR/lua/Release/libluaPackage.dylib simpleCanvas.so
        $ lua demo.lua

---
## Dependencies
- Lua
- wxWidgets
- CMake

6 types of target executables can be built with CMake

~~~
$ tree -d
.
├── cli
│   ├── allKeys
│   ├── major
│   └── minor
├── gui
│   └── fbp
├── lib
└── lua
~~~