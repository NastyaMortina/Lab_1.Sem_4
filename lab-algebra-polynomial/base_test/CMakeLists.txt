set(target polynom_test)

#file(GLOB hdrs "*.h*" "../base/*.h" "../gtest/*.h")
file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp" "../base/polynom.cpp")

#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest)
