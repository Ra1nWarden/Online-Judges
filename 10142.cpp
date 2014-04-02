#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include <climits>

using namespace std;

pair<int, int> findMaxVote(vector<vector<int> > &votes) {
  vector<int> tally(votes[0].size(), 0);
  for(vector<vector<int> >::iterator itr = votes.begin(); itr != votes.end(); ++itr) {
    vector<int> vote = *itr;
    for(vector<int>::iterator nextitr = vote.begin(); nextitr != vote.end(); ++nextitr) {
      if(*nextitr != -1) {
	tally[*nextitr - 1]++;
	break;
      }
    }
  }
  // candidate + vote
  int maxvote = 0;
  int maxindex = -1;
  for(int i = 0; i < votes[0].size(); i++) {
    int currentvote = tally[i];
    if(currentvote > maxvote) {
      maxvote = currentvote;
      maxindex = i;
    }
  }
  pair<int, int> result;
  result.first = maxindex + 1;
  result.second = maxvote;
  return result;
}

bool contains(vector<int>& list, int number) {
  for(vector<int>::iterator itr = list.begin(); itr != list.end(); ++itr) {
    if(number == *itr)
      return true;
  }
  return false;
}

vector<int> eliminateWorst(vector<vector<int> >& votes, vector<int>& candidates) {
  vector<int> tally(votes[0].size(), 0);
  for(vector<vector<int> >::iterator itr = votes.begin(); itr != votes.end(); ++itr) {
    vector<int> vote = *itr;
    for(vector<int>::iterator nextitr = vote.begin(); nextitr != vote.end(); ++nextitr) {
      if(*nextitr != -1) {
	tally[*nextitr - 1]++;
	break;
      }
    }
  }
  vector<int> eliminatelist;
  int minvote = INT_MAX;
  for(int i = 0; i < votes[0].size(); i++) {
    if(contains(candidates, i+1)) {
      int currentvote = tally[i];
      if(currentvote < minvote) {
	minvote = currentvote;
	eliminatelist.clear();
	eliminatelist.push_back(i+1);
      }
      else if(currentvote == minvote)
	eliminatelist.push_back(i+1);
    }
  }
  for(vector<int>::iterator itr = eliminatelist.begin(); itr != eliminatelist.end(); ++itr) {
    int currenteliminate = *itr;
    for(vector<vector<int> >::iterator voteitr = votes.begin(); voteitr != votes.end(); ++voteitr) {
      for(vector<int>::iterator currentvote = voteitr->begin(); currentvote != voteitr->end(); ++currentvote) {
	if(*currentvote == currenteliminate) {
	  *currentvote = -1;
	  break;
	}
      }
    }
  }
  return eliminatelist;
}

void updateList(vector<int>& candidate, vector<int>& eliminate) {
  vector<int> result;
  for(vector<int>::iterator itr = candidate.begin(); itr != candidate.end(); ++itr) {
    int number = *itr;
    bool flag = true;
    for(vector<int>::iterator nextitr = eliminate.begin(); nextitr != eliminate.end(); ++nextitr) {
      if(*nextitr == number) {
	flag = false;
	break;
      }
    }
    if(flag)
      result.push_back(number);
  }
  candidate = result;
}



int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    cin >> ws;
    int total;
    cin >> total;
    cin >> ws;
    vector<string> candidate;
    for(int j = 0; j < total; j++) {
      string name;
      getline(cin, name);
      candidate.push_back(name);
    }
    vector<vector<int> > votes;
    while(!cin.eof()) {
      string line;
      getline(cin, line);
      if(line.empty())
	break;
      vector<int> ballot;
      istringstream iss (line.c_str());
      for(int j = 0; j < total; j++) {
	int vote;
	iss >> vote;
	ballot.push_back(vote);
      }
      votes.push_back(ballot);
    }
    vector<int> candidateindexlist;
    for(int i = 1; i <= total; i++)
      candidateindexlist.push_back(i);
    while(true) {
      if(votes.size() == 0) {
	for(vector<string>::iterator itr = candidate.begin(); itr != candidate.end(); ++itr)
	  cout << *itr << endl;
	break;
      }
      pair<int, int> winner = findMaxVote(votes);
      if(winner.second > (votes.size() / 2)) {
	cout << candidate[winner.first-1] << endl;
	break;
      }
      else {
	vector<int> eliminated = eliminateWorst(votes, candidateindexlist);
	if(eliminated.size() == candidateindexlist.size()) {
	  for(vector<int>::iterator itr = eliminated.begin(); itr != eliminated.end(); ++itr)
	    cout << candidate[*itr - 1] << endl;
	  break;
	}
	else
	  updateList(candidateindexlist, eliminated);
      }
    }
    if(i != cases-1)
      cout << endl;
  }
  return 0;
}
