public class Q07 {
    public static void main(String[] args) {
        String texto, texto_novo = "";
        Arq.openRead(MyIO.readLine());
        texto = Arq.readAll();
        Arq.close();
        for (int i = 0; i < texto.length(); i++) {
            char c = texto.charAt(i);
            if (c != ' ' && c != '\n') {
                texto_novo += (char) (c + 3);
            } else {
                texto_novo += c;
            }
        }
        Arq.openWrite(MyIO.readLine());
        Arq.print(texto_novo);
        Arq.close();
    }
}
