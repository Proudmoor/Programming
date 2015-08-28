import java.util.*;

public class programTime{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);

		int c1 = in.nextInt();
		int c2 = in.nextInt();
		int time = (int) Math.round((c2 - c1)/100.0);
		int r = 0, h = 0, m = 0;

		h = time / 3600;
		r = time % 3600;
		m = r / 60;
		r = r % 60;

		System.out.printf("%02d:%02d:%02d", h, m, r);
	}
}