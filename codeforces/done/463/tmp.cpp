#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define LLF "%I64u"
#define LLF "%llu"

int main(void) {
  unsigned long long int a, b, c, x, y, sum, c0;
  // scanf(LLF LLF LLF, &a, &b, &c);
  c = c0 = ULLONG_MAX;
  b = 10000223;
  a = 10000169;
  y = 0;
  sum = a + b;
  time_t t0 = time(NULL);
  while (c >= sum) { //if c becomes less than a+b, than there's no solution
    c -= b;
    if (c % a == 0) {
      break;
    }
  }
  if (c % a == 0) {
    y = (c0 - c) / b;
    x = c / a;
    printf("YES " LLF "*" LLF " + " LLF "*" LLF " = " LLF "\n", a, x, b, y, c);
  } else {
    printf("NO\n");
  }
  time_t t1 = time(NULL);
  printf("time :" LLF "\n", (unsigned long long) (t1 - t0));
  return 0;
}
