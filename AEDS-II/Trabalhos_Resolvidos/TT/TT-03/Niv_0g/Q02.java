public class Q02 {
    private static BufferedReader in = new BufferedReader(
            new InputStreamReader(System.in, Charset.forName("ISO-8859-1")));

    public static String readString() {
        String s = "";
        char tmp;
        try {
            do {
                tmp = (char) in.read();
                if (tmp != '\n' && tmp != ' ' && tmp != 13) {
                    s += tmp;
                }
            } while (tmp != '\n' && tmp != ' ');
        } catch (IOException ioe) {
        }
        return s;
    }

    public static void main(String[] args) throws Exception {

        MyIO.printf("Entre com uma palavra: ");
        String str = readString();

        MyIO.printf("Entre com um numero inteiro: ");
        int inteiro = Integer.parseInt(readString().trim());

        MyIO.printf("Entre com um numero real: ");
        double real = Double.parseDouble(readString().trim().replace(",", "."));

        MyIO.printf("Entre com um caractere: ");
        char caractere = (char) in.read();

        MyIO.println("Sua str: " + str);
        MyIO.println("Seu inteiro: " + inteiro);
        MyIO.println("Seu real: " + real);
        MyIO.println("Seu caractere: " + caractere);
    } 
}
