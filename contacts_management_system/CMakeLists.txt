cmake_minimum_required(VERSION 3.22)
project(ContactsManagementSystem)

set(CMAKE_CXX_STANDARD 11)

include_directories(inc)

add_executable(LearningCPP
        src/contacts_management_system.cpp
        src/main.cpp)