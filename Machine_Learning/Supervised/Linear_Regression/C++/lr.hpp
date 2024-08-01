#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T> class dataset {
private:
  long long x_n;
  long long y_n;
  vector<vector<T>> data;
  vector<stringstream> columns;

public:
  dataset(){};

  vector<vector<T>> getData();
  bool readcsv(const char *fileName);
  T retrieve(int i, int j);
  T retrieve(string i, string j);
};
