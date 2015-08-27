import java.lang.Math.*;
import java.util.Scanner;

public class NumSushu{
	public static boolean isPrime(int num){
		if(num == 1) return false;
		if(num == 2) return true;
		for(int i = 2; i <= Math.sqrt(num); i++){
			if(num % i == 0)
				return false;
		}
		return true;
	}

	public static void main(String [] args){
		Scanner in = new Scanner(System.in);

		int m = in.nextInt();
		int n = in.nextInt();

		int trial = 1;
		int count = 0;
		while(n > 0){
			trial++;
			if(isPrime(trial)){
				count++;
				n--;
				if(count >= m){
					int NumPrime = count - m;
					if((NumPrime+1) % 10 == 0 && count!=0){
						System.out.print(trial);
						System.out.println();
					}else if(n == 0){
						System.out.print(trial);
					}else{
						System.out.print(trial + " ");
					}
				}
			}
		}
	}
}