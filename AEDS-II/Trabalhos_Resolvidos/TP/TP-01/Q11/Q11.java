public class Q11 {
    // Se a palavra fim for lida, retorna true
    public static boolean isFim(String s){
        boolean resp = false;
            if(s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M'){
                resp = true;
            }
        return resp;
    }

    public static boolean comparacao(String palavra, int i){
        boolean resp = true;
        if(i < palavra.length() / 2){
            if(palavra.charAt(i) == palavra.charAt(palavra.length() - i - 1)){
                resp = true;
                i += 1;
                resp = comparacao(palavra, i);
            }
            else {
                resp = false;
            }
        }
        return resp;
    }

    // Faz a leitura da linha
    public static void leitura(){
        String palavra = "";
        palavra = MyIO.readLine();
        // Continua o loop até a palavra FIM ser achada
        while(!(isFim(palavra))){
            boolean resp;
            resp = comparacao(palavra, 0);
            if(resp == true){
                MyIO.println("SIM");
            } else {
                MyIO.println("NAO");
            }
            palavra = MyIO.readLine();
        }
    }
    public static void main(String[] args) {
        leitura();
    }

}
