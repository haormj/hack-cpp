project(hack_preprocessing)

add_compile_definitions(
	OS=linux
	ARCH=amd64
)

file(GLOB SRCS *.cpp)

add_executable(${PROJECT_NAME} ${SRCS})
