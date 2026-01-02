public class Log2 {
    public static int log2(int N) {
        // Base case: Hvis N er 1, er logaritmen 0
        if (N == 1) {
            return 0;
        } else {
            // Rekursiv tilfælde: Divider N med 2 og øg logaritmen med 1
            return 1 + log2(N / 2);
        }
    }

    public static void main(String[] args) {
        int N1 = 32;
        int N2 = 4096;

        System.out.println("log2(" + N1 + ") = " + log2(N1));
        System.out.println("log2(" + N2 + ") = " + log2(N2));
    }
}