import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;

// Fidelity Interview
public class SortedFrequencyOfStrings {
    static void frequency(List<String> list) {
        SortedMap<String, Integer> map = new TreeMap<>();

        for (String string : list) {
            String key = string.trim();
            if (key.length() > 0) {
                if (map.containsKey(key)) {
                    int value = map.get(key);
                    map.put(key, ++value);
                } else {
                    map.put(key, 1);
                }
            }
        }

        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }

    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("A");
        list.add("A");
        list.add("A");
        list.add("B");
        list.add("C");
        list.add("D");
        list.add("D");
        list.add("D");

        frequency(list);
    }
}
