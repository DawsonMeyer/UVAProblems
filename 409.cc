#include <bits/stdc++.h>
using namespace std;

//want to keep an array of keywords and check against every word
//in the excuses
int main()
{
  int numK, numEx;
  int numR=0;

  while(cin>>numK>>numEx)
  {
    numR++;
    string keys[20];
    pair<string, int> origEx[20];

    for(int i=0; i < numK; i++)
    {
      cin >> keys[i];
      cin.ignore();
    }

    for(int i=0; i < numEx; i++)
    {
      getline(cin, origEx[i].first);
      string excuse = origEx[i].first;

      for(int j = 0; j < excuse.length(); j++)
      {
        if(isalpha(excuse[j]))
        {
          excuse[j] = tolower(excuse[j]);
        }
        else {excuse[j] = ' ';}
      }
      istringstream iss;
      iss.str(excuse);
      int count = 0;

      while(iss.good())
      {
        string check;
        iss >> check;
        for(int k = 0; k < numK; k++)
        {

          if(check == keys[k])
          {
            count++;
          }
        }
      origEx[i].second = count;
      }
    }
    int max = 0;

    for(int k=0; k < numEx; k++)
    {
       if(origEx[k].second > max)
       {
         max = origEx[k].second;
       }
    }

    cout << "Excuse Set #" << numR << endl;

    for(int k=0; k < numEx; k++)
    {
      if(origEx[k].second == max)
      {
        cout << origEx[k].first << endl;
      }
    }
    cout << endl;
  }

  return 0;
}
