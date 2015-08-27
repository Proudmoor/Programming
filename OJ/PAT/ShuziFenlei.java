import java.util.Scanner;

public class ShuziFenlei{
	public static void main(String[] args){
		final int N = 1000;
		int[] num = new int[N];
		int a=0, b=0, c=0, d=0, e=0;
		int c2 = 0, c3 = 0, c4 = 0, c5 = 0;
		Scanner in = new Scanner(System.in);
		double count = 0.0;

		int n = in.nextInt();
		int sig = 1;
		for(int i = 0; i < n; i++){
			num[i] = in.nextInt();
		}

		for(int i : num){
			System.out.println(i);
		}

		for(int i : num){
			
			int temp = 0;

			if(i % 10 == 0){
				a = a + i;
			}
			if(i % 5 == 1){
				c2++;
				b = b + sig * i;
				sig = (-1) * sig;
			}
			if(i % 5 == 2){
				c3++;
				c++;
			}
			if(i % 5 == 3){
				c4++;
				d = d +i;
				count++;
			}
			if(i % 5 == 4){
				c5++;
				e = (i > e) ? i : e;
			}

		}

		System.out.print(a  == 0 ? "N " : (a + " "));
		System.out.print(c2 == 0 ? "N " : (b + " "));
		System.out.print(c3 == 0 ? "N " : (c + " "));
		if(c4==0){
			System.out.print("N ");
		} else{
			System.out.format("%.1f ", (d/count));
		}
		System.out.print(c5 == 0 ? "N" : e);

	}
}