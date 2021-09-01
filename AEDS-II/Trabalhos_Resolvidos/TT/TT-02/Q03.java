public class Q03 {
    public static void main(String[] args){
        int anoAtual;
        int ultimaPassagem = 1986;
        int intervalo = 76;
        anoAtual = MyIO.readInt();
        while(anoAtual != 0){
            int proximaPassagem = ultimaPassagem;
            boolean achou = false;
            while(achou == false){
                proximaPassagem += intervalo;
                if(anoAtual < proximaPassagem){
                    achou = true;
                }
            }
            MyIO.println(proximaPassagem);
            anoAtual = MyIO.readInt();
        }
    }
}
