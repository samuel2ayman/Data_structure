import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
	public static double average(int[] integ) {
        double sum=0 ,avr=0;
        int c=0;
        for (int i=0;i<integ.length;i++) 
        {
          sum=sum+integ[i];
          c++;
        }
        avr=sum/c;
        return avr;
    }
    
    public static void main(String[] args) {
        Scanner scan= new Scanner(System.in);
        String str= scan.nextLine(); 
        if(str.length()==2){System.out.print("0.0");
                             System.exit(0);}
        String[] arr = str.replaceAll("\\[", "")
                            .replaceAll(" ", "")
                            .replaceAll("]", "")
                            .split(",");
        int[] integ= new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            integ[i] = Integer.valueOf(arr[i]);
        }
        System.out.println(average(integ));
        
    }

    
}