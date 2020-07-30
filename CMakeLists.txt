cmake_minimum_required(VERSION 3.0.2)
project(aescape_gazebo)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rviz
  tf
  urdf
  xacro
  sensor_msgs
  message_generation
  geometry_msgs
  aescape_control)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

################################################
## Declare ROS messages, services and actions ##
################################################

add_message_files(
  # DIRECTORY msg
  FILES
  ArmGoal.msg)

generate_messages(
  DEPENDENCIES
  geometry_msgs
)
################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

###################################
## catkin specific configuration ##
###################################

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES aescape_gazebo
#  CATKIN_DEPENDS geometry_msgs roscpp rviz tf urdf xacro aescape_control
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

add_executable(DualCartesianMotionController_publisher src/DualCartesianMotionController_publisher.cpp)
target_link_libraries(DualCartesianMotionController_publisher ${catkin_LIBRARIES} ${std_msgs_LIBRARIES})

add_executable(RobotStatus_publisher src/RobotStatus_publisher.cpp)
target_link_libraries(RobotStatus_publisher ${catkin_LIBRARIES} ${std_msgs_LIBRARIES})
