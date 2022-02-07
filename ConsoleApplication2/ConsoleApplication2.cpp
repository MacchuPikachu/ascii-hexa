#include <stdio.h>

int main() {
	FILE* soubor = fopen("vystup.txt", "w");

	if (soubor == NULL) {
		printf("ERROR: Soubor nelze otevrit\n");
		return 1;
	}

	int ascii = 0x40;

	fprintf(soubor, "ASCII | HEXADECIMALNI\n");

	for (int i = 0; i < 26; i++) {
		ascii += 1;
		fwrite(&ascii, sizeof(int), 1, soubor);
		fprintf(soubor, "0x%x\n", ascii);
	}

	if (fclose(soubor) == EOF) {
		printf("ERROR: Soubor se nepodarilo otevrit\n");
		return 1;
	}

	return(0);
}