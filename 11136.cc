/*
  Dawson Meyer
  Problem #11136: Hoax or what

*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  while(cin >> n)
  {
    if(n == 0)
    {
      break;
    }
    multiset<int> urn;
    urn.clear();
    int m;
    long long diff = 0;//the difference between the biggest and smallest
    for(int i=0; i<n; i++)
    {
      cin >> m;
      for(int j=0; j<m; j++)
      {
        int bill;
        cin >> bill;
        urn.insert(bill);
      }
      diff += *urn.rbegin() - *urn.begin();//take the end(largest) and subtract the beginning
      urn.erase(urn.begin());
      urn.erase(urn.find(*urn.rbegin()));
    }
    cout << diff << endl;
  }
  return 0;
}
