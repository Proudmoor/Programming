import java.util.Scanner;

public class numPAT{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);

		String s = in.next();
		//System.out.println(s);
		int len = s.length();
		long long p= 0, pa=0, pat=0;
		for(int i = 0; i<len; i++){
			char c = s.charAt(i);
			if(c == 'P'){
				p ++;
			}else if(c == 'A'){
				pa = pa + p;
			}else if(c == 'T'){
				pat = pat + pa;
			}
		}
		pat = pat % 1000000007;
		System.out.print(pat);
	}
}