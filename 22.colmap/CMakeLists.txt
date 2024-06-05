project(hack_colmap)

cmake_minimum_required(VERSION 3.25)

find_package(COLMAP REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Glog REQUIRED)
find_package(OpenMP REQUIRED)

file(GLOB SRCS *.cpp)

add_executable(
	${PROJECT_NAME}
	${SRCS}
)

target_link_libraries(
	${PROJECT_NAME}
	colmap::colmap
    Eigen3::Eigen
    glog::glog
	OpenMP::OpenMP_CXX
)