public class Q06 {
    public static boolean isFim(String s) {
        boolean resp = false;
        if (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M') {
            resp = true;
        }
        return resp;
    }
    // Descobre se o caractere é uma vogal
    public static boolean isVogal(char c){
        boolean resp = false;
        if(c >= 97 && c <= 122){
            c = (char)(c - 32);
        }
        if(c == 65 || c == 69 || c == 73 || c == 79 || c == 85){
            resp = true;
        }
        return resp;
    }
    // Se todas as letras são vogais retorna SIM
    public static String isAllVogal(String s) {
        String resp = "SIM";
        for(int i = 0; i < s.length(); i++){
            if(!isVogal(s.charAt(i))){
                resp = "NAO";
                break;
            }
        }
        return resp;
    }
    // Se todas as letras não sao vogais e nem números retorna SIM
    public static String isAllConsoante(String s) {
        String resp = "SIM";
        for (int i = 0; i < s.length(); i++) {
            if (isVogal(s.charAt(i)) || ((s.charAt(i) >= 48) && (s.charAt(i) <= 57))) {
                resp = "NAO";
                break;
            }
        }
        return resp;
    }

    public static boolean isAlgarismo(char c){
        boolean resp = false;
        if(((c >= 48) && (c <= 57))){
            resp = true;
        }
        return resp;
    }


    // Se os caracteres possuirem na tabela ASCII os valores que os algarismos possuem então é um número inteiro
    public static String isInteiro(String s){
        String resp = "SIM";
        for (int i = 0; i < s.length(); i++) {
            if (!isAlgarismo(s.charAt(i))) {
                resp = "NAO";
            }
        }
        return resp;
    }
    //  Se os caracteres possuirem na tabela ASCII os valores que os algarismos
    // possuem e possui ao menos um ponto " . " retorna SIM
    public static String isReal(String s) {
        String resp = "SIM";
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!isAlgarismo(s.charAt(i))) {
                if (!(s.charAt(i) == 46) && !(s.charAt(i) == 44)) {
                    resp = "NAO";
                    break;
                } else{
                    j++;
                }
            }
        }
        if(j > 1){
            resp = "NAO";
        }
        return resp;
    }

    public static void testes(){
        String palavra = "";
        palavra = MyIO.readLine();
        while(!isFim(palavra)){
            String resp = "";
            resp += isAllVogal(palavra) + " ";
            resp += isAllConsoante(palavra) + " ";
            resp += isInteiro(palavra) + " ";
            resp += isReal(palavra);
            MyIO.println(resp);
            palavra = MyIO.readLine();
        }
    }
    public static void main(String[] args) {
        MyIO.setCharset("UTF-8");
        testes();
    }
}
