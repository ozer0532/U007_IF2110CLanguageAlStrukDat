// NAMA/NIM 	: Chokyi Ozer/13518107
// Tanggal		: 5 September 2019
// Topik 		: Array Statis
// Deskripsi	: 

#include <stdio.h>
#include "array.h"

void Count(TabInt T, ElType x) {
	// KAMUS LOKAL
	int i;
	int count;
	
	// ALGORITMA
	count = 0;
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
		if (Elmt(T, i) == x) {
			count++;
		}
	}
	
	printf("%d\n", count);
}

void FirstOccurence (TabInt T, ElType x) {
	// KAMUS LOKAL
	int result;
	
	// ALGORITMA
	result = Search1(T, x);
	if (result != IdxUndef) {
		printf("%d\n", result);
	} else {
		printf("%d tidak ada\n", x);
	}
	
}

void Position (TabInt T, ElType x) {
	// KAMUS LOKAL
	int median;
	
	// ALGORITMA
	if (x == ValMax(T)) {
		printf("maksimum\n");
	}
	if (x == ValMin(T)) {
		printf("minimum\n");
	}
	
	InsSortAsc(&T);
	if (NbElmt(T) % 2 == 0) {
		median = Elmt(T, NbElmt(T) / 2);
	} else {	// N mod 2 = 1
		median = Elmt(T, NbElmt(T) / 2 + 1);
	}
	if (x == median) {
		printf("median\n");
	}
}

int main() {
	// KAMUS
	TabInt T;
	int X;
	
	// ALGORITMA
	BacaIsi(&T);
	TulisIsiTab(T);
	printf("\n");
	
	scanf("%d", &X);
	Count(T, X);
	FirstOccurence(T, X);
	Position(T, X);
	
	return 0;
}
