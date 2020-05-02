#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{


    if (argc != 2)
    {
        printf("Usage: ./recover incard\n");
        return 1;
    }

    char *inc = argv[1];
    char outimg[8];

    // Open input card
    FILE *inptr = fopen(inc, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", inc);
        return 1;
    }

    int countV = 0;
    int count = 0;


    while (!feof(inptr))
    {
        BYTE buffer[512];
        int x = fread(buffer, sizeof(BYTE), 512, inptr);
        while(x == 512)
        {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //close previous file
            sprintf(outimg, "%03i.jpg", count);
            count++;
            FILE* outptr = fopen(outimg, "w");
            fwrite(buffer, sizeof(BYTE), 512, outptr);
            fclose(outptr);
        }
        else if (count == 0)
        {
            countV++;
        }
        else
        {
            FILE* outptr = fopen(outimg, "a");
            fseek(outptr, 0, SEEK_END);
            fwrite(buffer, sizeof(BYTE), 512, outptr);
            fclose(outptr);
        }
        }
    }
    fclose(inptr);
}