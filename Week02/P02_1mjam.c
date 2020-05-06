// NAMA / NIM - Chokyi Ozer / 13518107
// Tanggal - 29 Agustus 2019
// Topik - ADT Sederhana
// Deskripsi - Menghitung durasi meeting

#include <stdio.h>
#include "jam.h"

int main () {
	// KAMUS
	int n; // Jumlah input
	JAM max, min;
	JAM j1, j2; // Temp variable per record
	
	int i; // Iterator
	
	// ALGORITMA
	max = MakeJAM(0,0,0); min = MakeJAM(23,59,59); // Inisialisasi
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++) { // Traversal 1 to n times
		printf("[%d]\n", i);
		BacaJAM(&j1);
		BacaJAM(&j2);
		
		if (JLT(j1, j2)) {
			printf("%d\n", Durasi(j1, j2));
			if (JLT(j1, min)) {
				min = j1;
			}
			if (JGT(j2, max)) {
				max = j2;
			}
		} else { // j1 > j2
			printf("%d\n", Durasi(j2, j1));
			if (JLT(j2, min)) {
				min = j2;
			}
			if (JGT(j1, max)) {
				max = j1;
			}
		}
	}
	
	TulisJAM(min);
	printf("\n");
	TulisJAM(max);
	printf("\n");
	
	return 0;
}
