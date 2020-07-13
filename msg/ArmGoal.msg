# Goal sent to Helium Controller
# For purposes of commanding goals, pose should be with respect to arm base
Header header
geometry_msgs/Pose pose  # Position/Orientaiton of K frame, for command assume to be link0 frame
geometry_msgs/Wrench wrench
geometry_msgs/Pose EE_pose_K  # Position of K frame w.r.t EE frame
float64[] posture
float64[] K_x  # Gains for cartesian impedance [lx,ly,lz,rx,ry,rz] for axis in position control
float64[] K_x_force_control # Gains for cartesian impedance [lx,ly,lz,rx,ry,rz] for axis in force control
# If an axis is designated as position control, K_x_force_control gains are ignored and vice versa