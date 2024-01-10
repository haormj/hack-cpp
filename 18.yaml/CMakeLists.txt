project(hack_yaml)

find_package(yaml-cpp REQUIRED)

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