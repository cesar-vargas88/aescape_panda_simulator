#!/usr/bin/env bash
echo "Commadn to test that collisions elements are well done for bumber plugin"
cd ../urdf/
pwd
ls
rosrun xacro xacro --inorder robot.urdf.xacro > robot.urdf
gz sdf -p robot.urdf > robot.sdf