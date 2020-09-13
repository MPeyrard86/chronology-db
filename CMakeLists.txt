cmake_minimum_required(VERSION 3.17)
project(chronology_db)

include_directories(C:/MinGW/include)
link_directories(C:/MinGW/lib)

add_executable(chronology_db src/main.cpp)

add_definitions(-DBOOST_NO_AUTO_PTR=1)
add_definitions(-DBOOST_NO_CXX11_SCOPED_ENUMS=1)

set(CMAKE_CXX_STANDARD 20)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost COMPONENTS log_setup log system filesystem locale)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(chronology_db ${Boost_LIBRARIES})
endif()

# Add core sources
add_subdirectory(src)
