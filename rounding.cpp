
/*

In this problem we are asked to read two numbers and round them
using the method described in the problem. After that we are
asked to compare the difference between the two rounded results.

This problem is just simple simulation of the described process.
The only problem we face is the numbers can be up to 200 digits
long. This can cause issues with methods that read the given numbers
as doubles. Instead we will read the input as strings and convert
them to a nice form that we can easily deal with to solve the problem.

Let us first make an observation. Notice that the answer to the 
problem will always be 1 or 0. The reason this is possible is that 
the traditional rounding method only changes the whole part of the 
number either increasing it by 1 or 0. Gabe's rounding method also can 
increase by only 1 or 0. The reason is that when rounding from right to 
left the carry digit cannot be more than 1 on any rounding. This causes 
the rounded digit to be changed by at most 1 at any point even the end. 
We can also additionally prove that Gabe's method will always produce a 
result that is greater than or equal to John's method. Because of 
this we do not need to take the absolute value of the answer.

Using the observation that the whole part of the number changes by at 
most 1 we can simply throw away the whole part of the number and make
it 0 instead. This doesn't change the problem in any way and allows
us not to have to deal with the large numbers on the whole part.
(Remember that long's can only hold around 18 digits of a number
and there can be up to 200 digits in this problem)

*/

#include <stdio.h>
#include <string.h>

// A convenience function that converts a string decimal number
// into an array of digits that represents the fractional part
// of that number. The number of digits is saved in the passed pointer.
int * makeNice(char * toConvert, int * numDigits)
{
   // Start off assuming that we have found 0 digits
   int i = 0;
   *numDigits = 0;

   // Create an array to return that is the size of the
   // input string. We keep a variable for the real size
   // of the digits that we care about.
   int numChars = strlen(toConvert);
   int * result = new int[numChars];

   // Loop until we either reach the end of the 
   // string or hit a decimal
   while (i < numChars && toConvert[i] != '.')
      i++;

   // If we reached the end of the string then there is
   // no fractional part of our number. In this case we
   // simply return our array.
   if (i >= numChars)
      return result;
   
   // Progress our index value beyond the '.' character.
   i++;

   // Now simply loop through the remaining digits adding
   // them to the result array. We can simply convert character
   // digits to their integer counterparts by subtracting the 
   // character '0' from the digit. Note that we can do this
   // because the character codes for digits are consecutive.
   while (i < numChars)
   {
      result[*numDigits] = (int)(toConvert[i]-'0');
      (*numDigits)++;
      i++;
   }

   // Return the result
   return result;
}

int main()
{
   char inputString[202];
   int numTestCases, numDigits;
   int * digits;

   // Read in the number of test cases that we need to process 
   // and begin to process each test case that we need to answer.
   scanf("%d", &numTestCases);
   for (int c=0; c < numTestCases; c++)
   {
      // Read in the numbers into an input string
      scanf("%s", inputString);
   
      // We wrote a convenience function called makeNice.
      // Using this we can covert the string into an array
      // of numbers that only represents the digits right 
      // of the decimal place. This function takes in two
      // parameters. One is the input string and the other
      // is a pointer to the number of digits we found that
      // we would like to save. 
      digits = makeNice(inputString, &numDigits);

      // Apply John's standard rounding method. To simplify things
      // we can use integer division to determine the amount the
      // answer changes by.
      int johnsAnswer = numDigits == 0 ? 0 : (digits[0] / 5);

      // To apply Gabe's method we can simply run through the
      // digits from right to left and maintain the carry digit.
      // This digit will always be 1 or 0 and will contain the
      // answer at the end of all operations.
      int gabesAnswer = 0;
      for (int i=numDigits-1; i>=0; i--)
      {
         // Apply the carry digit to the current digit.
         digits[i] += gabesAnswer;

         // If we have a number greater than 10 we must make it our
         // new carry digit. If not the current carry digit is 0.
         gabesAnswer = digits[i] / 10;

         // Now that we have applied the larger than 10 number
         // we need to only consider only the least significant digit.
         digits[i] = digits[i] % 10;

         // Apply this digit to the carry digit. Based on the rounding rule.
         gabesAnswer += digits[i] / 5;
      }


      // Save the answer keeping in mind that gabes answer is always greater.
      int answer = gabesAnswer - johnsAnswer;
      printf("Homework #%d: %d\n", c+1, answer); 

      // Since "digits" was created in our convenience function
      // we now have to delete it. We owned this array.
      delete[] digits;
   }

   return 0;
}
