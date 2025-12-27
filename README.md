# Lua Package: SimpleCanvas

## Purpose
Create 2D diagrams from Lua scripts, building up modules using simple primitives

Two types of output files are generated: HGL and PNG

- HGP (vector)
	The output format HGP was chosen as the most suitable, because of its relative simplicity and the fact that the output product is a text file.


- PNG (raster)
	- use wxWidgets 2D drawing primitives to create PNG files. This can be done in two ways
    - runnibg the app built from this project to read lua scripts
    - run lua scripts with the lua interpreter from the command line
	- other graphic formats are possible with a very simple modification to the source code

---
## Usage

- Use CMake to build the project targets into directory BLD_DIR

### macOS
- Go to the directory containing your Lua script is

        $ cd lua_scripts
        $ ln -s $BLD_DIR/lua/Release/libluaPackage.<VERSION>.dylib simpleCanvas.so
        $ lua demo.lua

- Alternatively use `LUA_DIR`

---
## Dependencies
- [Lua](https://www.lua.org/)
- [wxWidgets](https://wxwidgets.org/)
- [wxFormBuilder](https://github.com/wxFormBuilder/wxFormBuilder)
- [CMake](https://cmake.org/)

In this project, 6 different target executables can be built with CMake:

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

---
## References
- [HP-GL Reference Guide](https://www.isoplotec.co.jp/HPGL/eHPGL.htm)
