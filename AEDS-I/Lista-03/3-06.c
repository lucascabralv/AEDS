/*
Faça um programa para ler uma mensagem do teclado e criptografá-la utilizando o ciframento de César. 
Nesse caso, cada caractere da mensagem deve ser substituído pelo caractere cujo código ASCII é igual ao seu mais uma constante K (lida do teclado).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
  char msg[50];
  int k;
  printf("Digite uma mensagem a ser criptografada:\n");
  fgets(msg, 50, stdin);
  printf("\nDigite um número inteiro:\n");
  scanf("%d", &k);

  for(int i = 0; i < strlen(msg); i++){
      //Evita que os espaços (em ASCII = 32) sejam alterados
      if(msg[i] != 32)
        msg[i] = msg[i] + k;
  }
  printf("\n=> Mensagem criptografada:\n%s\n", msg);
  return 0;
}