/***********************************
Michael Galletti
05/01/2013
Robot Reckoning
---
This problem required you simulate a robot's movement, given an input sequence. There's no real trick here, it all boils down to a little trigonomety and following directions.
***********************************/
import java.util.*;
import java.io.*;

public class robot {
   public static void main(String[] args) throws Exception{
      Scanner reader = new Scanner(System.in);
      int times = reader.nextInt(); //Number of test cases
      for(int t = 1; t <= times; t++){
         int n = reader.nextInt(); //Number of directions
         double targetX = reader.nextDouble(); //Target's x coordinate
         double targetY = reader.nextDouble(); //Target's y coordinate
         
         double x = 0; //Our current x coordinate
         double y = 0; //Our current y coordinate
         double direction = 0; //The angle of our current heading, in radians
         for(int i = 0; i < n; i++){
            //Since we're being given a rotation in the clockwise direction, we need to multiply
            //the angle we read in by -1. Additionally, we'll convert it to radians, as all of the
            //built in trigonometric functions take their parameters in radians.
            double angle = -Math.toRadians(reader.nextDouble());
            double distance = reader.nextDouble(); //The distance to travel once we've rotated
            
            //We can perform the rotation by simply adding the input angle to our current heading
            direction += angle;
            
            //Solve a right triangle, given the hypotenuse (distance)
            double dx = distance * Math.cos(direction);
            double dy = distance * Math.sin(direction);
            
            //Add the triangle's legs to the appropriate coordinates, moving our robot
            x += dx;
            y += dy;
         }
         
         //Perform the final check. If the euclidean distance from our final x and y to the target is <= 1, then we're good.
         if(Math.sqrt(Math.pow(x-targetX, 2) + Math.pow(y-targetY, 2)) <= 1){
            System.out.println("Trip #"+t+": YES");
         }else{
            System.out.println("Trip #"+t+": NO");
         }
      }
   }
}
