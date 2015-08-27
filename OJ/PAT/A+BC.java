import java.util.Scanner;

public class ABC{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int a, b, c;
		for(int i = 0; i < n; i++){
			a = in.nextInt();
			b = in.nextInt();
			c = in.nextInt();

			System.out.println("Case #" + i +": "+((a + b) > c).toString());
		}

	}
}