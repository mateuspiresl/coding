# 1 "inline3.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "inline3.c"
inline void InsertionSort(int *v, int size);

int y[5] = { 5, 4, 3, 2, 1 };

int main(int argc, char* argv[]) {
 InsertionSort(y, 5);
 return y[0];
}
