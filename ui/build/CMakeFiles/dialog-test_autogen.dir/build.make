# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\it's a cake\1\pr\upnp_chat\ui"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\it's a cake\1\pr\upnp_chat\ui\build"

# Utility rule file for dialog-test_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/dialog-test_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dialog-test_autogen.dir/progress.make

CMakeFiles/dialog-test_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="D:\it's a cake\1\pr\upnp_chat\ui\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target dialog-test"
	C:\msys64\mingw64\bin\cmake.exe -E cmake_autogen "D:/it's a cake/1/pr/upnp_chat/ui/build/CMakeFiles/dialog-test_autogen.dir/AutogenInfo.json" ""

dialog-test_autogen: CMakeFiles/dialog-test_autogen
dialog-test_autogen: CMakeFiles/dialog-test_autogen.dir/build.make
.PHONY : dialog-test_autogen

# Rule to build all files generated by this target.
CMakeFiles/dialog-test_autogen.dir/build: dialog-test_autogen
.PHONY : CMakeFiles/dialog-test_autogen.dir/build

CMakeFiles/dialog-test_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\dialog-test_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/dialog-test_autogen.dir/clean

CMakeFiles/dialog-test_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\it's a cake\1\pr\upnp_chat\ui" "D:\it's a cake\1\pr\upnp_chat\ui" "D:\it's a cake\1\pr\upnp_chat\ui\build" "D:\it's a cake\1\pr\upnp_chat\ui\build" "D:\it's a cake\1\pr\upnp_chat\ui\build\CMakeFiles\dialog-test_autogen.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/dialog-test_autogen.dir/depend
