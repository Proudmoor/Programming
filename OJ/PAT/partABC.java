import java.util.*;
import java.lang.Math.*;
public class partABC{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);

		int countA = 0;
		int countB = 0;
		String sA = in.next();
		String cA = in.next();
		String sB = in.next();
		String cB = in.next();

		for(int i = 0; i < sA.length(); i++){
			char c = cA.charAt(0);
			if(c == sA.charAt(i)){
				countA++;
			}
		}
		for(int i = 0; i < sB.length(); i++){
			char c = cB.charAt(0);
			if(c == sB.charAt(i)){
				countB++;
			}
		}
		int pa=0 , pb = 0;
		while(countA>0){
			int pow = (int) Math.pow(10, --countA);
			pa =pa + Integer.parseInt(cA) * pow;
		}
		while(countB>0){
			int pow = (int) Math.pow(10, --countB);
			pb =pb + Integer.parseInt(cB) * pow;
		}
		System.out.println(pa + pb );
	}
}