#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n = 0;
  int m = 0;
  int dragons[20000]={0};
  int knights[20000]={0};
  while((cin >> n >> m) && n!=0 && m!=0)
  {
    //cout << "n" << n << endl;
    for(int i=0; i<n; i++)
    {
      cin >> dragons[i];
      //cout << dragons[i];
    }
    for(int i=0; i<m; i++)
    {
      cin >> knights[i];
    }

    sort(dragons, dragons+n);
    sort(knights, knights+m);

    //just use the shortest knight that can cut the head

    int gold, d, k;
    gold = d = k = 0;

    while(d<n && k<m)
    {
      while(dragons[d] > knights[k] && k<m) {k++;}
      if(k==m) {break;}
      gold += knights[k];
      d++;
      k++;
    }
    if(d==n)
    {
      cout << gold << endl;
    }
    else
    {
      cout << "Loowater is doomed!" << endl;
    }

  }
}
