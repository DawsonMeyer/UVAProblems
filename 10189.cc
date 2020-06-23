/*
  Thoughts: as the input is being taken, keep a 2-D int array with
  every '.' from the input as a 0 and every '*' as -1000000 and add
  1 to every spot around it.  May need to pad the array.  When output
  happens, whenever there is a negative number, output '*' instead.

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, field = 0;

  while(cin >> n >> m)
  {
    if(!n && !m) //if both are zero, the program ends
    {
      return 0;
    }

    field++;

    if(field > 1)//needs to be an empty line between the outputs and not at the end
    {
      cout << endl;
    }

    char a[101][101]; // for storing the mines and such
    int in[101][101] = {0};

    //get the input of the minefield
    for(int i=0; i < n; i++)
    {
      for(int j=0; j < m; j++ )
      {
        cin >> a[i][j];
        if(a[i][j] == '*')
        {
          in[i][j] = -1000000;
          in[i][j+1]++;
          in[i][j-1]++;
          in[i+1][j+1]++;
          in[i+1][j]++;
          in[i+1][j-1]++;
          in[i-1][j+1]++;
          in[i-1][j]++;
          in[i-1][j-1]++;
        }
      }
    }

    cout << "Field #" << field << ":" << endl;
    //for the output of the integer representation of the minefield
    for(int i=0; i < n; i++)
    {
      for(int j =0; j < m; j++)
      {
        if(in[i][j] < 0)//if it is less than 0, its a mine
        {
          cout << '*';
        }
        else {cout << in[i][j];}
        //cout << endl;
      }
      cout << endl;
    }
  }
  return 0;
}
