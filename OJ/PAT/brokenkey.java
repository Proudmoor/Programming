import java.util.*;

public class brokenkey{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

		String brokenkey = in.next();
		String text      = in.next();

		Set<Character> key = new HashSet<>();
		for(int i=0; i < brokenkey.length(); i++){
			char c = brokenkey.charAt(i);
			key.add(brokenkey.charAt(i));
			key.add(Character.toLowerCase(c));
		}

		if(key.contains('+')){
			for(int i = 0; i < text.length(); i++){
				char c = text.charAt(i);
				if(key.contains(text.charAt(i)) || Character.isUpperCase(c))
					continue;
				else 
					System.out.print(text.charAt(i));
			}
		}else {
			for(int i = 0; i < text.length(); i++){
				char c = text.charAt(i);
				if(key.contains(c))
					continue;
				else
					System.out.print(c);
			}
		}
	}
}