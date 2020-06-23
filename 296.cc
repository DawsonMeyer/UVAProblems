/*
  Dawson Meyer
  Problem #296: Safebreaker

  This solution just uses brute force in order to find the correct spaces and
  the digits that are in the wrong spot.  Every correct answer that is found
  goes into a queue so I can easily see if there are more than one solution or
  not.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int cases;
   cin >> cases;
   while(cases--)
   {
      int num;
      cin >> num;
      cin.ignore();
      int g[10][6];
      for(int i=0; i<num; i++)
      {
	 string st;
	 getline(cin, st);
	 g[i][0] = st[0] - '0';//first position
	 g[i][1] = st[1] - '0';
	 g[i][2] = st[2] - '0';
	 g[i][3] = st[3] - '0';//fourth position
	 g[i][4] = st[5] - '0';//correct digits
	 g[i][5] = st[7] - '0';//misplaced digits
      }

      queue<int> ans; //for storing the answer(s)

      //these for loops are to iterate over all of the numbers between 0000 and 9999
      for(int a =0; a<10; a++)
	 for(int b =0; b<10; b++)
	    for(int c =0; c<10; c++)
	       for(int d =0; d<10; d++)
	       {
		  bool works = true;//assume that this number is true firstly

		  for(int i=0; i<num; i++)//look for correct places
		  {
		     int temp[4] = {g[i][0], g[i][1], g[i][2], g[i][3]};//for testing the input number
		     int correctPlace = 0; //count of correctly placed digits
		     int wrongPlace = 0; //count of correct digits in the wrong place
		     int check[4] = {a,b,c,d}; //for testing the current number

		     for(int j=0; j < 4; j++)//the number of correct places in the string
		     {
			if(g[i][j] == check[j])//if its the same in both strings
			{
			   correctPlace++;
			}
		     }

		     //look for the number of misplaced, but correct numbers
		     for(int k = 0; k < 4; k++)
		     {
			for(int l = 0; l < 4; l++)
			{
			   if(temp[k] == check[l] && temp[k] != -1)//if its the same number but in a different place
			   {
			      temp[k] = -1; //dont use this number in this place again
			      check[l] = -1; //dont use the number in this place again
			      wrongPlace++;
			   }
			}
		     }
		     wrongPlace -= correctPlace;

		     //if the number of correct == the found correct, then that string is an answer
		     if(correctPlace != g[i][4] || wrongPlace != g[i][5])
		     {
			works = false;
		     }
		  }
		  if(works)
		  {
		     int psh = ((a*1000) + (b*100) + (c*10) + d); //add them all together to get the number that is the answer
		     ans.push(psh);  //put this number into the queue
		  }
	       }
      if(ans.empty())
      {
	 cout << "impossible" << endl;//becasue ans queue is empty
      }
      else if(ans.size() == 1)
      {
	 cout << setw(4) << setfill('0') << ans.front() << endl; //becasue there is only one solution
      }
      else
      {
	 cout << "indeterminate" << endl; //too many solutions
      }
   }
   return 0;
}
