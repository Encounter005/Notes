cmake_minimum_required(VERSION 3.5)

project(project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    main.cpp
    Array.h
    Array.hpp
    List.h
    List.hpp
    Queue.h
    Queue.hpp
    Stack.h
    Stack.hpp
    StrVec.h
    StrVec.cpp
)
