#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

struct Contestant {
  int number, correct, time;
  map<int, int> tries;
  bool submitted;
  Contestant(int number) : number(number), correct(0), time(0), submitted(false) {};
  bool operator<(const Contestant& compare) const {
    if(correct == compare.correct) {
      if(time == compare.time) {
	return number < compare.number;
      }
      return time < compare.time;
    }
    return correct > compare.correct;
  };
};

ostream& operator<<(ostream& oss, const Contestant& con) {
  oss << con.number + 1 << " " << con.correct << " " << con.time;
  return oss;
}

int main() {
  int cases;
  cin >> cases >> ws;
  string line;
  for(int i = 0 ;i < cases; i++) {
    if(i != 0)
      cout << endl;
    vector<Contestant> contestants;
    for(int j = 0; j < 100; j++)
      contestants.push_back(Contestant(j));
    while(true) {
      if(!getline(cin, line))
	break;
      if(line == "")
	 break;
      istringstream iss(line.c_str());
      int contestant, problem, time;
      char judged;
      iss >> contestant >> problem >> time >> judged;
      Contestant * affected = &contestants[contestant - 1];
      affected->submitted = true;
      if (judged == 'I') {
	int prev = affected->tries[problem];
	if(prev > -1)
	  affected->tries[problem] = prev + 1;
      }
      else if (judged == 'C') {
	int prev = affected->tries[problem];
	if(prev > -1) {
	  affected->correct += 1;
	  affected->time += (time + prev * 20);
	  affected->tries[problem] = -1;
	}
      }
    }
    sort(contestants.begin(), contestants.end());
    for(int j = 0; j < contestants.size(); j++) {
      if(contestants[j].submitted)
	cout << contestants[j] << endl;
    }
  }
  return 0;
}
