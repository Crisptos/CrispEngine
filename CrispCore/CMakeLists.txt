include(FetchContent)

FetchContent_Declare(
	spdlog
	GIT_REPOSITORY https://github.com/gabime/spdlog.git
	GIT_TAG v1.15.3
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(spdlog)

set(SDL_TEST OFF CACHE BOOL "" FORCE)                  # Disable SDL test suite
set(SDL_INSTALL_TESTS OFF CACHE BOOL "" FORCE)         # Disable install of tests

FetchContent_Declare(
	SDL3
	GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
	GIT_TAG release-3.2.16
	GIT_SHALLOW TRUE
	EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(SDL3)

set(CORE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source")

file(GLOB_RECURSE CORE_SOURCE ${CORE_SOURCE_DIR}/*.cpp ${CORE_SOURCE_DIR}/*.h)

add_library(CrispCore STATIC ${CORE_SOURCE})

target_include_directories(CrispCore PUBLIC ${CORE_SOURCE_DIR})

target_link_libraries(CrispCore spdlog::spdlog SDL3::SDL3)