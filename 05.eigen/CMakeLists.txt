add_executable(hack_eigen main.cpp)

target_include_directories(
	hack_eigen
	PRIVATE 
	/opt/homebrew/include/eigen3/
)