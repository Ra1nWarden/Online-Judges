#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

// str in hh:mm:ss
double getTimeInSecond(string& str) {
  string hour = str.substr(0, 2);
  string minute = str.substr(3, 2);
  string second = str.substr(6, 2);
  double h, m, s;
  h = (double) atoi(hour.c_str());
  m = (double) atoi(minute.c_str());
  s = (double) atoi(second.c_str());
  return 3600 * h + 60 * m + s;
}

int main() {
  string line;
  vector<string> lines;
  while(true) {
    getline(cin, line);
    if (!cin)
      break;
    lines.push_back(line);
  }
  double distance = 0;
  double speed = 0;
  double time = 0; // in second
  for(vector<string>::iterator itr = lines.begin(); itr != lines.end(); itr++) {
    if (itr == lines.begin()) {
      if (itr->length() < 10) {
	time = getTimeInSecond(*itr);
	printf("%s %.2f km\n", itr->c_str(), distance);
      }
      else {
	string timepart = itr->substr(0, 8);
	time = getTimeInSecond(timepart);
	speed = (double) atoi(itr->substr(9).c_str());
      }
    }
    else {
      if (itr->length() < 10) {
	double newtime = getTimeInSecond(*itr);
	double elapsed = newtime - time;
	double distance_travel = elapsed * speed / 3600;
	distance += distance_travel;
	time += elapsed;
	printf("%s %.2f km\n", itr->c_str(), distance);
      }
      else {
	string timepart = itr->substr(0, 8);
	double newtime = getTimeInSecond(timepart);
	double elapsed = newtime - time;
	double distance_travel = elapsed * speed / 3600;
	distance += distance_travel;
	time += elapsed;
	speed = (double) atoi(itr->substr(9).c_str());
      }
    }
  }
  return 0;
}
