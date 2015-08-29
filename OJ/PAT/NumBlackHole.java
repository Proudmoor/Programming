import java.util.*;
import java.lang.Math.*;

public class NumBlackHole{
	public static void spiltNumber(int n, ArrayList<Integer> list){
		for(int i = 0; i < 4; i++){
			list.add(n % 10);
			n = n / 10;
		}
	}
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

		int number = in.nextInt();
		

		while (number != 6174){

			ArrayList<Integer> a = new ArrayList<>();
			
			spiltNumber(number, a);

			Collections.sort(a);


			int numB = 1000 * a.get(3) + 100 * a.get(2) + 10 * a.get(1) + a.get(0);
			
			int numA = 1000 * a.get(0) + 100 * a.get(1)+ 10 * a.get(2) + a.get(3);

			number = numB - numA;
			if(numB - numA ==0){
				System.out.printf("%04d - %04d = %04d\n", numB, numA, number);
				break;
			}
			System.out.printf("%04d - %04d = %04d\n", numB, numA, number);
		}
	}
}