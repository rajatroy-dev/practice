import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/*
 * https://www.hackerearth.com/problem/algorithm/free-walk-0f675f40-0d59a400/
 */
public class TestClass {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        for (int t_i = 0; t_i < T; t_i++) {
            String S = br.readLine();

            int out_ = solve(S);
            System.out.println(out_);
        }

        wr.close();
        br.close();
    }

    static int solve(String S) {
        int maxA = 0;
        int maxC = 0;
        int maxQ = 0;

        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == 'A') {
                maxA++;
            } else if (S.charAt(i) == 'C') {
                maxC++;
            } else if (S.charAt(i) == '?') {
                maxQ++;
            }
        }

        if (maxA >= maxC) {
            return maxA + maxQ;
        } else {
            return maxC + maxQ;
        }
    }
}