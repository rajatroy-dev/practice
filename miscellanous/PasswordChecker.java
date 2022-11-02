import java.util.regex.Matcher;
import java.util.regex.Pattern;

/*
 * Password should be check in the following order:
 * 
 * 1. The password should have a minimum length of 8 and maximum length of 31.
 *      If not return 10;
 * 2. The password should have minimum one alphabet and one number.
 *      If not return 20;
 * 3. The password should have one of the following special character: # $ @ % & _
 *      If not return 30;
 * 4. The password should not contain 2 same character repetition.
 *      If not return 40;
 * 5. If password is valid return 0;
 * 
 * Fidelity interview question
 */

public class PasswordChecker {
    static int passwordChecker(String password) {
        String trimmedPassword = password.trim();

        if (trimmedPassword.length() < 8 || trimmedPassword.length() > 31) {
            return 10;
        }

        Pattern alphaPattern = Pattern.compile("[a-zA-Z]+");
        Matcher alphaMatcher = alphaPattern.matcher(trimmedPassword);
        Pattern numPattern = Pattern.compile("[0-9]+");
        Matcher numMatcher = numPattern.matcher(trimmedPassword);
        if (!alphaMatcher.find() || !numMatcher.find()) {
            return 20;
        }

        Pattern specialPattern = Pattern.compile("[#$@%&_]+");
        Matcher specialMatcher = specialPattern.matcher(trimmedPassword);
        if (!specialMatcher.find()) {
            return 30;
        }

        boolean repetitionExists = false;
        for (int i = 0; i < trimmedPassword.length() - 1; i++) {
            if (trimmedPassword.charAt(i) == trimmedPassword.charAt(i + 1)) {
                repetitionExists = true;
                break;
            }
        }
        if (repetitionExists) {
            return 40;
        }

        return 0;
    }

    public static void main(String[] args) {
        String password = "password$123";
        System.out.println(passwordChecker(password));;
    }
}