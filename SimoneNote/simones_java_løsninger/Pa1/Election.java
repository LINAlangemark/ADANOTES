import java.util.HashMap;
import java.util.Map;

public class Election {

    // Implementering af metode til at finde vinderen af et valg
    public static int findWinner(int[] votes) {
        // Initialiserer en HashMap til at tælle stemmerne for hver kandidat
        Map<Integer, Integer> candidateVotes = new HashMap<>();
        // Initialiserer variabler til at holde antallet af stemmer og tærskelværdien for at vinde
        int totalVotes = votes.length;
        // Tærskelværdien for at vinde er halvdelen af stemmerne
        int winningThreshold = totalVotes / 2;

        // Tæller stemmerne for hver kandidat i HashMap
        for (int vote : votes) {
            candidateVotes.put(vote, candidateVotes.getOrDefault(vote, 0) + 1);
        }

        // Finder kandidaten med flest stemmer over tærskelværdien og returnerer kandidatnummeret
        for (Map.Entry<Integer, Integer> entry : candidateVotes.entrySet()) {
            if (entry.getValue() > winningThreshold) {
                return entry.getKey();
            }
        }

        // Hvis ingen kandidat har fået over halvdelen af stemmerne, returneres -1
        return -1;
    }

    public static void main(String[] args) {
        int[] votes = {7, 4, 3, 5, 3, 1, 6, 4, 5, 1, 7, 5};
        int winner = findWinner(votes);
        System.out.println("Vinderen er kandidat " + winner);
    }
}