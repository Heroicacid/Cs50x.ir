#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //usage correction
    if (argc != 2)
    {
        printf("usage: ./recover IMAGE\n");
        return 1;
    }
    
    char *inputFile = argv[1];
    
    //opening
    FILE *inputF = fopen(inputFile, "r");

    if (inputF == NULL)
    {
        printf("can't be opened!\n");
        return 2;
    }


    //###.jpg'\0' --> the null is '\0'
    char imgname[8];                 //char namedfile = malloc(sizeof(char) * 8)

    unsigned char buffer[512];

    FILE *outputF = NULL;

    int numCounter = 0;

    while (fread(&buffer, sizeof(buffer), 1, inputF))
    {
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0))
        {
            if (outputF != NULL)
            {
                fclose(outputF);
            }
           
            sprintf(imgname, "%03i.jpg", numCounter++);
            outputF = fopen(imgname, "w");
            fwrite(&buffer, sizeof(buffer), 1, outputF);

        }
       
        else if (outputF != NULL)
        {
            fwrite(&buffer, sizeof(buffer), 1, outputF);
        }
    }

    fclose(outputF);
    fclose(inputF);
    return 0;

}