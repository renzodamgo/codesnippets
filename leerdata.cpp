#include <fstream>
#include <iostream>
#include <string>
std::ifstream infile("data.cvs");
int main() {
  char c;
  std::string nombre;
  std::string apellido;
  std::string ape2;
  while (( infile >> nombre >> c >>  apellido >> c >> ape2) && (c == ',') )  {
    std::cout << nombre << " " << apellido << " " << ape2 << std::endl;
  };
}
