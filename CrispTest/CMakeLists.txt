set(TEST_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source")

file(GLOB_RECURSE TEST_SOURCE ${TEST_SOURCE_DIR}/*.cpp ${TEST_SOURCE_DIR}/*.h)

add_executable(CrispTest ${TEST_SOURCE})

target_link_libraries(CrispTest PRIVATE CrispCore)