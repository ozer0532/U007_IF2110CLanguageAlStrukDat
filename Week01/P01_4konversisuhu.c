// NAMA/NIM	: Chokyi Ozer / 13518107
// Tanggal 	: 22 Aug 2019
// Topik 	: Pengenalan C
// Deskripsi: Mengkonversi suhu dari Celcius

#include <stdio.h>

int main () {
	// KAMUS
	float c;
	char code;
	float out;
	
	// ALGORITMA
	scanf("%f %c", &c, &code);
	if (code == 'R') {
		out = 0.8 * c;
	} else if (code == 'F') {
		out = (1.8 * c) + 32;
	} else if (code == 'K') {
		out = c + 273.15;
	} else {
		// Do Nothing
	}
	printf("%.2f\n", out);
	
	return 0;
}
