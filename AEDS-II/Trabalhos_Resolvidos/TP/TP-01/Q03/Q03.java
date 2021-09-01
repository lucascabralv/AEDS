public class Q03 {
    // Se a palavra fim for lida, retorna true
    public static boolean isFim(String s) {
        boolean resp = false;
        if (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M') {
            resp = true;
        }
        return resp;
    }

    public static void leitura() {
        String palavra = "";
        palavra = MyIO.readLine();
        // Continua o loop até a palavra FIM ser achada
        while (!(isFim(palavra))) {
            String novaPalavra = "";
            boolean resp = true;
            for (int i = 0; i < palavra.length(); i++) {
                // adiciona 3 ao valor ASCII do caractere
                novaPalavra += (char)(palavra.charAt(i) + 3);
            }
            MyIO.println(novaPalavra);
            palavra = MyIO.readLine();
        }
    }

    public static void main(String[] args) {
        leitura();
    }
}