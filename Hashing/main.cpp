#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
  unordered_map<string,int> mp;
  cout << mp.size();
  cout <<"\n";
  mp["Deep Sea"] = 233;
  mp["Dark doom"] = 2333;
  mp["Lyke Li"] = 2;
  mp["co cai sawsc vi di doi loz"] = 69696969;
  for(auto x: mp)
  {
      cout << x.first << " "<< x.second<< endl;
  }

  return 0;
}

