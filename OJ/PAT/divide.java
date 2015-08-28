import java.util.*;

public class divide{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);

		String A = in.next();
		int    b = in.nextInt();
		StringBuilder Q = new StringBuilder();
		int r = 0, q = 0;
		for(int i = 0; i < A.length(); i++){
			char a = A.charAt(i);
			
			if(r == 0){
				 r = Integer.parseInt(String.valueOf(a)) % b;
				 q = Integer.parseInt(String.valueOf(a)) / b;
				 //System.out.println(r + " " + q);
			} else {
				int temp = r * 10 + Integer.parseInt(String.valueOf(a));
				r = temp % b;
				q = temp/ b;
				//System.out.println(r + " " + q);
			}
			if(i == 0 && q == 0){
				continue;
			}
			Q.append(q);
		}

		System.out.println (Q.toString() +" " + r);
	}
}