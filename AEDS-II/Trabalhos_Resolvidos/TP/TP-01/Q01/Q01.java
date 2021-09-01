public class Q01 {
    // Se a palavra fim for lida, retorna true
    public static boolean isFim(String s){
        boolean resp = false;
            if(s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M'){
                resp = true;
            }
        return resp;
    }
    // Faz a leitura da linha
    public static void leitura(){
        String palavra = "";
        palavra = MyIO.readLine();
        // Continua o loop até a palavra FIM ser achada
        while(!(isFim(palavra))){
            boolean resp = true;
            for(int i = 0; i < palavra.length()/2; i++){
                // Compara a letra na posição i com a última-i-1, o -1 é para que a simetria fique exata,
                // já que em uma palavra de cinco letras, a última letra está na posição 4
                if(palavra.charAt(i) != palavra.charAt(palavra.length() - i - 1)){
                    resp = false;
                }
            }
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