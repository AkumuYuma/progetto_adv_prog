# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/build

# Include any dependencies generated for this target.
include CMakeFiles/evolution.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/evolution.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/evolution.out.dir/flags.make

CMakeFiles/evolution.out.dir/src/main.cpp.o: CMakeFiles/evolution.out.dir/flags.make
CMakeFiles/evolution.out.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/evolution.out.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/evolution.out.dir/src/main.cpp.o -c /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/main.cpp

CMakeFiles/evolution.out.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evolution.out.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/main.cpp > CMakeFiles/evolution.out.dir/src/main.cpp.i

CMakeFiles/evolution.out.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evolution.out.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/main.cpp -o CMakeFiles/evolution.out.dir/src/main.cpp.s

CMakeFiles/evolution.out.dir/src/randomTools.cpp.o: CMakeFiles/evolution.out.dir/flags.make
CMakeFiles/evolution.out.dir/src/randomTools.cpp.o: ../src/randomTools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/evolution.out.dir/src/randomTools.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/evolution.out.dir/src/randomTools.cpp.o -c /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/randomTools.cpp

CMakeFiles/evolution.out.dir/src/randomTools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evolution.out.dir/src/randomTools.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/randomTools.cpp > CMakeFiles/evolution.out.dir/src/randomTools.cpp.i

CMakeFiles/evolution.out.dir/src/randomTools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evolution.out.dir/src/randomTools.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/randomTools.cpp -o CMakeFiles/evolution.out.dir/src/randomTools.cpp.s

CMakeFiles/evolution.out.dir/src/utilities.cpp.o: CMakeFiles/evolution.out.dir/flags.make
CMakeFiles/evolution.out.dir/src/utilities.cpp.o: ../src/utilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/evolution.out.dir/src/utilities.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/evolution.out.dir/src/utilities.cpp.o -c /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/utilities.cpp

CMakeFiles/evolution.out.dir/src/utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evolution.out.dir/src/utilities.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/utilities.cpp > CMakeFiles/evolution.out.dir/src/utilities.cpp.i

CMakeFiles/evolution.out.dir/src/utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evolution.out.dir/src/utilities.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/utilities.cpp -o CMakeFiles/evolution.out.dir/src/utilities.cpp.s

CMakeFiles/evolution.out.dir/src/vectorTools.cpp.o: CMakeFiles/evolution.out.dir/flags.make
CMakeFiles/evolution.out.dir/src/vectorTools.cpp.o: ../src/vectorTools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/evolution.out.dir/src/vectorTools.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/evolution.out.dir/src/vectorTools.cpp.o -c /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/vectorTools.cpp

CMakeFiles/evolution.out.dir/src/vectorTools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evolution.out.dir/src/vectorTools.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/vectorTools.cpp > CMakeFiles/evolution.out.dir/src/vectorTools.cpp.i

CMakeFiles/evolution.out.dir/src/vectorTools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evolution.out.dir/src/vectorTools.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/vectorTools.cpp -o CMakeFiles/evolution.out.dir/src/vectorTools.cpp.s

CMakeFiles/evolution.out.dir/src/veichle.cpp.o: CMakeFiles/evolution.out.dir/flags.make
CMakeFiles/evolution.out.dir/src/veichle.cpp.o: ../src/veichle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/evolution.out.dir/src/veichle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/evolution.out.dir/src/veichle.cpp.o -c /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/veichle.cpp

CMakeFiles/evolution.out.dir/src/veichle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evolution.out.dir/src/veichle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/veichle.cpp > CMakeFiles/evolution.out.dir/src/veichle.cpp.i

CMakeFiles/evolution.out.dir/src/veichle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evolution.out.dir/src/veichle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/src/veichle.cpp -o CMakeFiles/evolution.out.dir/src/veichle.cpp.s

# Object files for target evolution.out
evolution_out_OBJECTS = \
"CMakeFiles/evolution.out.dir/src/main.cpp.o" \
"CMakeFiles/evolution.out.dir/src/randomTools.cpp.o" \
"CMakeFiles/evolution.out.dir/src/utilities.cpp.o" \
"CMakeFiles/evolution.out.dir/src/vectorTools.cpp.o" \
"CMakeFiles/evolution.out.dir/src/veichle.cpp.o"

# External object files for target evolution.out
evolution_out_EXTERNAL_OBJECTS =

evolution.out: CMakeFiles/evolution.out.dir/src/main.cpp.o
evolution.out: CMakeFiles/evolution.out.dir/src/randomTools.cpp.o
evolution.out: CMakeFiles/evolution.out.dir/src/utilities.cpp.o
evolution.out: CMakeFiles/evolution.out.dir/src/vectorTools.cpp.o
evolution.out: CMakeFiles/evolution.out.dir/src/veichle.cpp.o
evolution.out: CMakeFiles/evolution.out.dir/build.make
evolution.out: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
evolution.out: /usr/lib/x86_64-linux-gnu/libsfml-network.so.2.5.1
evolution.out: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
evolution.out: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
evolution.out: CMakeFiles/evolution.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable evolution.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/evolution.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/evolution.out.dir/build: evolution.out

.PHONY : CMakeFiles/evolution.out.dir/build

CMakeFiles/evolution.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/evolution.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/evolution.out.dir/clean

CMakeFiles/evolution.out.dir/depend:
	cd /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/build /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/build /home/emanuele/Scrivania/università/Magistrale/secondo_semestre/advanced_c++/progettoCorso/build/CMakeFiles/evolution.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/evolution.out.dir/depend

