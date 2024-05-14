#include "robot_commander/robot_commander.h"
#include "ros/ros.h"
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(int argc, char **argv) {
    ros::init(argc, argv, "polygon_vertices");

    RobotCommander robot;

    map<int, pair<float, float>> vertices;

    int i = 0;
    vertices[++i] = make_pair(robot.get_x_position(), robot.get_y_position());
    robot.move_forward(2);
    vertices[++i] = make_pair(robot.get_x_position(), robot.get_y_position());
    robot.turn(0.3, 4);
    vertices[++i] = make_pair(robot.get_x_position(), robot.get_y_position());
    robot.move_forward(7);
    vertices[++i] = make_pair(robot.get_x_position(), robot.get_y_position());
    robot.turn(0.2, 3);
    vertices[++i] = make_pair(robot.get_x_position(), robot.get_y_position());
    robot.move_forward(3);
    vertices[++i] = make_pair(robot.get_x_position(), robot.get_y_position());
    robot.turn(0.2, 3);
    vertices[++i] = make_pair(robot.get_x_position(), robot.get_y_position());
    robot.move_forward(3);
    vertices[++i] = make_pair(robot.get_x_position(), robot.get_y_position());
    robot.stop_moving();

    cout << vertices.size() << " vertices recorded:\n";
    for (auto vertex: vertices) {
        cout << "(" << vertex.second.first << ", " << vertex.second.second << ") -> " << vertex.first << '\n';    
    }

    return 0;
}