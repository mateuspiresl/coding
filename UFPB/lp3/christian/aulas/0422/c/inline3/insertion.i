# 1 "insertion.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "insertion.c"
inline void InsertionSort(int *v, int size) {
 int j;
 int key;

 for (int i = 1; i < size; i++) {
  key = v[i];
  j = i - 1;

  while (j >= 0 && v[j] > key) {
   v[j + 1] = v[j];
   j = j - 1;
  }

  v[j + 1] = key;
 }
}
