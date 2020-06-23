/*
  Dawson Meyer
  Problem #10026: Shoemaker's Problem

  sort inputs by cost/time ratio decreasing, then by index increasing,
  then output.  Eliminate the highest cost/time ratios first.

  stable_sort() keeps them in the same order as they were when they were input
  I think a vector would work well for this.
*/

#include <bits/stdc++.h>
using namespace std;

//the struct to keep track of the different jobs
struct Job{
   double time;//need to be doubles because division
   double cost;
   int key;
};

//function to compare the cost/time ratios between jobs
bool compare(const Job &jb1, const Job &jb2)
{
   return (jb1.cost/jb1.time) > (jb2.cost/jb2.time);
}

int main()
{
   int tc;
   cin >> tc;
   while(tc--)
   {
      int n;
      cin >> n;
      vector<Job> jobs(n);//vector works well with stable sort

      for(int i=0; i<n; i++)
      {
	 cin >> jobs[i].time >> jobs[i].cost;
	 jobs[i].key = i+1;//so I can keep track of the key a little easier
      }

      //stable_sort() will make sure that ties keep the same order as they
      //were input.
      stable_sort(jobs.begin(), jobs.end(), compare);

      cout << jobs[0].key;//so I can get the spacing right

      for(int i=1; i<n; i++)
      {
	 cout << " " << jobs[i].key;//now there wont be a space afterwards
      }
      cout << endl;

      if(tc)
      {
	 cout << endl;//blank line between test cases and not after the last one
      }
   }
   return 0;
}
