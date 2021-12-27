import java.util.*;
import java.io.*;

public class shadow {
	
	//This is the width of the shadow of the tower. It can be
	//found in the second paragraph of the problem statement.
	static final double Shadow_Width = 97;
	
	public static void main(String[] args) throws IOException {
		
		Scanner in = new Scanner(System.in);
		
		//The number of travelers
		int n = in.nextInt();
		
		//for-loop for each test case
		for(int traveler = 1; traveler <= n; traveler++)
		{
			//the speed of the current traveler
			double s = in.nextDouble();
			
			//the name of the current traveler
			String m = in.next();
			
			//the time it takes for the current traveler to cross the shadow in seconds
			double time = Shadow_Width / s;
			
			//This prints out the first line of output using the printf function. %d prints
			//an integer, %s prints a String, and %.2f prints a double to two places after the decimal.
			// (/n) prints a newline.
			System.out.printf("Traveler #%d, %s: %.2f seconds\n",traveler,m,time);
			
			//Printing out the second line of output
			if(time < 5)
				System.out.println("Barely noticed it!");
			
			else if(time >= 5 && time < 30)
				System.out.println("*shudder*");
			
			else if(time >= 30 && time < 60)
				System.out.println("My heart is pounding.");
			
			else if(time >= 60 && time < 300)
				System.out.println("Um, did something move in there?");
			
			else
				System.out.println("Mommy, I want my blanket!");
			
			//the output requires a blank line between outputs
			System.out.println();
			
		}
		
		
	}

}
