// NAMA / NIM	: Chokyi Ozer / 13518107
// Tanggal		: 26 September 2019
// Topik		: Mesin Kata
// Deskripsi	: Menghitung jumlah kemunculan suatu substring

#include <stdio.h>
#include "mesinkata.h"

void Salin(Kata* dest, Kata src) {
/* Menyalin kata
   I.S. : dest sembarang, src sebuah kata yang valid
   F.S. : dest merupakan kata dengan panjang yang sama dengan src
          dan tiap karakter dest sama dengan src */
	// KAMUS LOKAL
	int i;
	
	// ALGORITMA
	for (i = 1; i <= src.Length; i++) {
		(*dest).TabKata[i] = src.TabKata[i];
	}
	(*dest).Length = src.Length;
}

int main () {
	// KAMUS
	Kata pattern;
	int i, j;
	int count;
	boolean identical;
	
	// ALGORITMA
	STARTKATA();
	Salin(&pattern, CKata);
	count = 0;
	ADVKATA();
	while (!EndKata) {
		for (i = 1; i <= CKata.Length - pattern.Length + 1; i++) {
			if (CKata.TabKata[i] == pattern.TabKata[1]) {
				identical = true;
				j = 1;
				while (identical && j < pattern.Length) {
					if (CKata.TabKata[i + j] == pattern.TabKata[1 + j]) {
						j++;
					} else {
						identical = false;
					}
				}
				if (identical) {
					count++;
				}
			}
		}
		ADVKATA();
	}
	
	printf("%d\n", count);
	
	return 0;
}
