// NAMA/NIM	: Chokyi Ozer / 13518107
// Tanggal 	: 22 Aug 2019
// Topik 	: Pengenalan C
// Deskripsi: Menjumlahkan 3 angka di layar

#include <stdio.h>

int main () {
	// KAMUS
	int a, b, c;
	int max;
	// ALG0RITMA
	scanf("%d %d %d", &a, &b, &c);
	max = max2(max2(a, b), c);
	printf("%d\n", max);

	return 0;
}

int max2 (int a, int b) {
	return (a > b)? a:b;
}
