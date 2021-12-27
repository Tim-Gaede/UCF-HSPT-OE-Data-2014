import java.util.*;
import java.io.*;

public class metawish
{
   public static void main(String[] args) throws IOException
   {
      // Creates a scanner to read from stdin.
      Scanner in = new Scanner(System.in);
      // Reads the number of test cases.
      int t = in.nextInt();
      // Reads the empty rest of line after the number of test cases.
      in.nextLine();
      // Loops through each test case.
      // Each input will start with "I wish for" so we consider the substring after the 10th character.
      // The capitalization does not matter, so we make the rest of the string lower case.
      // Then we check if the rest of string contains the string "wish"
      // If it doesn't the wish will be granted, else it won't be.
      for (int i = 1; i <= t; i++)
         if (!(in.nextLine()).substring(10).toLowerCase().contains("wish"))
            System.out.println("Wish Response #" + i + ": Your wish will be granted.");
         else
            System.out.println("Wish Response #" + i + ": Stop trying to wish for more wishes!");
   }
}
