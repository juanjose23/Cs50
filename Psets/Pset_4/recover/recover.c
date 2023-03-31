#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
    //Valida si lo ingresado por el usuario es valido
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    //Almacena el nombre del archivo
    char *infile = argv[1];

    //abre el fichero
    FILE *inptr = fopen(infile, "r");

    //valida si el usuario ingreso el nombre del archivo
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;

    }

    unsigned char buffer[512];
    int filenumber = 0;
    char filename[8];

    FILE *outptr = NULL;


    //lee los 512 bytes del bloque de la imagen
    while (fread(&buffer, sizeof(buffer), 1, inptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            sprintf(filename, "%03i.jpg", filenumber++);
            printf("%s\n", filename);
            outptr = fopen(filename, "w");
            fwrite(&buffer, sizeof(buffer), 1, outptr);
        }
        else if (outptr != NULL)
        {
            fwrite(&buffer, sizeof(buffer), 1, outptr);
        }
    }

    //se cierran todos los ficheros que se hayan abierto
    fclose(inptr);
    fclose(outptr);

    return 0;
}
