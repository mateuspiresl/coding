#include <bits/stdc++.h>

#define DIM 4 //define matrix functions	
#define cls(arr) memset(arr, 0, sizeof arr);

using namespace std;

//usefull
template<typename T> void swap(T *f, T *s) { *f = *f ^ *s; *s = *f ^ *s; *f = *f ^ *s; }


//functions

//base exponent
int power(int b, int e) { 
	return e == 0 ? 1 : b * power(b, e-1);
}

//number
int fact(int n) { 
	return n == 0 ? 1 : n * fact(n-1);
}

//more

//first, ratio, quantity
int sumPA(int i, int r, int n) { 
	return ((i + (i + r*(n-1)))*n) / 2;
}

//first, ratio, quantity
int sumPG(int i, int r, int n) {
	return r == 1 ? i * n : i *  ((1 - power(r, n) - 1) / (1 - r));
}

//quantity (>1)
int *fibNumbers(int n) { 
	int *f = (int*) malloc(sizeof(int) * n);
	f[0] = f[1] = 1;
	for(int i = 2; i < n; i++) f[i] = f[i-1] + f[i-2];
	return f;
}

//quantity (>0)
int *catNumbers(int n) { 
	int *c = (int*) malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) c[i] = fact(2*i) / (fact(i+1) * fact(i)); 
	return c;
}

//number base
char *numConvers(int n, int b) {
	char *num = (char*) malloc(sizeof(char) * 64);
	int cont = 64-1, contt;
	
	do {
		num[cont--] = (n%b >= 10 ? 'A' + (n-10)%b : '0' + n%b); 
		n /= b;
	} while(n != 0);

	for(cont = cont + 1, contt = 0; cont < 64; cont++, contt++)
		swap(&num[cont], &num[contt]);
	num[contt] = '\0';

	return num;
}

//result, left matrix, lrow, lcolumn, right matrix, rrow, rcolumn
void multMatrix(int res[][DIM], int m[][DIM], int rm, int cm, int n[][DIM], int rn, int cn) {
	if(cm != rn) return;
	
	for(int i = 0; i < rm; i++) cls(res[i])

	for(int i = 0; i < rm; i++)
		for(int j = 0; j < cn; j++)
			for(int k = 0; k < cm; k++)
				res[i][j] += m[i][k] * n[k][j];
}


// matrix, exponent (m[N][N]^E)
void matrixExponentiation(int m[][DIM], int N, int E) {
	int result[N][N];
	int tmp[N][N];

	for(int i = 0; i < N; i++) 
		for(int j = 0; j < N; j++)
			result[i][j] = (i==j ? 1 : 0);

	while(E) {
		if(E%2) {
			cls(tmp);
			for(int i = 0; i < N; i++)
	    		for(int j = 0; j < N; j++)
	    	   		for(int k = 0; k < N; k++)
	    	   			tmp[i][j] += m[i][k] * result[k][j];
	    	for(int i = 0; i < N; i++)
	    		for(int j = 0; j < N; j++)
	    			result[i][j] = tmp[i][j];
		}

		cls(tmp);
		for(int i = 0; i < N; i++)
	    	for(int j = 0; j < N; j++)
	    		for(int k = 0; k < N; k++)
	    			tmp[i][j] += m[i][k] * m[k][j];
	    for(int i = 0; i < N; i++)
	    	for(int j = 0; j < N; j++)
	    		m[i][j] = tmp[i][j];

		E/=2;
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			m[i][j] = result[i][j];
}

//initial, transition (probability j to i), time, trow, tcolumnn (P,k = T^k * P,0)
void markovChain(int p[], int T[][DIM], int k, int rt, int ct) {
	int tmp[ct];
	
	for(int i = 0; i < k; i++) {
		cls(tmp);
		for(int j = 0; j < rt; j++)
			for(int l = 0; l < ct; l++)
				tmp[j] += T[j][l] * p[l];
		for(int j = 0; j < rt; j++)
			p[j] = tmp[j];
	}
}

int main()
{

	return 0;
}
