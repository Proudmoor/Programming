import java.util.*;
import java.util.regex.*;

public class Caculat {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

		String s1 = in.next();
		String s2 = in.next();
		int a = Integer.parseInt(s1.split("/")[0]);
		int b = Integer.parseInt(s1.split("/")[1]);

		int c = Integer.parseInt(s2.split("/")[0]);
		int d = Integer.parseInt(s2.split("/")[1]);

		System.out.println(a + " " + b + " " + c);
	}
}