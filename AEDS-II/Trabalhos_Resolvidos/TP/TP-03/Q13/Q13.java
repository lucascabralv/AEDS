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
        // String file = "/Users/lucascabral/Desktop/series/" + fileName;

        /** Series no WSL */
        //String file = "/mnt/c/Users/cabral/Documents/Github/AEDS/AEDS-II/series/"+fileName;

        /** Series no Verde */
        String file = "/tmp/series/" + fileName;

        try {
            FileReader fileReader = new FileReader(file); // declaração da variável fileReader que será recebida pelo
                                                          // bufferedReader

            BufferedReader br = new BufferedReader(fileReader); // declaração do bufferedReader para leitura do arquivo

            // set nome da série
            this.name = removeSpace(searchName(fileName));

            // set Formato da série
            while (!br.readLine().contains("Formato"))
                ;
            this.format = removeSpace(removeTags(br.readLine()));

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
            this.broadcaster = removeSpace(removeTags(br.readLine()));

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

class Celula {
    public Serie elemento;
    public Celula prox;

    public Celula() {
        this(new Serie());
    }

    public Celula(Serie x) {
        this.elemento = x.clone();
        this.prox = null;
    }
}

class Pilha {
    private Celula topo;

    public Pilha() {
        topo = null;
    }

    /*
     * Empilha o elemento
     */
    public void empilhar(Serie x){
        Celula tmp = new Celula(x); // Cria celula temporaria e tmp aponta para ela
        tmp.prox = topo; // tmp.prox terá o valor de topo que é uma variável de Pilha
        topo = tmp; // topo receberá o endereço de memória de tmp
        tmp = null;
    }

    /*
     * Desempilha
     */
    public Serie desempilhar() throws Exception {
        if (topo == null) {
            throw new Exception("Erro!");
        }
        Serie elemento = topo.elemento.clone();
        Celula tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        return elemento;
    }

    public void mostrar() {
        for (Celula i = topo; i != null; i = i.prox) {
            i.elemento.printClass();
        }
    }
} // END CLASSE PILHA

public class Q12 {
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

    public static void lerComandos(String linha, Pilha pilha) throws Exception {
        String comando = linha.substring(0, 1);
        String serieArquivo;
        switch (comando) {
        case "I": {
            serieArquivo = linha.substring(2, linha.length());
            pilha.empilhar(criaSerie(serieArquivo));
            break;
        }
        case "R": {
            Serie retorno = pilha.desempilhar();
            MyIO.println("(R) " + retorno.getName());
            break;
        }
        }
    }

    public static void main(String[] args) {
        MyIO.setCharset("UTF-8");
        Pilha pilha = new Pilha();

        String palavra = "";
        palavra = MyIO.readLine();
        // Continua o loop até a palavra FIM ser achada
        while (!(isFim(palavra))) {
            Serie serie = new Serie(palavra);
            try {
                pilha.empilhar(serie);
            } catch (Exception e) {
            }
            palavra = MyIO.readLine();
        }

        int num = MyIO.readInt();
        // Continua o loop até a palavra FIM ser achada
        for (int i = 0; i < num; i++) {
            palavra = MyIO.readLine();
            try {
                lerComandos(palavra, pilha);
            } catch (Exception e) {
            }
        }
        pilha.mostrar();
    }
}