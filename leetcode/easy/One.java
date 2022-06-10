import java.util.Arrays;
import java.util.List;

/*
 * Swap adjacent element from a list
 */

public class One {
    public static void main(String[] args) {
        List<Integer> mylist = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 0);

        for (int i = 0; i < mylist.size() - 1; i += 2) {
            int t = mylist.get(i);
            mylist.set(i, mylist.get(i + 1));
            mylist.set(i + 1, t);
        }

        System.out.println(mylist);
    }
}