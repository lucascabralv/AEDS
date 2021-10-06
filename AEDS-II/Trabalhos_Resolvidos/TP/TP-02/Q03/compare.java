public class compare {
    public static void main(String[] args) {
        String chave = MyIO.readLine();
        while(!chave.equals("FIM")){
            String comp = MyIO.readLine();
            if (comp.equals(chave)){
                MyIO.println("Iguais");
            } else if(comp.compareTo(chave)>0){
                MyIO.println(chave + " - " + comp);
            } else {
                MyIO.println(comp + " - " + chave);
            }
            chave = MyIO.readLine();
        }
    }
}
