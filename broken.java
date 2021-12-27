import java.util.*;
public class broken {

	//Class for storing answers to allow easy sorting.
	class Answer implements Comparable<Answer> {
		long parts, typeA, typeB;
		//Constructor
		Answer(long p, long a, long b) {
			parts = p;
			typeA = a;
			typeB = b;
		}
		//Comparator (for sorting).
		public int compareTo(Answer a) {
			if (parts != a.parts)
				return Long.signum(parts-a.parts);
			if (typeA != a.typeA)
				return Long.signum(typeA - a.typeA);
			return Long.signum(typeB - a.typeB);
		}
		//Equality check (to eliminate duplicate answers).
		public boolean equals(Answer a) {
			return parts==a.parts && typeA==a.typeA && typeB==a.typeB;
		}
	}

	//Main function.
	broken(Scanner in) {

		//Read in then loop over the number of ships.
		int ships = in.nextInt();
		for (int s=0; s<ships; s++) {

			//Read in N and M (the number of each type of reactor).
			int N = in.nextInt();
			int M = in.nextInt();
			long[] typeA = new long[N];
			long[] typeB = new long[M];

			//Read in the fraction values a/b and c/d.
			long a = in.nextInt();
			long b = in.nextInt();
			long c = in.nextInt();
			long d = in.nextInt();

			//Read in the possible reactor weights.
			for (int i=0; i<N; i++)
				typeA[i] = in.nextInt();
			for (int i=0; i<M; i++)
				typeB[i] = in.nextInt();

			//Use a TreeSet so that only unique answers are output, and they
			// are in sorted order.
			TreeSet<Answer> list = new TreeSet<Answer>();

			//For each of the possible combinations of the weights of the reactors...
			for (int i=0; i<N; i++)
				for (int j=0; j<M; j++) {

					//If the funky matter reactor weight is strictly less than the dark matter
					// reactor weight...
					if (typeA[i] < typeB[j]) {

						/*
						 * Based on the problem description, set up the system of equations:
						 *  (other + typeA + typeB) / parts = a/b
						 *  other / (parts - 2) = c/d
						 *
						 * To solve for `parts`, isolate `other` in both equations and set them
						 *  equal. This should produce:
						 *  (c*parts - 2*c) / d = other = (a*parts - b*(typeA+typeB))
						 *
						 * Now solve for `parts`, and you get a fraction with the numerator and
						 *  denominator defined in the code to follow. Because it only makes
						 *  sense to have an integer number of parts greater than or equal to 3,
						 *  we make sure only to add such results to our answer list.
						 */
						long numerator = 2*c*b - b*d*(typeA[i]+typeB[j]);
						long denominator = b*c-a*d;
						if (denominator != 0 && numerator%denominator == 0 && numerator/denominator >= 3)
							list.add(new Answer(numerator/denominator,typeA[i],typeB[j]));

					}
				}

			//Output the answer header...
			System.out.printf("Starship #%d:\n",s+1);
			//...the answer count...
			System.out.printf("There are %d possible reactor combinations.\n",list.size());
			//...and all of the answers in order...
			for (Answer ans: list)
				System.out.printf("%d parts, funky matter reactor mass %d, dark matter reactor mass %d.\n",ans.parts,ans.typeA,ans.typeB);
			//...then a new line to end the current ship.
			System.out.println();
		}
	}

	//Initializing the main class to keep everything in instance scope.
	public static void main(String[] args) {
		new broken(new Scanner(System.in));
	}
}
