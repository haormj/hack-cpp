project(hack_gflags)

find_package(gflags REQUIRED)

file(GLOB SRCS *.cpp)

add_executable(${PROJECT_NAME} ${SRCS})

target_include_directories(
	${PROJECT_NAME}
	PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}
	${gflags_INCLUDE_DIR}
)

target_link_libraries(
	${PROJECT_NAME}
	gflags
)
