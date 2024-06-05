set(CMAKE_CXX_STANDARD 11)

function(add_subdirectories dir)
    file(GLOB entries "./*")
    foreach(entry ${entries})
        if(IS_DIRECTORY ${entry})
            # 检查目录下是否有 CMakeLists.txt 文件
            if(EXISTS ${entry}/CMakeLists.txt)
                # 添加子目录
                add_subdirectory(${entry})
            endif()
        endif()
    endforeach()
endfunction()

# 在主目录中调用函数，传入主目录路径
add_subdirectories(${CMAKE_CURRENT_SOURCE_DIR})