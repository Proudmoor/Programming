import java.util.*;
import java.io.*;


class Node{
	String Address;
	int data;
	String Next;
	// public String toString(){
	// 	System.out.print(Address +" "+ data + " " +Next);
	// 	return "";
	// }
}

public class reverseList{
	public static void main(String[] args){
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		String flag = in.next();
		int n = in.nextInt();
		int k = in.nextInt();
		int ListCount = n / k;
		int reminder = n % k;
		Node []list = new Node[n];

		for(int i = 0; i < n; i++){
			list[i] = new Node();
			list[i].Address = in.next();
			list[i].data    = in.nextInt();
			list[i].Next    = in.next();
		}

		// for(Node ls : list){
		// 	System.out.println(ls.Address);
		// }
		Node[] ordered = new Node[n];
		int temp = 0;
		while (!flag.equals("-1")){
			
			for(int i = 0; i < n; i++){
				
				if(flag.equals(list[i].Address)){
					ordered[temp] = new Node();
					ordered[temp].Address  = list[i].Address;
					ordered[temp].data     = list[i].data;
					ordered[temp].Next    =  list[i].Next;
					flag = list[i].Next;
					temp++;
					break;
				}
			}
		}

		// for (Node node : ordered){
		// 	System.out.println(node.Address +" "+ node.data + " " +node.Next);
		// }
		int time = 1;
		while(time <=ListCount){
			for(int i = 0; i < k; i++){
				Node node = ordered[time * k - i-1];
				System.out.println(node.Address +" "+ node.data + " " +node.Next);
			}
			time++;
		}
		for(int i = 0; i < reminder; i++){
			Node node = ordered[ListCount * k + i];
			System.out.println(node.Address +" "+ node.data + " " +node.Next);
		}
	}	
}