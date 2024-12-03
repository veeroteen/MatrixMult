# CMakeList.txt : CMake project for MatrixMult, include source and define
# project specific logic here.
#

cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

add_compile_options("-O1")
project ("MatrixMult")
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Timer)


# Add source to this project's executable.
add_executable (MatrixMult "main.cpp" "Matrix/MatrixMult.h" "Matrix/MatrixA.cpp" "Matrix/MatrixV.cpp" "Matrix/MatrixVR.cpp" "Matrix/Converters.cpp" "Matrix/MatrixAR.cpp")

