//Young Liu
//Miniproject 1
//2-11-15
//java

import java.util.Scanner;
public class Vignere {
	
	 public static void main(String[] args) {
		 Scanner input = new Scanner(System.in);
  
		 //allows the user to select whether to encrypt or decrypt
		 System.out.println("1. Decrypt or 2. Encrypt? Please enter 1 or 2:");
		 int option = input.nextInt();
		 System.out.println("Please enter the key:");
		 String key = input.next();
		 String output;
		 
		 if (option==1){//calls decrypt
			 System.out.println("Please enter the ciphertext:");
			 String ciphertext = input.next();
			 System.out.println(decrypt(ciphertext, key));
		 }
	 
		 else if (option==2){//calls encrypt
			 System.out.println("Please enter the plaintext:");
			 String plaintext = input.next();
			 System.out.println(encrypt(plaintext, key));
		 }
	 }
		 
	        /*String key = "superbowl";
	        String plaintext = "Jayhawk";
	        String encryption = "jirotiohvbunlrxy";
	        //String enc = encrypt(plaintext, key);
	        //String dec = decrypt(encryption, key);
	        //System.out.println(enc);
	        System.out.println(decrypt(encryption, key));*/

	    static String encrypt(String text, String key) {
	        String output = "";
	        text = text.toLowerCase();
	        key = key.toLowerCase();
	        int j=0;
	        int k;
	        for (int i=0; i<text.length(); i++){//runs through the whole string
	        	char a = text.charAt(i);
	        	if (a >= 'a' && a <= 'z'){ //makes sure to skip spaces and other good stuff
	        		if (j==key.length()){
	        			j=0;//to wrap around the key if the text is longer
	        		}
	        		k = a + ((key.charAt(j)-97) % 26);//takes the number mod 26 then adds
	        		if(k>122){
	        			k = (k-122) + 96;//in case it goes over z value
	        		}
	        		output += (char)k;
	        		j++;
	        	}		
	        }	        
	        return output;
	    }

	    static String decrypt(String text, String key) {
	    	String output = "";
	        text = text.toLowerCase();
	        key = key.toLowerCase();
	        int j=0;
	        int k;
	        for (int i=0; i<text.length(); i++){//runs through the whole string
	        	char a = text.charAt(i);
	        	if (a >= 'a' && a <= 'z'){ //ensure we stay in the alphabet
	        		if (j==key.length()){
	        			j=0;//to wrap around the key if the text is longer
	        		}
	        		k = a - ((key.charAt(j)-97) % 26); //takes mod and subtracts it
	        		if(k<97){
	        			k = 122 - (96-k);//in case it goes under the a value
	        		}
	        		output += (char)k;
	        		j++;
	        	}		
	        }	        
	        return output;
	    }
}