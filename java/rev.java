import java.util.Scanner;
public class rev{
	public static void main(String[] args){
	Scanner scnr = new Scanner(System.in);
	
	System.out.print("Enter an integer: ");
	int num = scnr.nextInt();
	int rev = 0, dig;
	
	while  (num != 0) {
		dig = num % 10 ;
		rev = rev*10 + dig ;
		num = num / 10 ;
	}

	System.out.println("Reversed number: " + rev);
	scnr.close();
	}

}
