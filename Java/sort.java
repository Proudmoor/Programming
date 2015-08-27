
public class sort{
	private static int[] re = {21,25,11,32,12,35,55,77,66};
	private static int p = 0;
	
	public static void main(String[] args){
		int t = 0;
		System.out.println("The Array is:");
		for(int i = 0; i < re.length; i++)
			System.out.print(re[i]+"\t");
		System.out.println();
		while(p<re.length){
			if(p%2 == 0){
				t = maxNum(re,p);
				swapNum(re,p,t);
			}else{
				t = minNum(re,p);
				swapNum(re,p,t);
			}
			p++;
		}
		System.out.println("After sorting Array is: ");
		for(int i = 0; i <re.length; i++)
			System.out.print(re[i]+"\t");
		System.out.println();
	}

	public static int minNum(int[] r, int t){
		int key = t, temp = r[t];
		for(int i = t+1; i<r.length;i++){
			if(temp>r[i]){
				key = i;
				temp= r[i];
			}
		}
		return key;
	}

	public static int maxNum(int[] r, int t){
		int key =t ,temp = r[t];
		for(int i = t+1; i < r.length;i++){
			if(temp<r[i]){
				key = i;
				temp = r[i];
			}
		}

		return key;
	}

	public static void swapNum(int[] r, int p, int k){
		int temp = r[p];
		r[p] = r[k];
		r[k] = temp;
	}
}