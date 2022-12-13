public class SplitAStringInBalancedStrings {
    private static int balancedStringSplit(String s) {
        int res = 0, cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            cnt += s.charAt(i) == 'L' ? 1 : -1;
            if (cnt == 0)
                ++res;
        }
        return res;
    }

    public static void main(String[] args) {
        String str = "RLRRLLRLRL";

        System.out.println(balancedStringSplit(str));
    }
}