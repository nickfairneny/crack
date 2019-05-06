#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "md5.h"

int main(int argc, char *argv[])
{
	FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w"); 
    
    if(!in)
    {
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }
    
    if (!out)
    {
        printf("Can't open %s for writing\n", argv[2]);
        exit(1);
    }
    
    char password[20]; 
 
	while (fgets(password, 20, in) != NULL)
	{
	    char *hash = md5(password, strlen(password) -1);
	    //(hash, 38, in);
    	//printf("Hash: %s\n", hash);
    	fprintf(out, "%s\n", hash);
    	free(hash);
    	
    }
    
    fclose(in);
    fclose(out);
    
}    