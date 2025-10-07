import java.util.Scanner;

public class calc{
	public static void main(String[] args){
		Scanner scnr = new Scanner(System.in);
		int choice;
		double n1,n2,res;

		while(true){
		   System.out.print("\n1.Addition\n2.Subtraction \n3.Multiplication\n4.Division\n5.Exit\nEnter your choice : ");
		   choice = scnr.nextInt();
		   switch(choice){
			case 1 :
				System.out.print("enter the number 1 : ");
				n1 = scnr.nextDouble();
				System.out.print("enter the number 2 : ");
				n2 = scnr.nextDouble();
				System.out.println("result is :" + (n1 + n2));
				break;
			
			case 2 :
				System.out.print("enter the number 1 : ");
				n1 = scnr.nextDouble();
				System.out.print("enter the number 2 : ");
				n2 = scnr.nextDouble();
				System.out.println("\nresult is :" + (n1 - n2));
				break;
			
			case 3 :
				System.out.print("enter the number 1 : ");
				n1 = scnr.nextDouble();
				System.out.print("enter the number 2 : ");
				n2 = scnr.nextDouble();
				System.out.println("\nresult is :" + (n1 * n2));
				break;

			case 4 :
				System.out.print("enter the number 1 : ");
				n1 = scnr.nextDouble();
				System.out.print("enter the number 2 : ");
				n2 = scnr.nextDouble();
				System.out.println("\nresult is :" + (n1 / n2));
				break;

			case 5 :
				System.out.println("Exiting...");
				scnr.close();
				System.exit(0);
				break;

			default :
				System.out.println("Enter A Valid Choice!...");
				break;

			}
		}

	}
 }
