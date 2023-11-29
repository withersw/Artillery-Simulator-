cmake_minimum_required(VERSION 3.26)
project(230_07_Lab_GLDemo__1_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

find_package(OpenGL REQUIRED)

add_executable(230_07_Lab_GLDemo__1_
        acceleration.cpp
        acceleration.h
        ground.cpp
        ground.h
        Lab07.cpp
        position.cpp
        position.h
        test.cpp
        test.h
        testGround.h
        testPosition.h
        uiDraw.cpp
        uiDraw.h
        uiInteract.cpp
        uiInteract.h
        angle.h
        angle.cpp
        testAcceleration.h
        velocity.h
        velocity.cpp
        testVelocity.h)

target_link_libraries(230_07_Lab_GLDemo__1_ OpenGL::GL)

target_link_libraries(230_07_Lab_GLDemo__1_ "-framework GLUT")