import java.util.*;

public class ScoreStudent{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();

		List<Integer> ls = new ArrayList<>();
		for(int i =0; i < n; i++){
			ls.add(in.nextInt());
		}

		List<Integer> li = new ArrayList<>();
		int k = in.nextInt();
		for(int i = 0; i < k; i++){
			li.add(in.nextInt());
		}

		for(int i = 0; i < li.size(); i++){
			int score = li.get(i);
			int count = 0;
			for(int j : ls){
				if( j == score)
					count++;
			}
			if(i == li.size() -1)
				System.out.print(count);
			else
				System.out.print((count) + " ");
		}
	}
}