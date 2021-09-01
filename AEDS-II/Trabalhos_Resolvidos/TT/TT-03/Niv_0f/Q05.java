public class Q05 {
    public static void main(String[] args) {
        String texto, texto_novo = "";
        Arq.openRead(MyIO.readLine());
        texto = Arq.readAll();
        Arq.close();
        for(int i = 0; i < texto.length(); i++){
            char c = texto.charAt(i);
            if(c <= 122 && c >= 97){
                texto_novo += (char)(c - 32);
            } else {
                texto_novo += c;
            }
        }
        Arq.openWrite(MyIO.readLine());
        Arq.print(texto_novo);
        Arq.close();
    }   
}
