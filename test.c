#include <stdio.h>

enum Hari {SENIN=1, SELASA, RABU};

int main(){
  enum Hari h = RABU;
  printf("%d\n", h);
  return 0;
}