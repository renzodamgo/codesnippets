#include "Columna.h"
#include "Fila.h"
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
class Dataframe {
private:
  map<string, Columna *> colmap;
  vector<Fila *> filas;

public:
  Dataframe(){};
  ~Dataframe();
  void cargarArchivo(string nombre, int ncol) {
    ifstream data;
    data.open(nombre);
    string line;
    int i = 0;
    getline(data, line);
    filas.push_back(new Fila(i));
    stringstream ss(line);
    for (int j = 0; j < ncol; ++j) {
      getline(ss, line, ',');
      colmap.insert(pair<string, Columna *>(line, new Columna(line)));
    };

    i++;
  }
}

;
int main() {
  int ncol;
  cin >> ncol;
  string archivo;
  cin >> archivo;
  Dataframe *dat = new Dataframe();
  dat->cargarArchivo(archivo, ncol);
}
