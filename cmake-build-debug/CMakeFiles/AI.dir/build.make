# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\AI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\AI\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\AI.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\AI.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\AI.dir\flags.make

CMakeFiles\AI.dir\src\main.cpp.obj: CMakeFiles\AI.dir\flags.make
CMakeFiles\AI.dir\src\main.cpp.obj: ..\src\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AI.dir/src/main.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AI.dir\src\main.cpp.obj /FdCMakeFiles\AI.dir\ /FS -c E:\AI\src\main.cpp
<<

CMakeFiles\AI.dir\src\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AI.dir/src/main.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\AI.dir\src\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AI\src\main.cpp
<<

CMakeFiles\AI.dir\src\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AI.dir/src/main.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AI.dir\src\main.cpp.s /c E:\AI\src\main.cpp
<<

CMakeFiles\AI.dir\src\Engine\Window.cpp.obj: CMakeFiles\AI.dir\flags.make
CMakeFiles\AI.dir\src\Engine\Window.cpp.obj: ..\src\Engine\Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AI.dir/src/Engine/Window.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AI.dir\src\Engine\Window.cpp.obj /FdCMakeFiles\AI.dir\ /FS -c E:\AI\src\Engine\Window.cpp
<<

CMakeFiles\AI.dir\src\Engine\Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AI.dir/src/Engine/Window.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\AI.dir\src\Engine\Window.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AI\src\Engine\Window.cpp
<<

CMakeFiles\AI.dir\src\Engine\Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AI.dir/src/Engine/Window.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AI.dir\src\Engine\Window.cpp.s /c E:\AI\src\Engine\Window.cpp
<<

CMakeFiles\AI.dir\src\Pathfinding\AStar.cpp.obj: CMakeFiles\AI.dir\flags.make
CMakeFiles\AI.dir\src\Pathfinding\AStar.cpp.obj: ..\src\Pathfinding\AStar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AI.dir/src/Pathfinding/AStar.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AI.dir\src\Pathfinding\AStar.cpp.obj /FdCMakeFiles\AI.dir\ /FS -c E:\AI\src\Pathfinding\AStar.cpp
<<

CMakeFiles\AI.dir\src\Pathfinding\AStar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AI.dir/src/Pathfinding/AStar.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\AI.dir\src\Pathfinding\AStar.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AI\src\Pathfinding\AStar.cpp
<<

CMakeFiles\AI.dir\src\Pathfinding\AStar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AI.dir/src/Pathfinding/AStar.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AI.dir\src\Pathfinding\AStar.cpp.s /c E:\AI\src\Pathfinding\AStar.cpp
<<

CMakeFiles\AI.dir\src\Math\Math.cpp.obj: CMakeFiles\AI.dir\flags.make
CMakeFiles\AI.dir\src\Math\Math.cpp.obj: ..\src\Math\Math.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AI.dir/src/Math/Math.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AI.dir\src\Math\Math.cpp.obj /FdCMakeFiles\AI.dir\ /FS -c E:\AI\src\Math\Math.cpp
<<

CMakeFiles\AI.dir\src\Math\Math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AI.dir/src/Math/Math.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\AI.dir\src\Math\Math.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AI\src\Math\Math.cpp
<<

CMakeFiles\AI.dir\src\Math\Math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AI.dir/src/Math/Math.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AI.dir\src\Math\Math.cpp.s /c E:\AI\src\Math\Math.cpp
<<

CMakeFiles\AI.dir\src\Core\Maze.cpp.obj: CMakeFiles\AI.dir\flags.make
CMakeFiles\AI.dir\src\Core\Maze.cpp.obj: ..\src\Core\Maze.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AI.dir/src/Core/Maze.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AI.dir\src\Core\Maze.cpp.obj /FdCMakeFiles\AI.dir\ /FS -c E:\AI\src\Core\Maze.cpp
<<

CMakeFiles\AI.dir\src\Core\Maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AI.dir/src/Core/Maze.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\AI.dir\src\Core\Maze.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AI\src\Core\Maze.cpp
<<

CMakeFiles\AI.dir\src\Core\Maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AI.dir/src/Core/Maze.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AI.dir\src\Core\Maze.cpp.s /c E:\AI\src\Core\Maze.cpp
<<

CMakeFiles\AI.dir\src\Core\Timer.cpp.obj: CMakeFiles\AI.dir\flags.make
CMakeFiles\AI.dir\src\Core\Timer.cpp.obj: ..\src\Core\Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AI.dir/src/Core/Timer.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\AI.dir\src\Core\Timer.cpp.obj /FdCMakeFiles\AI.dir\ /FS -c E:\AI\src\Core\Timer.cpp
<<

CMakeFiles\AI.dir\src\Core\Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AI.dir/src/Core/Timer.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\AI.dir\src\Core\Timer.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AI\src\Core\Timer.cpp
<<

CMakeFiles\AI.dir\src\Core\Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AI.dir/src/Core/Timer.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\AI.dir\src\Core\Timer.cpp.s /c E:\AI\src\Core\Timer.cpp
<<

# Object files for target AI
AI_OBJECTS = \
"CMakeFiles\AI.dir\src\main.cpp.obj" \
"CMakeFiles\AI.dir\src\Engine\Window.cpp.obj" \
"CMakeFiles\AI.dir\src\Pathfinding\AStar.cpp.obj" \
"CMakeFiles\AI.dir\src\Math\Math.cpp.obj" \
"CMakeFiles\AI.dir\src\Core\Maze.cpp.obj" \
"CMakeFiles\AI.dir\src\Core\Timer.cpp.obj"

# External object files for target AI
AI_EXTERNAL_OBJECTS =

AI.exe: CMakeFiles\AI.dir\src\main.cpp.obj
AI.exe: CMakeFiles\AI.dir\src\Engine\Window.cpp.obj
AI.exe: CMakeFiles\AI.dir\src\Pathfinding\AStar.cpp.obj
AI.exe: CMakeFiles\AI.dir\src\Math\Math.cpp.obj
AI.exe: CMakeFiles\AI.dir\src\Core\Maze.cpp.obj
AI.exe: CMakeFiles\AI.dir\src\Core\Timer.cpp.obj
AI.exe: CMakeFiles\AI.dir\build.make
AI.exe: CMakeFiles\AI.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\AI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable AI.exe"
	"E:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\AI.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\AI.dir\objects1.rsp @<<
 /out:AI.exe /implib:AI.lib /pdb:E:\AI\cmake-build-debug\AI.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\AI.dir\build: AI.exe
.PHONY : CMakeFiles\AI.dir\build

CMakeFiles\AI.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AI.dir\cmake_clean.cmake
.PHONY : CMakeFiles\AI.dir\clean

CMakeFiles\AI.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\AI E:\AI E:\AI\cmake-build-debug E:\AI\cmake-build-debug E:\AI\cmake-build-debug\CMakeFiles\AI.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\AI.dir\depend
