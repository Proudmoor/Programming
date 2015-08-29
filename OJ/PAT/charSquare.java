import java.util.*;

public class charSquare{


	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String a = in.next();
		int lines = (n  % 2 == 0 ? n / 2 : (n/2 +1));

		String top = "";
		for(int i = 0; i < n; i++){
			top += a;
		}
		String line = "";
		for(int i = 0; i < n-2; i++){
			line += " ";
		}
		line = a + line + a;

		System.out.println(top);
		for(int i = 0; i<lines -2 ; i++){
			System.out.println(line);
		}
		System.out.println(top);

	}

}