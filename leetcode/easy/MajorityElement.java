public class MajorityElement {
    // http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
    private static int majorityElement(int[] num) {
        int major = num[0], count = 1;

        for (int i = 1; i < num.length; i++) {
            if (count == 0) {
                count++;
                major = num[i];
            } else if (major == num[i]) {
                count++;
            } else
                count--;

        }

        return major;
    }

    public static void main(String[] args) {
        int[] num = { 2, 2, 1, 1, 1, 2, 2 };

        System.out.println(majorityElement(num));
    }
}
