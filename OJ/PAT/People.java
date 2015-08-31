import java.util.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date; 
import java.text.ParseException;
// class compareAge implements Comparator<String>{
// 	

// 	public int compare(String s1, String s2) throws ParseException{
// 		DateFormat df = new SimpleDateFormat("yyyy/MM/dd");
// 		Date d1 = df.parse(s1);
// 		Date d2 = df.parse(s2);

// 		if(d1.getTime() > d2.getTime()){
// 			return 1;
// 		} else if (d1.getTime() == d2.getTime()){
// 			return 0;
// 		}else{
// 			return -1;
// 		}
// 	}
// }

public class People{
	static DateFormat df = new SimpleDateFormat("yyyy/MM/dd");
	static SimpleDateFormat df1 =new SimpleDateFormat("yyyy-MM-dd");

	public static void main(String[] args) throws ParseException{
		Scanner in = new Scanner (System.in);

		int n = in.nextInt();
		TreeMap<Date, String> map = new TreeMap<>();
		String oldestName = "";
		String youngestName = "";
		int count = 0;
		Date today =  df.parse("2014/09/06");
		Date twoHundred = df1.parse("1814-09-06");
		for(int i = 0; i < n; i++){
			String name = in.next();
			Date birthday = df.parse(in.next());
			if(birthday.getTime() > today.getTime() || birthday.getTime() < twoHundred.getTime()){
				count++;
			}
			//if(birthday > oldestName)
			System.out.println(df1.format(birthday));
			map.put(birthday, name);
		}
		System.out.println(count);
		// Collections.sort(map, new compareAge());
		//ArrayList<String> keys = new ArrayList(map.value());

	}


}