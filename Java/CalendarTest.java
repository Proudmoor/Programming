import java.text.DateFormatSymbols;
import java.util.*;

public class CalendarTest{
	public static void main(String[] args){
		//构造函数将d初始化为当前日期
		GregorianCalendar d = new GregorianCalendar();
		//用get方法获取当前日月
		int today = d.get(Calendar.DAY_OF_MONTH);
		int month = d.get(Calendar.MONTH);
		//d设置为这个月第一天， 并且得到这一天为星期几，ps：星期一、二、。。。
		d.set(Calendar.DAY_OF_MONTH,1);
		int weekday = d.get(Calendar.DAY_OF_WEEK);
		//得到当前地区星期起始日
		int firstDayOfWeek = d.getFirstDayOfWeek();
		//得到这个月1号是星期几时需要缩进的步数，这个循环过后，d的日期将指向星期日。
		int indent = 0;
		while(weekday != firstDayOfWeek){
			indent++;
			d.add(Calendar.DAY_OF_MONTH, -1);
			weekday = d.get(Calendar.DAY_OF_WEEK);
		}
		
		//所以这一行从星期日开始打印，知道weekday等于星期日。
		String[] weekdayNames = new DateFormatSymbols().getShortWeekdays();
		do{
			System.out.printf("%4s", weekdayNames[weekday]);
			d.add(Calendar.DAY_OF_MONTH, 1);
			weekday = d.get(Calendar.DAY_OF_WEEK);
		} while(weekday != firstDayOfWeek);

		System.out.println();
		for(int i = 1; i <= indent; i++)
			System.out.print("       ");

		d.set(Calendar.DAY_OF_MONTH,1);

		do {
			int day = d.get(Calendar.DAY_OF_MONTH);
			System.out.printf("%6d", day);

			if(day == today) System.out.printf("*");
				else System.out.print(" ");

			d.add(Calendar.DAY_OF_MONTH,1);
			weekday = d.get(Calendar.DAY_OF_WEEK);

			if(weekday == firstDayOfWeek) System.out.println();
		} while(d.get(Calendar.MONTH) == month);//当d是下一个月的第一天时退出循环。

		if(weekday!=firstDayOfWeek) System.out.println();//如果最后不是星期日，则打印一行空白

	}
}