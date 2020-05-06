// NAMA / NIM : CHOKYI OZER / 13518107
// TANGGAL : 3 Oktober 2019
// TOPIK : ADT Queue
// DESKRIPSI : Membuat ADT Priority Queue

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q) {
/* Mengirim true jika Q kosong: lihat definisi di atas */
	// KAMUS LOKAL
	
	// ALGORITMA
	return Head(Q) == Nil && Tail(Q) == Nil;
}

boolean IsFull (PrioQueueChar Q) {
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
	// KAMUS LOKAL
	int diff;
	
	// ALGORITMA
	diff = Head(Q) - Tail(Q);
	return diff == -1 || diff == (1 - MaxEl(Q));
}

int NBElmt (PrioQueueChar Q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	// KAMUS LOKAL
	
	// ALGORITMA
	return (IsEmpty(Q)) ? 0 : ((Tail(Q) - Head(Q) + MaxEl(Q) + 1) % MaxEl(Q));
}

/* *** Kreator *** */
void CreateEmpty (PrioQueueChar * Q, int Max) {
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	// KAMUS LOKAL
	
	// ALGORITMA
	(*Q).T = (infotype *) malloc ((Max + 1) * sizeof(infotype));
	if ((*Q).T != NULL) {
		MaxEl(*Q) = Max;
		Head(*Q) = 0;
		Tail(*Q) = 0;
	} else {
		MaxEl(*Q) = 0;
		Head(*Q) = 0;
		Tail(*Q) = 0;
	}
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q) {
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	// KAMUS LOKAL
	
	// ALGORITMA
	free((*Q).T);
	MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void Add (PrioQueueChar * Q, infotype X) {
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
	// KAMUS LOKAL
	int i, j;
	boolean found;
	
	// ALGORITMA
	if (IsEmpty(*Q)) {			// KASUS KOSONG
		Head(*Q) = 1;
		Tail(*Q) = 1;
		InfoHead(*Q) = X;
	} else {						// KASUS TENGAH
		found = false;
		i = Head(*Q);
		while (i != Tail(*Q) && !found) {
			if (Prio(Elmt(*Q, i)) > Prio(X)) {		// FOUND
				
				for (j = Tail(*Q); j != i; j = ((j - 2 + MaxEl(*Q)) % MaxEl(*Q)) + 1) {
					Elmt(*Q, (j == MaxEl(*Q))?1:j+1) = Elmt(*Q, j);
				}
				Elmt(*Q, (i == MaxEl(*Q))?1:i+1) = Elmt(*Q, i);
				Elmt(*Q, i) = X;
				
				Tail(*Q) = (Tail(*Q) == MaxEl(*Q))?1:Tail(*Q)+1;
				found = true;
			} else {
				i = (i == MaxEl(*Q))?1:i+1;
			}
		}
		
		if (!found) {				// KASUS BELAKANG
			if (Prio(InfoTail(*Q)) > Prio(X)) {
				Tail(*Q) = (Tail(*Q) == MaxEl(*Q))?1:Tail(*Q)+1;
				InfoTail(*Q) = Elmt(*Q, i);
				Elmt(*Q, i) = X;
			} else {
				Tail(*Q) = (Tail(*Q) == MaxEl(*Q))?1:Tail(*Q)+1;
				InfoTail(*Q) = X;
			}
		}
	}
}

void Del (PrioQueueChar * Q, infotype * X) {
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
    // KAMUS LOKAL
    
    // ALGORITMA
    *X = InfoTail(*Q);
    Tail(*Q) = ((Tail(*Q) - 2 + MaxEl(*Q)) % MaxEl(*Q)) + 1;
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q) {
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
	// KAMUS LOKAL
	int i;
	
	// ALGORITMA
	for (i = Head(Q); i != Tail(Q); i = (i == MaxEl(Q))?1:i+1) {
		printf("%d %c\n", Prio(Elmt(Q, i)), Info(Elmt(Q, i)));
	}
	if (!IsEmpty(Q)) {
		printf("%d %c\n", Prio(InfoTail(Q)), Info(InfoTail(Q)));
	}
	printf("#\n");
}
