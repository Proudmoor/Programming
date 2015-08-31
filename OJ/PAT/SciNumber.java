import java.util.*;

public class SciNumber{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

		String s = in.next();
		int exp = 0;
		String afterE;

		int i = 0;
		char c = ' ';
		while(c!='E'){
			c = s.charAt(i);
			i++;
		}
		afterE = s.substring(i, s.length());
		exp = Integer.parseInt(afterE);
		String number = Character.isDigit(s.charAt(0)) ? s.substring(0, i-1) : s.substring(1, i-1);
	
		String result = number.substring(0,1) + number.substring(2, number.length());
		if(exp >=0){
			if(exp > number.length() -1){
				for(int k = 0; k < exp -number.length() + 2 ; k++)
					result +="0";
			} else {
				result = result.substring(0, exp+1) + "." + result.substring(exp+1, result.length());
			}
		} else if (exp < 0) {
			String temp = "0.";
			for(int k = 0; k < (0-exp)-1; k++){
				temp +="0";
			}
			result = temp + result;
		}
		if(s.charAt(0) == '-'){
			System.out.print('-');
		}
		System.out.print(result);
	}
}