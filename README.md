# aescape panda simulator 

A **Gazebo simulator** for the Franka Emika Panda robot with ROS interface.

## Features

- ros_control *controllers* (cartesian_motion_controller) available that can be controlled through ROS topics.
- Real-time *robot state* (joint state) available through ROS topics.

### Dependencies

cartesian_controllers install from source https://github.com/cesar-vargas88/cartesian_controllers.git

### Installation

1.Clone the repo:

```bash
    cd <catkin_ws>/src
    git clone --branch franka_panda https://github.com/cesar-vargas88/cartesian_controllers.git
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

#### Some useful ROS topics

##### Published Topics

| ROS Topic | Data |
| ------ | ------ |
| */panda/joint_states* | joint positions, velocities, efforts |

##### Subscribed Topics

| ROS Topic | Data |
| ------ | ------ |
| */panda/cartesian_motion_controller/target_frame* | command the robot PoseStamped using the cartesian_motion_controller |
