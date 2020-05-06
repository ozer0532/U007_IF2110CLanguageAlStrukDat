// NAMA/NIM	: Chokyi Ozer / 13518107
// Tanggal 	: 22 Aug 2019
// Topik 	: Pengenalan C
// Deskripsi: Menjumlahkan deret aritmetika dari 1 hingga N

#include <stdio.h>

int main () {
	// KAMUS
	int i;
	int n;
	int series;
	
	// ALGORITMA
	scanf("%d", &n);
	series = 0;
	for (i = 1; i <= n; i++) {
		series += i;
	}
	printf("%d\n", series);
	
	return 0;
}
