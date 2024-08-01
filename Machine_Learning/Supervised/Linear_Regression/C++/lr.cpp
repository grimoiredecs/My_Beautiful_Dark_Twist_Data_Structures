#include "lr.hpp"

template <typename T> bool dataset<T>::readcsv(const char *fileName) {

  fstream myfile;
  myfile.open("data.csv");
  if (!myfile) {
    throw std::runtime_error("Could not open file");
  }
  string str;
  cout << "Enter the name of your dependent variable: ";
  getline(std::cin, str);
  while (getline(myfile, columns, ' ')) {
  }
}
