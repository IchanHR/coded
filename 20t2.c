#include <stdio.h> // standard input/output library
#include <string.h> // string manipulation functions

int main() {
    FILE *fin, *fout, *fwords; // file pointers for input, output, and words files (indicating for file input, output, and words to be censored)
    char token[256]; //a token variable to hold each word read from the input file
    int current_line_len = 0; // marking current length of the line being written to the output file
    int replaced_count = 0; // counter for the number of words replaced

    fin = fopen("input.txt", "r"); // open input file for reading
    if (!fin) {
        printf("Error: tidak dapat membuka input.txt\n"); // if the file cannot be opened, print an error message
        return 1;
    }

    fout = fopen("censored.txt", "w"); // open output file for writing
    if (!fout) { 
        printf("Error: tidak dapat membuat censored.txt\n"); // if the output file cannot be created, print an error message
        fclose(fin); // close the input file before exiting
        return 1;
    }

    fwords = fopen("words.txt", "w"); // open words file for writing
    if (!fwords) {
        printf("Error: tidak dapat membuat words.txt\n"); // if the words file cannot be created, print an error message
        fclose(fin); // close the input file before exiting
        fclose(fout); // close the output file before exiting
        return 1;
    }

    
    while (fscanf(fin, "%255s", token) == 1) { // read words from the input file, up to 255 characters
        char outWord[256]; // output word buffer to hold the processed word
        int len = strlen(token); // get the length of the current token

        
        if (len == 4) { // check if the word length is exactly 4 characters
            strcpy(outWord, "**"); // replacing the word with "**"
            fprintf(fwords, "%s\n", token); // write the censored word to the words file
            replaced_count++; // increment the replaced count
        } else {
            strcpy(outWord, token); // copy the original word to the output word buffer
        }

        int lenWithSpace = strlen(outWord) + 1;  // calculating the length of the word plus a space

        
        if (current_line_len == 0) { // if this is the first word in the line
            fprintf(fout, "%s ", outWord); // write the word to the output file
            current_line_len = lenWithSpace; // update the current line length
        } else {
            if (current_line_len + lenWithSpace > 40) { // check if adding the word exceeds the line length limit
                fprintf(fout, "\n"); // if it does, start a new line
                fprintf(fout, "%s ", outWord); // write the word to the new line
                current_line_len = lenWithSpace; // reset the current line length
            } else {
                fprintf(fout, "%s ", outWord); // write the word to the current line
                current_line_len += lenWithSpace; // update the current line length
            }
        }
    }

    fprintf(fout, "\n"); // ensure the last line ends with a newline character

    printf("%d words were censored!\n", replaced_count); // print the number of words that were censored

    fclose(fin); // close the input file
    fclose(fout); // close the output file
    fclose(fwords); // close the words file

    return 0;
}