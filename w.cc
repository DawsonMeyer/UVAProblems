#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int a[100000];

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
      a[i] = 0;
      int w, num;
      cin >> w;
      while(w--)
      {
        cin >> num;
        a[i] += num;
      }
    }

    sort(a, a+n);
    double total = 0, cur = 0;
    for(int i=0; i<n; i++)
    {
      cur += a[i];
      total += cur;
    }

    cout << fixed << setprecision(8) << total/n << endl;
  }

  return 0;
}
