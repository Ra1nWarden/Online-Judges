#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int> > getRepeatedIndex(string& word) {
  vector<vector<int> > result;
  int wordlength = word.length();
  vector<bool> ticks(wordlength);
  for(vector<bool>::iterator itr = ticks.begin(); itr != ticks.end(); ++itr)
    *itr = false;
  for(int i = 0; i < wordlength; i++) {
    if(ticks[i])
      continue;
    char currentchar = word[i];
    ticks[i] = true;
    vector<int> counter;
    counter.push_back(i);
    for(int j = i+1; j < wordlength; j++) {
      if(word[j] == currentchar) {
	counter.push_back(j);
	ticks[j] = true;
      }
    }
    if(counter.size() > 1)
      result.push_back(counter);
  }
  return result;
}

bool comparePattern(vector<vector<int> >& one, vector<vector<int> >& two) {
  if(one.size() != two.size())
    return false;
  for(int i = 0; i < one.size(); i++) {
    vector<int> fromone = one[i];
    if(count(two.begin(), two.end(), fromone) == 0)
      return false;
  }
  return true;
}

vector<string> getMatch(vector<string>& dict, string word) {
  vector<string> result;
  int wordlength = word.length();
  for(vector<string>::iterator itr = dict.begin(); itr != dict.end(); ++itr) {
    if(itr->length() != wordlength)
      continue;
    vector<vector<int> > wordpattern = getRepeatedIndex(word);
    vector<vector<int> > matchedpattern = getRepeatedIndex(*itr);
    if(comparePattern(wordpattern, matchedpattern))
      result.push_back(*itr);
  }
  return result;
}

bool validate(vector<string>& partdecoded, vector<string>& encrypted) {
  map<char, char> forwardmap;
  map<char, char> backwardmap;
  for(int i = 0; i < partdecoded.size(); i++) {
    string orig = encrypted[i];
    string convert = partdecoded[i];
    for(int j = 0; j < orig.length(); j++) {
      char origchar = orig[j];
      char convertchar = convert[j];
      if(forwardmap.count(origchar) == 1) {
	if(forwardmap[origchar] != convertchar)
	  return false;
      }
      if(backwardmap.count(convertchar) == 1) {
	if(backwardmap[convertchar] != origchar)
	  return false;
      }
      if(forwardmap.count(origchar) == 0)
	forwardmap[origchar] = convertchar;
      if(backwardmap.count(convertchar) == 0)
	backwardmap[convertchar] = origchar;
    }
  }
  return true;
}


vector<string> decode(vector<string>& encrypted, map<string, vector<string> >& matchmap) {
  int stringlength = encrypted.size();
  vector<string> result;
  vector<int> indexlist;
  int currentworkingindex = 0;
  while(indexlist.size() != stringlength) {
    if(currentworkingindex == -1) {
      result.clear();
      return result;
    }
    int nextmatchindex;
    if(currentworkingindex == indexlist.size())
      nextmatchindex = 0;
    else
      nextmatchindex = indexlist[currentworkingindex] + 1;
    string currentworkingword = encrypted[currentworkingindex];
    vector<string> possibleMatch = matchmap[currentworkingword];
    if(nextmatchindex >= possibleMatch.size()) {
      currentworkingindex--;
      indexlist.erase(indexlist.end() - 1);
      result.erase(result.end() - 1);
      continue;
    }
    else {
      string nextdecoded = possibleMatch[nextmatchindex];
      if(nextmatchindex == 0)
	result.push_back(nextdecoded);
      else
	result[result.size() - 1] = nextdecoded;
      if(validate(result, encrypted)) {
	if(nextmatchindex == 0)
	  indexlist.push_back(nextmatchindex);
	else
	  indexlist[indexlist.size() - 1] = nextmatchindex;
	currentworkingindex++;
      }
      else {
	if(nextmatchindex == 0)
	  indexlist.push_back(nextmatchindex);
	else
	  indexlist[indexlist.size() - 1] = nextmatchindex;
      }
    }
  }
  return result;
}

int main() {
  int words;
  cin >> words;
  vector<string> dict;
  for(int i = 0; i < words; i++) {
    string word;
    cin >> word;
    dict.push_back(word);
  }
  cin >> ws;
  while(!cin.eof()) {
    string line;
    getline(cin, line);
    istringstream iss(line.c_str());
    vector<string> encrypted;
    while(!iss.eof()) {
      string word;
      iss >> word;
      encrypted.push_back(word);
    }
    bool possibilitycheck = true;
    map<string, vector<string> > decodepossible;
    for(vector<string>::iterator itr = encrypted.begin(); itr != encrypted.end(); ++itr) {
      vector<string> matched = getMatch(dict, *itr);
      if(matched.size() == 0) {
	possibilitycheck = false;
	break;
      }
      decodepossible[*itr] = matched;
    }
    bool resultcheck = true;
    vector<string> result;
    if(possibilitycheck) {
      result = decode(encrypted, decodepossible);
      if(result.size() == 0)
	resultcheck = false;
    }
    else
      resultcheck = false;
    if(resultcheck) {
      for(int i = 0; i < result.size(); i++) {
	if(i == result.size() - 1)
	  cout << result[i] << endl;
	else
	  cout << result[i] << " ";
      }
    }
    else {
      for(int i = 0; i < encrypted.size(); i++) {
	for(int j = 0; j < encrypted[i].length(); j++)
	  cout << "*";
	if(i != encrypted.size() - 1)
	  cout << " ";
	else
	  cout << endl;
      }
    }
  }
  return 0;
}
