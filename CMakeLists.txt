cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Stamon VERSION 2.4.4)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/stdc_imp)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(CMAKE_C_FLAGS_DEBUG "-g -Og -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Og -DDEBUG")

set(CMAKE_C_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "-std=c17")
    set(CMAKE_CXX_FLAGS "-std=c++11")

    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -march=native")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native")
endif()

include(cmake/compressing_binary) 
include(cmake/show-flags) 
include(cmake/mklib)
include(cmake/mkheader)

add_subdirectory(include/stamon)
add_subdirectory(src)
# add_subdirectory(test) # 暂时取消 test

# if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
#         if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
#             set(stamon_binary ${EXECUTABLE_OUTPUT_PATH}/stamon.exe)
#             set(test_binary ${EXECUTABLE_OUTPUT_PATH}/stamon-test.exe)
#         else()
#             set(stamon_binary ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_BUILD_TYPE}/stamon.exe)
#             set(test_binary ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_BUILD_TYPE}/stamon-test.exe)
#         endif()
# else()
#     set(stamon_binary ${EXECUTABLE_OUTPUT_PATH}/stamon)
#     set(test_binary ${EXECUTABLE_OUTPUT_PATH}/stamon-test)
# endif()

# add_test(NAME stamon
#     COMMAND ${stamon_binary} build code.st code.stvc
# )

# add_test(NAME test
#     COMMAND ${test_binary}
# )
