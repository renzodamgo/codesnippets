#include "Columna.h"
#include "Fila.h"
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
typedef map<string, Columna *> mapita;
using namespace std;
class Dataframe {

private:
  map<string, Columna *> colmap;
  mapita *s;
  vector<Fila *> filas;

public:
  Dataframe(){};
  ~Dataframe();
  void cargarArchivo(string nombre, int ncol) {
    s = new mapita();
    vector<string> colnames;
    ifstream data;
    data.open(nombre);
    string line;
    int i = 0;
    getline(data, line);
    stringstream ss(line);
    for (int j = 0; j < ncol; ++j) {
      getline(ss, line, ',');
      colmap.insert(pair<string, Columna *>(line, new Columna()));
      s->insert(pair<string, Columna *>(line, new Columna()));
      colnames.push_back(line);
    };

    while (getline(data, line)) {
      stringstream ss(line);
      for (int j = 0; j < ncol; ++j) {
        getline(ss, line, ',');
        /* cout << line << " \\ "; */
        colmap[colnames[j]]->inputData(line);
      }
    }
  }
  void mostrarcolumnas() {
    map<string, Columna *>::iterator itr;
    // mapita::iterator itr;
    for (itr = s->begin(); itr != s->end(); ++itr) {
      cout << itr->first << '\t';
    }
  }
  void mostrarcolumna(string nombreCol) { colmap[nombreCol]->showcol(); }
}

;
int main() {
  /* string archivo;
  int ncol;
  cout << "Numero de columnas: ";
  cin >> ncol;
  cout << "Nombre del archivo: ";
  cin >> archivo; */
  Dataframe *dat = new Dataframe();
  dat->cargarArchivo("data.csv", 4);
  string nombredecol;
  cin >> nombredecol;
  dat->mostrarcolumna(nombredecol);
}