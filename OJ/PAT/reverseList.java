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
	public static void reverse(ArrayList<Node> list, int begin, int end){
		for(int i = 0; i<=(end - begin)/ 2; i++){
			Node temp = list.get(begin + i);
			list.set(begin+i, list.get(end - i));
			list.set(end - i, temp);
		}
	}
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
		// Node[] ordered = new Node[n];
		ArrayList<Node> ordered = new ArrayList<Node>();
		
		while (!flag.equals("-1")){
			
			for(int i = 0; i < n; i++){
				
				if(flag.equals(list[i].Address)){
					Node temp = new Node();

					temp.Address = list[i].Address;
					temp.data    = list[i].data;
					temp.Next    = list[i].Next;
					ordered.add(temp);
					flag = list[i].Next;
					break;
				}
			}
		}

		if(k == 1){
			for (Node node : ordered){
				System.out.println(node.Address +" "+ node.data + " " +node.Next);
			}
		}

		int times = ordered.size() / k;
        for (int i = 0; i < times; ++i) {
            int begin = i * k;
            int end = i * k + k - 1;
            reverse(ordered, begin, end);
        }

		for (Node node : ordered){
				System.out.println(node.Address +" "+ node.data + " " +node.Next);
		}

		
	}	
}