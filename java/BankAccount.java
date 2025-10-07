import java.util.Scanner;

class BankAccount {
	int accountNumber;
	String accountName;
	float accountBalance;
	
	//default const
	BankAccount(){
		accountNumber = 0000;
		accountName = "JohnDoe";
		accountBalance = 0000;
	}
	
	//construct parameter
	BankAccount(int accNumber,String accName,float accBalance){
		accountNumber = accNumber;
		accountName = accName;
		accountBalance = accBalance;
	}
	
	//deposit fn
	void deposit(float amount){
		accountBalance += amount;
	}
	
	//withdraw fn
	void withdraw(float amount){
		if (accountBalance >= amount)
			accountBalance -= amount;
		else 
			System.out.println("Insufficient balance ");
	}
	
	//display fn
	void disp(){
		System.out.println("Account Number : " + accountNumber);
		System.out.println("Account Name : " + accountName);
		System.out.println("Account Balance :" + accountBalance);
	}
	
	public static void main(String[] args){
		Scanner scnr = new Scanner(System.in);
		
		BankAccount acc1 = new BankAccount();
		
		System.out.print("Enter Account Number : ");
		int accNum = scnr.nextInt();
		System.out.print("Enter Account Name : ");
		scnr.nextLine();
		String accName = scnr.nextLine();
		System.out.print("Enter Account Balance :");
		float accBal = scnr.nextFloat();
		
		BankAccount acc2 = new BankAccount(accNum,accName,accBal);
		
		System.out.println("\n -----------Account1------------");
		acc1.disp();
		System.out.println("\n -----------Account2------------");
		acc2.disp();
		
		System.out.println("\nChoose Operation:");
        	System.out.println("1. Deposit");
        	System.out.println("2. Withdraw");
        	int choice = scnr.nextInt();

        	System.out.println("Enter the amount: ");
        	float amount = scnr.nextFloat();

        	System.out.println("Which account (1 or 2): ");
        	int accChoice = scnr.nextInt();

		if(choice == 1){
			if(accChoice == 1){
				acc1.deposit(amount);
				acc1.disp();
			}
			
			else if(accChoice == 2){
				acc2.deposit(amount);
				acc2.disp();
			}
			
			else 
				System.out.println("wrong input");
			}
		else if(choice == 2){
			if(accChoice == 1){
				acc1.withdraw(amount);
				acc1.disp();
			}
			
			else if(accChoice == 2){
				acc2.withdraw(amount);
				acc2.disp();
			}
			
			else 
				System.out.println("wrong input");
			}
		else
			System.out.println("INVALID input ");
		
		scnr.close();
			
		}
	}
