#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define block 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Wrong usage - try: ./recover [Memory card]\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Invalid input\n");
        return 2;
    }

    uint8_t buffer[block];

    int new_jpg = -1;
    char filename[9];

    FILE *img = NULL;
    /* Check every block until it finds a .jpg file, then creates
    a new file with the data until finds another jpg and so on. */
    while (fread(buffer, 1, block, file) == block)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            new_jpg++;
            if (new_jpg == 0)
            {
                sprintf(filename, "%03i.jpg", new_jpg);
                img = fopen(filename, "a");
                fwrite(buffer, 1, block, img);
            }

            else
            {
                fclose(img);

                sprintf(filename, "%03i.jpg", new_jpg);
                img = fopen(filename, "a");
                fwrite(buffer, 1, block, img);
            }
        }

        else if (new_jpg != -1)
        {
            fwrite(buffer, 1, block, img);
        }
    }
    fclose(file);
    fclose(img);
}