// NAMA / NIM: Chokyi Ozer / 13518107
// Tanggal: 19 September 2019
// Topik: ADT Matriks
// Deskripsi: Menerapkan konvolusi pada 2 matriks

#include <stdio.h>
#include "matriks.h"

int main()
{
	// KAMUS
	int N, M, K;
	MATRIKS A, B;
	MATRIKS C;
	
	int x, y; 
	int i, j, u, v;
	int ei, ej, eu, ev;
	int mp;				// Mid-point
	
	// ALGORITMA
	// INPUT
	scanf("%d %d", &N, &M);
	BacaMATRIKS(&A, N, M);
	scanf ("%d", &K);
	BacaMATRIKS(&B, K, K);
	
	// PROCESS
	MakeMATRIKS(N, M, &C);
	mp = (NBrsEff(B) + 1) / 2;
	
	for (x = GetFirstIdxBrs(C); x <= GetLastIdxBrs(C); x++) {
		for (y = GetFirstIdxKol(C); y <= GetLastIdxKol(C); y++) {
			Elmt(C, x, y) = 0;
			printf("----(%d, %d)----\n", x, y);
			// START POINT B
			u = (x - mp > 0)? GetFirstIdxBrs(B) : (GetFirstIdxBrs(B) + (mp - x));
			
			// START POINT A
			i = (x - mp < 0)? GetFirstIdxBrs(A) : (GetFirstIdxBrs(A) + (x - mp));
			
			// END POINT B
			eu = (x + mp - 1 <= GetLastIdxBrs(C))? GetLastIdxBrs(B) : (GetLastIdxBrs(B) - (x - mp + 1));
			ev = (y + mp - 1 <= GetLastIdxKol(C))? GetLastIdxKol(B) : (GetLastIdxKol(B) - (y - mp + 1));
			
			// SUMMING
			while (u <= eu) {
				// START POINT B
				v = (y - mp > 0)? GetFirstIdxKol(B) : (GetFirstIdxKol(B) + (mp - y));
				
				// START POINT A
				j = (y - mp < 0)? GetFirstIdxKol(A) : (GetFirstIdxKol(A) + (y - mp));
				
				while (v <= ev) {
					printf("A[%d, %d](%d) + B[%d, %d](%d)\n", i, j, Elmt(A, i, j), u, v, Elmt(B, u, v));
					Elmt(C, x, y) += Elmt(B, u, v) * Elmt(A, i, j);
					v++; j++;
				}
				printf("\n");
				u++; i++;
			}
			printf("\n");
		}
	}
	
	TulisMATRIKS(C);
	
	return 0;
}

