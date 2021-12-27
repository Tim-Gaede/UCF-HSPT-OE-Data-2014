import java.io.File;
import java.io.IOException;
import java.util.Scanner;


public class rounding {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(System.in);

    int cases = in.nextInt();
    for (int c=0; c < cases; c++) {
      String value = in.next();
      boolean john = johnRoundUp(value);
      boolean gabe = gabeRoundUp(value);
      
      // If John and Gabe disagree about how the number should be rounded then there is a difference of one.
      System.out.printf("Homework #%d: ", c+1);
      if (john != gabe) {
        System.out.println(1);
      } else {
        // Otherwise they agree the number should be rounded either up or down so there is no difference.
        System.out.println(0);
      }
    }
  }

  public static boolean johnRoundUp(String value) {
    int decimalLocation = value.indexOf('.');
    if (decimalLocation == -1 || decimalLocation + 1 == value.length()) return false;
    char v = value.charAt(decimalLocation + 1);
    // John only looks at the left most digit after the decimal place.
    if (v >= '5') {
      return true;
    }
    return false;
  }

  public static boolean gabeRoundUp(String value) {
    int decimalLocation = value.indexOf('.');
    if (decimalLocation == -1 || decimalLocation + 1 == value.length()) return false;

    // Gabe looks at the possibility of a carry changing for the rounding.
    int carry = 0;
    for (int i = value.length() - 1; i >= 0; i--) {
      if (i == decimalLocation) {
        // if at the decimal simply check to see if there is a carry.
        if (carry == 1) return true;
        // if there isn't Gabe round's down.
        return false;
      }
      char v = value.charAt(i);
      int currentValue = Integer.parseInt("" + v) + carry;
      if (currentValue >= 5) {
        carry = 1;
      } else {
        carry = 0;
      }
    }
    return false;
  }
}
