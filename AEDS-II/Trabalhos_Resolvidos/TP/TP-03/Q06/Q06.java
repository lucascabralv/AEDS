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
        String resp = this.name + " " + this.format + " " + this.duration + " " + this.country + " " + this.language
                + " " + this.broadcaster + " " + this.streaming + " " + this.seasons + " " + this.episodes;
        return resp;
    }

    // método para printar a classe
    public void printClass() {
        System.out.println(this.toString().replaceAll("  ", " "));
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
        if (line.charAt(0) == ' ') {
            for (int i = 1; i < line.length(); i++) {
                resp += line.charAt(i);
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
        String file = "/Users/lucascabral/Desktop/series/" + fileName;
        //String file = "/tmp/series/" + fileName;
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

class Lista {
    private Serie series[];
    private int tamanho;
    private int comparacoes;
    private int movimentacoes;

    // Construtor da classe.
    public Lista() {
        this(100);
    }

    public Lista(int tam) {
        series = new Serie[tam];
        tamanho = 0;
        comparacoes = 0;
        movimentacoes = 0;
    }

    public int getComparacoes() {
        return comparacoes;
    }

    public int getMovimentacoes() {
        return movimentacoes;
    }

    /*
     * Insere um elemento na primeira posicao da lista e move os demais elementos
     * para o fim da lista.
     */
    public void inserirInicio(Serie x) throws Exception {
        // validar insercao
        if (tamanho >= series.length) {
            throw new Exception("Erro ao inserir!");
        }
        // levar elementos para o fim do array
        for (int i = tamanho; i > 0; i--) {
            series[i] = series[i - 1].clone();
        }
        series[0] = x.clone();
        tamanho++;
    }

    /*
     * Insere um elemento na ultima posicao da lista.
     */
    public void inserirFim(Serie x) throws Exception {
        // validar insercao
        if (tamanho >= series.length) {
            throw new Exception("Erro ao inserir!");
        }
        series[tamanho] = x.clone();
        tamanho++;
    }

    /*
     * Insere um elemento em uma posicao especifica e move os demais elementos para
     * o fim da lista.
     */
    public void inserir(Serie x, int pos) throws Exception {
        // validar insercao
        if (tamanho >= series.length || pos < 0 || pos > tamanho) {
            throw new Exception("Erro ao inserir!");
        }
        // levar elementos para o fim do array
        for (int i = tamanho; i > pos; i--) {
            series[i] = series[i - 1].clone();
        }
        series[pos] = x.clone();
        tamanho++;
    }

    /*
     * Remove um elemento da primeira posicao da lista e movimenta os demais
     * elementos para o inicio da mesma.
     */
    public Serie removerInicio() throws Exception {
        // validar remocao
        if (tamanho == 0) {
            throw new Exception("Erro ao remover!");
        }
        Serie resp = series[0].clone();
        // MyIO.println("Serie removida: " + resp.getName() + " -> 0");
        tamanho--;

        for (int i = 0; i < tamanho; i++) {
            series[i] = series[i + 1].clone();
        }
        return resp;
    }

    /**
     * Remove um elemento da ultima posicao da lista.
     */
    public Serie removerFim() throws Exception {
        // validar remocao
        if (tamanho == 0) {
            throw new Exception("Erro ao remover!");
        }
        // MyIO.println("Serie removida: " + series[tamanho].getName() + " -> " +
        // tamanho);
        return series[--tamanho];
    }

    /*
     * Remove um elemento de uma posicao especifica da lista e movimenta os demais
     * elementos para o inicio da mesma.
     */
    public Serie remover(int pos) throws Exception {
        // validar remocao
        if (tamanho == 0 || pos < 0 || pos >= tamanho) {
            throw new Exception("Erro ao remover!");
        }
        Serie resp = series[pos].clone();
        // MyIO.println("Serie removida: " + resp.getName() + " -> " + pos);
        tamanho--;

        for (int i = pos; i < tamanho; i++) {
            series[i] = series[i + 1].clone();
        }

        return resp;
    }

    public void mostrar() {
        for (int i = 0; i < tamanho; i++) {
            //series[i].printClass();
            MyIO.println(series[i].getCountry() + " --- " + series[i].getName());
        }
    }

    public void swap(int i, int j) {
        Serie temp = series[i].clone();
        series[i] = series[j].clone();
        series[j] = temp.clone();
        movimentacoes += 3;
    }
    
    public void sort(String tipo) {
        quicksort(0, tamanho - 1, tipo);
    }
    
    public void sort() {
        quicksort(0, tamanho - 1, "Name");
    }

    private void quicksort(int esq, int dir, String tipo) {
        int i = esq, j = dir;
        Serie pivo = series[(dir + esq) / 2].clone();
        
        if(tipo == "Country"){
            while (i <= j) {
                while (series[i].getCountry().compareTo(pivo.getCountry()) < 0)
                    i++;
                while (series[j].getCountry().compareTo(pivo.getCountry()) > 0)
                    j--;
                if (i <= j) {
                    swap(i, j);
                    i++;
                    j--;
                }
            }
            if (esq < j)
                quicksort(esq, j, "Country");
            if (i < dir)
                quicksort(i, dir, "Country");
        } else {
            while (i <= j) {
                while (series[i].getName().compareTo(pivo.getName()) < 0)
                    i++;
                while (series[j].getName().compareTo(pivo.getName()) > 0)
                    j--;
                if (i <= j) {
                    swap(i, j);
                    i++;
                    j--;
                }
            }
            if (esq < j)
                quicksort(esq, j, "Name");
            if (i < dir)
                quicksort(i, dir, "Name");
        }
    }

} // END CLASSE LISTA

public class Q06 {
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
        Lista lista = new Lista();

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

        lista.sort();
        //lista.sort("Country");

        // End timer
        long fim = new Date().getTime();
        double tempo = (fim - inicio) / 1000.0;

        Arq.openWrite("728738_quicksort.txt");
        Arq.println("728738\t" + lista.getComparacoes() + "\t" + lista.getMovimentacoes() + "\t" + tempo);
        Arq.close();

        lista.mostrar();
    }
}
