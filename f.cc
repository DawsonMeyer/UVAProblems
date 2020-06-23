#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

int main()
{
  prime.push_back(2);
  for(int i=2; i<20000; i++)
  {
    for(int j=2; j<20000; j++)
    {
      if(i%j==0)
      {
        break;
      }
      else if(i==j+1)
      {
        prime.push_back(i);
      }
    }
  }

  int t;
  cin >> t;
  while(t--)
  {
    int nf, canHit=0;
    double dist=0;
    cin >> nf >> dist;

    int x[20001] = {0}, y[20001] = {0};
    int tempx, tempy;
    for(int i=1; i<=nf; i++)
    {
      cin >> tempx;
      cin >> tempy;
      x[i] = tempx;
      y[i] = tempy;
    }
    if(dist == 0)
    {
        cout << 0 << endl;
        continue;
    }
    //at this point have to deal with the flower points.
    //find dist between the point youre at and the next flower
    //then see if the guy can walk far enough.
    int x1, x2, y1, y2;
    double between = 0;
    for(int i=0; i<nf; i++)
    {
      //cout << "dist: " << dist << endl;
      x1 = x[i];
      x2 = x[i+1];
      y1 = y[i];
      y2 = y[i+1];

      between = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));

      if(between > dist)
      {
        break;
      }
      else
      {
        dist -= between;
        canHit++;
      }
    }

    for(unsigned int i=0; i<prime.size(); i++)
    {
      if(canHit == 1)
      {
        cout << 0 << endl;
        break;
      }
      if(prime.at(i) == canHit)
      {
        cout << canHit << endl;
        break;
      }
      else if(prime.at(i) == 19997)
      {
        cout << prime.at(i) << endl;
        break;
      }
      else if(prime.at(i)<canHit && prime.at(i+1)>canHit)
      {
        cout << prime.at(i) << endl;
        break;
      }
    }
  }
  return 0;
}
