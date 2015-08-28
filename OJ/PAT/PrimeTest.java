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

	public static int primeCount(int n){
		BitSet b = new BitSet(n+1);
		int count = 0;
		int i;
		for(i = 2 ; i<=n; i++){
			b.set(i);
		}
		i = 2;
		while(i * i <=n){
			if(b.get(i)){
				count++;
				System.out.print(i + " ");
				int k = 2 * i;
				while(k<=n){
					b.clear(k);
					k += i;
				}
			}
			i++;
		}
		while(i <= n){
			if(b.get(i)){
				count++;
				System.out.print(i + " ");
			}
			i++;
		}
		return count;
	}

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int count = 0;
		//int n = in.nextInt();
		int n = 200;
		long start = System.currentTimeMillis();
		for(int i = 1; i <=n; i+=2){// begin with 1 so count+=1;
			if(isPrime(i)){
				count++;
			}
		}
		long end = System.currentTimeMillis();
		System.out.println("There are "+(count + 1) + " Primes");
		System.out.println("Cost " + (end - start) + " milliseconds");

		/*筛子算法测试素数*/
		count = 0;
		long start2 = System.currentTimeMillis();
		//BitSet b = new BitSet(n+1);
		int num = primeCount(n);
		long end2 = System.currentTimeMillis();
		System.out.println("There are "+ num + " Primes");
		System.out.println("Cost " + (end2 - start2) + " milliseconds");



	}
}