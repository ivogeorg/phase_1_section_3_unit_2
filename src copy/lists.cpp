#include <forward_list>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {

  list<string> laser{"range_max", "range_min", "angle_max", "angle_min"};

  list<string>::iterator front_iter = laser.begin();
  list<string>::iterator end_iter = laser.end();

  cout << *front_iter << '\n';
  advance(front_iter, 2);
  cout << *front_iter << '\n';
  advance(end_iter, -3);
  cout << *end_iter << '\n';

  forward_list<string> fwd_laser{"range_max", "range_min", "angle_max",
                                 "angle_min"};

  auto fwd_front_iter = fwd_laser.begin();
  auto fwd_end_iter = fwd_laser.end();

  cout << *fwd_front_iter << '\n';
  advance(fwd_front_iter, 2);
  cout << *fwd_front_iter << '\n';
  advance(fwd_end_iter, -3); // Seg fault!
  cout << *fwd_end_iter << '\n';

  return 0;
}