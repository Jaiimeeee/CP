#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	FILE *f = fopen(argv[1], "r");
	char  c;
	 if (argc != 3)  {
            fprintf(stderr, "Error");
        }
	else {
	FILE *q = fopen(argv[2], "w");
	if (q == NULL){
	char ruta_completa[256];
        snprintf(ruta_completa, sizeof(ruta_completa), "%s/nombre_archivo.txt", argv[2]);
	FILE  *fptr = fopen(ruta_completa,  "w");
	if(fptr == NULL){
	fprintf(stdout, "Error al crear el fichero");
	exit(0);
	}
	else{
	c = fgetc(f);
   	while (c != EOF)
   	 {
        fputc(c, fptr);
        c = fgetc(f);
    }
//JOnny
    printf("\nCopiado a%s", fptr);

    fclose(f);
    fclose(fptr);
    return 0;
}

}
	else{

        c = fgetc(f);
        while (c != EOF)
         {
        fputc(c, q);
        c = fgetc(f);
    }

    printf("\nCopiado a %s", q);

    fclose(f);
    fclose(q);
	return 0;

        }
    }
}


