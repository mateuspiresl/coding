# 1 "inline4.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "inline4.c"
# 1 "insertion.h" 1
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
# 2 "inline4.c" 2

int y[5] = { 5, 4, 3, 2, 1 };

extern float Median(int *v, int size);

int main(int argc, char* argv[]) {
 InsertionSort(y, 5);
 float m = Median(y, 5);
 return (int) m * y[0];
}
