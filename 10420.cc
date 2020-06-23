#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<string, int> conquests;

  int num;
  cin >> num;
  cin.ignore();

  for(int i=0; i<num; i++)
  {
    string country;
    getline(cin, country);
    istringstream iss(country);
    string temp;
    iss >> temp;

    if(conquests.find(temp) == conquests.end())
    {
      conquests[temp] = 1;
    }
    else
    {
      conquests[temp]++;
    }
  }
  for(map<string, int>::iterator it = conquests.begin(); it != conquests.end(); it++)
  {
    cout << it->first << " " << it->second << endl;
  }
  
  return 0;
}
