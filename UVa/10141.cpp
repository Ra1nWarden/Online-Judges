#include <iostream>
#include <vector>

using namespace std;

int main() {
  int feats, products;
  int reps = 1;
  while(cin >> feats >> products) {
    if (feats == 0 && products == 0)
      break;
    if (reps != 1)
      cout << endl;
    cin >> ws;
    string line;
    for(int i = 0; i < feats; i++)
      getline(cin, line);
    cin >> ws;
    vector<string> prods;
    string selected = "";
    double leastprice = -1;
    int maxchecked = -1;
    for(int i = 0; i < products; i++) {
      string brand;
      getline(cin, brand);
      double price;
      int checked;
      cin >> ws >> price >> checked;
      if (checked > maxchecked) {
	maxchecked = checked;
	selected = brand;
	leastprice = price;
      }
      else if (checked == maxchecked && price < leastprice) {
	selected = brand;
	leastprice = price;
      }
      cin >> ws;
      string prod_feat;
      for(int j = 0; j < checked; j++)
	getline(cin, prod_feat);
      cin >> ws;
    }
    cout << "RFP #" << reps << endl;
    cout << selected << endl;
    reps++;
  }
  return 0;
}
