public class Q04 {
    public static void main(String[] args) {
        String  texto;
        Arq.openRead(MyIO.readLine());
        texto = Arq.readAll();
        Arq.close();
        Arq.openWrite(MyIO.readLine());
        Arq.print(texto);
        Arq.close();
    }
}
