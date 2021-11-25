import java.io.*;
import java.util.*;

class Aluno {
    // declaração dos atributos
    private String nome;
    private int distancia;
    private char regiao;

    // construtor primário
    public Aluno() {
        nome = "";
        distancia = 0;
        regiao = ' ';
    }

    // construtor secundário
    public Aluno(String nome, int distancia, char regiao){
        this.nome = nome;
        this.distancia = distancia;
        this.regiao = regiao;
    }

    public String getNome(){
        return this.nome;
    }

    public int getDistancia(){
        return this.distancia;
    }

    public char getRegiao() {
        return this.regiao;
    }

    public Aluno clone(){
        Aluno aluno = new Aluno(this.nome, this.distancia, this.regiao);
        return aluno;
    }

    public void printName(){
        MyIO.println(this.nome);
    }
}

class Lista {
    private Aluno van[];
    private int tamanho;

    // Construtor da classe.
    public Lista() {
        this(100);
    }

    public Lista(int tam) {
        van = new Aluno[tam];
        tamanho = 0;
    }

    /*
     * Insere um elemento na primeira posicao da lista e move os demais elementos
     * para o fim da lista.
     */
    public void inserirInicio(Aluno x) throws Exception {
        // validar insercao
        if (tamanho >= van.length) {
            throw new Exception("Erro ao inserir!");
        }
        // levar elementos para o fim do array
        for (int i = tamanho; i > 0; i--) {
            van[i] = van[i - 1].clone();
        }
        van[0] = x.clone();
        tamanho++;
    }
    /**
     * Mostra todos os elementos da lista
     */
    public void mostrar() {
        for (int i = 0; i < tamanho; i++) {
            van[i].printName();
        }
    }

    /**
     * Troca de posicao dois alunos
     */
    private void swap(int i, int j){
        Aluno tmp = van[i].clone();
        van[i] = van[j].clone();
        van[j] = tmp.clone();
    }

    /**
     * Ordem de ordenação requisitada: Distancia, Regiao, Nome
     * Como o algorítmo de seleção é estável, o resultado sai como esperado
     * ao fazer a ordenação na ordem inversa da que foi originalmente pedida (Nome, Regiao, Distancia)
     */
    public void ordenar(){
        for(int i = 0; i < (tamanho - 1); i++){
	        int menor = i;
	        for(int j = (i + 1); j < tamanho; j++){
		        if(van[menor].getNome().compareTo(van[j].getNome())>0){
			        menor = j;
		        }
	        }
	    swap(menor, i);
        }

        for(int i = 0; i < (tamanho - 1); i++){
	        int menor = i;
	        for(int j = (i + 1); j < tamanho; j++){
		        if(van[menor].getRegiao() > van[j].getRegiao()){
			        menor = j;
		        }
	        }
	    swap(menor, i);
        }

        for(int i = 0; i < (tamanho - 1); i++){
	        int menor = i;
	        for(int j = (i + 1); j < tamanho; j++){
		        if(van[menor].getDistancia() > van[j].getDistancia()){
			        menor = j;
		        }
	        }
	    swap(menor, i);
        }
    }


} // END CLASSE LISTA

public class Q01 {

    public static void main(String[] args) {
        MyIO.setCharset("UTF-8");
        int tam = MyIO.readInt();
        Lista lista = new Lista(tam);
        String linha = "";
        for(int i = 0; i < tam; i++){
            linha = MyIO.readLine();
            String resp[] = linha.split(" "); // Faz um split em todos os " " (espaços)
            Aluno aluno = new Aluno(resp[0], Integer.parseInt(resp[2]), resp[1].charAt(0));
            try {
                lista.inserirInicio(aluno);
            } catch (Exception e) {
            }
            
        }

        lista.ordenar();
        
        lista.mostrar();
    }
}
