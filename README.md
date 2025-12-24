# luaSimpleCanvas
Create 2D drawings from Lua scripts

This project was originated out of the need for creating 2D diagrams programmatically and/or from source code scripts.

The initial application was to create music diagrams for cello.

The output format HGP was chosen as the most suitable, because of its relative simplicity and the fact that the output product is a text file.

Conversion to more modern image formats (PNG) is done in post-processing with tools like [ImageMagick](https://imagemagick.org/).

Note: it was discovered later that ImageMagick relies on two utilities [hp2xx](https://www.gnu.org/software/hp2xx/) and `gs` (Ghostscript) that must be present on the system. On Linux this is a good solutioin, but on macOS brew has `gs` but it doesn't have `hp2xx` which must be built from sources. When I did that, I ended up with "broken" PNG files, in the sense that they were missing all color information. I might need to spend more time on this macOS issue.

It was decided to split the core functionality into a library and the music diagrams were create by a custom app calling into that library. At present the  output files are okay for conversion to other formats, but if they were to drive a real plotter they would need to be optimized to minimize the swapping of pens, and to sort the XY coordinates in each command so that the pen doesn't jump back and forth unnecessarily.

An alternative implementation of the library could use wxWidgets drawing primitives to achieve the same result.

