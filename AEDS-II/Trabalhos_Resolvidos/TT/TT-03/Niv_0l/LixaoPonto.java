import java.lang.Math;

class Ponto{
    private double x, y;
    private int id;
    private static int nextID = 0;

    public Ponto(){
        this.x = this.y = 0;    
        this.id = this.nextID;
        this.nextID++; 
    }
    public Ponto(double x, double y){
        this.x = x;
        this.y = y;   
        this.id = this.nextID;
        this.nextID++; 
    }
    public void setx(double x){
        this.x = x;
    }
    public void sety(double y){
        this.y = y;
    }
    public double getx(){
        return this.x;
    }
    public double gety(){
        return this.y;
    }
    public int getID(){
        return this.id;
    }
    public static int getNextID(){
        return nextID;
    }
    public double dist(Ponto p2){
        return Math.sqrt(Math.pow(this.x - p2.getx(),2) + Math.pow(this.y - p2.gety(),2));
    }
    public double dist(double x2, double y2){
        return Math.sqrt(Math.pow(this.x - x2,2) + Math.pow(this.y - y2,2));
    }
    public double dist(double x1, double y1, double x2, double y2){
        return Math.sqrt(Math.pow(x1 - x2,2) + Math.pow(y1 - y2,2));
    }
    public static String isTriangulo(Ponto p1, Ponto p2, Ponto p3){
        String resp = "Não";
        double a = p1.dist(p2), b = p2.dist(p3), c = p3.dist(p1);
        if((Math.abs(b-c) < a && b+c > a) && (Math.abs(a-c) < b && a+c > b) && (Math.abs(a-b) < c && a+b > c)){
            resp = "Sim";
        }
        return resp;
    }
    public double getAreaRetangulo(Ponto p2){
        return Math.abs(this.x - p2.getx()) * Math.abs(this.y - p2.gety());
    }

}

public class LixaoPonto {
    public static void main(String[] args) {
        Ponto p1 = new Ponto(4,3);
        Ponto p2 = new Ponto(8,5);
        Ponto p3 = new Ponto(9.2,10);

        MyIO.println("Distancia entre p1 e p2: " + p1.dist(p2));
        MyIO.println("Distancia entre p1 e (5,2): " + p1.dist(5,2));
        MyIO.println("Distancia entre (4,3) e (5,3): " + p1.dist(4,3,5,2));
        MyIO.println("P1, P2, P3 sao triangulo? " + Ponto.isTriangulo(p1,p2,p3));
        MyIO.println("Area retangulo: " + p1.getAreaRetangulo(p2));
        MyIO.println("ID de P1: " + p1.getID());
        MyIO.println("ID de P2: " + p2.getID());
        MyIO.println("ID de P3: " + p3.getID());
        MyIO.println("Next ID: " + Ponto.getNextID());
    }
}
