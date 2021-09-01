public class java08{
    public static void main(String[] args){
        byte b = 0; short s = 0; int i = 0; long l = 0;
        while(i < 10){
            b++; s++; i++; l++;
            System.out.println("b = " + b + " | s = " + s + " | i = " + i + " | l = " + l);
        } 
    }
}
// Modifiquei o código para não imprimir no terminal indeterminamente. Mas é
// possível observar que os números são adiconados
// em 1 até que atinjam o máximo de bits de cada tipo de variável. O byte por
// exemplo soma normalmente até 127, depois
// disso o bit responsável pelo sinal do número é aumentado em 1 e vira
// negativo.
