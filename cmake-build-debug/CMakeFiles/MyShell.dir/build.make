# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/samuelguzman/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/samuelguzman/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/samuelguzman/CLionProjects/MyShell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samuelguzman/CLionProjects/MyShell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MyShell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyShell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyShell.dir/flags.make

CMakeFiles/MyShell.dir/commandsC/my_grep.c.o: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/commandsC/my_grep.c.o: ../commandsC/my_grep.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MyShell.dir/commandsC/my_grep.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/commandsC/my_grep.c.o   -c /home/samuelguzman/CLionProjects/MyShell/commandsC/my_grep.c

CMakeFiles/MyShell.dir/commandsC/my_grep.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/commandsC/my_grep.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuelguzman/CLionProjects/MyShell/commandsC/my_grep.c > CMakeFiles/MyShell.dir/commandsC/my_grep.c.i

CMakeFiles/MyShell.dir/commandsC/my_grep.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/commandsC/my_grep.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuelguzman/CLionProjects/MyShell/commandsC/my_grep.c -o CMakeFiles/MyShell.dir/commandsC/my_grep.c.s

CMakeFiles/MyShell.dir/myShell0.c.o: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/myShell0.c.o: ../myShell0.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MyShell.dir/myShell0.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/myShell0.c.o   -c /home/samuelguzman/CLionProjects/MyShell/myShell0.c

CMakeFiles/MyShell.dir/myShell0.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/myShell0.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuelguzman/CLionProjects/MyShell/myShell0.c > CMakeFiles/MyShell.dir/myShell0.c.i

CMakeFiles/MyShell.dir/myShell0.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/myShell0.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuelguzman/CLionProjects/MyShell/myShell0.c -o CMakeFiles/MyShell.dir/myShell0.c.s

CMakeFiles/MyShell.dir/commandsC/my_cp.c.o: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/commandsC/my_cp.c.o: ../commandsC/my_cp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MyShell.dir/commandsC/my_cp.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/commandsC/my_cp.c.o   -c /home/samuelguzman/CLionProjects/MyShell/commandsC/my_cp.c

CMakeFiles/MyShell.dir/commandsC/my_cp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/commandsC/my_cp.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuelguzman/CLionProjects/MyShell/commandsC/my_cp.c > CMakeFiles/MyShell.dir/commandsC/my_cp.c.i

CMakeFiles/MyShell.dir/commandsC/my_cp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/commandsC/my_cp.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuelguzman/CLionProjects/MyShell/commandsC/my_cp.c -o CMakeFiles/MyShell.dir/commandsC/my_cp.c.s

CMakeFiles/MyShell.dir/commandsC/my_help.c.o: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/commandsC/my_help.c.o: ../commandsC/my_help.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/MyShell.dir/commandsC/my_help.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/commandsC/my_help.c.o   -c /home/samuelguzman/CLionProjects/MyShell/commandsC/my_help.c

CMakeFiles/MyShell.dir/commandsC/my_help.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/commandsC/my_help.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuelguzman/CLionProjects/MyShell/commandsC/my_help.c > CMakeFiles/MyShell.dir/commandsC/my_help.c.i

CMakeFiles/MyShell.dir/commandsC/my_help.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/commandsC/my_help.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuelguzman/CLionProjects/MyShell/commandsC/my_help.c -o CMakeFiles/MyShell.dir/commandsC/my_help.c.s

CMakeFiles/MyShell.dir/commandsC/my_mv.c.o: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/commandsC/my_mv.c.o: ../commandsC/my_mv.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/MyShell.dir/commandsC/my_mv.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/commandsC/my_mv.c.o   -c /home/samuelguzman/CLionProjects/MyShell/commandsC/my_mv.c

CMakeFiles/MyShell.dir/commandsC/my_mv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/commandsC/my_mv.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuelguzman/CLionProjects/MyShell/commandsC/my_mv.c > CMakeFiles/MyShell.dir/commandsC/my_mv.c.i

CMakeFiles/MyShell.dir/commandsC/my_mv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/commandsC/my_mv.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuelguzman/CLionProjects/MyShell/commandsC/my_mv.c -o CMakeFiles/MyShell.dir/commandsC/my_mv.c.s

CMakeFiles/MyShell.dir/commandsC/my_cat.c.o: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/commandsC/my_cat.c.o: ../commandsC/my_cat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/MyShell.dir/commandsC/my_cat.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/commandsC/my_cat.c.o   -c /home/samuelguzman/CLionProjects/MyShell/commandsC/my_cat.c

CMakeFiles/MyShell.dir/commandsC/my_cat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/commandsC/my_cat.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuelguzman/CLionProjects/MyShell/commandsC/my_cat.c > CMakeFiles/MyShell.dir/commandsC/my_cat.c.i

CMakeFiles/MyShell.dir/commandsC/my_cat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/commandsC/my_cat.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuelguzman/CLionProjects/MyShell/commandsC/my_cat.c -o CMakeFiles/MyShell.dir/commandsC/my_cat.c.s

CMakeFiles/MyShell.dir/commandsC/my_ls.c.o: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/commandsC/my_ls.c.o: ../commandsC/my_ls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/MyShell.dir/commandsC/my_ls.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/commandsC/my_ls.c.o   -c /home/samuelguzman/CLionProjects/MyShell/commandsC/my_ls.c

CMakeFiles/MyShell.dir/commandsC/my_ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/commandsC/my_ls.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuelguzman/CLionProjects/MyShell/commandsC/my_ls.c > CMakeFiles/MyShell.dir/commandsC/my_ls.c.i

CMakeFiles/MyShell.dir/commandsC/my_ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/commandsC/my_ls.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuelguzman/CLionProjects/MyShell/commandsC/my_ls.c -o CMakeFiles/MyShell.dir/commandsC/my_ls.c.s

CMakeFiles/MyShell.dir/commandsC/my_man.c.o: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/commandsC/my_man.c.o: ../commandsC/my_man.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/MyShell.dir/commandsC/my_man.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/commandsC/my_man.c.o   -c /home/samuelguzman/CLionProjects/MyShell/commandsC/my_man.c

CMakeFiles/MyShell.dir/commandsC/my_man.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/commandsC/my_man.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuelguzman/CLionProjects/MyShell/commandsC/my_man.c > CMakeFiles/MyShell.dir/commandsC/my_man.c.i

CMakeFiles/MyShell.dir/commandsC/my_man.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/commandsC/my_man.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuelguzman/CLionProjects/MyShell/commandsC/my_man.c -o CMakeFiles/MyShell.dir/commandsC/my_man.c.s

CMakeFiles/MyShell.dir/commandsC/game.c.o: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/commandsC/game.c.o: ../commandsC/game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/MyShell.dir/commandsC/game.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/commandsC/game.c.o   -c /home/samuelguzman/CLionProjects/MyShell/commandsC/game.c

CMakeFiles/MyShell.dir/commandsC/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/commandsC/game.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuelguzman/CLionProjects/MyShell/commandsC/game.c > CMakeFiles/MyShell.dir/commandsC/game.c.i

CMakeFiles/MyShell.dir/commandsC/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/commandsC/game.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuelguzman/CLionProjects/MyShell/commandsC/game.c -o CMakeFiles/MyShell.dir/commandsC/game.c.s

CMakeFiles/MyShell.dir/commandsC/test.c.o: CMakeFiles/MyShell.dir/flags.make
CMakeFiles/MyShell.dir/commandsC/test.c.o: ../commandsC/test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/MyShell.dir/commandsC/test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyShell.dir/commandsC/test.c.o   -c /home/samuelguzman/CLionProjects/MyShell/commandsC/test.c

CMakeFiles/MyShell.dir/commandsC/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyShell.dir/commandsC/test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuelguzman/CLionProjects/MyShell/commandsC/test.c > CMakeFiles/MyShell.dir/commandsC/test.c.i

CMakeFiles/MyShell.dir/commandsC/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyShell.dir/commandsC/test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuelguzman/CLionProjects/MyShell/commandsC/test.c -o CMakeFiles/MyShell.dir/commandsC/test.c.s

# Object files for target MyShell
MyShell_OBJECTS = \
"CMakeFiles/MyShell.dir/commandsC/my_grep.c.o" \
"CMakeFiles/MyShell.dir/myShell0.c.o" \
"CMakeFiles/MyShell.dir/commandsC/my_cp.c.o" \
"CMakeFiles/MyShell.dir/commandsC/my_help.c.o" \
"CMakeFiles/MyShell.dir/commandsC/my_mv.c.o" \
"CMakeFiles/MyShell.dir/commandsC/my_cat.c.o" \
"CMakeFiles/MyShell.dir/commandsC/my_ls.c.o" \
"CMakeFiles/MyShell.dir/commandsC/my_man.c.o" \
"CMakeFiles/MyShell.dir/commandsC/game.c.o" \
"CMakeFiles/MyShell.dir/commandsC/test.c.o"

# External object files for target MyShell
MyShell_EXTERNAL_OBJECTS =

MyShell: CMakeFiles/MyShell.dir/commandsC/my_grep.c.o
MyShell: CMakeFiles/MyShell.dir/myShell0.c.o
MyShell: CMakeFiles/MyShell.dir/commandsC/my_cp.c.o
MyShell: CMakeFiles/MyShell.dir/commandsC/my_help.c.o
MyShell: CMakeFiles/MyShell.dir/commandsC/my_mv.c.o
MyShell: CMakeFiles/MyShell.dir/commandsC/my_cat.c.o
MyShell: CMakeFiles/MyShell.dir/commandsC/my_ls.c.o
MyShell: CMakeFiles/MyShell.dir/commandsC/my_man.c.o
MyShell: CMakeFiles/MyShell.dir/commandsC/game.c.o
MyShell: CMakeFiles/MyShell.dir/commandsC/test.c.o
MyShell: CMakeFiles/MyShell.dir/build.make
MyShell: CMakeFiles/MyShell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable MyShell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyShell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyShell.dir/build: MyShell

.PHONY : CMakeFiles/MyShell.dir/build

CMakeFiles/MyShell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyShell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyShell.dir/clean

CMakeFiles/MyShell.dir/depend:
	cd /home/samuelguzman/CLionProjects/MyShell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samuelguzman/CLionProjects/MyShell /home/samuelguzman/CLionProjects/MyShell /home/samuelguzman/CLionProjects/MyShell/cmake-build-debug /home/samuelguzman/CLionProjects/MyShell/cmake-build-debug /home/samuelguzman/CLionProjects/MyShell/cmake-build-debug/CMakeFiles/MyShell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyShell.dir/depend

