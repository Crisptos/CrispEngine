set(TEST_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source")

file(GLOB_RECURSE TEST_SOURCE ${TEST_SOURCE_DIR}/*.cpp ${TEST_SOURCE_DIR}/*.h)

add_executable(CrispTest ${TEST_SOURCE})

target_link_libraries(CrispTest PRIVATE CrispCore)

# WIN32 Only: Copy SDL3.dll to CrispTest
if(WIN32)
    add_custom_command(TARGET CrispTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:CrispTest>
            $<TARGET_FILE_DIR:CrispTest>
        COMMENT "Copying all needed runtime DLLs"
    )
endif()