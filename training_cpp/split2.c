#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** str_split( char* str, char delim, int* numSplits )
{
    char** ret;
    int retLen;
    char* c;

    printf("entry to split \n");
    if ( ( str == NULL ) ||
            ( delim == '\0' ) )
    {
        /* Either of those will cause problems */
        ret = NULL;
        retLen = -1;
    }
    else
    {
        retLen = 0;
        c = str;

        /* Pre-calculate number of elements */
        do
        {
            if ( *c == delim )
            {
                retLen++;
            }

            c++;
        } while ( *c != '\0' );

        ret = malloc( ( retLen + 1 ) * sizeof( *ret ) );
        ret[retLen] = NULL;

        c = str;
        retLen = 1;
        ret[0] = str;

        do
        {
            if ( *c == delim )
            {
                ret[retLen++] = &c[1];
                *c = '\0';
            }

            c++;
        } while ( *c != '\0' );
    }

    if ( numSplits != NULL )
    {
        *numSplits = retLen;
    }

    printf("return from split \n");
    return ret;
}

int main()
{
    char *str = "one,two,three,four";
    char **split = NULL;
    int i = 0;
    int tokens = 0;
    char *strCpy = NULL;

    strCpy = malloc( strlen( str ) * sizeof( *strCpy ) );
    strcpy( strCpy, str );

    split = str_split(strCpy, ',', &tokens);

    for ( i = 0; i < tokens; i++ )
    {
        puts(split[i]);
    }

    free(split);
    free(strCpy);

    return 0;
}
