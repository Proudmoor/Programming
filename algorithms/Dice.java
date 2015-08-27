import java.io.*;
import java.util.*;

public class Dice{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		double [] dist = new double[2 * 6 +1];

		for(int i = 0; i < N; i++){
			int dice1 = StdRandom.uniform(1, 7);
			int dice2 = StdRandom.uniform(1, 7);
			System.out.println(dice1);
			System.out.println(dice2);
			System.out.println("-----");
			dist[dice1 + dice2]++;
		}

		for(int k = 2; k < 13; k++){
			dist[k] /= N;
		}
		System.out.print(Arrays.toString(dist));
	}
}