import java.util.Arrays;

public class ClosestToPowerOfTwo {

    public static int[] findClosest(int[] nums) {
        int[] result = new int[4];                              // For at gemme de tre tal og nærmeste power of two
        int minDiff = Integer.MAX_VALUE;                        // For at gemme den mindste forskel mellem summen af tre tal og nærmeste power of two

        for (int i = 0; i < nums.length - 2; i++) {              
            for (int j = i + 1; j < nums.length - 1; j++) {     
                for (int k = j + 1; k < nums.length; k++) {    
                    int sum = nums[i] + nums[j] + nums[k]; 
                    int nearestPower = nearestPowerOfTwo(sum); // Find nærmeste power of two for summen af tre tal
                    int diff = Math.abs(sum - nearestPower);   // Find forskellen mellem summen af tre tal og nærmeste power of two

                    if (diff < minDiff) {                      // Hvis forskellen er mindre end den hidtil mindste forskel 
                        minDiff = diff;                        // Opdater minDiff
                        result[0] = nums[i];
                        result[1] = nums[j];
                        result[2] = nums[k];
                        result[3] = nearestPower;              // Opdater result med de tre tal og nærmeste power of two
                    
                    } else if (diff == minDiff && Math.abs(sum - nearestPower) < Math.abs((result[0] + result[1] + result[2]) - result[3])) { // Hvis summen af de tre tal er tættere på nærmeste power of two end summen af de tidligere tre tal
                        result[0] = nums[i];
                        result[1] = nums[j];
                        result[2] = nums[k];
                        result[3] = nearestPower;
                    }
                }
                if (minDiff == 0) {                            // Hvis forskellen er 0, så er det den mindste forskel muligt, så vi kan stoppe
                    break;
                }
            }
        }
        return result;
    }

    private static int nearestPowerOfTwo(int num) {                         // Metode til at finde nærmeste power of two for et tal 
        int power = 1;                                                      // Initialiser power til 1
        while (power < num) {                                               // Find den største power of two, der er mindre end num
            power <<= 1;                                                    // Opdater power med den næste power of two
        }
        int lowerPower = power >> 1;                                        // Find den mindste power of two, der er større end num
        return (num - lowerPower) < (power - num) ? lowerPower : power;     // Returner den nærmeste power of two
    }

    public static void main(String[] args) {                                // Main metode til at teste findClosest metoden
        int[] nums = {23, 56, 22, 11, 65, 89, 3, 44, 87, 910, 45, 35, 98};  // Array med tal
        int[] result = findClosest(nums);                                   // Kald findClosest metoden med nums arrayet
        System.out.println(Arrays.toString(result));                        // Udskriv result arrayet
    }
}