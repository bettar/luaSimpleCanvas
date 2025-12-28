// Alex Bettarini - 22 Dec 2025
#include <iostream>

#include "wx/wx.h"

#include "engineWx.h"

#include <lua.hpp> // Lua C API header

static wxMemoryDC *memDC = nullptr;
static HPGL::engineWx *engine2;

int cpp_rect(lua_State* L)
{
    double x1 = luaL_checknumber(L, 1);
    double y1 = luaL_checknumber(L, 2);
    double w = luaL_checknumber(L, 3);
    double h = luaL_checknumber(L, 4);
    
    engine2->anyRect(x1, y1, w, h);

    return 0; // Number of return values
}

int cpp_penDashed(lua_State* L)
{
    if (!lua_isboolean(L, 1))
         return luaL_error(L, "Expected a bool");
    
    bool dashed = lua_toboolean(L, 1);
    if (dashed)
        engine2->setLineDashed(); //std::cout << " dashed";
    else
        engine2->setLineDashed(false); //std::cout << " NOT dashed";

    return 0; // Number of return values
}

int cpp_pen(lua_State* L)
{
    auto color = luaL_checkinteger(L, 1);
    double thickness = luaL_checknumber(L, 2);
    
    //std::cout << __FUNCTION__ << " Line " << __LINE__ << " " << color << std::endl;

    switch (color) {
        case 0: engine2->whitePen(thickness); break;
        case 1: engine2->blackPen(thickness); break;
        case 2: engine2->redPen(thickness); break;
        case 3: engine2->greenPen(thickness); break;
        case 4: engine2->bluePen(thickness); break;
        case 5: engine2->cyanPen(thickness); break;
        case 6: engine2->magentaPen(thickness); break;
        case 7: engine2->yellowPen(thickness); break;

        default:
            break;
    }

    return 0; // Number of return values
}

int cpp_line(lua_State* L)
{
    double x1 = luaL_checknumber(L, 1);
    double y1 = luaL_checknumber(L, 2);
    double x2 = luaL_checknumber(L, 3);
    double y2 = luaL_checknumber(L, 4);
    
    engine2->anyLine(x1, y1, x2, y2);

    return 0; // Number of return values
}

int cpp_create(lua_State* L)
{
    //std::cout << __FUNCTION__ << " Line " << __LINE__ << std::endl;
    
    // Check and fetch arguments from the Lua stack
    double w = luaL_checknumber(L, 1);
    double h = luaL_checknumber(L, 2);

    {
        if (memDC)
            delete memDC;
        
        memDC = new wxMemoryDC;
        
        if (engine2)
            delete engine2;
        
        engine2 = new HPGL::engineWx(memDC);
        
        engine2->initialize(0,0,w,h);
    }
    
    lua_pushnumber(L, w + h);     // Push the result onto the Lua stack
    return 1; // Return the number of results
}

int cpp_save(lua_State* L)
{
    const char* name = luaL_checkstring(L, 1);

    engine2->terminate();
    auto _bmp = engine2->_bmp;
    if (_bmp.IsOk())
        _bmp.SaveFile(name, wxBITMAP_TYPE_PNG);
    
    return 0; // Number of return values
}

int cpp_text_size(lua_State* L)
{
    double sz = luaL_checknumber(L, 1);
    engine2->textSize(sz);
    return 0; // Number of return values
}

int cpp_text(lua_State* L)
{
    double dx = luaL_checknumber(L, 1);
    double dy = luaL_checknumber(L, 2);
    const char* label = luaL_checkstring(L, 3);
    
    //std::cout << __FUNCTION__ << " Line " << __LINE__ << " " << label << std::endl;
    engine2->labelRelative(dx, dy, label);
    
    return 0; // Number of return values
}

// Register functions with Lua
static const struct luaL_Reg mylib [] = {
    {"canvas", cpp_create},
    {"save", cpp_save},
    {"rect", cpp_rect},
    {"line", cpp_line},
    {"pen", cpp_pen},
    {"penDashed", cpp_penDashed},
    {"labelRelative", cpp_text},
    {"labelSize", cpp_text_size},
    {NULL, NULL} // Sentinel
};

// --------- C_API

#ifdef _WIN32
#define DllExport   __declspec( dllexport )
#else
#define DllExport
#endif

// Called when Lua requires this module
extern "C" int DllExport luaopen_simpleCanvas(lua_State *L)
{
    wxImage::AddHandler(new wxPNGHandler);
    
    luaL_newlib(L, mylib); // Create a table with our functions
    return 1;               // Return the table
}


