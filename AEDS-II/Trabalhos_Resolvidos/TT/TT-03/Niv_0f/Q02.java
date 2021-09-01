public class Q02 {
    public static void main(String[] args) {
        String nome, texto = "";
        nome = MyIO.readLine();
        Arq.openRead(nome);
        while(Arq.hasNext()){
            texto += Arq.readLine();
            texto += "\n";
        }
        MyIO.print(texto);
        Arq.close();
    }
}
