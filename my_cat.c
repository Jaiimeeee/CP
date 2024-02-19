
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc==1){
	char a[1000];
       while(1){
	scanf("%s", a);
  
	printf("%s",a);
}
}
else{
    int i;
    for (i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (f == NULL) {
            fprintf(stderr, "El fichero %s no existe\n", argv[i]);
        } else {
            char mybuffer[4];
            size_t leer;
            while (leer =fread(mybuffer, 4, 1, f)>0) {
		
                fprintf(stdout, "%s",  mybuffer);
            }
            
        }
    }
}

}

