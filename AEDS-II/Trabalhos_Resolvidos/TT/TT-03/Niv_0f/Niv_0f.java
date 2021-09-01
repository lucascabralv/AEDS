public class Niv_0f{
    public static void main(String args[]){
        Arq.openRead("Arq_Teste.txt");
        String str = "";
        while(Arq.hasNext() == true){
            str += Arq.readAll();
        }
        Arq.close();
        Arq.openWrite("copy.txt");
        Arq.print(str);
        Arq.close();
        MyIO.println("Copiado com sucesso!");
    }
}