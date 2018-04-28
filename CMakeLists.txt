CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
project(openssl_rsa)

#Bring the headers, such as Student.h into the project
include_directories(include)
 
#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
add_executable(openssl_rsa ${SOURCES})

target_link_libraries(openssl_rsa
    crypto
)