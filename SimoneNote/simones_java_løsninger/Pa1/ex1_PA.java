// Opgave 1. rekursiv algoritme

public class ex1_PA {

    public static int sumUligeKvadrater(int n) {
        // Base case: Hvis n er mindre end 1, er summen 0
        if (n < 1) {
            return 0;
        }

        // Hvis n er ulige, inkluderer vi n^2 i summen
        // og kalder rekursivt for n-2
        if (n % 2 != 0) {
            return n * n + sumUligeKvadrater(n - 2); // Fordi der kun kaldes rekursivt for n-2 når n er ulige, undgås overflødige iterationer over lige tal
        } else {
            // Hvis n er lige, kalder vi rekursivt for n-1
            // Det ulige tal før n vil allerede være inkluderet
            return sumUligeKvadrater(n - 1);
        }
    }

    public static void main(String[] args) {
        int n = 8;
        int result = sumUligeKvadrater(n);
        System.out.println("Summen af de ulige kvadrater fra 1 til " + n + " er: " + result);
    }
}
