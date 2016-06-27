import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/* 
 There are two kangaroos on an x-axis ready to jump in the positive direction (i.e, toward positive infinity). The first kangaroo starts at location x1 and moves at a rate of v1  meters per jump. The second kangaroo starts at location x2 and moves at a rate of  meters v2 per jump. Given the starting locations and movement rates for each kangaroo, can you determine if they'll ever land at the same location at the same time?
 */

public class Kangaroo 
{
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        System.out.print("First kangaroo starter position: ");
        int x1 = in.nextInt(); //position of kangaroo 1
        System.out.print("First kangaroo jump size (speed): ");
        int v1 = in.nextInt(); //jump size ("speed") of kangaroo 1
        System.out.print("Second kangaroo starter position: ");
        int x2 = in.nextInt(); //position of kangaroo 2
        System.out.print("Second kangaroo starter jump size (speed): ");
        int v2 = in.nextInt(); //jump size ("speed") of kangaroo 2
        
        boolean hasMeeting = false, done = false;
        while (!done)
        {
			if (x1 == x2) //when they meet
			{
				System.out.println("YES");
				System.out.println("They meet at position "+x1);
				hasMeeting = true;
				done = true;
			}
			
			if ( ((x1 > x2) && (v1 > v2))  //if x2 can't reach x1 kangaroo anyomore
				 || ((x2 > x1) && (v2 > v1)) ) //or x1 can't reach x2
				 done = true;
			
			//jumping towards:
			x1+=v1; 
			x2+=v2;
		}
		
		if (!hasMeeting)
			System.out.println("NO");
    }
}
