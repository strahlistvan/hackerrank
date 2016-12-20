import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class FibMod 
{

    public static void main(String[] args) 
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        String str = Integer.toString(n);
        BigInteger a = new BigInteger(str);
        
        n = sc.nextInt();
        str = Integer.toString(n);
        BigInteger b = new BigInteger(str);
        int steps = sc.nextInt();
        
        if (steps == 1)
        {
           System.out.println(b);    
           return;
        }
        if (steps == 2)
        {
            System.out.println(a);
            return;
        }
        
		BigInteger[] FibMod = new BigInteger [steps];
		FibMod[0] = a;
		FibMod[1] = b;
		
        for (int i=2; i<steps; ++i)
        {  
			FibMod[i] = (FibMod[i-1].multiply(FibMod[i-1])).add(FibMod[i-2]);
     //       BigInteger temp = (a.multiply(a)).add(b);
       //     b = a;
         //   a = temp;
//		System.out.println((i+1)+" value: ");
	//		if (i+1 == steps)
	//			System.out.println(FibMod[i]);
			
        }
        System.out.println(FibMod[steps-1]);
        
	//	System.out.println("valami: ");
	//	for  (int i=0; i<FibMod.length; ++i)
	//		System.out.println(FibMod[i]);
    }
}