public class NumberOfStepsToReduceANumberToZero {
    private static int numberOfSteps(int num) {
        if (num == 0)
            return 0;
        int result = 0;

        while (num != 0) {
            result += ((num & 1) == 0 ? 1 : 2);
            num >>= 1;
        }
        return result - 1;
    }

    public static void main(String[] args) {
        System.out.println(numberOfSteps(14));
        System.out.println(numberOfSteps(8));
        System.out.println(numberOfSteps(123));
    }
}
