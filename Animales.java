public class Animales {
    
    private String tipo;
    private int patotas;

    public Animales (String tipo, int patotas) {
        this.tipo = tipo;
        this.patotas = patotas;
    }
    
    public void comer(){
        System.out.println("este animal kome piksa sin hueso");

    }

    public String gettipo(){
        return tipo; //ayuda
    }

    public int getpatotas(){
        return patotas; //abre las patotas
    }
}
