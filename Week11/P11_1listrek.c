// NAMA / NIM : Chokyi Ozer / 13518107
// Topik : Rekursif
// Deskripsi : ADT List Rekursif

/* *** Manajemen Memori *** */

#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"

/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    } else {
        return Nil;
    }
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void Dealokasi (address P) {
    // KAMUS LOKAL

    // ALGORITMA
    free(P);
}

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */

/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsEmpty(List L) {
    // KAMUS LOKAL

    // ALGORITMA
    if (L == Nil) {
        return 1;
    } else {
        return 0;
    }
}

/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
int IsOneElmt(List L) {
    // KAMUS LOKAL

    // ALGORITMA
    if (!IsEmpty(L)) {
        if (Next(L) == Nil) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

/* *** Selektor *** */

/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
infotype FirstElmt (List L) {
    // KAMUS LOKAL

    // ALGORITMA
    return Info(L);
}

/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
List Tail(List L) {
    // KAMUS LOKAL

    // ALGORITMA
    return Next(L);
}

/* *** Konstruktor *** */

/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
List Konso(infotype e, List L) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = Alokasi(e);
    if (P == Nil) {
        return L;
    } else {
        Next(P) = L;
        return P;
    }
}

/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
List KonsB(List L, infotype e) {
     // KAMUS LOKAL

    // ALGORITMA
    if (IsEmpty(L)) {
        return Alokasi(e);
    } else {
        Next(L) = KonsB(Tail(L), e);
        return L;
    }
}

/* *** Operasi Lain *** */

/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 
List Copy (List L) {
    // KAMUS LOKAL

    // ALGORITMA
    if (IsEmpty(L)) {               // BASIS 0
        return Nil;
    } else {                        // REKURENS
        return Konso(FirstElmt(L), Copy(Tail(L)));
    }
}

/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
void MCopy (List Lin, List *Lout) {
    // KAMUS LOKAL
    List LTemp;

    // ALGORITMA
    if (IsEmpty(Lin)) {
        *Lout = Nil;
    } else {
        MCopy(Tail(Lin), &LTemp);
        *Lout = Konso(FirstElmt(Lin), LTemp);
    }
}

/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
List Concat (List L1, List L2) {
    // KAMUS LOKAL

    // ALGORITMA
    if (IsEmpty(L1)) {          // BASIS 0
        return Copy(L2);
    } else {                    // REKURENS
        return Konso(FirstElmt(L1), Concat(Tail(L1), L2));
    }
}

/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
void MConcat (List L1, List L2, List *LHsl) {
    // KAMUS LOKAL
    List LTemp;
    // ALGORITMA
    if (IsEmpty(L1)) {
        *LHsl = Copy(L2);
    } else {
        MConcat(Tail(L1), L2, &LTemp);
        *LHsl = Konso(FirstElmt(L1), LTemp);
    }
}

/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
void PrintList (List L) {
    // KAMUS LOKAL

    // ALGORITMA
    if (!IsEmpty(L)) {
        printf("%d\n", FirstElmt(L));
        PrintList(Tail(L));
    }
}

/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
int NbElmtList (List L) {
    // KAMUS LOKAL

    // ALGORITMA
    if (IsEmpty(L)) {           // BASIS 0
        return 0;  
    } else {                    // REKURENS
        return 1 + NbElmtList(Tail(L));
    }
}

/* Mengirim true jika X adalah anggota list, false jika tidak */
boolean Search (List L, infotype X) {
    // KAMUS LOKAL

    // ALGORITMA
    if (IsEmpty(L)) {       // BASIS 0
        return false;
    } else {
        if (FirstElmt(L) == X) {
            return true;
        } else {            // REKURENS
            return Search(Tail(L), X);
        }
    }
}














/*** Pencarian nilai ekstrim ***/

/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */

/* Mengirimkan nilai info(P) yang maksimum */
infotype MaxList (List L) {
	// KAMUS LOKAL
	infotype max;
	
	// ALGORITMA
	if (IsOneElmt(L)) { // BASIS 1
		return FirstElmt(L);
	} else {
		max = MaxList(Tail(L));
		if (max > FirstElmt(L)) {
			return max;
		} else {
			return FirstElmt(L);
		}
	}
}

/* Mengirimkan nilai info(P) yang minimum */
infotype MinList (List L) {
	// KAMUS LOKAL
	infotype min;
	
	// ALGORITMA
	if (IsOneElmt(L)) { // BASIS 1
		return FirstElmt(L);
	} else {
		min = MinList(Tail(L));
		if (min < FirstElmt(L)) {
			return min;
		} else {
			return FirstElmt(L);
		}
	}
}

/* Mengirimkan total jumlah elemen List L */
infotype SumList (List L) {
    // KAMUS LOKAL

    // ALGORITMA
    if (IsEmpty(L)) {           // BASIS 0
        return 0;  
    } else {                    // REKURENS
        return FirstElmt(L) + SumList(Tail(L));
    }
}

/* Mengirimkan nilai rata-rata elemen list L */
float AverageList (List L) {
	// KAMUS LOKAL
	
	// ALGORITMA
	return (float)SumList(L) / (float)NbElmtList(L);
}

/*** Operasi-Operasi Lain ***/

/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
List InverseList (List L) {
	// KAMUS LOKAL
	
	// ALGORITMA
	if (IsEmpty(L)) {		// BASIS 0
		return Nil;
	} else {
		return KonsB(InverseList(Tail(L)), FirstElmt(L));
	}
}

/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */
void SplitPosNeg (List L, List *L1, List *L2) {
	// KAMUS LOKAL
	
	// ALGORITMA
	if (IsEmpty(L)) {			// BASIS 0
		*L1 = Nil;
		*L2 = Nil;
	} else {
		SplitPosNeg(Tail(L), L1, L2);
		if (FirstElmt(L) >= 0) {
			*L1 = Konso(FirstElmt(L), *L1);
		} else {
			*L2 = Konso(FirstElmt(L), *L2);
		}
	}
}

/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */
void SplitOnX (List L, infotype X, List *L1, List *L2) {
	// KAMUS LOKAL
	
	// ALGORITMA
	if (IsEmpty(L)) {			// BASIS 0
		*L1 = Nil;
		*L2 = Nil;
	} else {
		SplitOnX(Tail(L), X, L1, L2);
		if (FirstElmt(L) < X) {
			*L1 = Konso(FirstElmt(L), *L1);
		} else {
			*L2 = Konso(FirstElmt(L), *L2);
		}
	}
}

/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */
int ListCompare (List L1, List L2) {
	// KAMUS LOKAL
	
	// ALGORITMA
	if (IsEmpty(L1) || IsEmpty(L2)) {		// BASIS 0
		if (IsEmpty(L1) && !IsEmpty(L2)) {
			return -1;
		} else if (!IsEmpty(L1) && IsEmpty(L2)) {
			return 1;
		} else {
			return 0;
		}
	} else {
		if (FirstElmt(L1) < FirstElmt(L2)) {
			return -1;
		} else if (FirstElmt(L1) > FirstElmt(L2)) {
			return 1;
		} else {				// REKURENS
			return ListCompare(Tail(L1), Tail(L2));
		}
	}
}

/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
boolean IsAllExist (List L1, List L2) {
	// KAMUS LOKAL
	
	// ALGORITMA
	if (IsEmpty(L1)) {
		return false;
	} else {
		if (Search(L2, FirstElmt(L1))) {
			if (IsOneElmt(L1)) {
				return true;
			} else {
				return IsAllExist(Tail(L1), L2);
			}
		} else {
			return false;
		}
	}
}
