#include "stdio.h"

int main()
{
    // Default to stdin
    FILE* ifp = stdin;

    int n;
    // Reads the number of test cases
    fscanf(ifp, "%d", &n);

    //The length of the shadow is always 97 meters
    int shadowLength = 97;

    int i;
    // Loops through each test case
    for (i = 1; i <= n; i++)
    {
        double speed;
        // Reads the speed
        fscanf(ifp, "%lf", &speed);

        //Array to store name
        char name[21];
        //Reads in the name
        fscanf(ifp, "%s", name);

        //Time in the shadow is equal to distance/speed
        double time = shadowLength/speed;

        printf("Traveler #%d, %s: %.2lf seconds\n", i, name, time);

        //Print the proper message based on the amount of time
        if(time < 5){
            printf("Barely noticed it!\n");
        }
        else if(time < 30){
            printf("*shudder*\n");
        }
        else if(time < 60){
            printf("My heart is pounding.\n");
        }
        else if(time < 300){
            printf("Um, did something move in there?\n");
        }
        else{
            printf("Mommy, I want my blanket!\n");
        }
        printf("\n");
    }
    return 0;
}
