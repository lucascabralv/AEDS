public class Q01 {
    public static void main(String[] args) {

        // Declara scanner
        Scanner scanner = new Scanner(System.in);

        MyIO.printf("Entre com uma palavra: ");
        String str = scanner.nextLine();

        MyIO.printf("Entre com um caractere: ");
        char caractere = scanner.nextLine().charAt(0);

        MyIO.printf("Entre com um numero inteiro: ");
        int inteiro = scanner.nextInt();

        MyIO.printf("Entre com um numero real: ");
        double real = scanner.nextDouble();

        MyIO.println("Sua str: " + str);
        MyIO.println("Seu inteiro: " + inteiro);
        MyIO.println("Seu real: " + real);
        MyIO.println("Seu caractere: " + caractere);
    }
}
