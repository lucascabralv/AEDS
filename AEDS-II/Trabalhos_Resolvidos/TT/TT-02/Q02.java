public class Q02 {
    public static int maiorNumero(int n1, int n2, int n3){
        int resp;
        if(n1 > n2 && n1 > n3){
            resp = n1;
        } else if(n2 > n1 && n2 > n3){
            resp = n2;
        } else {
            resp = n3;
        }
        return resp;
    }

    public static void achaIdade(){
        int mae, filho1, filho2, filho3;
        mae = MyIO.readInt();
        while(mae != 0){
            filho1 = MyIO.readInt();
            filho2 = MyIO.readInt();
            filho3 = mae - (filho1 + filho2);
            MyIO.println(maiorNumero(filho1, filho2, filho3));
            mae = MyIO.readInt();
        }
    }
    public static void main(String args[]){
        achaIdade();
    }
}
