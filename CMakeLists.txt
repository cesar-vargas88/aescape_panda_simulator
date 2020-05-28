cmake_minimum_required(VERSION 3.0.2)
project(aescape_panda_simulator)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rviz
  tf
  urdf
  xacro)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

################################################
## Declare ROS messages, services and actions ##
################################################

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

###################################
## catkin specific configuration ##
###################################

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES aescape_panda_simulator
#  CATKIN_DEPENDS geometry_msgs roscpp rviz tf urdf xacro
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

#################
## Demo plugin ##
#################

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(model_push SHARED plugins/model_push.cc)
target_link_libraries(model_push ${GAZEBO_LIBRARIES})

add_executable(JointGroupPositionController_publisher src/JointGroupPositionController_publisher.cpp)
target_link_libraries(JointGroupPositionController_publisher ${catkin_LIBRARIES} ${std_msgs_LIBRARIES})

add_executable(JointStateController_subscriber src/JointStateController_subscriber.cpp)
target_link_libraries(JointStateController_subscriber ${catkin_LIBRARIES} ${std_msgs_LIBRARIES})
