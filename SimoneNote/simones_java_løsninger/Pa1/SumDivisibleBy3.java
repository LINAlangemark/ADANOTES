import java.util.Arrays;

// Implementering af metode til at finde summen af alle tal op til N, der er delelige med 3

public class SumDivisibleBy3 {
    static int[] memo;

    // Rekursiv metode til at finde summen af alle tal op til N, der er delelige med 3
    public static int sumDivisibleBy3(int N) {
        // Hvis memo ikke er initialiseret eller er for lille, initialiseres memo
        if (memo == null || memo.length <= N) {
            // Initialiserer memo med -1 for at markere, at værdien ikke er beregnet endnu
            memo = new int[N + 1];
            Arrays.fill(memo, -1);
        }

        // Base case: Hvis N er mindre end 3, er summen 0
        if (N < 3) {
            return 0;
        }

        // Hvis værdien allerede er beregnet, returneres den
        if (memo[N] != -1) {
            return memo[N];
        }

        if (N % 3 == 0) {
            // Hvis N er deleligt med 3, inkluderer vi N i summen
            memo[N] = N + sumDivisibleBy3(N - 3);
        } else {
            // Hvis N ikke er deleligt med 3, fortsætter vi rekursivt med N-1
            memo[N] = sumDivisibleBy3(N - 1);
        }

        return memo[N];
    }

    public static void main(String[] args) {
        int N1 = 12;
        int N2 = 14;
        System.out.println("Sum of numbers divisible by 3 up to " + N1 + " is: " + sumDivisibleBy3(N1)); 
        System.out.println("Sum of numbers divisible by 3 up to " + N2 + " is: " + sumDivisibleBy3(N2)); 
    }
}