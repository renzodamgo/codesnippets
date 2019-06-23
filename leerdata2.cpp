
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;
/* class col {
private:
}; */

int main() {
  ifstream data;
  data.open("data.csv");
  int ncol;
  map<string, int> dataframe;
  cout << "numero de col: " << endl;
  cin >> ncol;
  int i = 0;
  string line;
  while (getline(data, line)) {
    stringstream ss(line);
    for (int j = 0; j < ncol; ++j) {
      getline(ss, line, ',');
      dataframe.insert(pair<string, int>(line, j));
    }
  }
  /* while (data.good()) {
    getline(data, line, ',');
    dataframe.insert(pair<string, int>(line, i % 3));

    i++;
  } */
  
  /* cout << "\nThe map gquiz1 is : \n";
  cout << "\tKEY\tELEMENT\n"; */
  int colelegida;
  cout << "Que columna deseas ver [1.." << ncol << "]: ";
  cin >> colelegida;
  colelegida--;
  cout << endl;
  map<string, int>::iterator itr;
  for (itr = dataframe.begin(); itr != dataframe.end(); ++itr) {
      cout << itr->first << '\n';
      cout << endl;
    
  }
}

/*   for (itr = dataframe.begin(); itr != dataframe.end(); ++itr) {
    if (itr->second == 2) {
      cout << '\t' << itr->first << '\t' << itr->second << '\n';
      cout << endl;
    }
  }
  cout << endl;
} */