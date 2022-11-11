import java.util.HashMap;

public class CheckIfAllSubArrayElementsAreInArray {
    static boolean isPresent(String[] array, String[] subArray) {
        int arrayLength = array.length;
        int subArrayLength = subArray.length;
        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < subArrayLength; i++) {
            map.put(subArray[i], 1);
        }

        int count = 0;
        for (int i = 0; i < arrayLength; i++) {
            if (map.containsKey(array[i])) {
                count++;
            }
        }

        return count == subArrayLength;
    }

    public static void main(String[] args) {
        String[] array = { "AB", "CD", "EF", "GH" };
        String[] subArray = { "EF", "AB" };

        System.out.println(isPresent(array, subArray));
    }
}
