import java.util.Iterator;
import java.util.Stack;

public class RemoveAdjacentDuplicateCharacters {
    static void remove(String str) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            Character character = str.charAt(i);

            if (!stack.isEmpty() && stack.peek() == character) {
                stack.pop();
            } else {
                stack.push(character);
            }
        }

        Iterator<Character> iterator = stack.iterator();
        while (iterator.hasNext()) {
            System.out.print(iterator.next());
        }
        System.out.println();
    }

    public static void main(String[] args) {
        String str = "aabccbad";
        remove(str);
    }
}
