import java.util.Scanner;
import java.io.*;
import java.util.*;

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

	public String toString(){
		System.out.print(id + " " + Moral + " " + Abi);
		return "";
	}
}

public class Mor_Abli{
	public static void main(String[] args){
		Scanner input = new Scanner(new BufferedInputStream(System.in));
		int Number = input.nextInt();
		int Low    = input.nextInt();
		int High   = input.nextInt();

		Student[] st = new Student[Number];

		for(int i = 0; i < Number; i++){
			st[i] = new Student();
			st[i].setID(input.nextInt());
			st[i].setMoral(input.nextInt());
			st[i].setAbi(input.nextInt());
		}
		List<Student> a1 = new ArrayList<>();
		List<Student> a2 = new ArrayList<>();
		List<Student> a3 = new ArrayList<>();
		List<Student> a4 = new ArrayList<>();
		int LowCount = 0;
		for(Student s: st){
			if(s.getMoral() <Low || s.getAbi() < Low){
				LowCount++;
			}else if(s.getMoral() >= High && s.getAbi() >= High){
				a1.add(s);
			}else if(s.getMoral() >=High && s.getAbi() < High){
				a2.add(s);
			}else if(s.getMoral() < High && s.getAbi() < High && s.getMoral() >= s.getAbi()){
				a3.add(s);
			}else{
				a4.add(s);
			}
		}

		Comparator<Student> cp = new Comparator<Student>(){
            public int compare(Student a, Student b){
                if(a.getSum() != b.getSum()){
                    return b.getSum() - a.getSum();
                } else if(a.getMoral() != b.getMoral()){
                    return b.getMoral() - a. getMoral();
                } else {
                    return a.getID() - b.getID();
                }
            }
        };
        Collections.sort(a1, cp);
        Collections.sort(a2, cp);
        Collections.sort(a3, cp);
        Collections.sort(a4, cp);
        System.out.println(Number - LowCount);

		for(Student s: a1){
			System.out.println(s);
		}
		for(Student s: a2){
			System.out.println(s);
		}
		for(Student s: a3){
			System.out.println(s);
		}
	}
}