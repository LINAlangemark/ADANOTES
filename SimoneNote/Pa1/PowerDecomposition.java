// Metode til at finde største heltallige værdi af X og Y hvor X^Y = Z

public class PowerDecomposition {

    public static int[] findXY(int Z) {
        // Hvis Z er mindre end eller lig med 0 eller større end eller lig med 100000, returneres {-1, -1}
        if (Z <= 0 || Z >= 100000) {
            return new int[] {-1, -1};
        }

        // Initialiserer maxX og maxY til -1
        int maxX = -1;
        int maxY = -1;

        // Itererer fra 3 til kvadratroden af Z
        for (int X = 3; X < Math.sqrt(Z) + 1; X++) {
            int low = 3;
            // Finder højeste potens af X, der er mindre end Z
            int high = (int) (Math.log(Z) / Math.log(X)) + 1;

            // Finder potensen af X, der er lig med Z
            while (low <= high) {
                int mid = (low + high) / 2;
                // Beregner X^mid
                int power = (int) Math.pow(X, mid);

                // Hvis power er lig med Z, opdateres maxX og maxY
                if (power == Z) {
                    if (X > maxX) {
                        maxX = X;
                        maxY = mid;
                    }
                    break;
                
                    // Hvis power er mindre end Z, opdateres low
                } else if (power < Z) {
                    low = mid + 1;
                    // Hvis power er større end Z, opdateres high
                } else {
                    high = mid - 1;
                }
            }
        }
        // Hvis maxX er -1, returneres {-1, -1}
        if (maxX == -1) {
            return new int[] {-1, -1}; 
        }
        // Returnerer maxX og maxY
        return new int[] {maxX, maxY};
    }

    public static void main(String[] args) {
        int Z1 = 6561;
        int[] result1 = findXY(Z1);
        System.out.println("For Z = " + Z1 + ": X = " + result1[0] + ", Y = " + result1[1]);

        int Z2 = 3125;
        int[] result2 = findXY(Z2);
        System.out.println("For Z = " + Z2 + ": X = " + result2[0] + ", Y = " + result2[1]);

        int Z3 = 100000;
        int[] result3 = findXY(Z3);
        System.out.println("For Z = " + Z3 + ": X = " + result3[0] + ", Y = " + result3[1]);
    }
}