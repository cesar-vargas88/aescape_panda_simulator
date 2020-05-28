# aescape panda simulator 

A **Gazebo simulator** for the Franka Emika Panda robot with ROS interface.

## Features

- ros_control *controllers* (joint position, velocity, torque) available that can be controlled through ROS topics.
- Real-time *robot state* (joint state) available through ROS topics.

### Dependencies

cartesian_controllers install from source https://github.com/cesar-vargas88/cartesian_controllers.git

### Installation

1.Clone the repo:

```bash
    cd <catkin_ws>/src
    git clone https://github.com/cesar-vargas88/aescape_panda_simulator.git
```

2.Install dependency packages:

```bash
    sudo apt-get install ros-melodic-ros-control ros-melodic-ros-controllers ros-melodic-controller-manager sudo apt install ros-melodic-joint-state-publisher-gui ros-melodic-gazebo-ros-pkgs ros-melodic-gazebo-ros-control
```

3.Once the dependencies are met, the package can be installed using catkin_make:

```bash
    echo "source /opt/ros/$ROS_DISTRO/setup.bash" >> ~/.bashrc
    catkin build # if catkin not found, install catkin tools (apt install python-catkin-tools)
    cd ..
    source devel/setup.bash
```

### Usage

The rviz can be started by running:

```bash
    roslaunch aescape_panda_simulator panda_rviz.launch
```

The gazebo simulator can be started by running:

```bash
    roslaunch aescape_panda_simulator panda_gazebo.launch
```

The JointGroupPositionController can be started by running:

```bash
    roslaunch aescape_panda_simulator panda_JointGroupPositionController.launch
```

#### Demos

- Run `roslaunch aescape_panda_simulator panda_JointGroupPositionController_example.launch` to run a demo for testing the JointGroupPositionController with the simulated robot. This script starts the simulator, rviz, the JointGroupPositionController and the JointGroupPositionController_publisher demo.

#### Some useful ROS topics

##### Published Topics

| ROS Topic | Data |
| ------ | ------ |
| */panda/joint_states* | joint positions, velocities, efforts |

##### Subscribed Topics

| ROS Topic | Data |
| ------ | ------ |
| */panda/joint_group_position_controller/command* | command the robot using the JointGroupPositionController |
