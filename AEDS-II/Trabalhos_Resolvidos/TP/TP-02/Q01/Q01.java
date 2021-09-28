import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Scanner;

class Serie {
    // Atributos
    String nome;
    String formato;
    String duracao;
    String pais;
    String idioma;
    String emissora;
    String transmissao;
    int episodios;
    int temporadas;

    Serie() {
        nome = "";
        formato = "";
        duracao = "";
        pais = "";
        idioma = "";
        emissora = "";
        transmissao = "";
        episodios = 0;
        temporadas = 0;
    }

    // SETS
    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setFormato(String formato) {
        this.formato = formato;
    }

    public void setDuracao(String duracao) {
        this.duracao = duracao;
    }

    public void setPais(String pais) {
        this.pais = pais;
    }

    public void setIdioma(String idioma) {
        this.idioma = idioma;
    }

    public void setEmissora(String emissora) {
        this.emissora = emissora;
    }

    public void setTransmissao(String transmissao) {
        this.transmissao = transmissao;
    }

    public void setEpisodios(int episodios) {
        this.episodios = episodios;
    }

    public void setTemporadas(int temporadas) {
        this.temporadas = temporadas;
    }

    // GETS
    public String getNome() {
        return this.nome;
    }

    public String getFormato() {
        return this.formato;
    }

    public String getDuracao() {
        return this.duracao;
    }

    public String getPais() {
        return this.pais;
    }

    public String getIdioma() {
        return this.idioma;
    }

    public String getEmissora() {
        return this.emissora;
    }

    public String getTransmissao() {
        return this.transmissao;
    }

    public int getEpisodios() {
        return this.episodios;
    }

    public int getTemporadas() {
        return this.temporadas;
    }

    // Transforma todas as informações em uma string única.
    public String toString() {
        return (this.nome + " " + this.formato + " " + this.duracao + " " + this.pais + " " + this.idioma + " "
                + this.emissora + " " + this.transmissao + " " + this.episodios + " " + this.temporadas)
                        .replace("&#160;", "").replace("&nbsp;", " ").replaceAll("  ", " ");
    }

    String removeTags(String line) {
        String newLine = "";
        int i = 0;
        while (i < line.length()) {
            if (line.charAt(i) == '<') {
                i++;
                while (line.charAt(i) != '>')
                    i++;
            } else {
                newLine += line.charAt(i);
            }
            i++;
        }
        return newLine;
    }

    // Remove tags e deixa apenas os números
    int removeTagsInt(String line) {
        String newLine = "";
        int i = 0;
        while (i < line.length()) {
            if (line.charAt(i) == '<') {
                i++;
                while (line.charAt(i) != '>')
                    i++;
            } else {
                newLine += line.charAt(i);
            }
            i++;
        }
        int resp = new Scanner(newLine).useDelimiter("\\D+").nextInt();
        return resp;
    }

    // Abre e lê arquivo
    public void ler(String nomeArquivo) throws Exception {
        InputStreamReader isr = new InputStreamReader(new FileInputStream(nomeArquivo));
        BufferedReader br = new BufferedReader(isr);

        // "Pula" as linhas enquanto não achar a palavra desejada
        while (!br.readLine().contains("infobox_v2"))
            ;
        br.readLine();
        // Atribui o texto ao nome
        this.nome = removeTags(br.readLine());

        while (!br.readLine().contains("Formato"))
            ;
        this.formato = removeTags(br.readLine());

        while (!br.readLine().contains("Duração"))
            ;
        this.duracao = removeTags(br.readLine());

        while (!br.readLine().contains("País de origem"))
            ;
        this.pais = removeTags(br.readLine());

        while (!br.readLine().contains("Idioma original"))
            ;
        this.idioma = removeTags(br.readLine());

        while (!br.readLine().contains("Emissora de televisão original"))
            ;
        this.emissora = removeTags(br.readLine());

        while (!br.readLine().contains("Transmissão original"))
            ;
        this.transmissao = removeTags(br.readLine());

        while (!br.readLine().contains("temporadas"))
            ;
        this.episodios = removeTagsInt(br.readLine());

        while (!br.readLine().contains("N.º de episódios"))
            ;
        this.temporadas = removeTagsInt(br.readLine());

        br.close();
    }
}

public class Q01 {
    // Confere se a palavra é igual a FIM
    public static boolean isFim(String s) {
        boolean resp = false;
        if (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M') {
            resp = true;
        }
        return resp;
    }

    public static void main(String[] args) {
        MyIO.setCharset("UTF-8");
        String palavra = "";
        palavra = MyIO.readLine();
        // Continua o loop até a palavra FIM ser achada
        while (!(isFim(palavra))) {
            Serie serie = new Serie();
            // Define o caminho para o arquivo
            //String pathSeries = "/tmp/series/" + palavra;
            String pathSeries = "/Users/lucascabral/Desktop/series/" + palavra;
            try {
                // Le arquivo e imprime as informações selecionadas
                serie.ler(pathSeries);
                MyIO.println(serie.toString());
            } catch (Exception e) {
            }
            palavra = MyIO.readLine();
        }
    }
}