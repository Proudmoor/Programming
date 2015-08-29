import java.util.*;

public class BlueShit{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		Map<Integer, Integer > score = new HashMap<>();
		for(int i = 0; i < n; i++){
			int key = in.nextInt();
			int value = in.nextInt();
			score.put(key, score.get(key) == null ? value :score.get(key) + value);
		}
		
		int max = 0 , school = 0;
		for(int i : score.keySet()){
			if(score.get(i) > max){
				max = score.get(i);
				school = i;
			}
		}

		System.out.printf("%d %d",school, max);


	}
}