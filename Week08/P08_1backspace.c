// Nama / NIM : Chokyi Ozer
// Tanggal : 17 Oktober 2019
// Topik : ADT Stack
// Deskripsi : Mengecek kesamaan sequence

#include <stdio.h>
#include "stackt.h"

int main () {
	// KAMUS
	int n, m;
	Stack a, b;
	
	int i, input;
	boolean found;
	
	// ALGORITMA
	
	// init
	CreateEmpty(&a);
	CreateEmpty(&b);
	scanf("%d %d", &n, &m);
	
	// proses input
	// a
	for (i = 0; i < n; i++) {
		scanf("%d", &input);
		if (input == 0) {
			if (!IsEmpty(a)) {
				Pop(&a, &input);
			}
		} else {
			Push(&a, input);
		}
	}
	
	// b
	for (i = 0; i < m; i++) {
		scanf("%d", &input);
		if (input == 0) {
			if (!IsEmpty(b)) {
				Pop(&b, &input);
			}
		} else {
			Push(&b, input);
		}
	}
	
	// proses cek
	while (!IsEmpty(a) && !IsEmpty(b) && !found) {
		Pop(&a, &n);
		Pop(&b, &m);
		if (n != m) {
			found = true;
		}
	}
	
	if ((!(IsEmpty(a) && IsEmpty(b)) && (IsEmpty(a) || IsEmpty(b))) || found) {
		printf("Tidak sama\n");
	} else {
		printf("Sama\n");
	}
	
	
	return 0;
}
