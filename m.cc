//basically, put on the stack and then pop with correct dimensions.
#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int t, num=1;
  cin >> t;
  while(t--)
  {
    cout << "Test " << num << endl;
    int r,c;
    stack<char> st;
    cin >> r >> c;
    char px;
    for(int i=0; i<r; i++)
    {
      for(int j=0; j<c; j++)
      {
        cin >> px;
        st.push(px);
      }
    }
    for(int i=0; i < r; i++)
    {
      for(int j=0; j<c; j++)
      {
        cout << st.top();
        st.pop();
      }
      cout << endl;
    }
    num++;
  }

  return 0;
}
