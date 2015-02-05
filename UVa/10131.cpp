#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

struct elephant {
  int weight;
  int iq;
  int maxlength;
  int index;
  vector<elephant*> seq;
  elephant(int a, int b) : weight(a), iq(b), maxlength(1) {};
};

bool compare(const elephant* a, const elephant* b) {
  if(a->weight <= b->weight)
    return false;
  return true;
}

int main() {
  vector<elephant*> elephants;
  int index = 1;
  while(!cin.eof()) {
    int weight, iq;
    cin >> weight >> iq;
    elephant* current = new elephant(weight, iq);
    current->index = index;
    current->seq.push_back(current);
    elephants.push_back(current);
    index++;
  }
  sort(elephants.begin(), elephants.end(), compare);
  for(int i = 0; i < elephants.size(); i++) {
    elephant* compare = elephants[i];
    for(int j = i-1; j >= 0; j--) {
      elephant* small = elephants[j];
      vector<elephant*> smallseq = elephants[j]->seq;
      if(small->iq < compare->iq) {
	int updatelength = small->maxlength + 1;
	if(updatelength > compare->maxlength) { 
	  compare->maxlength = updatelength;
	  smallseq.push_back(compare);
	  compare->seq = smallseq;
	}
      }
    }
  }
  int maxn = 0;
  vector<elephant*> result;
  for(int i = 0; i < elephants.size(); i++) {
    if(elephants[i]->maxlength > maxn) {
      maxn = elephants[i]->maxlength;
      result = elephants[i]->seq;
    }
  }
  cout << maxn << endl;
  for(int i = result.size() - 1; i >= 0; i--)
    cout << result[i]->index << endl;
  return 0;
}
