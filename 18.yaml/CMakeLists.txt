project(hack_yaml)

include(FetchContent)

FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG yaml-cpp-0.7.0 # Can be a tag (yaml-cpp-x.x.x), a commit hash, or a branch name (master)
)
FetchContent_GetProperties(yaml-cpp)

if(NOT yaml-cpp_POPULATED)
  message(STATUS "Fetching yaml-cpp...")
  FetchContent_Populate(yaml-cpp)
  add_subdirectory(${yaml-cpp_SOURCE_DIR} ${yaml-cpp_BINARY_DIR})
endif()
# find_package(yaml-cpp REQUIRED)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/config.yaml"
    "${CMAKE_CURRENT_BINARY_DIR}/config.yaml"
    COPYONLY
)

file(GLOB SRCS *.cpp)

add_executable(
	${PROJECT_NAME}
	${SRCS}
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	yaml-cpp::yaml-cpp
)