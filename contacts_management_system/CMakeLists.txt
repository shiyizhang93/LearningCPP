cmake_minimum_required(VERSION 3.10)
project(ContactsManagementSystem)

set(CMAKE_CXX_STANDARD 11)

include_directories(inc)

add_executable(contacts_management_system
        src/contacts_management_system.cpp
        src/main.cpp)