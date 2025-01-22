#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/gdexample", "src/navmesh_test"])


def get_library(name, sources):
    if env["platform"] == "macos":
        library = env.SharedLibrary(
            f"game/gdextensions/{name}/bin/lib{name}.{env["platform"]}.{env["target"]}.framework/lib{name}.{env["platform"]}.{env["target"]}",
            source=sources,
        )
    elif env["platform"] == "ios":
        if env["ios_simulator"]:
            library = env.StaticLibrary(
                f"game/gdextensions/{name}/bin/lib{name}.{env["platform"]}.{env["target"]}.simulator.a",
                source=sources,
            )
        else:
            library = env.StaticLibrary(
                f"game/gdextensions/{name}/bin/lib{name}.{env["platform"]}.{env["target"]}.a",
                source=sources,
            )
    else:
        library = env.SharedLibrary(
            f"game/gdextensions/{name}/bin/lib{name}{env["suffix"]}{env["SHLIBSUFFIX"]}",
            source=sources,
        )
    return library



src_gdexample = Glob("src/gdexample/*.cpp")
src_navmesh_test = Glob("src/navmesh_test/*.cpp")

libgdexample = get_library("gdexample", src_gdexample)
libnavmesh_test = get_library("navmesh_test", src_navmesh_test)

Default(libgdexample, libnavmesh_test)
