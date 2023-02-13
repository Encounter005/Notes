cmake_minimum_required(VERSION 3.5)

project(Example LANGUAGE CXX VERSION 0.1.9.0)

# NOTE : project( Example --项目名称 LANGUAGE CXX -- 使用的编程语言 VERSION 0.1.9.0 # Major, Minar , Patch, Tweak 版本号 )

# NOTE : 设置C++标准
set(CMAKE_CXX+STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

configure_file(Configure.h.in Configure.h)

# NOTE : 设置可执行文件怎样去生成
add_executable(Myadd main.cpp)

# NOTE : add_executable(项目名字 源码名称)
