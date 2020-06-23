#include <bits/stdc++.h>
using namespace std;

int num[3001];
int diff[3001];
int main()
{
  int a;
  while(cin >> a)
  {
    bool jolly = 1;
    int b;

    for(int i=0; i<a; i++)
    {
      cin >> b;
      num[i] = b;
    }
    for(int i=0; i<a-1; i++)
    {
      diff[i] = abs(num[i] - num[i+1]);
      //cout << diff[i];
    }
    sort(diff, diff+a-1);
    for(int i=0; i<a-1; i++)
    {
      if(diff[i] != i+1)
      {
        jolly = 0;
        break;
      }
    }
    if(jolly == 0)
      cout << "Not jolly" << endl;
    else
      cout << "Jolly" << endl;
  }
  return 0;
}
