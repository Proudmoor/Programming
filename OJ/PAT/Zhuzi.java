import java.util.*;

public class Zhuzi{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		char[] sell = in.next().toCharArray();
		char[] buy  = in.next().toCharArray();
		int richOf = sell.length - buy.length;
		Map<Character ,Integer> sellMap = new HashMap<>();
		Map<Character ,Integer> buyMap  = new HashMap<>();

		for(char c: sell){
			sellMap.put(c, sellMap.get(c) == null?1:(sellMap.get(c)+1));
		}
		for(char c: buy){
			buyMap.put(c, buyMap.get(c) == null? 1: (buyMap.get(c)+1));
		}
		for(char c: buyMap.keySet()){
			if(sellMap.containsKey(c)){
				sellMap.put(c, sellMap.get(c) - buyMap.get(c));
			}else{
				sellMap.put(c, 0 - buyMap.get(c));
			}
		}
		int lackOf = 0;
		//System.out.println(sellMap);
		for(char c: sellMap.keySet()){
			if(sellMap.get(c) < 0){
				lackOf +=sellMap.get(c);
			}
		}

		if(lackOf >= 0){
			System.out.println("Yes" + " " + richOf);
		} else{
			System.out.println("No" + " "  + (0-lackOf));
		}
	}
}