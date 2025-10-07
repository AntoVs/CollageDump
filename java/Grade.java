import java.util.Scanner;

public class Grade {
	public static void main(String[] args){
		Scanner scnr = new Scanner(System.in);
		System.out.print("insert the marks obtained : ");
		int score = scnr.nextInt();

		if (score >= 90 && score <= 100) 
			System.out.println("Grade: A");
		else if (score >= 80 && score < 90)
	        	System.out.println("Grade: B");
    		else if (score >= 70 && score < 80)
	        	System.out.println("Grade: C");
    		else if (score >= 60 && score < 70)
			System.out.println("Grade: D");
    		else if (score >= 0 && score < 60)
        		System.out.println("Grade: F");
    		else
        		System.out.print("Invalid score.Please enter a value between 0 and 100.\n");
		scnr.close();
	}

}
