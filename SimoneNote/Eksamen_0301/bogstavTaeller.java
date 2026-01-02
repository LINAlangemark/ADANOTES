public class bogstavTaeller{
    public static boolean erBogstav(char c){
        return "abcdefghijklmnopqrstuvwxyz".indexOf(c) !=-1;
    }

    public static int antalBogstaver(String str, int i){
        //Base case: Hvis vi har nået slutningen af strengen
        if (i < 0){
            return 0;
        }

        //Rekursiv case: Tæl bogstavet på den aktuelle position
        // kald rekursivt for resten af strengen
        return (erBogstav(str.charAt(i)) ? 1: 0) + antalBogstaver(str, i-1);
    } 

    public static void main(String[] args) {
        String str = "banana";
        int antalBogstaver = antalBogstaver(str, str.length()-1);
        System.out.println("Antal bogstaver i \"" + str + "\":" +antalBogstaver);
    }
}
