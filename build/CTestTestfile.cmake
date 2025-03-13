# CMake generated Testfile for 
# Source directory: /home/roman/Work/test-repo
# Build directory: /home/roman/Work/test-repo/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[AllTests]=] "/home/roman/Work/test-repo/build/testproj")
set_tests_properties([=[AllTests]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/roman/Work/test-repo/CMakeLists.txt;20;add_test;/home/roman/Work/test-repo/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
