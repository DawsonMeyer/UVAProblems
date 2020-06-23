#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int countB(int n)
{
  int count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int rec(int n)
{
  if(!n)
  {
    return 0;
  }
  return max(rec(n/10), countB(n));
}

int main()
{
  int t, num, ans;
  cin >> t;
  while(t--)
  {
    cin >> num;
    ans = rec(num);
    cout << ans << endl;
  }
  return 0;
}
