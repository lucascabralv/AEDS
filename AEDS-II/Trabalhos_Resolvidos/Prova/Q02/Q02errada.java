public class Q02errada {
    
    // Fui entender o que realmente era a questão so depois, entao nao tive mais tempo...
    // dá até vergonha, mas ta bom. Até vi que tinham soluções no google mas nada a ver copiar

    public static void printintercalado(String variaveis, String operacoes){
        String resp = "";
        resp += variaveis.charAt(0);
        for(int i = 1; i < variaveis.length() || i < operacoes.length(); i++){
            if(variaveis.length() > i){
                resp += variaveis.charAt(i);
            }
            if(operacoes.length() > i){
                resp += operacoes.charAt(i);
            }
        }
        MyIO.println(resp);
    }

    public static void getExpressao(String resp){
        String linha = removeParenteses(resp);
        String variaveis = "";
        String operacoes = " ";
        for (int i = 0; i < linha.length(); i++) {
            if (linha.charAt(i) >= 42 && linha.charAt(i) <= 47) {
                operacoes += linha.charAt(i);
            } else {
                variaveis += linha.charAt(i);
            }
        }
        printintercalado(variaveis, operacoes);
    }

    public static String removeParenteses(String linha){
        String resp = "";
        for (int i = 0; i < linha.length(); i++) {
            if (linha.charAt(i) != '(' && linha.charAt(i) != ')') {
                resp += linha.charAt(i);
            }
        }
        return resp;
    }
    public static void main(String[] args) {
        int tam = MyIO.readInt();
        String linha;
        for(int i = 0; i < tam; i ++){
            linha = MyIO.readLine();
            getExpressao(linha);
        }
    }
}
