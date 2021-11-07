import java.io.*;
import java.util.*;

import java.io.FileReader;

class Serie {
   // declaração dos atributos
   private String name;
   private String format;
   private String duration;
   private String country;
   private String language;
   private String broadcaster;
   private String streaming;
   private int seasons;
   private int episodes;

   // construtor primário
   public Serie() {
      name = "";
      format = "";
      duration = "";
      country = "";
      language = "";
      broadcaster = "";
      streaming = "";
      seasons = 0;
      episodes = 0;
   }

   // construtor secundário
   public Serie(String name, String format, String duration, String country, String language, String broadcaster,
         String streaming, int seasons, int episodes) {
      this.name = name;
      this.format = format;
      this.duration = duration;
      this.country = country;
      this.language = language;
      this.broadcaster = broadcaster;
      this.streaming = streaming;
      this.seasons = seasons;
      this.episodes = episodes;
   }

   public Serie(String arquivo) {
      readClass(arquivo);
   }

   // método para setar o atributo name
   public void setName(String name) {
      this.name = name;
   }

   // método para setar o atributo formato
   public void setFormat(String format) {
      this.format = format;
   }

   // método para setar o atributo duration
   public void setDuration(String duration) {
      this.duration = duration;
   }

   // método para setar o atributo country
   public void setCountry(String country) {
      this.country = country;
   }

   // método para setar o atributo language
   public void setLanguage(String language) {
      this.language = language;
   }

   // método para setar o atributo broadcaster
   public void setBroadcaster(String broadcaster) {
      this.broadcaster = broadcaster;
   }

   // método para setar o atributo streaming
   public void setStreaming(String streaming) {
      this.streaming = streaming;
   }

   // método para setar o atributo seasons
   public void setSeasons(int seasons) {
      this.seasons = seasons;
   }

   // método para setar o atributo episodes
   public void setEpisodes(int episodes) {
      this.episodes = episodes;
   }

   // método para retornar o atributo name
   public String getName() {
      return this.name;
   }

   // método para retornar o atributo format
   public String getFormat() {
      return this.format;
   }

   // método para retornar o atributo duration
   public String getDuration() {
      return this.duration;
   }

   // método para retornar o atributo country
   public String getCountry() {
      return this.country;
   }

   // método para retornar o atributo language
   public String getLanguage() {
      return this.language;
   }

   // método para retornar o atributo broadcaster
   public String getBroadcaster() {
      return this.broadcaster;
   }

   // método para retornar o atributo streaming
   public String getStreaming() {
      return this.streaming;
   }

   // método para retornar o atributo seasons
   public int getSeasons() {
      return this.seasons;
   }

   // método para retornar o atributo episodes
   public int getEpisodes() {
      return this.episodes;
   }

   // método para clonar a classe
   public Serie clone() {
      Serie resp = new Serie();
      resp.name = this.name;
      resp.format = this.format;
      resp.duration = this.duration;
      resp.country = this.country;
      resp.language = this.language;
      resp.broadcaster = this.broadcaster;
      resp.streaming = this.streaming;
      resp.seasons = this.seasons;
      resp.episodes = this.episodes;
      return resp;
   }

   public String toString() {
      String resp = this.name + " " + this.format + " " + this.duration + " " + this.country + " " + this.language + " "
            + this.broadcaster + " " + this.streaming + " " + this.seasons + " " + this.episodes;
      return resp;
   }

   // método para printar a classe
   public void printClass() {
      System.out.println(this.toString());
   }

   // método para tratar a linha, deixar apenas números e converter o retorno de
   // String para Integer
   public int justInt(String line) {
      String resp = "";
      for (int i = 0; i < line.length(); i++) {
         if (line.charAt(i) >= '0' && line.charAt(i) <= '9') { // caso o caracter seja um número ele é concatenado a
                                                               // variável resp
            resp += line.charAt(i);
         } else { // caso seja outro caracter, o i recebe o valor da condição de parada e o método
                  // de repetição é encerrado
            i = line.length();
         }
      }
      return Integer.parseInt(resp); // conversão da string resp para número inteiro a ser retornado
   }

   // método para a remoção das tags da linha lida do arquivo para retornar apenas
   // o que é desejado
   public String removeTags(String line) {
      String resp = "";
      int i = 0;
      while (i < line.length()) { // enquanto i for menor que o tamanho da String linha
         if (line.charAt(i) == '<') { // é testado para verificar se o contador i ainda está dentro das tags
            i++;
            while (line.charAt(i) != '>')
               i++; // ao encontrar o sinal de fechamento das tags o laço de repetição é encerrado
         } else if (line.charAt(i) == '&') { // mesmo tratamento de cima mas para outras exceções presentes em alguns
                                             // outros arquivos
            i++;
            while (line.charAt(i) != ';')
               i++;
         } else { // o que estiver fora das tags é concatenado a String resp a ser retornada
            resp += line.charAt(i);
         }
         i++;
      }
      // System.out.println(resp);
      return resp;
   }

   public String removeSpace(String line) {
      String resp = "";
      if (line.charAt(0) == ' ' || line.charAt(line.length() - 1) == ' ') {
         for (int i = 0; i < line.length(); i++) {
            if ((i == 0 || i == (line.length() - 1)) && line.charAt(i) == ' ') {
               // Não adiciona
            } else {
               resp += line.charAt(i);
            }
         }
      } else {
         resp = line;
      }
      return resp;
   }

   // método para tratar o nome do arquivo e retornar o nome da série
   public String searchName(String fileName) {
      String resp = "";
      for (int i = 0; i < fileName.length(); i++) {
         if (fileName.charAt(i) == '_') { // caso o caracter na posição i seja igual ao '_' a variável resp recebe um
                                          // espaço em branco
            resp += ' ';
         } else { // caso não tenha espaço em branco o caracter é concatenado à string resp
            resp += fileName.charAt(i);
         }
      }
      return resp.substring(0, resp.length() - 5); // retorno da substring resp retirando os 5 últimos caracteres
                                                   // relacionados à extensão do arquivo
   }

   // método para leitura do arquivo .html e tratamento das linhas
   public void readClass(String fileName) {
      /** Series no Mac */
      //String file = "/Users/lucascabral/Desktop/series/" + fileName;

      /** Series no WSL */
      //String file = "/mnt/c/Users/cabral/Documents/Github/AEDS/AEDS-II/series/" + fileName;

      /** Series no Verde */
      String file = "/tmp/series/" + fileName;

      try {
         FileReader fileReader = new FileReader(file); // declaração da variável fileReader que será recebida pelo
                                                       // bufferedReader

         BufferedReader br = new BufferedReader(fileReader); // declaração do bufferedReader para leitura do arquivo

         // set nome da série
         this.name = searchName(fileName);

         // set Formato da série
         while (!br.readLine().contains("Formato"))
            ;
         this.format = removeTags(br.readLine());

         // set duração da série
         while (!br.readLine().contains("Duração"))
            ;
         this.duration = removeTags(br.readLine());

         // set país da série
         while (!br.readLine().contains("País de origem"))
            ;
         this.country = removeSpace(removeTags(br.readLine()));

         // set idioma da série
         while (!br.readLine().contains("Idioma original"))
            ;
         this.language = removeSpace(removeTags(br.readLine()));

         // set emissora da série
         while (!br.readLine().contains("Emissora de televisão"))
            ;
         this.broadcaster = removeTags(br.readLine());

         // set transmissão original da série
         while (!br.readLine().contains("Transmissão original"))
            ;
         this.streaming = removeTags(br.readLine());

         // set temporadas da série
         while (!br.readLine().contains("N.º de temporadas"))
            ;
         this.seasons = justInt(removeTags(br.readLine()));

         // set episódios da série
         while (!br.readLine().contains("N.º de episódios"))
            ;
         this.episodes = justInt(removeTags(br.readLine()));

         // método para mostrar a classe
         // this.printClass();
         // fechamento do bufferedReader
         br.close();
         // Tratamento de exceções
      } catch (FileNotFoundException e) {
         System.out.println("Unable to open file '" + fileName + "'");
      } catch (IOException e) {
         System.out.println("Error reading file '" + fileName + "'");
      }
   }
}

class CelulaDupla {
   public Serie elemento;
   public CelulaDupla prox, ant;

   public CelulaDupla() {
      this(new Serie());
   }

   public CelulaDupla(Serie x) {
      this.elemento = x.clone();
      this.prox = this.ant = null;
   }
}

class ListaDupla {
   private CelulaDupla primeiro, ultimo;
   private int movimentacoes;
   private int comparacoes;

   public ListaDupla() {
      primeiro = new CelulaDupla();
      ultimo = primeiro;
      movimentacoes = 0;
      comparacoes = 0;
   }
   
   public int getComparacoes() {
      return comparacoes;
   }

   public int getMovimentacoes() {
      return movimentacoes;
   }
   
   public void inserirInicio(Serie x) {
      CelulaDupla tmp = new CelulaDupla(x);
      tmp.ant = primeiro;
      tmp.prox = primeiro.prox;
      primeiro.prox = tmp;
      if (primeiro == ultimo) {
         ultimo = tmp;
      } else {
         tmp.prox.ant = tmp;
      }
      tmp = null;
   }
   
   public void inserirFim(Serie x) {
      ultimo.prox = new CelulaDupla(x);
      ultimo.prox.ant = ultimo;
      ultimo = ultimo.prox;
   }
   
   public void inserir(Serie x, int pos) throws Exception{
      int tamanho = tamanhoLista();
      if(pos < 0 || pos > tamanho){ 
         throw new Exception("Erro");
      } else if(pos == 0){
         inserirInicio(x);
      } else if(pos == tamanho){
         inserirFim(x);
      } else {
         CelulaDupla i = primeiro;
         for(int j = 0; j < pos; j++, i = i.prox);
         CelulaDupla tmp = new CelulaDupla(x);
         tmp.ant = i;
         tmp.prox = i.prox;
         tmp.ant.prox = tmp.prox.ant = tmp;
         tmp = i = null;
      }
   }

   public Serie removerInicio() throws Exception {
		if(primeiro == ultimo) {
			throw new Exception("Erro!");
		}
		CelulaDupla tmp = primeiro;
		primeiro = primeiro.prox;

		Serie elemento = primeiro.elemento.clone();
		tmp.prox = primeiro.ant = null;
		tmp = null;
		return elemento;
	}
   
   public Serie removerFim() throws Exception {
      if (primeiro == ultimo) {
         throw new Exception("Erro");
      }

      Serie elemento = ultimo.elemento.clone();
      ultimo = ultimo.ant;
      ultimo.prox.ant = null;
      ultimo.prox = null;
      return elemento;
   }
  
   public Serie remover(int pos) throws Exception {
      int tamanho = tamanhoLista();
      Serie elemento;
      if(primeiro == ultimo || pos < 0 || pos >= tamanho){
         throw new Exception("Erro");
      } else if(pos == 0){
         elemento = removerInicio();
      } else if(pos == tamanho){
         elemento = removerFim();
      } else {
         CelulaDupla i = primeiro;
         for(int j = 0; j < pos; j++, i = i.prox);
         i.ant.prox = i.prox;
         i.prox.ant = i.ant;
         elemento = i.elemento.clone();
         i.prox = i.ant = null;
         i = null;
      }
      return elemento;
   }

   public void mostrar() {
      for (CelulaDupla i = primeiro.prox; i != null; i = i.prox) {
         i.elemento.printClass();
      }
   }
   
   public int tamanhoLista() {
      return tamanhoLista(primeiro, ultimo);
   }
   
   public int tamanhoLista(CelulaDupla esq, CelulaDupla dir) {
      int tamanho = 0;
      for (CelulaDupla i = esq; i != dir; i = i.prox, tamanho++);
      return tamanho;
   }
   
   // Encapsulamento de ordenar
   public void ordenar() {
      ordenar(0);
   }

   // Ordena internamente cada grupo com Country igual
   private void ordenar(int inicio) {
      int i = inicio + 1;
      while (i < tamanhoLista() && getCelulaDupla(inicio).elemento.getCountry().equals(getCelulaDupla(i).elemento.getCountry())) {
         i++;
      }
      i--;
      if (i < tamanhoLista()) {
         quicksortName(inicio, i);
         ordenar(i + 1);
      }
   }

   // Troca os elementos de posicao na lista
   public void swap(int i, int j) {
      Serie temp = getCelulaDupla(i).elemento.clone();
      getCelulaDupla(i).elemento = getCelulaDupla(j).elemento.clone();
      getCelulaDupla(j).elemento = temp.clone();
      movimentacoes += 3;
   }
   
   //Encapsulamento de ordenacao por Name
   public void nameSort() {
      quicksortName(1, tamanhoLista() - 1);
   }

   // Encapsulamento de ordenacao por Country
   public void countrySort() {
      quicksort(1, tamanhoLista() - 1);
   }

   private CelulaDupla getCelulaDupla(int pos){
      CelulaDupla resp = primeiro.prox;
      for(int i = 0; i < pos && resp != null; i++, resp = resp.prox);
      return resp;
   }

   private void quicksort(int esq, int dir) {
      int i = esq, j = dir;
      Serie pivo = getCelulaDupla((dir + esq) / 2).elemento.clone();
      while (i <= j) {
         while (getCelulaDupla(i).elemento.getCountry().compareTo(pivo.getCountry()) < 0)
            i++;
         while (getCelulaDupla(j).elemento.getCountry().compareTo(pivo.getCountry()) > 0)
            j--;
         comparacoes++;
         if (i <= j) {
            swap(i, j);
            i++;
            j--;
         }
      }
      comparacoes++;
      if (esq < j)
         quicksort(esq, j);
      comparacoes++;
      if (i < dir)
         quicksort(i, dir);
   }

   // Quicksort utilizando o atributo Name
   private void quicksortName(int esq, int dir) {
      int i = esq, j = dir;
      Serie pivo = getCelulaDupla((dir + esq) / 2).elemento.clone();
      while (i <= j) {
         while (getCelulaDupla(i).elemento.getName().compareTo(pivo.getName()) < 0)
            i++;
         while (getCelulaDupla(j).elemento.getName().compareTo(pivo.getName()) > 0)
            j--;
         if (i <= j) {
            swap(i, j);
            movimentacoes -= 3; // Para observar apenas o custo do Quicksort utilizando o atributo Country
            i++;
            j--;
         }
      }
      if (esq < j)
         quicksortName(esq, j);
      if (i < dir)
         quicksortName(i, dir);
   }
   
}// END CLASS LISTADUPLA

public class Q14 {
   // Confere se a palavra é igual a FIM
   public static boolean isFim(String s) {
      boolean resp = false;
      if (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M') {
         resp = true;
      }
      return resp;
   }

   public static Serie criaSerie(String arquivo) {
      Serie serie = new Serie(arquivo);
      return serie;
   }

   public static void main(String[] args) {
      MyIO.setCharset("UTF-8");
      ListaDupla lista = new ListaDupla();

      String palavra = "";
      palavra = MyIO.readLine();
      // Continua o loop até a palavra FIM ser achada
      while (!(isFim(palavra))) {
         Serie serie = new Serie(palavra);
         try {
            lista.inserirFim(serie);
         } catch (Exception e) {
         }
         palavra = MyIO.readLine();
      }
      // Start timer
      long inicio = new Date().getTime();

      // Ordena alfabeticamente pelo atributo Country
      lista.countrySort();

      // End timer
      long fim = new Date().getTime();
      double tempo = (fim - inicio) / 1000.0;
      
      // Ordena alfabeticamente pelo atributo Name, respeitando a ordenacao anterior
      lista.ordenar();

      Arq.openWrite("728738_quicksort2.txt");
      Arq.println("728738\t" + lista.getComparacoes() + "\t" + lista.getMovimentacoes() + "\t" + tempo);
      Arq.close();

      lista.mostrar();
   }
}