// NAMA / NIM: Chokyi Ozer / 13518107
// Tanggal: 31-10-19
// Topik: Variasi List Linier
// Deskripsi: Round Robin

#include "listsirkuler.h"
#include <stdio.h>

/* Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
- jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar */
/* Jika L kosong, cetak "List kosong" */
/* I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir L diproses sesuai aturan round-robin.
L mungkin menjadi kosong. */
void DeleteRR (List *L, infotype TQ) {
	// KAMUS LOKAL
	address P;
	infotype temp;
	
	// ALGORITMA
	P = First(*L);
	while (Next(P) != First(*L)) {
		P = Next(P);
	}
	Info(P) -= TQ;
	if (Info(P) > 0) {
		First(*L) = P;
		printf("%d\n", TQ);
	} else {
		printf("%d\n", Info(P) + TQ);
		DelVLast(L, &temp);
	}
}

/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */
float Average (List L) {
	// KAMUS LOKAL
	address P;
	infotype sum;
	int count;
	
	// ALGORITMA
	P = First(L);
	sum = Info(P);
	count = 1;
	while (Next(P) != First(L)) {
		P = Next(P);
		sum += Info(P);
		count++;
	}
	return ((float)sum)/((float)count);
}


int main () {
	// KAMUS
	infotype Q;
	char code;
	List L;
	int data;
	float avg;
	
	// ALGORITMA
	// input T_Q
	do {
		scanf("%d", &Q);
	} while (Q <= 0);
	CreateEmpty(&L);
	
	// main loop
	while (true) {
		scanf(" %c", &code);
		if (code == 'A') {
			scanf("%d", &data);
			if (data > 0) {
				InsVFirst(&L, data);
			}
		} else if (code == 'D') {
			if (IsEmpty(L)) {
				printf("List kosong\n");
			} else {
				DeleteRR(&L, Q);
			}
		} else if (code == 'F') {
			if (IsEmpty(L)) {
				printf("Proses selesai\n");
			} else {
				avg = Average(L);
				printf("%.2f\n", avg);
			}
			
			return 0;
			
		} else {
			printf("Kode salah\n");
			
		}
	}
}
