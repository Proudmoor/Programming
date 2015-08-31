import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
 
 
 
import java.util.ArrayList;
 class Main{
   
    public static void main(String[] args){
        int[] numberCount = new int[10];
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<10;++i){
            numberCount[i] = sc.nextInt();
        }
        for(int i=1;i<10;++i){
            if(numberCount[i]!=0){
                System.out.print(i);
                numberCount[i]--;
                break;
            }
        }
        for(int i=0;i<10;++i){
            if(numberCount[i]!=0){
                for(int j=0;j<numberCount[i];++j){
                    System.out.print(i);
                }
            }
        }
    }
 }
