
/*

In this problem we are asked to play a game of guess who. In guess who you
are given some suspects that could be the culprit and the culprit. Each
suspect has some characteristic that you use to distinguish them. The guessing
player must ask yes or no questions about each person and win if they narrow
the suspects down to a single person. The problem would like to find the minimum
number of guesses until we win.

The first thing that catches the eye when looking at this problem is the bounds
on the traits variable which is only 15. This small number is useful when 
considering a brute force type approach. We can simply consider guessing a
trait of a suspect or not. How many ways are there to guess or not guess a trait?
We can guess or not guess a single trait 2 ways. We can guess or not guess two
traits 2*2=4 ways since guessing a trait is independent of guessing another
trait. If we have k traits than we can guess 2^k possible ways. Since k in this
problem is at most 15 trying all 2^15 ways is quite reasonable. Computers are
fast enough to run though this number of possibilities reasonably quickly.
As a rough estamite I like to say that a computer can execute 10^8 lines of
code in 1 second. We can use this rough estamite to determine how reasonable
our solution idea is.

If we try all 2^k possibilities then we mearly have to check how many suspects
are left after those guesses are made. Note that we don't say what our guesses
are just that we are guessing that particular trait. We simply eliminate any 
suspect that has the opposite trait as our main suspect. 

Actually we can make life easier on ourselves. Instead of saving the traits of
individual suspects we can save whether guessing that trait will eliminate the
given suspect from suspicion. This will make running through the results at
the end easier. To obtain our answer we just take the guessing possibility with
the minimum number of guesses that eliminated all our suspects.

The total order runtime of our solution is O(N * K * 2 ^ N). We run through the
N * K sized table for each possibility to verify the uniqueness of our answer.

*/

import java.util.*;

public class who
{
   public static void main(String[] args)
   {
      // To keep all methods called in main from being static I simply call
      // my main class's constructor and work from the constructor.
      new who(new Scanner(System.in));
   }

   // Number of suspects and the number of characteristics. 
   int numSuspects, numTraits;
   
   // Book keeping for our brute force approach
   boolean[][] willEliminate;
   boolean[] didGuess;
   int bestAnswer;

   // A method that checks if the current guessing scheme is sufficient to
   // narrow down the number of suspects to one.
   boolean isUnique()
   {
      // Loop through each suspect seeing if it matches our main suspect with
      // the guesses that have been made by the second player.
      for (int i=0; i<numSuspects; i++)
      {
         // Check if at least one of the guesses eliminates this suspect.
         boolean didMatch = true;
         for (int j=0; j<numTraits; j++)
            if (didGuess[j] && willEliminate[i][j])
               didMatch = false;
   
         // If the two main suspects match under the currect guessing scheme
         // then return that the guessing is not sufficient for a solution.
         if (didMatch)
            return false;
      }
      return true;
   }

   // A recursive approach to brute forcing our choices.
   // We simply consider each trait. We either take the trait
   // or do not take the trait. 
   void bruteForce(int curTrait, int numGuesses)
   {
      // The base case of our recursion is when all traits have been decided
      if (curTrait >= numTraits)
      {
         // Only update our answer if all other suspects have been eliminated
         if (isUnique())
            bestAnswer = Math.min(bestAnswer, numGuesses);
         return;
      }

      // Try the solution without taking the current trait
      didGuess[curTrait] = false;
      bruteForce(curTrait+1, numGuesses);

      // Try the solution with taking the current trait
      didGuess[curTrait] = true;
      bruteForce(curTrait+1, numGuesses+1);
   }

   // Our new main where we work.
   public who(Scanner in)
   {
      // Initialize a game counter
      int curGame = 0;

      // Read in the number of games and loop through each game
      int numGames = in.nextInt();
      while (numGames-->0)
      {
         // Increment the game counter
         curGame++;

         // Read in the number of suspects and subtract 1. We keep our
         // main suspect separate to simplify things.
         numSuspects = in.nextInt() - 1;
         numTraits = in.nextInt();

         // Create a two dimensional table that determines if guessing 
         // some trait j for some suspect i will eliminate suspect i.
         // This value will be saved in the table at row i column j.
         willEliminate = new boolean[numSuspects][numTraits];
         String mainSuspect = in.next();
         for (int i=0; i<numSuspects; i++)
         {
            String curSuspect = in.next();
            for (int j=0; j<numTraits; j++)
               willEliminate[i][j] = mainSuspect.charAt(j) != curSuspect.charAt(j);
         }

         // Now that we have created our table determine all guessing 
         // strategies and compute the best answer. In the worst case 
         // this answer will be numTraits since the problem specifies 
         // that each set of characteristics will be unique.
         bestAnswer = numTraits;
         didGuess = new boolean[numTraits];
         bruteForce(0, 0);

         // Print the result
         System.out.printf("Game #%d: %d%n", curGame, bestAnswer);
      }
   }
}
