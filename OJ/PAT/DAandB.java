import java.util.*;

public class DAandB{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int A = in.nextInt();
		int B = in.nextInt();
		int div = in.nextInt();

		int r = 0 ;
		int Q = A + B;
		Stack<Integer> result = new Stack<>();
		do{
			r = Q % div;
			Q /= div;
			//System.out.println(r);
			result.push(r);
		}while(Q!=0);
		while(!result.empty()){
			System.out.print(result.pop());
		}
	}
}
