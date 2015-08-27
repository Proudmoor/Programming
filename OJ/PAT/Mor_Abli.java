import java.util.Scanner;
import java.io.*;

class Student{
	int id, Moral, Abi, sum;
	public int getID(){
		return id;
	}
	public void setID(int num){
		this.id = num;
	}
	public int getMoral(){
		return Moral;
	}
	public void setMoral(int Moral){
		this.Moral = Moral;
	}
	public int getAbi(){
		return Abi;
	}
	public void setAbi(int Abi){
		this.Abi = Abi;
	}

	public int getSum(){
		return this.Moral + this.Abi;
	}
}

public class Mor_Abli{
	public static void main(String[] args){
		Scanner input = new Scanner(new BufferedInputStream(System.in));
		int Number = input.nextInt();
		int Low    = input.nextInt();
		int High   = input.nextInt();

		System.out.println(Number);
		Student[] st = new Student[Number];
		for(Student s2: st){
			System.out.println(s2);
		}
		Student s = new Student();
		s.setID(input.nextInt());
		s.setMoral(input.nextInt());
		s.setAbi(input.nextInt());
		for(int i = 0; i < Number-1; i++){
			st[i] = new Student();
			st[i].setID(input.nextInt());
			st[i].setMoral(input.nextInt());
			st[i].setAbi(input.nextInt());
		}
		System.out.println(st[10].getID() + " " + st[10].getMoral() + " " + st[10].getAbi());

		for(int i = 0; i < Number-1; i++){
			System.out.println(st[i].getID() + " " + st[i].getMoral() + " " + st[i].getAbi());
		}
		// System.out.println(s1.getID() + " " + s1.getMoral() + " " + s1.getAbi());
	}
}