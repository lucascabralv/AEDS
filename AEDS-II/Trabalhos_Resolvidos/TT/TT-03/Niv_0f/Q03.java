public class Q03 {
    public static void main(String[] args) {
        String texto, novo_texto = "";
        Arq.openRead(MyIO.readLine());
        texto = Arq.readAll();
        for(int i = 0; i < texto.length(); i++){
            if(texto.charAt(i) <= 122 && texto.charAt(i) >= 97){
                novo_texto += (char)(texto.charAt(i) - 32);
            } else {
                novo_texto += texto.charAt(i);
            }
        }
        MyIO.print(novo_texto + "\n");
    }
}
