#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch;
	FILE *fin;
	FILE *fout;
	fin = fopen("in.txt", "rt");
	fout = fopen("out.txt", "wt");

	if (fin != NULL)
		while (!feof(fin)) {
			ch = getc(fin);
			if (ch < 48 || ch > 57)
				putc(ch, fout);
		}
	fclose(fin);
	fclose(fout);
	return 0;
}
