
#include <stdio.h>
#include <math.h>


#define MAX_STATIONS   50


int main()
{
   FILE *   infile;
   int      numRaces;
   int      i;
   int      j;
   int      mikeSpeed, stevenSpeed;
   int      numSwitches;
   int      switchDistance[MAX_STATIONS+1];
   int      driftDistance;
   int      mikeLocation;
   double   stevenLocation;
   int      atSwitch;
   double   timeItTook;

   // Default to reading from stdin
   infile = stdin;

   // Read in the number of races to process
   fscanf(infile, "%d", &numRaces);

   // Loop over each race
   for (i=0; i < numRaces; i++)
   {
      // Read in the number of episodes left and number of rooms that exist
      fscanf(infile, "%d %d %d", &mikeSpeed, &stevenSpeed, &numSwitches);

      // Read in the switch data
      for (j=0; j < numSwitches+1; j++)
         fscanf(infile, "%d", &switchDistance[j]);

      // Initialize how much Mike can drift and also the locations for
      // Mike and SteVen
      driftDistance = 0;
      mikeLocation = 0;
      stevenLocation = switchDistance[numSwitches];

      // See how far Mike can get
      atSwitch = 0;
      while (mikeLocation < stevenLocation)
      {
         // Figure out how long it will take Mike to get to the next switch
         // from where he is
         timeItTook = (double ) (switchDistance[atSwitch] - mikeLocation) /
                      (double ) mikeSpeed;

         // Move Mike there
         mikeLocation = switchDistance[atSwitch];

         // And move SteVen an appropriate amount
         stevenLocation -= stevenSpeed * timeItTook;

         // If they won't collide, count the distance in for drifting
         if (mikeLocation < stevenLocation)
            driftDistance = mikeLocation;

         // Try the next switch
         atSwitch++;
      }
      
      // Output header
      printf("Race #%d: Mike, drift like a boss for %d miles.\n", 
             i+1, driftDistance);
   }

   // Return that we're ending okay
   return 0;
}

