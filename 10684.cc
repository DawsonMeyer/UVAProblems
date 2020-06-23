/*
  Dawson Meyer
  Problem #10684: The jackpot

  This problem is fairly straightforward just need to keep a running answer
  that has to be positive.
*/
#include <iostream>
using namespace std;

int main()
{
   int N;`
   while(cin >> N && N)
   {
      int num;
      int ans=0, sum=0;
      for(int i=0; i < N; i++)
      {
	       cin >> num;
	       sum += num; //add the new num to the running sum

	        if(sum < 0)//if the sum goes below zero
	         {
	            sum = 0;//start over
	         }
	        if(sum > ans)//if the sum becomes bigger than the ans so far
	        {
	           ans = sum;//make the ans the same as it
	        }
      }
      if(ans > 0)
      {
	      cout << "The maximum winning streak is " << ans << "." << endl;
      }
      else
	     cout << "Losing streak." << endl;

   }
   return 0;
}
