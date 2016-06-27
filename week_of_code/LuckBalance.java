import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class LuckBalance 
{
    public static void main(String[] args) 
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        
        System.out.print("How many contests: ");
        int contestCount = sc.nextInt();
        System.out.print("How many important contests should win: ");
        int importantLimit = sc.nextInt();
        
        int[] luck =  new int [contestCount];
        int[] isImportant  = new int [contestCount];
        int allImportantCount = 0;
        
        for (int i=0; i<contestCount; ++i)
        {
			System.out.println((i+1)+". contest's luck cost (positive integer): ");
			luck[i] = sc.nextInt();
			System.out.println("Is the "+(i+1)+". contest's important (0/1): ");
			isImportant[i] = sc.nextInt();		
			allImportantCount += isImportant[i];
		}
		
		//sort contests: first the important onesuck order
		for (int i=0; i<contestCount; ++i)
		{
			for (int j=i; j<contestCount; ++j)
			{
				if (isImportant[i] < isImportant[j])
				{
					int temp = luck[i];
					luck[i] = luck[j];
					luck[j] = temp;
					
					temp = isImportant[i];
					isImportant[i] = isImportant[j];
					isImportant[j] = temp;
				}
				
				 //if both is equally important (or unimportant) sort decreasing luck cost
				if (isImportant[i] == isImportant[j] && luck[i] > luck[j])
				{
					int temp = luck[i];
					luck[i] = luck[j];
					luck[j] = temp;
				}
			}
		}
		
		//Show the order, just for debugging
		for (int i=0; i<contestCount; ++i)
		{
			System.out.printf("%d (%d), ", luck[i], isImportant[i]);
		}		
		
		//while you need to win, win some important contests (decrease luck)
		int importantCount = 0, totalLuck = 0, index = 0;
		while (allImportantCount > importantLimit)
		{	
			allImportantCount -= isImportant[index];
			totalLuck -= luck[index];
			++index;
		}
		
		//if there is negative luck contest, win it (increase luck)
		while (luck[index] < 0)
		{
			totalLuck -= luck[index];
			++index;
		}
		
		//loose everything else (increase as much luck as possible)
		for (int i=index; i<luck.length; ++i) 
		{
			totalLuck += luck[i];
		}
		
		System.out.println("\nTotal luck: "+totalLuck);
    }
}
