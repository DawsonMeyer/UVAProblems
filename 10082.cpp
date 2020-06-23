#include <bits/stdc++.h>
using namespace std;

string keyboard = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";

int main() {
  char c;
  while(cin.get(c))
  {
    int index = keyboard.find(c);
    if(index != string::npos)
    {
      cout << keyboard[index-1];
    }
    else {cout << c;}
  }

  return 0;
}
