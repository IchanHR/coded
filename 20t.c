#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fcens = fopen("censored.txt", "w");
    FILE *fwords = fopen("words.txt", "w");

    if (!fin || !fcens || !fwords) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    char word[100];
    int censored_count = 0;
    int line_length = 0;

    while (fscanf(fin, "%s", word) != EOF) {
        char clean_word[100];
        int len = strlen(word);
        int clean_len = 0;

        // Bersihkan karakter non-huruf di akhir (misal koma, titik)
        for (int i = 0; i < len; ++i) {
            if (isalpha(word[i])) {
                clean_word[clean_len++] = word[i];
            }
        }
        clean_word[clean_len] = '\0';

        if (strlen(clean_word) == 4) {
            // Tambahkan newline jika baris melebihi 40 karakter
            if (line_length + 5 > 40) {
                fprintf(fcens, "\n");
                line_length = 0;
            }
            fprintf(fcens, "**** ");
            fprintf(fwords, "%s\n", clean_word);
            censored_count++;
            line_length += 5; // **** + spasi
        } else {
            // Tambahkan newline jika baris melebihi 40 karakter
            if (line_length + strlen(word) + 1 > 40) {
                fprintf(fcens, "\n");
                line_length = 0;
            }
            fprintf(fcens, "%s ", word);
            line_length += strlen(word) + 1;
        }
    }

    printf("%d words were censored!\n", censored_count);

    fclose(fin);
    fclose(fcens);
    fclose(fwords);
    return 0;
}
