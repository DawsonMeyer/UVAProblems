/*
  Dawson Meyer
  Problem #11195: Another n-Queen Problem

  This is the code for the backTrack function from the textbook.  This solution
  utilizes a bitset to keep track of the diagonals and the rows.  This way you
  can check the positions of the queens and come up with the amount of solutions
  for each case.
*/

#include <bits/stdc++.h>
using namespace std;

bitset<30> rw, ld, rd; //bitset for the rows, the left diagonal, and the right diagonal
int n, ans=0; //the number of rows for each case, and the number of answers
char in[14][14]; //the boards represented via an array

void backTrack(int c)
{
   //if the count is the same as the number in, then add one to ans count and return the function right away
   //this is for the base case of the recursion
   if(c == n) { ans++ ; return; }

   //keep going until all rows are complete
   for(int r=0; r < n; r++)
   {
      //this if statement first checks that the character is not a "*" at the position
      //and that the row at r is 0 (has no queen) and the left diagonal has no queen in it
      //and that the right diagonal doesn't have queen in it.  The n-1 in the left diagonal is
      //for keeping the value positive.
      if(in[r][c] != '*' && !rw[r] && !ld[r-c+n-1] && !rd[r+c])
      {
	 rw[r] = ld[r-c+n-1] = rd[r+c] = true; //sets the row. left diagonal, right diagonal to 1
	 backTrack(c+1); //recurse for the next check
	 rw[r] = ld[r-c+n-1] = rd[r+c] = false; //sets the row, ld, and rd to 0
      }
   }
}

int main()
{
   int count;
   while(cin >> n && n != 0)
   {
      count++; //add to the count every run through
      ans = 0; //re initialize the ans so there isnt overlap
      for(int i=0; i < n; i++)
      {
	 for(int j=0; j < n; j++)
	 {
	    cin >> in[i][j]; //take in the boards
	 }
      }
      backTrack(0); //calle the backTrack function for 0 first, and it will recurse for the answer

      cout << "Case " << count << ": " << ans << endl; //print the number of
   }

   return 0;
}
