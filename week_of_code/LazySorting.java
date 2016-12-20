import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*
 Logan is cleaning his apartment. In particular, he must sort his old favorite sequence, P, of N positive integers in nondecreasing order. He's tired from a long day, so he invented an easy way (in his opinion) to do this job. His algorithm can be described by the following pseudocode:

while isNotSorted(P) do {   
    WaitOneMinute();
    RandomShuffle(P)
}
Can you determine the expected number of minutes that Logan will spend waiting for P to be sorted?
(1<= N <= 18, 1<= P <= 100)
*/

public class LazySorting 
{
	public static int factorial(int n)
	{
		if (n==0 || n==1)
		{
			return 1;
		}
		int fact = 1;
		for (int i=1; i<=n; ++i)
		{
			fact*=i;
		}
		return fact;
	}

    public static void main(String[] args) 
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] numbers = new int[N];
        int[] counts = new int[101];
        
        for (int i=0; i<N; ++i)
        {
			numbers[i] = sc.nextInt();
			++counts[numbers[i]];
		}
		
		int prob_base = factorial(N);
	//	System.out.println(prob_base);
		for (int i=1; i<=100; ++i)
		{
	//		System.out.println(counts[i]); 
			prob_base/=factorial(counts[i]);
		}
		
	//	System.out.println(prob_base);
		
		final int CYCLES = 1000;
		BigDecimal exp_val = new BigDecimal("0");
		for (int i=1; i<=CYCLES; ++i)
		{
			BigDecimal fraction = new BigDecimal("1");
			for (int j=1; j<=i; ++j)
			{
				fraction = fraction.multiply(new BigDecimal(prob_base));
			}
			
			 fraction = (new BigDecimal("1")).divide(fraction);
			 //System.out.println(fraction);
			 
			exp_val = exp_val.add(fraction.multiply(new BigDecimal(i)));
		}
		BigDecimal old = exp_val.setScale(6, RoundingMode.HALF_UP);
		System.out.println(old);
    }
}
