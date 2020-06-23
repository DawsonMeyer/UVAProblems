/*
  Dawson Meyer
  Problem #497: Strategic Defence Initiative

  Need to dynamically allocate the space in the data structure.  So use a
  Vector.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> M;

//changing Howard's code to work with vectors that get passed in
int sasc_seq(vector<int> v1, int S[])
{
   vector<int> last(v1.size()+1), pos(v1.size()+1), pred(v1.size());
   if (v1.size() == 0) {
      return 0;
   }

   int len = 1;
   last[1] = v1[pos[1] = 0];

   for (int i = 1; i < v1.size(); i++) {
      int j = lower_bound(last.begin()+1, last.begin()+len+1, v1[i]) -
	 last.begin();
      pred[i] = (j-1 > 0) ? pos[j-1] : -1;
      last[j] = v1[pos[j] = i];
      len = max(len, j);
   }

   int start = pos[len];
   for (int i = len-1; i >= 0; i--) {
      S[i] = v1[start];
      start = pred[start];
   }

   return len;
}

int main()
{
   int N;
   cin >> N;
   cin.ignore();
   cin.ignore();
   while(N)
   {
      M.clear();
      N--;
      string temp;
      int alt;
      while(getline(cin, temp) && temp != "")
      {
	       alt = stoi(temp, 0, 10);
	       M.push_back(alt);
      }
      int ans=0;
      int *S = new int[M.size()];
      ans = sasc_seq(M, S);

      cout << "Max hits: " << ans << endl;
      for(int i=0; i < ans; i++)
      {
	       cout << S[i] << endl;
      }
      delete S;

      if(N)
      {
	       cout << endl;
      }
   }
   return 0;
}
