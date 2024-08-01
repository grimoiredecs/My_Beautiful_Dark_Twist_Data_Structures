#include "lr.hpp"

template <typename T> bool dataset<T>::readcsv(const char *fileName) {

  fstream myfile;
  myfile.open("data.csv");
  if (!myfile) {
    cerr << "Error loading file";
    return 1;
  }
  string str;
  cout << "Enter the name of your desired variable: ";
  getline(std::cin, str);
}
