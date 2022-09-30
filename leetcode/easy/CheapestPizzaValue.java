import java.util.HashMap;

/**
 * Pizza quantity   ->  DiscountedPrice
 * 50               ->  15000
 * 10               ->  3250
 * 2                ->  750
 * 1                ->  400
 * 
 * Given a pizza quantity, find the minimum price.  
 */

public class CheapestPizzaValue {
    private static int solve(int pizzaQuanity, int sum, HashMap<Integer, Integer> discountChart) {
        if (pizzaQuanity >= 50) {
            sum = sum + (pizzaQuanity / 50) * discountChart.get(50);
            return solve(pizzaQuanity % 50, sum, discountChart);
        } else if (pizzaQuanity >= 10) {
            sum = sum + (pizzaQuanity / 10) * discountChart.get(10);
            return solve(pizzaQuanity % 10, sum, discountChart);
        } else if (pizzaQuanity >= 2) {
            sum = sum + (pizzaQuanity / 2) * discountChart.get(2);
            return solve(pizzaQuanity % 2, sum, discountChart);
        } else if (pizzaQuanity >= 1) {
            sum = sum + 1 * discountChart.get(1);
        }
        return sum;
    }

    public static void main(String[] args) {
        HashMap<Integer, Integer> discountChart = new HashMap<>();
        discountChart.put(50, 15000);
        discountChart.put(10, 3250);
        discountChart.put(2, 750);
        discountChart.put(1, 400);

        int pizzaQuanity = 53;
        System.out.println(solve(pizzaQuanity, 0, discountChart));
    }
}
