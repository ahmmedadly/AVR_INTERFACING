
# set cmake version
cmake_minimum_required(VERSION 3.12)

# to specify cmake to not compile based on OS 
set(CMAKE_SYSTEM_NAME Generic)

#set project
project(Task3 C)

# include directories
set(${PROJECT_NAME}_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc" "${CMAKE_CURRENT_SOURCE_DIR}/../MCAL/port/inc" "${CMAKE_CURRENT_SOURCE_DIR}/../MCAL/dio/inc")

# To get all files .c inside the directory mentioned :: you can use GLOB_RECURSE to loop inside directories   
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Task3.c")

set(MCAL_LIBS
    port
    dio
    
)

# just for debugging
message(STATUS "${${PROJECT_NAME}_SOURCES}")
message(STATUS "${CMAKE_C_COMPILER}")

foreach(var ${MCAL_LIBS})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../MCAL/${var}/ "${CMAKE_BINARY_DIR}/${var}/")

endforeach()

# call dio cmake to generate library and get the target
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../Components/MCAL/Dio/ ${CMAKE_BINARY_DIR}/Dio)

# Set compiler flag after sub directories
set(CMAKE_C_COMPILER "/usr/bin/avr-gcc")

# library target
add_executable(${PROJECT_NAME} "${${PROJECT_NAME}_SOURCES}")

# include directory to the target
target_include_directories(${PROJECT_NAME} PUBLIC "${${PROJECT_NAME}_INCLUDE_DIR}")
target_link_libraries(${PROJECT_NAME} ${MCAL_LIBS})

add_custom_target(
    avr-hex
    COMMAND avr-objcopy -O ihex ${PROJECT_NAME} ${PROJECT_NAME}.hex
    DEPENDS ${PROJECT_NAME}
)

# add_dependencies(avr-hex ${PROJECT_NAME})

