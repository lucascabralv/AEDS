import java.io.RandomAccessFile;
import java.io.IOException;

public class Q09 {
    // Salva inputs no arquivo como double
    public static void salvarArquivo(int num) throws IOException{
        RandomAccessFile raf = new RandomAccessFile("arquivo.bin", "rw");
        for(int i = 0; i < num; i++){
            double real = Double.parseDouble(MyIO.readLine());
            raf.writeDouble(real);
        }
        raf.close();
    }
    // le arquivo 
    public static void lerArquivo(int num) throws IOException{
        RandomAccessFile raf = new RandomAccessFile("arquivo.bin", "r");
        long posicao = raf.getFilePointer();
        // faz a leitura de traz para frente, começando pelos ultimos 8 bytes
        for(int i = num-1; i >= 0; i--){
            raf.seek(i*8);
            double real = raf.readDouble();
            if(real % 1 == 0){
                // se numero é inteiro, imprime sem o .0
                MyIO.println((int)real);
            } else {
                MyIO.println(real);
            }
        }
        raf.close();
    }
    public static void main(String[] args){
        int num = MyIO.readInt();
        try {
            salvarArquivo(num);
            lerArquivo(num);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
