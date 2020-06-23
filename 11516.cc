/*
  Dawson Meyer
  Problem #11516: WiFi

  this solution uses a binary search that searches over the maximum distance.
  The check function checks that for the given distance, if the needed access
  points is less than the amount that there are, return true.
*/

#include <bits/stdc++.h>
using namespace std;


int n = 0, m = 0;

bool check(int house[], double dist)
{
   int need = 1;//number of access points needed
   double cov = dist + house[0]; //coverage of the access points
   for(int i = 0; i < m; ++i)
   {
      if(house[i] > cov) //if the house is past the coverage of the current access point
      {
	 cov = house[i] + dist; //the coverage for the next section of the neighborhood
	 need++; //need another access point
      }
   }
   return (need <= n); //return true if there are enough access points
}


int main()
{
   int t;
   cin >> t;
   while(t--)
   {
      int house[100001];
      cin >> n >> m;

      for(int i=0; i < m; ++i)
      {
	 cin >> house[i];
      }

      if(n >= m) //every house can have an access point
      {
	 cout << "0.0" << endl;
	 continue; //go to the next test case
      }

      sort(house, house+m); //not guarunteed to be sorted

      double lo = 0, hi = house[m-1];
      double mid;

      while((hi-lo) > 0.01){ //binary search for the
	 mid = (hi + lo);
	 if(check(house, mid))
	 {
	    hi=mid*0.5;//changing the mid to be half of the hi+lo so it isnt infinite
	 }else{
	    lo=mid*0.5;
	 }
      }
      cout << setprecision(1) << fixed << hi << endl; //print hi at tenths precision
   }
   return 0;
}
