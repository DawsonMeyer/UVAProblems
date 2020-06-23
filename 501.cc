#include <bits/stdc++.h>
using namespace std;

int main()
{
  int c;
  cin >> c ;

  while(c--)
  {
    int m, n, inst[30100];
    cin >> m >> n;

    for(int i=0; i < m; i++)
    {
      cin >> inst[i];
    }

    multiset<int> nums;
    nums.insert(inst[0]); //put the first value into the multiset
    bool first = true;
    int u; //there is one u for every GET.  it represents how many elements are in the set at that GET
    int size =1;
    multiset<int>::iterator i = nums.begin();

    for(int j = 0; j < n; j++)
    {
      cin >> u;

      while(u > size)
      {
        nums.insert(inst[size]);
        if(*i > inst[size])
        {
          i--;
        }
        size++;
      }
      if(first)
      {
        //i = nums.begin();
        first = false;
      }else{
        i++;//add 1 every GET
      }

      cout << *i << endl;

    }
    if(c != 0) {cout<<endl;}
  }
  return 0;
}
