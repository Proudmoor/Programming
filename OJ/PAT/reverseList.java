import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
 
class Node {
    int address;
    int data;
    int nextAddress;
 
    public Node(int address, int data, int nextAddress){
        super();
        this.address = address;
        this.data = data;
        this.nextAddress = nextAddress;
    }
 
    @Override
    public String toString() {
        StringBuilder sBuilder = new StringBuilder();
        for (int i = String.valueOf(address).length(); i < 5; i++)
            sBuilder.append("0");
        sBuilder.append(address).append(" ").append(data).append(" ");
        if (nextAddress != -1) {
            for (int i = String.valueOf(nextAddress).length(); i < 5; i++)
                sBuilder.append("0");
        }
        sBuilder.append(nextAddress);
        return sBuilder.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int head = sc.nextInt();
        int nums = sc.nextInt();
        int k = sc.nextInt();
        Map<Integer, Node> map = new HashMap<Integer, Node>();
        for (int i = 0; i < nums; i++) {
            int n = sc.nextInt();
            map.put(n, new Node(n, sc.nextInt(), sc.nextInt()));
        }
        ArrayList<Integer> list = new ArrayList<Integer>();
        int key = head;
        while (key != -1) {
            Node tempT = map.get(key);
            list.add(key);
            //System.out.println(tempT);
            key = tempT.nextAddress;
        }
        
        int times = list.size() / k;
        for (int i = 0; i < times; i++) {
 
            int begin = i * k;
            int end = i * k + k - 1;
            reverse(list, begin, end);
        }
        for (int i = 1; i < list.size(); i++) {
            map.get(list.get(i - 1)).nextAddress = map.get(list.get(i)).address;
        }
        map.get(list.get(list.size() - 1)).nextAddress = -1;
        head = list.get(0);
        key = head;
        while (key != -1) {
            Node tempT = map.get(key);
            list.add(key);
            System.out.println(tempT);
            key = tempT.nextAddress;
        }
         
    }
 
    private static void reverse(ArrayList<Integer> list, int begin, int end) {
        
        for (int i = 0; i <= (end - begin) / 2; i++) {
 
            int temp = list.get(begin + i);
            list.set(begin + i, list.get(end - i));
            list.set(end - i, temp);
            
        }
    }
}
 

