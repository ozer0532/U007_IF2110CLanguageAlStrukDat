// NAMA / NIM: Chokyi Ozer / 13518107
// Topik: ADT Matriks
// Deskripsi: Berisi fungsi yang berhubungan dengan matriks

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

#include "matriks.h"
#include <stdio.h>

/* *** Konstruktor membentuk MATRIKS *** */
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
void MakeMATRIKS (int NB, int NK, MATRIKS * M) {
    // KAMUS LOKAL

    // ALGORITMA
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */

boolean IsIdxValid (int i, int j) {
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
    // KAMUS LOKAL

    // ALGORITMA
    return (i >= BrsMin) && (i <= BrsMax) && (j >= KolMin) && (j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */

/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxBrs (MATRIKS M) {
    // KAMUS LOKAL

    // ALGORITMA
    return BrsMin;
}

/* Mengirimkan indeks kolom terkecil M */
indeks GetFirstIdxKol (MATRIKS M) {
    // KAMUS LOKAL

    // ALGORITMA
    return KolMin;
}

/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxBrs (MATRIKS M) {
    // KAMUS LOKAL

    // ALGORITMA
    return NBrsEff(M) + BrsMin - 1;
}

/* Mengirimkan indeks kolom terbesar M */
indeks GetLastIdxKol (MATRIKS M) {
    // KAMUS LOKAL

    // ALGORITMA
    return NKolEff(M) + KolMin - 1;
}

/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j) {
    // KAMUS LOKAL

    // ALGORITMA
    return (i >= GetFirstIdxBrs(M)) && (i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M)) && (j <= GetLastIdxKol(M));
}

/* Mengirimkan elemen M(i,i) */
ElType GetElmtDiagonal (MATRIKS M, indeks i) {
    // KAMUS LOKAL

    // ALGORITMA
    return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */


/* Melakukan assignment MHsl  MIn */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl) {
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);

    for (i = GetFirstIdxBrs(*MHsl); i <= GetLastIdxBrs(*MHsl); i++) {
        for (j = GetFirstIdxKol(*MHsl); j <= GetLastIdxKol(*MHsl); j++) {
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */

/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void BacaMATRIKS (MATRIKS * M, int NB, int NK) {
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    MakeMATRIKS(NB, NK, M);

    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            scanf("%d", &Elmt(*M, i, j));
        }
    }
}

/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
void TulisMATRIKS (MATRIKS M) {
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    for (i = GetFirstIdxBrs(M); i < GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
            printf("%d ", Elmt(M, i, j));
        }
        printf("%d\n", Elmt(M, i, j));
    }
    for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
        printf("%d ", Elmt(M, i, j));
    }
    printf("%d", Elmt(M, i, j));
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */

/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2) {
    // KAMUS LOKAL
    int i, j;
    MATRIKS out;

    // ALGORITMA
    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &out);

    for (i = GetFirstIdxBrs(out); i <= GetLastIdxBrs(out); i++) {
        for (j = GetFirstIdxKol(out); j <= GetLastIdxKol(out); j++) {
            Elmt(out, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
        }
    }

    return out;
}

/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2) {
    // KAMUS LOKAL
    int i, j;
    MATRIKS out;

    // ALGORITMA
    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &out);

    for (i = GetFirstIdxBrs(out); i <= GetLastIdxBrs(out); i++) {
        for (j = GetFirstIdxKol(out); j <= GetLastIdxKol(out); j++) {
            Elmt(out, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
        }
    }

    return out;
}

/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2) {
    // KAMUS LOKAL
    int i, j, k;
    MATRIKS out;

    // ALGORITMA
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &out);

    for (i = GetFirstIdxBrs(out); i <= GetLastIdxBrs(out); i++) {
        for (j = GetFirstIdxKol(out); j <= GetLastIdxKol(out); j++) {
            Elmt(out, i, j) = 0;
            for (k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++) {
                Elmt(out, i, j) += Elmt(M2, k, j) * Elmt(M1, i, k);
            }
        }
    }

    return out;
}

/* Mengirim hasil perkalian setiap elemen M dengan X */
MATRIKS KaliKons (MATRIKS M, ElType X) {
    // KAMUS LOKAL
    int i, j;
    MATRIKS out;

    // ALGORITMA
    MakeMATRIKS(NBrsEff(M), NKolEff(M), &out);

    for (i = GetFirstIdxBrs(out); i <= GetLastIdxBrs(out); i++) {
        for (j = GetFirstIdxKol(out); j <= GetLastIdxKol(out); j++) {
            Elmt(out, i, j) = Elmt(M, i, j) * X;
        }
    }

    return out;
}

/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
void PKaliKons (MATRIKS * M, ElType K) {
    // KAMUS LOKAL

    // ALGORITMA
    *M = KaliKons(*M, K);
}

/* ********** Operasi lain ********** */

/* Mengirimkan banyaknya elemen M */
int NBElmt (MATRIKS M) {
    // KAMUS LOKAL

    // ALGORITMA
    return (GetLastIdxBrs(M) - GetFirstIdxBrs(M) + 1) * (GetLastIdxKol(M) - GetFirstIdxKol(M) + 1);
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */


/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean EQ (MATRIKS M1, MATRIKS M2) { 
    // KAMUS LOKAL
    boolean out;
    int i, j;

    // ALGORITMA
    if (GetFirstIdxBrs(M1) == GetFirstIdxBrs(M2) && GetLastIdxBrs(M1) == GetLastIdxBrs(M2) && NBElmt(M1) == NBElmt(M2)) {
        i = GetFirstIdxBrs(M1);
        out = true;
        while (out && i <= GetLastIdxBrs(M1)) {
            j = GetFirstIdxKol(M2);
            while (out && j <= GetLastIdxKol(M2)) {
                if (Elmt(M1, i, j) != Elmt(M2, i, j)) {
                    out = false;
                } else {
                    j++;
                }
            }
            i++;
        }
    } else {
        out = false;
    }
    return out;
}

/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean NEQ (MATRIKS M1, MATRIKS M2) {
    // KAMUS LOKAL

    // ALGORITMA
    return !EQ(M1, M2);
}

/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
boolean EQSize (MATRIKS M1, MATRIKS M2) {
    // KAMUS LOKAL

    // ALGORITMA
    return NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */

/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsBujurSangkar (MATRIKS M) {
    // KAMUS LOKAL

    // ALGORITMA
    return NBrsEff(M) == NKolEff(M);
}

/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSimetri (MATRIKS M) {
    // KAMUS LOKAL
    boolean out;
    int i, j;

    // ALGORITMA
    if (IsBujurSangkar(M)) {
        i = GetFirstIdxBrs(M);
        out = true;
        while (out && i <= GetLastIdxBrs(M)) {
            j = GetFirstIdxKol(M);
            while (out && j <= GetLastIdxKol(M)) {
                if (Elmt(M, i, j) != Elmt(M, j, i)) {
                    out = false;
                } else {
                    j++;
                }
            }
            i++;
        }
    } else {
        out = false;
    }
    return out;
}

/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean IsSatuan (MATRIKS M) {
    // KAMUS LOKAL
    boolean out;
    int i, j;

    // ALGORITMA
    if (IsBujurSangkar(M)) {
        i = GetFirstIdxBrs(M);
        out = true;
        while (out && i <= GetLastIdxBrs(M)) {
            j = GetFirstIdxKol(M);
            while (out && j <= GetLastIdxKol(M)) {
                if (i == j) {
                    if (Elmt(M, i, j) != 1) {
                        out = false;
                    } else {
                        j++;
                    }
                } else {
                    if (Elmt(M, i, j) != 0) {
                        out = false;
                    } else {
                        j++;
                    }
                }
            }
            i++;
        }
    } else {
        out = false;
    }
    return out;
}

/* Mengirimkan true jika M adalah matriks sparse: mariks "jarang" dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
boolean IsSparse (MATRIKS M) {
    // KAMUS LOKAL
    int count;
    int i, j;

    // ALGORITMA
    count = 0;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            if (Elmt(M, i, j) != 0) {
                count ++;
            }
        }
    }
    return (count * 20) < NBElmt(M);
}

/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
MATRIKS Inverse1 (MATRIKS M) {
    // KAMUS LOKAL
    MATRIKS out;
    int i, j;

    // ALGORITMA
    MakeMATRIKS(NBrsEff(M), NKolEff(M), &out);

    for (i = GetFirstIdxBrs(out); i <= GetLastIdxBrs(out); i++) {
        for (j = GetFirstIdxKol(out); j <= GetLastIdxKol(out); j++) {
            Elmt(out, i, j) = Elmt(M, i, j) * -1;
        }
    }
    return out;
}

/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
float Determinan (MATRIKS M) {
    // KAMUS LOKAL
    MATRIKS minor;
    int i, j, k; // Iterator M
    int m, n;    // Iterator minor
    int det;

    // ALGORITMA
    if (NBElmt(M) != 1) {
        det = 0;
        for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
            MakeMATRIKS(NBrsEff(M) - 1, NKolEff(M) - 1, &minor);
            m = BrsMin;
            for (j = GetFirstIdxBrs(M); j <= GetLastIdxBrs(M); j++) {
                if (i != j) {
                    n = KolMin;
                    for (k = GetFirstIdxKol(M) + 1; k <= GetLastIdxKol(M); k++) {
                        Elmt(minor, m, n) = Elmt(M, j, k);
                        n++;
                    }
                    m++;
                }
            }
            det += Elmt(M, i, GetFirstIdxKol(M)) * Determinan(minor) * ((i%2 == 1)?1:-1);
        }
    } else {
        return Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M));
    }
}

/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void PInverse1 (MATRIKS * M) {
    // KAMUS LOKAL

    // ALGORITMA
    *M = Inverse1(*M);
}

/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
void Transpose (MATRIKS * M) {
    // KAMUS LOKAL
    MATRIKS out;
    int i, j;

    // ALGORITMA
    MakeMATRIKS(NBrsEff(*M), NKolEff(*M), &out);

    for (i = GetFirstIdxBrs(out); i <= GetLastIdxBrs(out); i++) {
        for (j = GetFirstIdxKol(out); j <= GetLastIdxKol(out); j++) {
            Elmt(out, i, j) = Elmt(*M, j, i);
        }
    }
    CopyMATRIKS(out, M);
}

/* ********** KELOMPOK PRAKTIKUM 5 ********** */

/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
float RataBrs (MATRIKS M, indeks i) {
	// KAMUS LOKAL
	float sum;
	int count;
	int j;
	
	// ALGORITMA
	sum = 0;
	count = 0;
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
		count ++;
		sum += (float)Elmt(M, i, j);
	}
	
	return (sum/(float)count);
}

/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
float RataKol (MATRIKS M, indeks j) {
	// KAMUS LOKAL
	float sum;
	int count;
	int i;
	
	// ALGORITMA
	sum = 0;
	count = 0;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		count ++;
		sum += (float)Elmt(M, i, j);
	}
	
	return (sum/(float)count);
}

/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min) {
	// KAMUS LOKAL
	int j;
	
	// ALGORITMA
	*max = Elmt(M, i, GetFirstIdxKol(M));
	*min = Elmt(M, i, GetFirstIdxKol(M));
	for (j = GetFirstIdxKol(M) + 1; j <= GetLastIdxKol(M); j++) {
		if (Elmt(M, i, j) > *max) {
			*max = Elmt(M, i, j);
		} else if (Elmt(M, i, j) < *min) {
			*min = Elmt(M, i, j);
		}
	}
}

/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min) {
	// KAMUS LOKAL
	int i;
	
	// ALGORITMA
	*max = Elmt(M, GetFirstIdxBrs(M), j);
	*min = Elmt(M, GetFirstIdxBrs(M), j);
	for (i = GetFirstIdxBrs(M) + 1; i <= GetLastIdxBrs(M); i++) {
		if (Elmt(M, i, j) > *max) {
			*max = Elmt(M, i, j);
		} else if (Elmt(M, i, j) < *min) {
			*min = Elmt(M, i, j);
		}
	}
}

/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
int CountXBrs (MATRIKS M, indeks i, ElType X) {
	// KAMUS LOKAL
	int count;
	int j;
	
	// ALGORITMA
	count = 0;
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
		if (Elmt(M, i, j) == X) {
			count ++;
		}
	}
	
	return count;
}

/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
int CountXKol (MATRIKS M, indeks j, ElType X) {
	// KAMUS LOKAL
	int count;
	int i;
	
	// ALGORITMA
	count = 0;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		if (Elmt(M, i, j) == X) {
			count ++;
		}
	}
	
	return count;
}
