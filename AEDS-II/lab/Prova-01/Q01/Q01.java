class Pais{
    private String nome;
    private int ouro;
    private int prata;
    private int bronze;

    Pais(){
        this.nome = "";
        this.ouro = 0;
        this.prata = 0;
        this.bronze = 0;
    }
    Pais(String nome, int ouro, int prata, int bronze){
        this.nome = nome;
        this.ouro = ouro;
        this.prata = prata;
        this.bronze = bronze;
    }
    public Pais clone(){
        Pais pais = new Pais(this.nome, this.ouro, this.prata, this.bronze);
        return pais;
    }
    //SETS
    public void setNome(String nome){
        this.nome = nome;
    }
    public void setOuro(int ouro){
        this.ouro = ouro;
    }
    public void setPrata(int prata){
        this.prata = prata;
    }
    public void setBronze(int bronze){
        this.bronze = bronze;
    }
    //GETS
    public String getNome(){
        return this.nome;
    }
    public int getOuro(){
        return this.ouro;
    }
    public int getPrata(){
        return this.prata;
    }
    public int getBronze(){
        return this.bronze;
    }
}
public class Q01 {
    // Mostra os atributos do pais
    public static void mostrar(Pais paises[]){
        for(int i = 0; i < paises.length; i++){
            MyIO.print(paises[i].getNome() + " ");
            MyIO.print(paises[i].getOuro() + " ");
            MyIO.print(paises[i].getPrata() + " ");
            MyIO.print(paises[i].getBronze() + "\n");
        }
    }
    // Faz o swap dos paises por meio do clone()
    public static void swap(int i, int j, Pais paises[]){
        Pais temp = paises[i].clone();
        paises[i] = paises[j].clone();
        paises[j] = temp.clone();
    }
    // Algoritmo de Seleção adaptado
    public static void ordenar(Pais paises[]){
        int n = paises.length;
        for (int i = 0; i < (n - 1); i++) {
            int maior = i;
            for (int j = (i + 1); j < n; j++) {
                if (paises[maior].getOuro() < paises[j].getOuro()) {
                    maior = j;
                } else if(paises[maior].getOuro() == paises[j].getOuro()){
                    // Se as medalhas de ouro sao iguais compara as de prata
                    if(paises[maior].getPrata() < paises[j].getPrata()){
                        maior = j;
                    } else if(paises[maior].getPrata() == paises[j].getPrata()){
                        // Se as medalhas de prata sao iguais compara as de bronze
                        if(paises[maior].getBronze() < paises[j].getBronze()){
                            maior = j;
                        }
                    }
                }
            }
            swap(maior, i, paises);
        }
    }
    public static void main(String[] args) {
        int qtde = MyIO.readInt();
        // Cria o array de paises
        Pais paises[] = new Pais[qtde];
        // "Cadastra" os paises recebidos pela entrada
        for(int i = 0; i < qtde; i++){
            String linha = MyIO.readLine();
            // Separa a linha pelos espaços
            String[] infos = linha.split("\\s+");
            paises[i] = new Pais();
            paises[i].setNome(infos[0]);
            paises[i].setOuro(Integer.parseInt(infos[1]));
            paises[i].setPrata(Integer.parseInt(infos[2]));
            paises[i].setBronze(Integer.parseInt(infos[3]));
        }
        ordenar(paises);
        mostrar(paises);
    }
}
