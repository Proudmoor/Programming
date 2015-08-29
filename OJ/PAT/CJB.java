import java.util.*;

class Game{
	int times;
	char[] records;

}

public class CJB{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		int times = in.nextInt();
		int [] victory = new int[3];
		int [] numA    = new int[3];
		int [] numB    = new int[3];

		for(int i = 0; i < times; i++){
			String A = in.next();
			String B = in.next();
			if(A.equals(B)) {
				victory[1]++;
			} else if((A.equals("J")&& B.equals("B")) || (A.equals("B")&& B.equals("C")) ||(A.equals("C")&& B.equals("J"))){
				victory[0]++;
				if(A.equals("C")) numA[0]++;
				if(A.equals("B")) numA[1]++;
				if(A.equals("J")) numA[2]++; 
			}else{
				victory[2]++;
				if(B.equals("C")) numB[0]++;
				if(B.equals("B")) numB[1]++;
				if(B.equals("J")) numB[2]++; 
			}

		}

		System.out.println(victory[0] + " " + victory[1] + " " + victory[2]);

		System.out.println(victory[2] + " " + victory[1] + " " + victory[0]);

		if(numA[0]>= numA[1]&& numA[0] >= numA[2])
			System.out.print("C");
		else if (numA[1] > numA[0] && numA[1] >=numA[2])
			System.out.print("B");
		else
			System.out.print("J");

		if(numB[0]>= numB[1]&& numB[0] >= numB[2])
			System.out.print(" C");
		else if (numB[1] > numB[0] && numB[1] >=numB[2])
			System.out.print(" B");
		else
			System.out.print(" J");


	}
}