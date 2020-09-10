cmake_minimum_required(VERSION 3.17)
project(chronology_db)

include_directories(C:/MinGW/include)
link_directories(C:/MinGW/lib)

add_definitions(-DBOOST_NO_AUTO_PTR=1)
set(CMAKE_CXX_STANDARD 20)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost COMPONENTS locale)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(chronology_db main.cpp app/chronology_configuration.cpp app/chronology_configuration.h)
    target_link_libraries(chronology_db ${Boost_LIBRARIES})
endif()

