find_package(gflags REQUIRED)

file(GLOB SRCS *.cpp)

add_executable(hack_gflags ${SRCS})

target_include_directories(
	hack_gflags
	PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}
	${gflags_INCLUDE_DIR}
)

target_link_libraries(
	hack_gflags
	gflags
)
