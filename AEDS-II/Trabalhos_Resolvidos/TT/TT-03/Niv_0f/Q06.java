public class Q06 {
    public static void main(String[] args) {
        String texto, texto_novo = "";
        Arq.openRead(MyIO.readLine());
        texto = Arq.readAll();
        Arq.close();
        for(int i = texto.length() - 1; i >= 0; i--){
            texto_novo += texto.charAt(i);;
        }
        Arq.openWrite(MyIO.readLine());
        Arq.print(texto_novo);
        Arq.close();
    }   
}
