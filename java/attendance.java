import java.util.Scanner;

public class attendance{
	public static void main(String[] args){
		Scanner scnr = new Scanner(System.in);
		
		System.out.print("Enter the Strength of class : ");
		int str = scnr.nextInt();
		int[] strarr = new int[str];
		for(int i=0; i<str; i++)
			strarr[i] = i+1;
		
		System.out.print("Enter the number of students present : ");
		int pre = scnr.nextInt();
		int[] prearr = new int[str];
		for(int i=0; i<str; i++)
			prearr[i] = 0;
		System.out.print("enter the students present : ");
		for(int i= 0; i<pre; i++){
			int roll = scnr.nextInt();
			prearr[roll-1] = roll;
		}
		
		System.out.print("Enter the number to be checked : ");
		int key = scnr.nextInt();
		int flag=0;
		for(int i=0; i<str; i++){
			if (prearr[i] == key)
				flag = 1;
		}
		if (flag == 1)
			System.out.println(key + " is present ");
		else
			System.out.println(key + " is not present");
		
		System.out.print("Those who are present are : ");
		for (int i=0; i<str; i++)
			if (prearr[i] != 0)
				System.out.print(prearr[i] + " ");
		
		System.out.print("\nThose who are absentees are : ");
		for (int i=0; i<str; i++)
			if (prearr[i] == 0)
				System.out.print(i+1 + " ");
		
		System.out.println();
		scnr.close();
	}
}

