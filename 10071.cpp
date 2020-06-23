#include <bits/stdc++.h>

using namespace std;

int main()
{
  int v,t,a;
  while(scanf("%d %d", &v, &t) == 2)
  {
    if(-100 <= v && v<=100 && 0<=t && t<=200)
    {
      a = 2*v*t;
    }

    printf("%d\n", a);
  }
  return 0;
}
