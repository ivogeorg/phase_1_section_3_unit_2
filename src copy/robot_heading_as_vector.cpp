#include "robot_commander/robot_commander.h"
#include "ros/duration.h"
#include <ros/ros.h>
#include <string>

int main(int argc, char **argv) {
  ros::init(argc, argv, "heading_vector");

  RobotCommander my_robot;

  // command the robot to keep going in circles
  my_robot.move_in_circles();

  int total_values;
  std::cout << "Enter the number of heading values that you want to capture: ";
  // get user input from the keyboard
  std::cin >> total_values;

  // INSERT YOUR CODE BELOW THIS LINE
  std::vector<float> headings;
  float heading;
  for (int i = 0; i < total_values; ++i) {
    heading = my_robot.get_heading();
    std::cout << "Collecting heading value: " << heading << '\n';
    headings.push_back(heading);
    ros::Duration(1).sleep();
  }

  std::cout << "Displaying saved data\n";
  for (int i=0; i<headings.size(); ++i) {
    std::cout << "Heading value " << i << ": " << headings.at(i) << '\n';
  }
  // INSERT YOUR CODE ABOVE THIS LINE

  // stop the robot
  my_robot.stop_moving();

  return 0;
}