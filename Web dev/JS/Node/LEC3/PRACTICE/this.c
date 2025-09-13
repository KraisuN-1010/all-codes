#include<stdio.h>
int main() {
  printf("Hello world \n");
  int b = fun(3.5, 6.5);
  printf("%d", b);
}
int fun(double a, double b) {
  return a + b;
}