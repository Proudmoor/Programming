import java.util.*;
class compTwoArray implements Comparator<int []>{
	public int compare (int[] c1, int[] c2){
		double price1 = (double)c1[1] / (double) c1[0];
		double price2 = (double)c2[1] / (double) c2[0];
		if(price1 > price2){
			return -1;
		} else if(price1 < price2){
			return 1;
		}else{
			return 0;
		}
	}
}

public class Yuebing{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

		int kinds = in.nextInt();
		int needs = in.nextInt();

		int load[][] = new int[kinds][2];

		for(int i=0; i < kinds; i++){
			load[i][0] = in.nextInt();
		}

		for(int i=0; i < kinds; i++){
			load[i][1] = in.nextInt();
		}

		Arrays.sort(load, new compTwoArray());
		System.out.println(Arrays.deepToString(load));

		int  sum = 0 ; int  needkinds = 0;
		for(int i =0; i < kinds; i++){
			if(sum >= needs){
				needkinds = i;
				break;
			}
			sum += load[i][0];
		}

		double profits = 0;
		int amount = 0;
		if(sum == needs){
			for(int i = 0; i< needkinds; i++){
				profits += load[i][1];
			}
		} else{
			profits = 0;
			for(int i = 0; i < needkinds-1 ; i++){
				profits += load[i][1];
				amount  += load[i][0];
			}
			profits = profits + ( (needs - amount)  * (double)load[needkinds-1][1] / (double)load[needkinds-1][0]); 
		}

		System.out.printf("%.2f\n", profits);
	}
}