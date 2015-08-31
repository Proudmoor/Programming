import java.util.*;

public class CorrectID{

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
    	int [] ZM = {'1', '0', 'X', '9' ,'8', '7' , '6', '5', '4', '3', '2'};
    	int [] factor = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    	int n = in.nextInt();
    	int allPassed = 0;
    	for(int i = 0; i < n; i++){
    		String id = in.next();
    		int sum = 0;
    	
    		for(int j = 0; j < id.length(); j++){
    			char c = id.charAt(j);

    			if(j != id.length() -1){
    				if(!Character.isDigit(c)){
    					System.out.println(id);
    					allPassed = 1;
    					break;
    				} else{
    					sum += Integer.parseInt(String.valueOf(c)) * factor[j];
    				}
    			} else{
    				int Z = sum % 11;
    				if( c!= ZM[Z]){
    					System.out.println(id);
    					allPassed = 1;
    				}
    				// if( Z == 2){
    				// 	if (c !='X'){
    				// 		System.out.println(id);
    				// 		allPassed = 1;
    				// 	}
    				// } else {
    				// 	try{
	    			// 		if( Integer.parseInt(String.valueOf(c))!= ZM[Z]){
	    			// 			System.out.println(id);
	    			// 			allPassed = 1;
	    			// 		}
	    			// 	} catch(NumberFormatException e){
	    					
	    			// 		System.out.println(id);
	    			// 		allPassed = 1;
	    			// 	}
    				// }
    			}

    		}
    	}

    	if(allPassed == 0)
    		System.out.println("All passed");
	}
}