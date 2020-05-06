// NAMA / NIM: CHOKYI OZER / 13518107
// TANGGAL : 24 Oktober 2019
// TOPIK : ADT List
// DESKRIPSI : Buat implementasi cache skema LRU

#include "listlinier.h"
#include <stdio.h>

int main () {
	// KAMUS
	int N;
	int Q;
	List L;
	int i;
	infotype getData;
	address addr;
	
	// ALGORITMA
	scanf("%d %d", &N, &Q);
	
	// init list
	CreateEmpty(&L);
	for (i = 1; i <= N; i++) {
		InsVLast(&L, i);
	}
	
	// cek hit/miss
	for (i = 1; i <= Q; i++) {
		scanf("%d", &getData);
		addr = Search(L, getData);
		if (addr != Nil) {
			DelP (&L, getData);
			InsVFirst(&L, getData);
			printf("hit ");
			PrintInfo(L);
			printf("\n");
		} else {
			DelVLast (&L, &N);
			InsVFirst(&L, getData);
			printf("miss ");
			PrintInfo(L);
			printf("\n");
		}
	}
	
	return 0;
}
