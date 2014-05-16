#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cctype>

using namespace std;

struct Team {
  string name;
  int totalpoints, gamesplayed, wins, ties, losses, goaldiff, goalscore, goalagainst;
  Team(string name) : name(name), totalpoints(0), gamesplayed(0), wins(0), ties(0), losses(0), goaldiff(0), goalscore(0), goalagainst(0) {};
  bool operator< (const Team& team2) const {
    if (totalpoints == team2.totalpoints) {
      if (wins == team2.wins) {
	if (goaldiff == team2.goaldiff) {
	  if (goalscore == team2.goalscore) {
	    if (gamesplayed == team2.gamesplayed) {
	      string converted1 = "";
	      string converted2 = "";
	      for(int i = 0; i < name.size(); i++)
		converted1 += tolower(name[i]);
	      for(int i = 0; i < team2.name.size(); i++)
		converted2 += tolower(team2.name[i]);
	      return converted1 > converted2;
	    }
	    else
	      return gamesplayed > team2.gamesplayed;
	  }
	  else
	    return goalscore < team2.goalscore;
	}
	else 
	  return goaldiff < team2.goaldiff;
      }
      else
	return wins < team2.wins;
    }
    else
      return totalpoints < team2.totalpoints;
  };
};

std::ostream& operator<<(std::ostream& oss, const Team& team) {
    oss << team.name << " " << team.totalpoints << "p, " << team.gamesplayed << "g (" << team.wins << "-" << team.ties << "-" << team.losses <<"), " << team.goaldiff << "gd (" << team.goalscore << "-" << team.goalagainst << ")";
    return oss;
};

void processGame(vector<Team>& teams, string game) {
  string team1, team2;
  string goal1str, goal2str;
  string info1, info2;
  istringstream iss(game.c_str());
  getline(iss, info1, '@');
  getline(iss, info2, '@');
  istringstream iss1(info1.c_str());
  getline(iss1, team1, '#');
  getline(iss1, goal1str, '#');
  istringstream iss2(info2.c_str());
  getline(iss2, goal2str, '#');
  getline(iss2, team2, '#');
  Team * one, * two;
  for(int i = 0; i < teams.size(); i++) {
    if(teams[i].name == team1)
      one = &teams[i];
    if(teams[i].name == team2)
      two = &teams[i];
  }
  one->gamesplayed += 1;
  two->gamesplayed += 1;
  int goal1 = atoi(goal1str.c_str());
  int goal2 = atoi(goal2str.c_str());
  one->goalscore += goal1;
  one->goalagainst += goal2;
  one->goaldiff = one->goalscore - one->goalagainst;
  two->goalscore += goal2;
  two->goalagainst += goal1;
  two->goaldiff = two->goalscore - two->goalagainst;
  if (goal1 > goal2) {
    one->wins += 1;
    one->totalpoints += 3;
    two->losses += 1;
  }
  else if (goal1 < goal2) {
    one->losses += 1;
    two->wins += 1;
    two->totalpoints += 3;
  }
  else {
    one->ties += 1;
    two->ties += 1;
    one->totalpoints += 1;
    two->totalpoints += 1;
  }
}

int main() {
  int cases;
  cin >> cases >> ws;
  for(int i = 0 ; i < cases; i++) {
    if (i != 0)
      cout << endl;
    string tournament;
    getline(cin, tournament);
    int teamcount;
    cin >> teamcount >> ws;
    vector<Team> teams;
    for(int j = 0; j < teamcount; j++) {
      string teamname;
      getline(cin, teamname);
      teams.push_back(Team(teamname));
    }
    int games;
    cin >> games >> ws;
    for(int j = 0 ;j < games; j++) {
      string game;
      getline(cin, game);
      processGame(teams, game);
    }
    sort(teams.begin(), teams.end());
    cout << tournament << endl;
    for(int j = 0; j < teams.size(); j++) {
      cout << j+1 << ") " << teams[teams.size() - 1 - j] << endl;;
    }
  }
  return 0;
}
