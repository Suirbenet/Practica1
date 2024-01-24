/**
 * funcionperrona
 */
public class funcionperrona {


    public static void main(String[] args) {
        Animales sergio = new Animales("hindue", 43);
        System.out.println("sergio es tipo: " + sergio.gettipo());
        System.out.println("sergio tiene " + sergio.getpatotas() + " patotas");
        sergio.comer();

        poyo nacho = new poyo("pajaro", 5);
        System.out.println("el poyo es de tipo: " + nacho.gettipo());
        System.out.println("y tiene " + nacho.getpatotas() + " patotas el culero");
        nacho.comer();
    }

}