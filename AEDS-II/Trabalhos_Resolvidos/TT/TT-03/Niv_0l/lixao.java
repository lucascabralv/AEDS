class Retangulo{
    private double altura;
    private double base;

    public Retangulo(){
        this.altura = 0;
        this.base = 0;
    }
    public Retangulo(double base, double altura){
        this.altura = altura;
        this.base = base;
    }
    public double getArea(){
        return base * altura;
    }
    public double getPerimetro(){
        return 2 * base + 2 * altura;
    }
    public double getDiagonal(){
        return Math.sqrt(base * base + altura * altura);
    }
}

public class lixao{
    public static void main(String[] args) {
        Retangulo r1 = new Retangulo(5,10);
        Retangulo r2 =  new Retangulo(2,3);
        MyIO.print("R1:\n • Área: " + r1.getArea() + "\n • Perímetro: " + r1.getPerimetro() + "\n • Diagonal: "
                + r1.getDiagonal());
        MyIO.print("\nR2:\n • Área: " + r2.getArea() + "\n • Perímetro: " + r2.getPerimetro() + "\n • Diagonal: "
                + r2.getDiagonal());
    }
}