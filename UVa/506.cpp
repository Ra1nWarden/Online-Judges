#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

map<string, int> pm;
map<int, string> rpm;
map<int, int> im;
map<int, vector<int> > dm;
map<int, vector<int> > rdm;
vector<int> installs;
int idx;

void list_packages() {
  for(int i = 0; i < installs.size(); i++) {
    string pack = rpm[installs[i]];
    cout << "   " << pack << endl;
  }
}

void remove_package(int pi, bool direct) {
  if(im.count(pi) == 0 || im[pi] == 0) {
    if(direct)
      cout << "   " << rpm[pi] << " is not installed." << endl;
  } else {
    for(int i = 0; i < rdm[pi].size(); i++) {
      int pii = rdm[pi][i];
      if(im.count(pii) && im[pii] > 0) {
	if(direct) {
	  cout << "   " << rpm[pi] << " is still needed." << endl;
	}
	return;
      }
    }
    if(direct) {
      if(im[pi] == 2) {
	cout << "   " << rpm[pi] << " is still needed." << endl;
	return;
      }
      cout << "   Removing " << rpm[pi] << endl;
      installs.erase(find(installs.begin(), installs.end(), pi));
      im[pi] = 0;
      if(dm.count(pi)) {
      	for(int i = 0; i < dm[pi].size(); i++) {
	  remove_package(dm[pi][i], false);
	}
      }
    } else {
      if(im[pi] == 1)
	return;
      cout << "   Removing " << rpm[pi] << endl;
      installs.erase(find(installs.begin(), installs.end(), pi));
      im[pi] = 0;
      if(dm.count(pi)) {
      	for(int i = 0; i < dm[pi].size(); i++) {
	  remove_package(dm[pi][i], false);
	}
      }
    }
  }
}

void install_package(int pi, bool direct) {
  if(im.count(pi) && im[pi] > 0) {
    if(direct)
      cout << "   " << rpm[pi] << " is already installed." << endl;
    return;
  }
  if(dm.count(pi)) {
    for(int i = 0; i < dm[pi].size(); i++) {
      install_package(dm[pi][i], false);
    }
  }
  if(direct)
    im[pi] = 1;
  else
    im[pi] = 2;
  installs.push_back(pi);
  cout << "   Installing " << rpm[pi] << endl;
}

void add_dependency(string package, vector<string> deps) {
  if(pm.count(package) == 0) {
    pm[package] = idx;
    rpm[idx++] = package;
  }
  vector<int> depsi;
  for(int i = 0; i < deps.size(); i++) {
    if(pm.count(deps[i]) == 0) {
      pm[deps[i]] = idx;
      rpm[idx++] = deps[i];
    }
    depsi.push_back(pm[deps[i]]);
  }
  dm[pm[package]] = depsi;
  for(int i = 0; i < depsi.size(); i++) {
    int di = depsi[i];
    if(rdm.count(di) == 0) {
      vector<int> v;
      v.push_back(pm[package]);
      rdm[di] = v;
    } else {
      vector<int> v = rdm[di];
      v.push_back(pm[package]);
      rdm[di] = v;
    }
  }
}

int main() {
  idx = 0;
  string line;
  ios::sync_with_stdio(false);
  while(getline(cin, line)) {
    cout << line << endl;
    stringstream ss(line.c_str());
    string inst;
    ss >> inst;
    if(inst == "LIST") {
      list_packages();
    } else if(inst == "REMOVE") {
      string package;
      ss >> package;
      if(pm.count(package) == 0) {
	pm[package] = idx;
	rpm[idx++] = package;
      }
      remove_package(pm[package], true);
    } else if(inst == "INSTALL") {
      string package;
      ss >> package;
      if(pm.count(package) == 0) {
	pm[package] = idx;
	rpm[idx++] = package;
      }
      install_package(pm[package], true);
    } else if(inst == "DEPEND") {
      vector<string> deps;
      string package;
      string target;
      ss >> target;
      while(ss >> package) {
	deps.push_back(package);
      }
      add_dependency(target, deps);
    } else {
      break;
    }
  }
  return 0;
}
