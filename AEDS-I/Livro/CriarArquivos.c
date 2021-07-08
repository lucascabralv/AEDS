

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void){	
	int nArquivos;
	char nomeArquivo[6];
	char nomeFolder[9];
	char nomeEnd[18];
	printf("Digite o número de arquivos que deseja criar:\n");
	scanf("%d", &nArquivos);

	for(int i = 01; i <= nArquivos; i++){
		FILE *pFile;
		if(i <= 9)
			snprintf(nomeArquivo, 6, "0%d.c", i);
		else
			snprintf(nomeArquivo, 5, "%d.c", i);
		if ((pFile = fopen(nomeArquivo, "w")) == NULL){
			printf("\nO Arquivo %d não pode ser aberto\n", i);
		}else{
			fprintf(pFile, "/*\n\n*/\n#include <stdio.h>\n\nint main(void){\n\n	return 0;\n}");
		}
	}
	return 0;
}