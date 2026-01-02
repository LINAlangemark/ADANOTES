public class AdditiveString {
     // Base case: Hvis s er mindre end 3, returneres false
    public static boolean additive(String s) {
        if (s.length() < 3) {
            return false;
        }
         // Første, anden og tredje karakter i s konverteres til heltal ved at trække '0' fra 
        int first = s.charAt(0) - '0';
        int second = s.charAt(1) - '0';
        int third = s.charAt(2) - '0';

        // Hvis tredje karakter er summen af de to foregående karakterer, returneres true ellers kaldes rekursivt for s uden første karakter
        if (third == first + second) {
            return true;
        } else {
            return additive(s.substring(1));
        }
    }

    public static void main(String[] args) {
        String s = "82842605";
        System.out.println(additive(s)); // Output: true
    }
}