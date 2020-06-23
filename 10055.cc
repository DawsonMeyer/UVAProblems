#include <stdio.h>
using namespace std;

int main()
{
   long long int a,b,c;

   while(scanf("%lld %lld", &a, &b) == 2) //while not end of file
   {
      if(a>b)
      {
	       c = a-b;
      }else{
	       c = b-a;
      }
      printf("%lld\n",c);
   }

   return 0;
}
