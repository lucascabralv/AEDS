public class Q02 {
    public static void evolucao(int n, int x, int y, int z){
        int resp = 0;
        // Se o n for maior ou igual a qualquer um deles, o máximo de evoluções é uma.
        if(n >= x || n >= y || n >= z){
            resp = 1;
            // Se n for maior ou igual a soma de qualquer um deles, o máx. de evoluções é duas
            if(n >= x+y || n >= x+z || n >= y+z){
                resp = 2;
                // Se n for maior ou igual a soma dos três, o máx. de evoluções é 3
                if(n >= x+y+z){
                    resp = 3;
                }
            }
        }
        MyIO.println(resp);
    }
   public static void main(String[] args) {
       int n, x, y, z;
        // N, o número de doces disponíveis. 
        n = MyIO.readInt();
        // X, o número de doces necessários para a primeira pô-que-mão evoluir.
        x = MyIO.readInt();
        // Y, o número de doces necessários para a segunda pô-que-mão evoluir.
        y = MyIO.readInt();
        // Z, o número de doces necessários para a terceira pô-que-mão evoluir.
        z = MyIO.readInt();
        evolucao(n, x, y, z);
   } 
}
