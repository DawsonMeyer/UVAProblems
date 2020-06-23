#include <bits/stdc++.h>
using namespace std;

bool check(string s, int n, int k);
int main()
{
  string s;
  while(cin >> s)
  {
    int n = s.length();

    for(int k = n; k >= 1; k--)
    {
      if(check(s, n, k))
      {
        cout << k << endl;
        break;
      }
    }
  }
  return 0;
}

bool check(string s, int n, int k)
{
  if(n % k)
  {
    return false;
  }
  int length = n/k;
  for(int i = 0; i < (n/k); i++)
  {
    for(int j = i+length; j < n; j += length)
    {
      if(s[j] != s[i])
      {
        return false;
      }
    }
  }
  return true;
}
