/*
  Dawson Meyer
  Problem #674: Coin Change

  change it up before hand in though because this isnt optimal I dont think
*/

#include <iostream>
using namespace std;

int a[8000] = {1, 1, 1, 1, 1};
const int coin[4] = {5, 10, 25, 50};

int main()
{
   for(int i=0; i<8000; i++)
   {
      a[i] = 1;//always possible to give 1 cent
   }
   for(int i=0; i < 4; i++)
      for(int j=coin[i]; j < 8000; j++)
      {
	       a[j] += a[j - coin[i]];
      }
   int n;
   while(cin >> n)
   {
      cout << a[n] << endl;
   }

   return 0;
}
