#include "stdio.h"

int main()
{
   // Default to stdin
   FILE* ifp = stdin;
   int i, n, j, f;

   // Reads the number of test cases.
   fscanf(ifp, "%d", &n);

   // Loops through each test case.
   for (i = 1; i <= n; i++)
   {
      // Reads the two input integers.
      fscanf(ifp, "%d %d", &j, &f);
      // Prints the scenario number
      printf("Scenario #%d: ", i);
      // If the time to get driving directions is less than or equal to the time for Frohan to escape, then Frohan will be nabbed.
      if (j <= f)
         printf("Agent Jimmie Flowers nabs Frohan!\n");
      // Else he gets away.
      else
         printf("Missed it by that much.\n");
   }

   return 0;
}
