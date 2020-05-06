// NAMA / NIM - CHOKYI OZER 13518107
// TANGGAL - 12 SEP 2019
// Topik - ARRAY DINAMIS
// DESKRIPSI - Array V3

#include "arraydinpos.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel) {
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
	// KAMUS LOKAL
	int i;

    // ALGORITMA
    TI(*T) = (int *) malloc ((maxel + IdxMin) * sizeof(int));
    MaxEl(*T) = maxel;
    for (i = IdxMin; i <= maxel; i++) {
		Elmt(*T, i) = ValUndef;
	}
}

void Dealokasi(TabInt *T) {
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    // KAMUS LOKAL

    // ALGORITMA
    free(TI(*T));
    MaxEl(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T) { 
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
	// KAMUS LOKAL
	int count;
	
	// ALGORITMA
	count = 0;
	while (count < MaxEl(T) + IdxMin && 
			Elmt(T, count + IdxMin) != ValUndef) {
		count++;
	}
	return count;
}
/* *** Daya tampung container *** */
int MaxElement(TabInt T) { return MaxEl(T); }
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T) { return IdxMin; }
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T) { return IdxMin + NbElmt(T) - 1; }
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i) { return (i >= IdxMin) && (i <= MaxEl(T)); }
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i) { return (i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)); }
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T) { return NbElmt(T) == 0; }
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T) { return NbElmt(T) == MaxEl(T); }
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T) {
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
    // KAMUS LOKAL
    int N;
    int i;

    // ALGORITMA
    MakeEmpty(T, MaxEl(*T));

    do {
        scanf("%d", &N);
    } while (N > MaxElement(*T) || N < 0);

    if (N != 0) {
        for (i = IdxMin; i <= N - IdxMin + 1; i++) {
            scanf("%d", &Elmt(*T, i));
        }
    }
}
void TulisIsiTab(TabInt T) {
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    if (NbElmt(T) == 0) {
        printf("[]");
    } else {
        printf("[%d", Elmt(T,GetFirstIdx(T)));
        for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++) {
            printf(",%d", Elmt(T, i));
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus) {
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen T1-T2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    // KAMUS LOKAL
    int i;
    TabInt T;

    // ALGORITMA
    MakeEmpty(&T, NbElmt(T1) + NbElmt(T2) + IdxMin);
    for (i = 1; i <= NbElmt(T1); i++) {
        if (plus) {
            Elmt(T, i) = Elmt(T1, i + GetFirstIdx(T1) - 1) + Elmt(T2, i + GetFirstIdx(T2) - 1);
        } else {
            Elmt(T, i) = Elmt(T1, i + GetFirstIdx(T1) - 1) - Elmt(T2, i + GetFirstIdx(T2) - 1);
        }
    }
    return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2) {
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
    // KAMUS LOKAL
    int i;
    boolean out;

    // ALGORITMA
    if (NbElmt(T1) == NbElmt(T2)) {
        out = true;
        for (i = 1; i <= NbElmt(T1); i++) {
            if (Elmt(T1, i + GetFirstIdx(T1) - 1) != Elmt(T2, i + GetFirstIdx(T2) - 1)) {
                out = false;
            }
        }
    } else {
        out = false;
    }
    return out;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X) {
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
    // KAMUS LOKAL
    IdxType idx;
    int i;

    // ALGORITMA
    idx = IdxUndef;
    if (NbElmt(T) != 0) {
        for (i = GetLastIdx(T); i >= GetFirstIdx(T); i--) {
            if (Elmt(T, i) == X) {
                idx = i;
            }
        }
    }
    return idx;
}

boolean SearchB(TabInt T, ElType X) {
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
    // KAMUS LOKAL
    int i;
    boolean output;

    // ALGORITMA
    output = false;
    i = GetFirstIdx(T);
    if (NbElmt(T) != 0) {
        while (i <= GetLastIdx(T) && !output) {
            if (Elmt(T, i) == X) {
                output = true;
            }
            i++;
        }
    }
    return output;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min) {
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
	// KAMUS LOKAL
    ElType max;
    ElType min;
    int i;

    // ALGORITMA
    max = Elmt(T, GetLastIdx(T));
    min = max;
    for (i = GetLastIdx(T); i >= GetFirstIdx(T); i--) {
        if (Elmt(T, i) > max) {
            max = Elmt(T, i);
        }
        if (Elmt(T, i) < min) {
            min = Elmt(T, i);
        }
    }
    *Max = max;
    *Min = min;  
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout) {
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    MakeEmpty(Tout, MaxEl(Tin));
    for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}
ElType SumTab(TabInt T) {
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
    // KAMUS LOKAL
    ElType sum;
    int i;

    // ALGORITMA
    sum = 0;
    for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        sum += Elmt(T, i);
    }
    return sum;
}
int CountX(TabInt T, ElType X) {
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
    // KAMUS LOKAL
    int count;
    int i;

    // ALGORITMA
    count = 0;
    for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (Elmt(T, i) == X) {
            count ++;
        }
    }
    return count;
}
boolean IsAllGenap(TabInt T) {
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
    // KAMUS LOKAL
    int i;
    boolean output;

    // ALGORITMA
    output = true;
    i = GetFirstIdx(T);
    if (NbElmt(T) != 0) {
        while (i <= GetLastIdx(T) && output) {
            if (Elmt(T, i) % 2 != 0) {
                output = false;
            }
            i++;
        }
    }
    if (IsEmpty(T)) output = false;
    return output;
}

void DelEli (TabInt * T, IdxType i, ElType * X) {
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
    // KAMUS LOKAL
    int j;

    // ALGORITMA
    *X = Elmt(*T, i);
    for (j = i + 1; j <= GetLastIdx(*T); j++) {
        Elmt(*T, j - 1) = Elmt(*T, j);
    }
    Elmt(*T, GetLastIdx(*T)) = ValUndef;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc) {
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
    // KAMUS LOKAL
    int i;
    IdxType idx;
    ElType max, min;
    TabInt out;
    int N;

    // ALGORITMA
    MakeEmpty(&out, MaxEl(*T));
    N = NbElmt(*T);
    for (i = 0; i < N; i++) {
        MaxMin(*T, &max, &min);
        if (asc) {
            idx = Search1(*T, min);
            DelEli(T, idx, &min);
            AddAsLastEl(&out, min);
        } else {
            idx = Search1(*T, max);
            DelEli(T, idx, &max);
            AddAsLastEl(&out, max);
        }
    }

    CopyTab(out, T);
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X) {
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    // KAMUS LOKAL

    // ALGORITMA
    Elmt(*T, NbElmt(*T) + IdxMin) = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X) {
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    // KAMUS LOKAL

    // ALGORITMA
    *X = Elmt(*T, NbElmt(*T) + IdxMin - 1);
    Elmt(*T, NbElmt(*T) + IdxMin - 1) = ValUndef;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num) {
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
    // KAMUS LOKAL

    // ALGORITMA
    realloc(TI(*T), (MaxEl(*T) + IdxMin + num) * sizeof(int));
    MaxEl(*T) += num;
}

void ShrinkTab(TabInt *T, int num) {
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
    // KAMUS LOKAL

    // ALGORITMA
    realloc(TI(*T), (MaxEl(*T) + IdxMin - num) * sizeof(int));
    MaxEl(*T) -= num;
}

void CompactTab(TabInt *T) {
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
    // KAMUS LOKAL

    // ALGORITMA
    realloc(TI(*T), (NbElmt(*T) + IdxMin) * sizeof(int));
    MaxEl(*T) = NbElmt(*T);
}
