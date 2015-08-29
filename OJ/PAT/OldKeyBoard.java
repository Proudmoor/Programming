import java.util.*;

public class OldKeyBoard{
	public static void main(String[] args){
		Scanner in = new Scanner (System.in);

		String old = in.next().toUpperCase();
		String broken = in.next().toUpperCase();
		
		Set<Character> set = new HashSet<>();
		for(int i = 0; i < broken.length(); i++){
			set.add(broken.charAt(i));
		}

		for(int i = 0; i < old.length(); i++){
			if(!set.contains(old.charAt(i))){
				System.out.print(old.charAt(i));
				set.add(old.charAt(i));
			}
		}
	
	}
}