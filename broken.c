#include <stdio.h>

//function to sort funky/dark reactors so that repeats can be more easily ignored
void sort(int array[], int size)
{
   int i, j;
   for(i=0;i<size;i++){
      for(j=i+1;j<size;j++){
         if(array[i]>array[j]){
            int temp = array[i];
            array[i]=array[j];
            array[j]=temp;
         }
      }
   }
}

//sorts all found solutions based on problem specification (increasing parts,increasing funky, increasing dark) 
void sortTriple(long long array[][3], int size)
{
   int i, j;
   for(i=0;i<size;i++){
      for(j=i+1;j<size;j++){
         if(
            (array[i][0]>array[j][0])
            ||(array[i][0]==array[j][0]&&array[i][1]>array[j][1])
            ||(array[i][0]==array[j][0]&&array[i][1]==array[j][1]&&array[i][2]>array[j][2])
         ){
            long long temp[3];
            temp[0]=array[i][0];
            temp[1]=array[i][1];
            temp[2]=array[i][2];
            
            array[i][0]=array[j][0];
            array[i][1]=array[j][1];
            array[i][2]=array[j][2];
            
            array[j][0]=temp[0];
            array[j][1]=temp[1];
            array[j][2]=temp[2];
         }
      }
   }
}


int main(void)
{
   FILE * fp = stdin;
   int cases = 0, ship = 0;
   fscanf(fp,"%d",&cases);

   for(ship = 1; ship<=cases; ship++){
      printf("Starship #%d:\n",ship);

      int found = 0;
      int N,M,i,j;
      long long A,B,C,D;
      
      //since N and M are bounded by 30, there can be at most 900 possibilities, this array stores the working combinations to be outputed later
      long long res[901][3];

      fscanf(fp,"%d %d",&N, &M);      
      fscanf(fp,"%lld %lld %lld %lld",&A, &B, &C, &D);      
      
      int funky[N], dark[M];
      for(i=0;i<N;i++)fscanf(fp,"%d",&funky[i]);
      for(j=0;j<M;j++)fscanf(fp,"%d",&dark[j]);
      
      //sort funky and dark, that way repeated elements will be adjacent
      sort(funky,N);
      sort(dark,M);

      for(i=0;i<N;i++){
             //ignore repeated funky weight
             if(i!=0&&funky[i]==funky[i-1])continue;

             for(j=0;j<M;j++){
                //ignore repeated dark weight
                 if(j!=0&&dark[j]==dark[j-1])continue;
            
            // "The funky matter reactor is also always strictly lighter than the dark matter reactor"
                 if(funky[i]<dark[j]){
                     //solve the equation for parts
               /* 
               for a specific funky and dark reactor, we want our total weight before the parts broke ( (A/B) *parts ) to be equal to the total weight after the parts broke ( C/D *(parts-2) ) with the funky and dark reactors included

               now we have the two sides to our equation

               parts * Average_Before == Average_After*(parts-2) + funky + dark
               parts* A/B == C/D*(parts-2) + funky + dark
               parts* A == B * (C/D*(parts-2) + funky + dark)
               parts* A == B*C/D*(parts-2) + B*funky + B*dark
               parts*A  - B*funky - B*dark == B*C/D*(parts-2)
               D*(parts*A  - B*funky - B*dark) == B*C*(parts-2)
               A*D*parts - B*D*funky - B*D*dark == B*C*(parts-2)
               A*D*parts - B*D*funky - B*D*dark == B*C*parts-2*B*C
               2*B*C - B*D*funky - B*D*dark == B*C*parts - A*D*parts
               2*B*C - B*D*funky - B*D*dark == parts*(B*C - A*D)
               (2*B*C - B*D*funky - B*D*dark) / (B*C - A*D) == parts

               */


               long long left = (2*B*C - B*D*funky[i] - B*D*dark[j]);
               long long parts = left / (B*C - A*D);
      
                     //verify that parts is a valid answer, fractional answers will be rounded by integer division and produce an invalid value for parts (if 3.5 parts solves the equation for a funky and dark combination, our math will return 3 due to integer rounding, and be ignored by this statement since we must have whole parts), answers where parts < 3 are invalid because a funky and dark reactor must be included along with at least one normal part. The average when the funky and dark parts are broken is gaurenteed to be greater than zero so a normal part must exist.
                     if(parts*(B*C - A*D)==left&&parts>=3){
                  res[found][0]=parts;
                  res[found][1]=(long long)funky[i];
                  res[found][2]=(long long)dark[j];                   
                         found++;
               }
            }

         }
      }
      printf("There are %d possible reactor combinations.\n",found);

      //sort output based on problem specification
      sortTriple(res,found);
      for(i=0;i<found;i++){
         printf("%lld parts, funky matter reactor mass %lld, dark matter reactor mass %lld.\n",res[i][0],res[i][1],res[i][2]);
      }
      printf("\n");
   }
   return 0;
}
