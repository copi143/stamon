file(GLOB_RECURSE ast_cpp_files "ast/*.cpp")
add_executable(stamon Main.cpp ${ast_cpp_files})
compressing_binary(stamon)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
        file(TO_NATIVE_PATH "${PROJECT_SOURCE_DIR}/src/bin-include" src)
        if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
            file(TO_NATIVE_PATH "${EXECUTABLE_OUTPUT_PATH}/include" tgt)
            add_custom_command(TARGET stamon POST_BUILD
                COMMAND Xcopy "${src}" "${tgt}" /s /e /i
            )
        else()
            file(TO_NATIVE_PATH "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_BUILD_TYPE}/include" tgt)
            add_custom_command(TARGET stamon POST_BUILD
                COMMAND Xcopy "${src}" "${tgt}" /s /e /i
            )
        endif()
else()
    add_custom_command(TARGET stamon POST_BUILD
        COMMAND cp -r -T "${PROJECT_SOURCE_DIR}/src/bin-include" "${EXECUTABLE_OUTPUT_PATH}/include"
    )
endif()