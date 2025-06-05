set(CORE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")

file(GLOB_RECURSE CORE_SOURCE ${CORE_SOURCE_DIR}/*.cpp ${CORE_SOURCE_DIR}/*.h)

add_library(CrispCore STATIC ${CORE_SOURCE})

target_include_directories(CrispCore PUBLIC ${CORE_SOURCE_DIR})