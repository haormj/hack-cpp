project(hack_protobuf)

find_package(Protobuf REQUIRED)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/person.prototxt"
    "${CMAKE_CURRENT_BINARY_DIR}/person.prototxt"
    COPYONLY
)

file(GLOB PROTO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/proto/*)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

file(GLOB SRCS *.cpp)

add_executable(
	${PROJECT_NAME}
	${PROTO_SRCS}
	${SRCS}
)

target_include_directories(
	${PROJECT_NAME}
	PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	protobuf::libprotobuf
)