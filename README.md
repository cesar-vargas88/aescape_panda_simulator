# aescape panda simulator 

A **Gazebo simulator** for the Franka Emika Panda robot with ROS interface.

## Features

- ros_control *controllers* (cartesian_motion_controller) available that can be controlled through ROS topics.
- Real-time *robot states* (joint_states franka_states transformed_world) available through ROS topics.

### Dependencies

- cartesian_controllers install from source https://github.com/cesar-vargas88/cartesian_controllers.git
- libfranka (sudo apt install ros-${ROS_DISTRO}-libfranka or install from source)
- franka-ros (sudo apt install ros-${ROS_DISTRO}-franka-ros or install from source)


### Installation

1.Clone the repo:

```bash
    cd <catkin_ws>/src
    git clone --branch franka_state_controller https://gitlab.com/aescape/cartesian_controllers.git
    git clone --branch cartesian_controller https://gitlab.com/aescape/aescape_gazebo.git
```

2.Install dependency packages:

```bash
    sudo apt-get install ros-melodic-ros-control ros-melodic-ros-controllers ros-melodic-controller-manager ros-melodic-joint-state-publisher-gui ros-melodic-gazebo-ros-pkgs ros-melodic-gazebo-ros-control
```

3.Once the dependencies are met, the package can be installed using catkin_make:

```bash
    echo "source /opt/ros/$ROS_DISTRO/setup.bash" >> ~/.bashrc
    catkin build # if catkin not found, install catkin tools (apt install python-catkin-tools)
    cd ..
    source devel/setup.bash
```

### Usage

The cartesian_publisher node can be started by running:

```bash
    roslaunch aescape_panda_simulator cartesian_publisher.launch
```

The use InteractiveMarkers to move robot EndEffector run:

```bash
    roslaunch aescape_panda_simulator cartesian_markers.launch
```

The dual_cartesian_publisher node can be started by running:

```bash
    roslaunch aescape_panda_simulator dual_cartesian_publisher.launch
```

The use InteractiveMarkers to move the robots EndEffector run:

```bash
    roslaunch aescape_panda_simulator dual_cartesian_markers.launch
```

#### Some useful ROS topics

##### Published Topics

| ROS Topic | Data |
| ------ | ------ |
| */panda/franka_state_controller/joint_states* | joint positions, velocities, efforts |
| */left/franka_state_controller/joint_states*  | joint positions, velocities, efforts |
| */right/franka_state_controller/joint_states* | joint positions, velocities, efforts |
| */panda/franka_state_controller/franka_states*  | franka_msgs::FrankaState |
| */left/franka_state_controller/franka_states*   | franka_msgs::FrankaState |
| */right/franka_state_controller/franka_states*  | franka_msgs::FrankaState |
| */panda/transformed_world* | geometry_msgs/WrenchStamped send it by the force sensor |
| */left/transformed_world*  | geometry_msgs/WrenchStamped send it by the force sensor |
| */right/transformed_world* | geometry_msgs/WrenchStamped send it by the force sensor |


##### Subscribed Topics

| ROS Topic |   Data  |
| --------- | --------|
| */panda/robot_goal* | geometry_msgs/PoseStamped command use by the cartesian_motion_controller |
| */left/robot_goal*  | geometry_msgs/PoseStamped command use by the cartesian_motion_controller |
| */right/robot_goal* | geometry_msgs/PoseStamped command use by the cartesian_motion_controller |
