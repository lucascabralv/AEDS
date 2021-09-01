import java.util.Random;

public class Q04{
    public static boolean isFim(String s) {
        boolean resp = false;
        if (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M') {
            resp = true;
        }
        return resp;
    }
    //substitui as letras randomizadas
    public static void alteraLetra(String s, char letra1, char letra2){
        String palavraModificada = "";
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == letra1){
                palavraModificada += letra2;
            } else {
                palavraModificada += s.charAt(i);
            }
        }
        MyIO.println(palavraModificada);
    }
    public static void alteracao(){
        String palavra = "";
        Random gerador = new Random();
        gerador.setSeed(4);
        palavra = MyIO.readLine();
        while (!(isFim(palavra))) {
            // gera randomicamente 2 letras
            char letra1 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
            char letra2 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
            alteraLetra(palavra, letra1, letra2);
            palavra = MyIO.readLine();
        }
    }
    public static void main(String args[]){
        alteracao();
    }
}