public class FindNthOccurence {
    private static int findNthOccurence(String str, char c, int pos) {
        int occurence = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == c) {
                occurence++;
            }
            
            if (occurence == pos) {
                return i;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        String str = "http://example.com/abc/def/ghi?a=b";

        System.out.println(findNthOccurence(str, '/', 3));
    }
}
