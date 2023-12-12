cmake_minimum_required(VERSION 3.21)

set(PATCH_VERSION 1 CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project("print_ip" VERSION ${PROJECT_VESRION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_subdirectory(libs)

add_executable(${PROJECT_NAME})
add_executable(print_ip_tests
    tests/print_ip_output.cpp
)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
)

target_include_directories(print_ip_tests 
    PRIVATE 
        ${GTEST_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        PrintIP)
target_link_libraries(print_ip_tests 
    PRIVATE 
        ${GTEST_BOTH_LIBRARIES} PrintIP)

if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic)
    target_compile_options(print_ip_tests PRIVATE -Wall -Wextra -Werror -pedantic)
endif()

# generate deb
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()
add_test(NAME print_ip_tests COMMAND print_ip_tests)