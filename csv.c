#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int main()
{
    FILE* stream = fopen("dat", "r");

    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp[32];
        for(int i=0; i<12; i++)
        {
            tmp[i] = strdup(line);
            printf("%s\t", getfield(tmp[i], i));
        free(tmp[i]);

        }
        printf("\n");
        // NOTE strtok clobbers tmp
    }
}
