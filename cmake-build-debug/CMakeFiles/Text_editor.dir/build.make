# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Applications\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Applications\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Mohannad\Desktop\Assignment 4\Text-editor"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Mohannad\Desktop\Assignment 4\Text-editor\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Text_editor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Text_editor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Text_editor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Text_editor.dir/flags.make

CMakeFiles/Text_editor.dir/text-editor.cpp.obj: CMakeFiles/Text_editor.dir/flags.make
CMakeFiles/Text_editor.dir/text-editor.cpp.obj: ../text-editor.cpp
CMakeFiles/Text_editor.dir/text-editor.cpp.obj: CMakeFiles/Text_editor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Mohannad\Desktop\Assignment 4\Text-editor\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Text_editor.dir/text-editor.cpp.obj"
	"D:\Applications\CLion 2021.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Text_editor.dir/text-editor.cpp.obj -MF CMakeFiles\Text_editor.dir\text-editor.cpp.obj.d -o CMakeFiles\Text_editor.dir\text-editor.cpp.obj -c "C:\Users\Mohannad\Desktop\Assignment 4\Text-editor\text-editor.cpp"

CMakeFiles/Text_editor.dir/text-editor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Text_editor.dir/text-editor.cpp.i"
	"D:\Applications\CLion 2021.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Mohannad\Desktop\Assignment 4\Text-editor\text-editor.cpp" > CMakeFiles\Text_editor.dir\text-editor.cpp.i

CMakeFiles/Text_editor.dir/text-editor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Text_editor.dir/text-editor.cpp.s"
	"D:\Applications\CLion 2021.3.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Mohannad\Desktop\Assignment 4\Text-editor\text-editor.cpp" -o CMakeFiles\Text_editor.dir\text-editor.cpp.s

# Object files for target Text_editor
Text_editor_OBJECTS = \
"CMakeFiles/Text_editor.dir/text-editor.cpp.obj"

# External object files for target Text_editor
Text_editor_EXTERNAL_OBJECTS =

Text_editor.exe: CMakeFiles/Text_editor.dir/text-editor.cpp.obj
Text_editor.exe: CMakeFiles/Text_editor.dir/build.make
Text_editor.exe: CMakeFiles/Text_editor.dir/linklibs.rsp
Text_editor.exe: CMakeFiles/Text_editor.dir/objects1.rsp
Text_editor.exe: CMakeFiles/Text_editor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Mohannad\Desktop\Assignment 4\Text-editor\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Text_editor.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Text_editor.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Text_editor.dir/build: Text_editor.exe
.PHONY : CMakeFiles/Text_editor.dir/build

CMakeFiles/Text_editor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Text_editor.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Text_editor.dir/clean

CMakeFiles/Text_editor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Mohannad\Desktop\Assignment 4\Text-editor" "C:\Users\Mohannad\Desktop\Assignment 4\Text-editor" "C:\Users\Mohannad\Desktop\Assignment 4\Text-editor\cmake-build-debug" "C:\Users\Mohannad\Desktop\Assignment 4\Text-editor\cmake-build-debug" "C:\Users\Mohannad\Desktop\Assignment 4\Text-editor\cmake-build-debug\CMakeFiles\Text_editor.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Text_editor.dir/depend

