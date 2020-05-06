// NAMA / NIM	: Chokyi Ozer / 13518107
// Tanggal		: 26 September 2019
// Topik		: Mesin Kata
// Deskripsi	: Buat ADT mesin token yang menerima ekspresi matematika

#include "mesintoken.h"

/* State Mesin Kata */
boolean EndToken;
Token CToken;

int CharToInt (char c) {
	switch (c) {
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case '0': return 0;
	}
}

void IgnoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
   // KAMUS LOKAL
   
   // ALGORITMA
   while ((CC == BLANK) && (CC != MARK)) {
        ADV();
    }
}

void STARTTOKEN() {
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
	// KAMUS LOKAL
	
	// ALGORITMA
	START();
	IgnoreBlank();
	if (CC == MARK) {
		EndToken = true;
	} else {
		EndToken = false;
		SalinToken();
	}
}

void ADVTOKEN() {
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */
   // KAMUS LOKAL
   
   // ALGORITMA
   IgnoreBlank();
   if (CC == MARK) {
	   EndToken = true;
   } else {
	   SalinToken();
	   IgnoreBlank();
   }
}

void SalinToken() {
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	// KAMUS LOKAL
    int i = 1;

    // ALGORITMA
    CToken.val = 0;
    while ((CC != MARK) && (CC != BLANK) && (i <= NMax)) {
		if (CC == '+' || CC == '-' || CC == '*' || CC == '/'|| CC == '^') {
			CToken.tkn = CC;
			CToken.val = -1;
		} else {
			CToken.tkn = 'b';
			CToken.val = CToken.val * 10 + CharToInt(CC);
		}
        ADV();
        i++;
    } 
}
