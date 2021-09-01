public class teste {
    public static void main(String[] args) {
        int mult= 0;
        int n = 5;
        for(int i = n+4; i > 0; i>>=1 ){
            mult++;
        }
        MyIO.println(mult);
    }
}
