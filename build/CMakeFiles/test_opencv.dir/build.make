# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leon/Projects/Almond

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leon/Projects/Almond/build

# Include any dependencies generated for this target.
include CMakeFiles/test_opencv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_opencv.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_opencv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_opencv.dir/flags.make

CMakeFiles/test_opencv.dir/main.cpp.o: CMakeFiles/test_opencv.dir/flags.make
CMakeFiles/test_opencv.dir/main.cpp.o: /home/leon/Projects/Almond/main.cpp
CMakeFiles/test_opencv.dir/main.cpp.o: CMakeFiles/test_opencv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/leon/Projects/Almond/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_opencv.dir/main.cpp.o"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_opencv.dir/main.cpp.o -MF CMakeFiles/test_opencv.dir/main.cpp.o.d -o CMakeFiles/test_opencv.dir/main.cpp.o -c /home/leon/Projects/Almond/main.cpp

CMakeFiles/test_opencv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_opencv.dir/main.cpp.i"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leon/Projects/Almond/main.cpp > CMakeFiles/test_opencv.dir/main.cpp.i

CMakeFiles/test_opencv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_opencv.dir/main.cpp.s"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leon/Projects/Almond/main.cpp -o CMakeFiles/test_opencv.dir/main.cpp.s

CMakeFiles/test_opencv.dir/imgproc.cpp.o: CMakeFiles/test_opencv.dir/flags.make
CMakeFiles/test_opencv.dir/imgproc.cpp.o: /home/leon/Projects/Almond/imgproc.cpp
CMakeFiles/test_opencv.dir/imgproc.cpp.o: CMakeFiles/test_opencv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/leon/Projects/Almond/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_opencv.dir/imgproc.cpp.o"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_opencv.dir/imgproc.cpp.o -MF CMakeFiles/test_opencv.dir/imgproc.cpp.o.d -o CMakeFiles/test_opencv.dir/imgproc.cpp.o -c /home/leon/Projects/Almond/imgproc.cpp

CMakeFiles/test_opencv.dir/imgproc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_opencv.dir/imgproc.cpp.i"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leon/Projects/Almond/imgproc.cpp > CMakeFiles/test_opencv.dir/imgproc.cpp.i

CMakeFiles/test_opencv.dir/imgproc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_opencv.dir/imgproc.cpp.s"
	/usr/bin/g++-12 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leon/Projects/Almond/imgproc.cpp -o CMakeFiles/test_opencv.dir/imgproc.cpp.s

# Object files for target test_opencv
test_opencv_OBJECTS = \
"CMakeFiles/test_opencv.dir/main.cpp.o" \
"CMakeFiles/test_opencv.dir/imgproc.cpp.o"

# External object files for target test_opencv
test_opencv_EXTERNAL_OBJECTS =

test_opencv: CMakeFiles/test_opencv.dir/main.cpp.o
test_opencv: CMakeFiles/test_opencv.dir/imgproc.cpp.o
test_opencv: CMakeFiles/test_opencv.dir/build.make
test_opencv: /usr/local/lib/libopencv_gapi.so.4.12.0
test_opencv: /usr/local/lib/libopencv_highgui.so.4.12.0
test_opencv: /usr/local/lib/libopencv_ml.so.4.12.0
test_opencv: /usr/local/lib/libopencv_objdetect.so.4.12.0
test_opencv: /usr/local/lib/libopencv_photo.so.4.12.0
test_opencv: /usr/local/lib/libopencv_stitching.so.4.12.0
test_opencv: /usr/local/lib/libopencv_video.so.4.12.0
test_opencv: /usr/local/lib/libopencv_videoio.so.4.12.0
test_opencv: /usr/local/lib/libopencv_imgcodecs.so.4.12.0
test_opencv: /usr/local/lib/libopencv_dnn.so.4.12.0
test_opencv: /usr/local/lib/libopencv_calib3d.so.4.12.0
test_opencv: /usr/local/lib/libopencv_features2d.so.4.12.0
test_opencv: /usr/local/lib/libopencv_flann.so.4.12.0
test_opencv: /usr/local/lib/libopencv_imgproc.so.4.12.0
test_opencv: /usr/local/lib/libopencv_core.so.4.12.0
test_opencv: CMakeFiles/test_opencv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/leon/Projects/Almond/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_opencv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_opencv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_opencv.dir/build: test_opencv
.PHONY : CMakeFiles/test_opencv.dir/build

CMakeFiles/test_opencv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_opencv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_opencv.dir/clean

CMakeFiles/test_opencv.dir/depend:
	cd /home/leon/Projects/Almond/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leon/Projects/Almond /home/leon/Projects/Almond /home/leon/Projects/Almond/build /home/leon/Projects/Almond/build /home/leon/Projects/Almond/build/CMakeFiles/test_opencv.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_opencv.dir/depend

