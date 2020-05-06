// NAMA / NIM: Chokyi Ozer / 13518107
// Tanggal: 14 Nov 2019
// Topik: Tree
// Deskripsi: Menghasilkan cerminan dari tree

#include "bintree.h"

/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */
void InvertBtree(BinTree *P) {
		// KAMUS LOKAL
		BinTree L, R;
		
		// ALGORITMA
		if (IsTreeEmpty(*P)) {
			// Do Nothing
		} else {
			L = Left(*P);
			R = Right(*P);
			InvertBtree(&L);
			InvertBtree(&R);
			Left(*P) = R;
			Right(*P) = L;
		}
}
 
