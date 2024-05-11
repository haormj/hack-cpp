project(hack_struct)

file(GLOB SRCS *.cpp)

add_executable(
	${PROJECT_NAME}
	${SRCS}
)