import java.util.Stack;

// Fidelity
public class CountValidCurlyBraces {
    static int validCurly(String str) {
        int count = 0;
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '{') {
                stack.push('{');
            } else {
                if (!stack.isEmpty() && str.charAt(i) == '}' && stack.peek() == '{') {
                    count++;
                }
            }
        }

        return count;
    }

    public static void main(String[] args) {
        String str = "this is { a valid curly } but { { this is not )]. This is ( valid parentheses ). This is [ valid square ]. Is this [{{{ (valid) }}}]";

        System.out.println(validCurly(str));
    }
}
