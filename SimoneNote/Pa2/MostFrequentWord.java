import java.util.HashMap;
import java.util.Map;

public class MostFrequentWord {
    public static String findMostFrequentWord(String text) {
        if (text == null || text.isEmpty()) {
            return "";
        }
    
        // Opret et HashMap til at tælle forekomster af hvert ord
        Map<String, Integer> wordCount = new HashMap<>();

        // Split teksten på mellemrum, kommaer og punktummer og konverter alle ord til lowercase
        String[] words = text.toLowerCase().split("[\\s,.!]+");

        // Tæl forekomster af hvert ord
        for (String word : words) {
            if (!word.isEmpty()) {
                wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
            }
        }

        // Find ordet med det højeste antal forekomster
        String mostFrequentWord = "";
        int maxCount = 0;
        for (Map.Entry<String, Integer> entry : wordCount.entrySet()) {
            if (entry.getValue() > maxCount) {
                maxCount = entry.getValue();
                mostFrequentWord = entry.getKey();
            }
        }

        return mostFrequentWord;
    }

    public static void main(String[] args) {
        String text = "I have a dog, a cat and four chickens";
        //String text = "The cattle were running back and forth, but there was no wolf to be seen, heard, or smelled, so the shepherd decided to take a little nap in a bed of grass and early summer flowers. Soon he was awakened by a sound he had never heard before.";
        String mostFrequentWord = findMostFrequentWord(text);
        System.out.println("The most frequent word is: " + mostFrequentWord);
    }
}