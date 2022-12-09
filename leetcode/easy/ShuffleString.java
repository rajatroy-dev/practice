public class ShuffleString {
    private static String restoreString(String s, int[] in) {
        char[] c = new char[in.length];
        for (int i = 0; i < in.length; i++)
            c[in[i]] = s.charAt(i);
        return new String(c);
    }

    public static void main(String[] args) {
        String s = "codeleet";
        int in[] = { 4, 5, 6, 7, 0, 2, 1, 3 };
        System.out.println(restoreString(s, in));
    }
}
