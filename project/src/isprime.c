#include "isprime.h"
#include <stdio.h>
#include <math.h>

int isprime(int n) {
   int f = 1;
   for (int i=2; i <= sqrt(n); i++) { 
      if (n % i == 0) { 
         f = 0;
	 break;
      }
   } 
   return f;
}
