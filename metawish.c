#include<stdio.h>
#include<string.h>

main()
{
    FILE *ifp;
    //open file
    ifp = fopen("metawish.in","r");
    int T,t;
    fscanf(ifp,"%d",&T);
    //create a character array to store input string
    char string[10000];
    fgets(string,sizeof string,ifp);
    //for each testcase
    for(t=1;t<=T;t++){
        fgets(string,sizeof string,ifp);
        int a,ok = 0;
        //start checking after "I wish "..
        for(a = 7;a<strlen(string);a++){
        
            //check for wish, Wish, WIsh, .... WISH
            if((string[a-3]=='w'||string[a-3]=='W')
                &&(string[a-2]=='i'||string[a-2]=='I')
                &&(string[a-1]=='s'||string[a-1]=='S')
                &&(string[a]=='h'||string[a]=='H'))
                    ok=1;
        }
        if(ok==0)
            printf("Wish Response #%d: Your wish will be granted.\n",t);
        else
            printf("Wish Response #%d: Stop trying to wish for more wishes!\n",t);

    }

}
