# 1 "sumdata.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "sumdata.c"
int x[5] = { 1, 2, 3, 4, 5 };

int Sum(void) {
 int i;
 int acc = 0;

 for (i = 0; i < 5; i++)
  acc += x[i];

 return acc;
}
