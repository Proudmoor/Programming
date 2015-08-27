import java.util.Scanner;
public class HomesDate{
	public static String[] week={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	public static void main(String[]  args){
		Scanner in = new Scanner(System.in);
		String [] code = new String[4];
		for(int i = 0; i< 4; i++){
			code[i] = in.nextLine();
		}
		for(String s: code){
			System.out.println(s);
		}
		in.close();
		int count = 0;
		for(int i = 0; i < code[0].length();i++){
			char c = code[0].charAt(i);
			if(c == code[1].charAt(i)){
				if(count == 0 && c >='A' && c<='G'){
					System.out.print(week[c-'A'] + " ");
					count++;
					continue;
				}
				if(count == 1){
					if(Character.isDigit(c)){
						System.out.print("0" + c + ":");
						break;
					}
					if (c >='A' && c<= 'N'){
						System.out.print((c - 'A' + 10) + ":");
						break;
					}
				}
			}
		}

		for(int i = 0; i < code[2].length(); i++){
			char c = code[2].charAt(i);
			if(c == code[3].charAt(i) && Character.isLetter(c)){
				System.out.print(i>=10? i+"" :"0" + i);
				break;
			}
		}
		System.out.println();
	}

}