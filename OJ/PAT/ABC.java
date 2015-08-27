import java.util.Scanner;
import java.math.BigInteger;

public class ABC{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long a, b ,c;
		for(int i = 0; i < n; i++){
			a = in.nextLong();
			b = in.nextLong();
			c = in.nextLong();

			System.out.println("Case #" + (i+1) + ": " + ((a+b) > c));
		}

	}
}