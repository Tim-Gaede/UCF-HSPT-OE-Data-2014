import java.util.*;
import java.io.*;
public class lte {
   public static void main(String[] args)throws IOException{
      Scanner br = new Scanner(System.in);
      
      //Read in the number of test cases
      int t = br.nextInt();
      
      for(int c = 1;c<=t;c++){
         //Read in the two times
         int t1 = br.nextInt();
         int t2 = br.nextInt();
         
         //Agent Jimmie finishes first
         if(t1 <= t2){
            System.out.println("Scenario #"+c+": Agent Jimmie Flowers nabs Frohan!");
         }
         //Frohan escapes
         else{
            System.out.println("Scenario #"+c+": Missed it by that much.");
         }
      }
   }
}

