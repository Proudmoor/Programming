/**
 * Created by pengfei on 15-5-10.
 */
public class Welcome {
    public static void main(String[] args){
        String[] greeting = new String[3];
        greeting[0] = "Welcome to Core Java";
        greeting[1] = "zhang peng fei";
        greeting[2] = "First Java";

        for(String g:greeting)
            System.out.println(g);
    }
}
