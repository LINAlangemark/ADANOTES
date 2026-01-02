public class Pattern {
    public static int findPattern(String text, String word) {
        int[] wordLetters = new int[26];
        for (int i = 0; i < word.length(); i++) {
            wordLetters[word.charAt(i) - 'a']++;
        }

        int wordLength = word.length();
        int textLength = text.length();
        int i = 0;

        while (i < textLength) {
            // Skip spaces
            while (i < textLength && text.charAt(i) == ' ') {
                i++;
            }

            // Find the end of the current word
            int start = i;
            while (i < textLength && text.charAt(i) != ' ') {
                i++;
            }
            int end = i;

            // Process the current word
            if (end > start) {
                if (end - start == wordLength && compareSubstring(text, start, end, word)) {
                    return 1;
                }

                if (end - start == wordLength && containsSameLetters(text, start, end, wordLetters)) {
                    return 2;
                }

                if (containsAllLettersInOrder(text, start, end, word)) {
                    return 3;
                }
            }
        }
        return 0;
    }

    private static boolean compareSubstring(String text, int start, int end, String word) {
        for (int i = 0; i < word.length(); i++) {
            if (text.charAt(start + i) != word.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    private static boolean containsSameLetters(String text, int start, int end, int[] wordLetters) {
        int[] letters = new int[26];
        for (int i = start; i < end; i++) {
            letters[text.charAt(i) - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (letters[i] != wordLetters[i]) {
                return false;
            }
        }
        return true;
    }

    private static boolean containsAllLettersInOrder(String text, int start, int end, String word) {
        int j = 0;
        for (int i = start; i < end; i++) {
            if (j < word.length() && text.charAt(i) == word.charAt(j)) {
                j++;
            }
        }
        return j == word.length();
    }

    public static void main(String[] args) {
        String text = "this is a test som mos storkemor ostemad";
        String word = "som";
        int result = findPattern(text, word);
        System.out.println("Result: " + result); // Output: 1
    }
}