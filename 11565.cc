#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;

  while(N)
  {
    int A, B, C;
    cin >> A >> B >> C;

    bool solved = false;
    int x, y, z;

    for(x = -100; x <= 100; x++)
    {
      for(y = -100; y <= 100; y++)
      {
        for(z = -100; z <= 100; z++)
        {
          if(x!=y && x!=z && y!=z && x+y+z == A && x*y*z == B && x*x+y*y+z*z == C)
          {
            if(!solved)
            {
              cout << x << " " << y << " " << z << endl;
              solved = true;
            }
          }
        }
      }
    }
    if(!solved)
    {
      cout << "No solution." << endl;
    }
    N--;
  }
}
