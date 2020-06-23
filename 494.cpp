//I wonder if it works just to count the spaces and add 1...
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string line;
  int spaces;

  while(getline(cin, line))
  {
    spaces = count_if(line.begin(), line.end(), [](unsigned char c){return isspace(c);});

    cout << spaces+1 << endl;
  }
  return 0;
}
