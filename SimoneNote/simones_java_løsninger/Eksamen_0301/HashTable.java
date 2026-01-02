public class HashTable {
    private static final int TABLE_SIZE = 13;

    //Implementering af quadratic probing
    private static int quadraticProbe(int index, int i, int[], table){
        while(table[index] != 0){
            index = (index + i * i) % TABLE_SIZE;
            i++;
        }
    return index;
    }
    public static void main(String[] args) {
        int[] table = new int[TABLE_SIZE]; // Squadratic probing
    

    // Indsæt elemtner i tabellen
    char[] keys = {'H','E','J'};
    for(char key){
        int index = hash(key);
        index = quadraticProbe(index, i, table);
        table[index]=key;
    }

}
}

