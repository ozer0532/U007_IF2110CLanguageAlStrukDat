// NAMA / NIM: Chokyi Ozer / 13518107
// Tanggal: 14 Nov 2019
// Topik: Tree
// Deskripsi: Menghasilkan pohon merkle

#include <stdio.h>
#include "bintree.h"

/* Menghasilkan true bila N adalah hasil dari 2^k
 * dimana k merupakan sebuah bilangan cacah */
boolean IsPowerOfTwo (int N) {
	// KAMUS LOKAL
	
	// ALGORITMA
	if (N > 0) {	
		while (N != 1 && N % 2 == 0) {
			N = N / 2;
		}
		return N == 1;
	} else {
		return false;
	}
}

void CreateMerkleTree (BinTree *P, int N, infotype * count) {
	// KAMUS LOKAL
	address Q;
	int l, r;
	
	// ALGORITMA
	*P = AlokNode(0);
	if (N == 1) {					// BASIS
		scanf("%d", count);
	} else {						// REKURENS
		CreateMerkleTree(&Left(*P), N/2, &l);
		CreateMerkleTree(&Right(*P), N/2, &r);
		*count = l + r;
	}
	Akar(*P) = *count;
}

int main () {
	// KAMUS LOKAL
	int N;
	BinTree P;
	int c;
	
	// ALGORITMA
	// Validasi nilai N
	scanf("%d", &N);
	if (!IsPowerOfTwo(N)) {
		printf("Jumlah masukan tidak sesuai\n");
	} else {
		CreateMerkleTree(&P, N, &c);
		PrintTree(P, 2);
	}
	
	return 0;
}
