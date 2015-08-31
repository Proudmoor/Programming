import java.util.*;

public class minNumber{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

		ArrayList<Integer> ls = new ArrayList<>();
		for(int i = 0; i < 10; i++){
			int n = in.nextInt();
			for(int j = 0; j < n; j++){
				ls.add(i);
			}
		}
		// for(int i : ls)
		// 	System.out.print(i);
		// Collections.sort(ls);
		// System.out.println(ls);
		int k = 0;
		while(ls.get(0) == 0){
			Collections.swap(ls, 0, k);
			k++;
			//System.out.println(ls);
		}

		for(int i: ls){
			System.out.print(i);
		}
	}
}