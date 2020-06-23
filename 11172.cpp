#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a;
  for(int i =0; i < a; i++)
  {
    int g,l;
    scanf("%d %d", &b, &c);
    if(b<c)
    {
      cout << "<" << endl;
    }else if (b>c) {
      cout << ">" << endl;
    }
    else
    {
      cout << "=" << endl;
    }
  }
  return 0;
}
