import java.util.*;

public class sandglass{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		String c = in.next();

		int sum = 0 , i = 0;
	
		for(i = 1; ;i++){
			sum = 2 * i * i - 1;
			if(sum > n) {
				i--;
				sum = 2 * i * i -1;
				break;
			}
		}
		i--;
		String star = "";
		String blank = "";

		for(int k = 0; k < 2 * i+1 ; k++){
			star += c;
		}
		for(int k = 0; k < i; k++){
			blank += " ";
		}
		for(int k = 0; k < i; k++){
			System.out.println(blank.substring(0,k) + star.substring(k, star.length()-k));
		}
		System.out.println(blank + c);
		for(int k = 0; k < i; k++){
			System.out.println(blank.substring(0, i-k-1) + star.substring(i-k-1, star.length() -i + k+1));
		}	

		System.out.println(n - sum);


	}
}