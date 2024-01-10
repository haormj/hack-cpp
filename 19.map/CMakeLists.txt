project(hack_map)

file(GLOB SRCS *.cpp)

add_executable(
	${PROJECT_NAME}
	${SRCS}
)