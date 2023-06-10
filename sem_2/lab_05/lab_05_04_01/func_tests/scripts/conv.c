#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "../../stud.h"

#define OK 0
#define ERR_PARAMS 1 
#define ERR_FILE 2

#define CHECK_FILES(file1, file2) if (file1 == NULL || file2 == NULL) return ERR_FILE

void binary_to_text(FILE *bin, FILE *txt);

void text_to_binary(FILE *txt, FILE *bin); 

int main(int argc, char **argv) 
{
    if (argc < 4) 
    {
        printf("Usage: ./conv.exe <key> <input_file> <output_file>\n");
        printf("Keys: -t2b (text to bin), -b2t (bin to text)\n");
        return ERR_PARAMS;
    }

    FILE *in_file;
    FILE *out_file;
    const char *key = argv[1];

    if (strcmp(key, "-b2t") == 0)
    {
        in_file = fopen(argv[2], "rb");
        out_file = fopen(argv[3], "w");
        CHECK_FILES(in_file, out_file);
        binary_to_text(in_file, out_file);
    } 
    else if (strcmp(key, "-t2b") == 0) 
    {
        in_file = fopen(argv[2], "r");
        out_file = fopen(argv[3], "wb");
        CHECK_FILES(in_file, out_file);
        text_to_binary(in_file, out_file);
    }
    else
    {
        printf("Error key\n");
        return ERR_PARAMS;
    }
    
    fclose(in_file);
    fclose(out_file);
    return OK;
}

void binary_to_text(FILE *bin, FILE *txt) 
{
    stud_t student;
    while (fread(&student, sizeof(stud_t), 1, bin) == 1)
    {
        fprintf(txt, "%s\n", student.surname);
        fprintf(txt, "%s\n", student.name);
        for (size_t i = 0; i < MARKS_COUNT; i++)
            fprintf(txt, "%" PRIu32 " ", student.marks[i]);
        fprintf(txt, "\n");
    }
}

void text_to_binary(FILE *txt, FILE *bin) 
{
    stud_t student;
    while (!stud_read(&student, txt))
        fwrite(&student, sizeof(stud_t), 1, bin);
}

