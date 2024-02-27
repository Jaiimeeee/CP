#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define BLUE    "\033[34m"
#define RESET   "\033[0m"
int main(int argc, char *argv[]) {
    if (argc==1){
	perror("Error");
}

else{
    bool encontrado = false;
    if (argc == 2){
	char linea[100];
	int i;
	while (fgets(linea,100, stdin) != NULL){
	for( i = 0; i<strlen(linea); i++){
		int j;
		for (j = 0; j<strlen(argv[1]); j++){
			if (linea[i+j] != argv[1][j]){
			break;
			}
		}
		if (j == strlen(argv[1])){
			int z;
			for(z =0; z<i; z++){
				printf("%c", linea[z]);
			}
			printf(BLUE "%s" RESET , argv[1]);
			int x;
			for(x = i+j; x<strlen(linea); x++){
				printf("%c", linea[x]);
			}
			
			break;
	  	}

	}
   }
    }
    else{
	    FILE *f = fopen(argv[2], "r");
		    if(f==NULL){
			    perror("Error");
	            }
		    else{
			char linea[1000];
			int i;
			while(fgets(linea, 1000, f) != NULL){
				for(i= 0; i<strlen(linea);i++){
					int j;
		      			for(j=0; j<strlen(argv[1]); j++){
						if(linea[i+j] != argv[1][j]){
							break;
						}
					}
					if (j == strlen(argv[1])){
						encontrado = true;
						int x;
						for(x = 0; x<i; x++){
							printf("%c", linea[x]);

						}
						printf(BLUE "%s" RESET, argv[1]);
					       	int z;
					       	for(z = i+j; z<strlen(linea); z++){ 
							printf("%c", linea[z]); 
						} 
						break; 
					} 
				} 
			} 
			fclose(f);
		    } 
    } 
    if (encontrado == true){ 
	    exit(0); 
    } 
    else{ 
	    exit(1); 
    }
   
} 
}
