#include <bits/stdc++.h>
using namespace std;

int main()
{
  int k;
  int array[13] = {2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313,
     459901, 1358657, 2504881};

  while((cin >> k) && (k != 0))
  {
    cout << array[k-1] << endl;
  }
  /*need to first find the answers in a brute force way
  //this works becasue there is only 13 possible k's.
  //the m we find could be a very large number so use long
  int k;
  while(cin >> k)
  {
    long m;
    for(m = k+1; m < 5000000; m++)
    {
      int pos = 0;
      bool found = true;
      for(int i=0; i < k; i++)
      {
        pos = (pos + (m-1)) % ((2*k) - i);
        if(pos < k)
        {
          found = false;
          break;
        }
      }
      if(found == true)
      {
        break;
      }
    }
    cout << m << endl;
  }*/

  return 0;
}
