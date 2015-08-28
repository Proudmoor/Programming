import java.util.BitSet;
import java.util.Scanner;
import java.util.*;
import java.lang.Math.*;

public class PrimeTest{
	public static boolean isPrime(int trial){
		if (trial == 1) return false;
		if (trial == 2) return true;
		for(int i = 2; i <= Math.sqrt(trial); i++){
			if(trial % i == 0){
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int count = 0;
		//int n = in.nextInt();
		int n = 2000000;
		long start = System.currentTimeMillis();
		for(int i = 1; i <=n; i+=2){// begin with 1 so count+=1;
			if(isPrime(i)){
				count++;
			}
		}
		long end = System.currentTimeMillis();
		System.out.println("There are "+(count + 1) + " Primes");
		System.out.println("Cost " + (end - start) + " milliseconds");
	}
}