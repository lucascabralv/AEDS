public class Q01 {
    public static void main(String[] args){
        String frase;
        String nome;
        nome = MyIO.readLine();
        frase = MyIO.readLine();
        Arq.openWrite(nome);
        Arq.println(frase);
        Arq.close();
    }
}
