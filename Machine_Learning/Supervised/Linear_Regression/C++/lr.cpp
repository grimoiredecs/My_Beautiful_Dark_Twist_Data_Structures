#include "lr.hpp"

template <typename T> bool dataset<T>::readcsv(const char *fileName) {

  fstream myfile;
  myfile.open("data.csv");
  if (!myfile) {
    throw std::runtime_error("Could not open file");
  }
  string str; // line
  cout << "Enter the name of your dependent variable: ";
  getline(std::cin, str);
  while (getline(myfile, columns, ' ')) {
  }
}
template <typename T> T dataset<T>::retrieve(int i, int j) {
  T res = data[i][j];
  return res;
}
template <typename T> T dataset<T>::retrieve(string i, string j) {}
