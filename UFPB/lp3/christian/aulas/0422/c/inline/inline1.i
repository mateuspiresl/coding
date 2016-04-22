# 1 "inline1.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "inline1.c"
int F1(int a)
{
 return a + 1;
}

int main(int argc, char *argv[])
{
 int x;

 if (argc > 1)
  x = 2;
 else
  x = 1;

 x = F1(x);

 return x;
}
