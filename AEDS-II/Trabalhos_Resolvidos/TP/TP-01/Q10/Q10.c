#include <stdio.h>
#include <stdlib.h>

// salva os numeros reais scaneados no arquivo em formato de binario
void salvarArquivo(int num, FILE *p){ 
    for(int i = 0; i < num; i++){
        double real;
        scanf("%lf", &real);
        fwrite(&real, 1, sizeof(double), p);
    }
}

// le recursivamente o arquivo, de forma que printa primeiro o real da ultima recursao e por ultimo
// da primeira, invertendo o resultado final
void lerArquivo(int num, FILE *r){
    if(num > 0){
        double real;
        fread(&real, 1, sizeof(double), r);
        lerArquivo(num-1, r);
        printf("%g\n", real);
    }
}

int main(void){
    int num;
    scanf("%d", &num);

    FILE *p;
    p = fopen("arquivo.bin", "wb");
    if (p != NULL){
        salvarArquivo(num, p);
        fclose(p);
    }

    FILE *r;
    r = fopen("arquivo.bin", "rb");
    if (r != NULL){
        lerArquivo(num, r);
        fclose(r);
    }
    return 0;
}
