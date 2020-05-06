// NAMA/NIM 	: Chokyi Ozer/13518107
// Tanggal		: 5 September 2019
// Topik 		: Array Statis
// Deskripsi	: 

#include <stdio.h>
#include "array.h"

int main() {
	// KAMUS
	TabInt T;
	TabInt sortUp;
	TabInt sortDown;
	
	// ALGORITMA
	BacaIsi(&T);
	
	CopyTab(T, &sortUp);
	CopyTab(T, &sortDown);
	
	MaxSortDesc(&sortDown);
	InsSortAsc(&sortUp);
	
	if (IsEQ (sortUp, sortDown)) {
		printf("Array monotonik statik\n");
	} else if (IsEQ(sortDown, T)) {
		printf("Array monotonik tidak membesar\n");
	} else if (IsEQ(sortUp, T)) {
		printf("Array monotonik tidak mengecil\n");
	} else {
		printf("Array tidak monotonik\n");
	}
	
	return 0;
}
