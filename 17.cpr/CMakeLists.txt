project(hack_cpr)

find_package(cpr REQUIRED)

file(GLOB SRCS *.cpp)

add_executable(
	${PROJECT_NAME}
	${PROTO_SRCS}
	${SRCS}
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	cpr::cpr
)