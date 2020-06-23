//Rat attack
#include <iostream>
#include <string.h>
using namespace std;

int killed[1024][1024];

bool inbound(int i, int j)
{
   return (i>-1 && i<1024) && (j>-1 && j<1024);
}

int main()
{
   int Cases;
   cin >> Cases;

   while(Cases--)
   {
      memset(killed, 0, sizeof killed);
      int d, n, x, y, ratpop, m;
      cin >> d;
      cin >> n;

      while(n--)
      {
	 cin >> x >> y >> ratpop;

	 //has the potential to go out of bounds
	 for(int i=x-d; i<=x+d; i++)
	 {
	    for(int j=y-d; j<=y+d; j++)
	    {
	       if(inbound(i,j))
	       {
		  killed[i][j] += ratpop;
	       }
	    }
	 }
      }

      m = -1;

      for(int i=0; i<1024; i++)
	 for(int j=0; j<1024; j++)
	 {
	    if(killed[i][j] > m)
	    {
	       m = killed[i][j];
	       x = i;
	       y = j;
	    }
	 }
      cout << x << " " << y << " " << m << endl;
   }
   return 0;
}
