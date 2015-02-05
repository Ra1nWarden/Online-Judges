#include <iostream>
#include <sstream>

using namespace std;

bool findCross(string hor, string ver, pair<int, int>* result) {
  for(int i = 0; i < hor.length(); i++) {
    for(int j = 0; j < ver.length(); j++) {
      if(hor[i] == ver[j]) {
	result->first = i;
	result->second = j;
	return true;
      }
    }
  }
  return false;
}

int main() {
  string line;
  bool init = true;
  while(getline(cin, line)) {
    if(line[0] == '#')
      break;
    if(!init)
      cout << endl;
    stringstream ss(line.c_str());
    string hor1, ver1, hor2, ver2;
    ss >> hor1 >> ver1 >> hor2 >> ver2;
    pair<int, int> one, two;
    if(findCross(hor1, ver1, &one) && findCross(hor2, ver2, &two)) {
      int fg = one.first;
      string firstgap = "";
      for(int i = 0; i < fg; i++)
	firstgap += " ";
      int sg = hor1.length() - fg - 1 + 3 + two.first;
      string secondgap = "";
      for(int i = 0; i < sg; i++)
	secondgap += " ";
      bool firstlonger1 = one.second > two.second;
      bool firstlonger2 = ver1.length() - one.second > ver2.length() - two.second;

      int vg1 = firstlonger1 ? one.second - two.second : two.second - one.second;
      int vg2 = max(one.second, two.second);
      vg2 += firstlonger2 ? (ver2.length() - two.second) : (ver1.length() - one.second);
      int vg3 = max(one.second, two.second);
      vg3 += firstlonger2 ? (ver1.length() - one.second) : (ver2.length() - two.second);

      for(int i = 0; i < vg3; i++) {
	if(i < vg1) {
	  if(firstlonger1)
	    cout << firstgap << ver1[i] << endl;
	  else
	    cout << firstgap << " " << secondgap << ver2[i] << endl;
	} else if(i < vg2) {
	  if(i == max(one.second, two.second))
	    cout << hor1 << "   " << hor2 << endl;
	  else {
	    if(firstlonger1)
	      cout << firstgap << ver1[i] << secondgap << ver2[i - vg1] << endl;
	    else
	      cout << firstgap << ver1[i - vg1] << secondgap << ver2[i] << endl;
	  }
	} else {
	  if(firstlonger2) {
	    if(firstlonger1)
	      cout << firstgap << ver1[i] << endl;
	    else
	      cout << firstgap << ver1[i - vg1] << endl;
	  } else {
	    if(firstlonger1)
	      cout << firstgap << " " << secondgap << ver2[i - vg1] << endl;
	    else
	      cout << firstgap << " " << secondgap << ver2[i] << endl;
	  }
	}
      }
    } else {
      cout << "Unable to make two crosses" << endl;
    }
    init = false;
  }
  return 0;
}
