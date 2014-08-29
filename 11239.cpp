#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Project {
  string name;
  int number;
  Project(string s, int n) : name(s), number(n) {};
  bool operator<(const Project& second) const {
    if(number > second.number)
      return true;
    else if (number == second.number)
      return name < second.name;
    else
      return false;
  };
};

void printMap(map<string, set<string> >& signup) {
  vector<Project> projects;
  for(map<string, set<string> >::iterator itr = signup.begin(); itr != signup.end(); itr++) {
    Project eachP(itr->first, itr->second.size());
    projects.push_back(eachP);
  }
  sort(projects.begin(), projects.end());
  for(int i = 0; i < projects.size(); i++)
    cout << projects[i].name << " " << projects[i].number << endl;
}

int main() {
  string line;
  bool reading = true;
  string project = "";
  map<string, set<string> > signup;
  map<string, string> studentInfo;
  while(true) {
    getline(cin, line);
    if(line == "0")
      break;
    else if(line == "1") {
      reading = false;
      printMap(signup);
      signup.clear();
      studentInfo.clear();
    }
    else if(line[0] >= 'A' && line[0] <= 'Z') {
      if(!reading) {
	reading = true;
      }
      project = line;
      set<string> newentry;
      signup[project] = newentry;
    }
    else {
      if(studentInfo.count(line) == 0) {
	set<string> newentry = signup[project];
	newentry.insert(line);
	signup[project] = newentry;
	studentInfo[line] = project;
      }
      else {
	string origproj = studentInfo[line];
	if(origproj != project) {
	  set<string> newentry = signup[origproj];
	  if(newentry.count(line) != 0)
	    newentry.erase(newentry.find(line));
	  signup[origproj] = newentry;
	}
      }
    }
  }
  return 0;
}
