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
        char* tmp = strdup(line);
        printf("FName %s\n", getfield(tmp, 1));
        tmp = strdup(line);
        printf("LName %s\n", getfield(tmp, 2));
        // NOTE strtok clobbers tmp
        free(tmp);
    }
}
