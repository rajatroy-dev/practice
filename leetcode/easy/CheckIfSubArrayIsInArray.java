public class CheckIfSubArrayIsInArray {
    static boolean isSubArray(String[] array, String[] subArray) {
        int arrayLength = array.length;
        int subArrayLength = subArray.length;

        int arrayIndex = 0, subArrayIndex = 0;

        while (arrayIndex < arrayLength && subArrayIndex < subArrayLength) {
            if (array[arrayIndex] == subArray[subArrayIndex]) {
                arrayIndex++;
                subArrayIndex++;

                if (subArrayIndex == subArrayLength) {
                    return true;
                }
            } else {
                arrayIndex = arrayIndex - subArrayIndex + 1;
                subArrayIndex = 0;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        String[] array = { "AB", "CD", "EF", "GH" };
        String[] subArray = { "CD", "IJ" };

        System.out.println(isSubArray(array, subArray));
    }
}
