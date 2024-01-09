project(hack_json)

find_package(nlohmann_json 3.2.0 REQUIRED)

file(GLOB SRCS *.cpp)

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	nlohmann_json::nlohmann_json
)