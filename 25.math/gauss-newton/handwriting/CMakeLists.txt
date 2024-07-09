project(hack-gn)

find_package(OpenCV REQUIRED)

file(GLOB SRCS *.cpp)

add_executable(
	${PROJECT_NAME}
	${SRCS}
)

target_include_directories(
	${PROJECT_NAME}
	PRIVATE 
	/opt/homebrew/include/eigen3/
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	${OpenCV_LIBS}
)
