// NAMA / NIM: CHOKYI OZER
// TANGGAL: 7 NOVEMBER 2019
// TOPIK: REKURSIF
// DESKRIPSI: Hapus elemen ke-N dari belakang

#include "listrek.h"

/* L terdefinisi, tidak mungkin kosong. */
/* Elemen ke-n L dari depan akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 3, 4, 5] */
List delNFromStart(List L, int n) {
	// KAMUS LOKAL
	List P1;
	List P2;
	
	// ALGORITMA
	if (n == 1) {
		P1 = L;
		P2 = Next(L);
		Dealokasi(P1);
		return P2;
	} else {
		P1 = L;
		P2 = delNFromStart(Next(L), n-1);
		SetNext(P1, P2);
		return P1;
	}
}

/* L terdefinisi, tidak mungkin kosong. */
/* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 2, 3, 5] */
List delNFromEnd(List L, int n) {
	// KAMUS LOKAL
	int count;
	
	// ALGORITMA
	count = NbElmtList(L);
	return delNFromStart(L, count - n + 1);
}
