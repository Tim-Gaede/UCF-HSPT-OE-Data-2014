#include<stdio.h>
#include<math.h>

main()
{
    FILE *ifp;
    //open file
    ifp = fopen("reckoning.in","r");
    int n,p,t;
    float x,y;
    fscanf(ifp,"%d",&n);
    //for each testcase
    for(t=1;t<=n;t++){
        float cx=0, cy=0;
        float ca=0;
        //scan in packets and captial location
        fscanf(ifp,"%d %f %f",&p,&x,&y);
        //while remaining packets to be processed
        while(p-->0){
            float a,d;
            fscanf(ifp,"%f %f",&a,&d);
            ca+=a;
            //if angle is not 0<= a <360, fix it
            if(ca<0.0)ca+=360;
            if(ca>=360.0)ca-=360;
            // convert angle to radians  
            float radians = ca*M_PI/180.0;
            //get x and y component then add them to current x,y
            cx += d*cos(radians);
            cy -= d*sin(radians);
        }
        //calcuate distance between current location and capital
        float dist = sqrt((cx-x)*(cx-x) + (cy-y)*(cy-y));
        if(dist<=1.00)
            printf("Trip #%d: YES\n",t);
        else
            printf("Trip #%d: NO\n",t);
    }

}
