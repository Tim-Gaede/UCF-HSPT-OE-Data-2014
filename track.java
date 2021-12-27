import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class track {
   public static void main(String[] args) throws FileNotFoundException {
      Scanner in = new Scanner(System.in);
      int cases = in.nextInt();
      for (int c = 0; c < cases; c++) {

         int m = in.nextInt();
         int s = in.nextInt();
         int[] stops = new int[in.nextInt() + 2];
         stops[0] = 0;// because he can not drift at all
                     // 'tis a sad thought to have
                     // everyone deserves to drift
         for (int i = 1; i < stops.length; i++) {
            stops[i] = in.nextInt();
         }

         // how many times each person goes their speed before they meet
         double meeting = (double) stops[stops.length - 1]
               / (double) (m + s);
         // where mark is when they meet
         double marksPos = meeting * m;
         // start by saying he goes to the first stop (which we hardcoded as
         // 0)
         int index = 0;

         // try seeing what stop he can go to
         while (index + 1 < stops.length && stops[index + 1] < marksPos) {
            index++;
         }

         System.out.printf(
               "Race #%d: Mike, drift like a boss for %d miles.\n", c + 1,
               stops[index]);
      }
   }
}
