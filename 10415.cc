/*
Problem #10415: Eb Alto Saxophone Player

want to use a table.
*/
#include <bits/stdc++.h>
using namespace std;

const bool notes[16][11] =
{
  {0,0,1,1,1,0,0,1,1,1,1}, //c
  {0,0,1,1,1,0,0,1,1,1,0}, //d
  {0,0,1,1,1,0,0,1,1,0,0}, //e
  {0,0,1,1,1,0,0,1,0,0,0}, //f
  {0,0,1,1,1,0,0,0,0,0,0}, //g
  {0,0,1,1,0,0,0,0,0,0,0}, //a
  {0,0,1,0,0,0,0,0,0,0,0}, //b
  {0,0,0,1,0,0,0,0,0,0,0}, //C
  {0,1,1,1,1,0,0,1,1,1,0}, //D
  {0,1,1,1,1,0,0,1,1,0,0}, //E
  {0,1,1,1,1,0,0,1,0,0,0}, //F
  {0,1,1,1,1,0,0,0,0,0,0}, //G
  {0,1,1,1,0,0,0,0,0,0,0}, //A
  {0,1,1,0,0,0,0,0,0,0,0}, //B
};

int main()
{
  int numTest;
  cin >> numTest;
  cin.ignore();
  string in;
  const string possible = "cdefgabCDEFGAB";

  for(int i=0; i < numTest; i++)
  {
    int finger[11] = {0}; //for the count for each finger
    getline(cin, in);

    int curNote = 15; //initialize them to be something that doesn't exist
    int prevNote = 15;
    for(int j = 0; j < in.size(); j++)
    {
      for(int k = 0; k <= possible.size(); k++)
      {
        if(in[j] == possible[k])//if its the same character
        {
          curNote = j; //the current note is j
          break; //break out of the for loop to find the next
        }
      }
      if(i == 0) //if it is the first note, then we want to use the table
      {
        for(int k = 1; k <= 10; k++)
        {
          finger[k] += notes[curNote][k];
        }
      }else{
        for(int k = 1; k <= 10; k++)
        {
          if(notes[prevNote][k] - notes[curNote][k] == -1)
          {
            finger[k]++;
          }
        }
      }
      prevNote = curNote;
    }
    for(int j = 0; j < 10; j++)
    {
      cout << finger[j] << " ";
    }
    cout << endl;
  }
  return 0;
}
