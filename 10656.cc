/*
  Dawson Meyer
  Problem #10656: Maximum Sum(II)

  There are no negative integers so that means that it just has to print
  all of the numbers in the substring that aren't zeroes.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;

   while(cin >> n && n!=0)
   {
      int a[1000] = {0};

      for(int i=0; i < n; i++)
      {
	 cin >> a[i]; //put it all into the array
      }

      bool space = false; //dont want to print a space the first time

      for(int i=0; i < n; i++)
      {
	 if(a[i]) //if there is a number in the position
	 {
	    if(space)
	    {
	       cout << " ";
	    }
	    space = true;//keep printing a space between the numbers
	    cout << a[i];//print the number
	 }
      }

      if(!space)
      {
	 //if the space is never true, then there is only 0's in the array
	 cout << "0";
      }

      cout << endl;
   }
   return 0;
}
