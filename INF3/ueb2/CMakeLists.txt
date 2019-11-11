cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(ueb2)

add_executable(
    ueb2	
    main.cpp
    CDate.cpp
    CDate.h
    CTime.cpp
    CTime.h
    CMoney.cpp
    CMoney.h
    CAddress.cpp
    CAddress.h
    CCustomer.cpp
    CCustomer.h
    CAccount.cpp
    CAccount.h	
    )
