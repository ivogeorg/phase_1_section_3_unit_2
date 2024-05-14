#include "robot_commander/robot_commander.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_position_as_array");

  RobotCommander my_robot;

  float pos[3] = {
    my_robot.get_x_position(),
    my_robot.get_y_position(),
    my_robot.get_z_position()
  };

  for (auto p: pos)
    std::cout << p << " ";
  std::cout << '\n';
  
  return 0;
}
