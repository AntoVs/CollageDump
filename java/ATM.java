import java.io.*;
import java.util.Scanner;
class InsufficientBalanceException extends Exception{
	public InsufficientBalanceException(String message){
		super(message);
		}
	}
class Account{
	String accNo;
	double balance;
	void loadbalance() throws IOException{
	  FileReader fr= new FileReader(accNo);
	  Scanner sc = new Scanner(fr);
	  if(sc.hasNextDouble())
	    balance=sc.nextDouble();
	  else
	    balance = 0;
	  fr.close();
	  sc.close();
	  }
	  void savebalance() throws IOException{
	   FileWriter fw = new FileWriter (accNo);
	   fw.write(balance +" ");
	   fw.close();
	   }
	   void deposit(double amt){
	     balance+=amt;
	     System.out.println("Deposited : " + amt + "\nCurrentBalance : " + balance);
	     }
	   void withdraw(double amt) throws IOException,InsufficientBalanceException{
	     if (amt > balance)
	     	throw new InsufficientBalanceException("Insufficient Balance");
	     balance-=amt;
	     System.out.println("Withdrawn : " + amt + "\nCurrent Balance : "+ balance);
	     }
	     void transfer(String toAcc,double amt) throws IOException,InsufficientBalanceException{
	     if (amt > balance)
	     	throw new InsufficientBalanceException("Insufficient Balance");
	     double tobalance=0.00;
	     balance-=amt;
	     tobalance+=amt;
	     FileReader fr= new FileReader(toAcc);
	     Scanner sc = new Scanner(fr);
	     if(sc.hasNextDouble())
	        balance=sc.nextDouble();
	     fr.close();
	     sc.close();
	     FileWriter fw = new FileWriter (toAcc);
	     System.out.println("Transfered : " + amt + " to " + toAcc + "\nCurrent balance :" + balance);
	     fw.close();
	     }
	     double checkbalance(){
	       return balance;
	       }
	}
public class ATM{
	public static void main(String [] args){
	  Scanner sc =new Scanner(System.in);
	  Account atm =new Account();
	  System.out.print("Enter your account number:");
	  atm.accNo=sc.nextLine();
	  try{
	    atm.loadbalance();
	    System.out.println("Your current Balance : "+ atm.checkbalance());
	    int ch;
	    do{
	      System.out.println("ATM\n1.Deposit \n2.Withdraw\n3.Bank Transfer\n4.Check Balance\n5.Exit");
	      System.out.print("Enter yr choice :");
	      ch = sc.nextInt();
	      switch(ch){
	      	   case 1:
	      	  	System.out.print("Enter amount : ");
	      	  	double atmdeposit=sc.nextDouble();
	      	  	atm.deposit(atmdeposit);
	      	  	break;
	      	   case 2:
	      	  	System.out.print("Enter amount : ");
	      	  	double atmwithdraw=sc.nextDouble();
	      	  	try{
	      	    	atm.withdraw(atmwithdraw);
	      	   	}
	      	   	catch(InsufficientBalanceException e){
	      	   		System.out.println("Error :" + e.getMessage());
	      	   	}
	      	   	break;
	       	   case 3:
	          	sc.nextLine();
	       	  	System.out.print("Enter account number to send : ");
	      	  	String toAcc = sc.nextLine();
	      	  	System.out.print("Enter amount : ");
	      	  	double atmtransfer=sc.nextDouble();
	      	  	try{
	      	    	atm.transfer(toAcc,atmtransfer);
	      	   	}
	      	   	catch(InsufficientBalanceException e){
	      	   		System.out.println("Error :" + e.getMessage());
	      	   	}
	      	  	 break;
	      	   case 4:
	      	   	System.out.println("Current balance : " + atm.checkbalance());
	      	   	break;
	      	   case 5:
	      	   	System.out.println("Exitting !!");
	      	   	break;
	      	   default:
	      	   	System.out.println("Invalid choice !!!!");
	      	   	break;
	      	   }
	      	}while(ch!=5);
	      }
	      catch(IOException e){
	           System.out.println("Error :" + e.getMessage());
	          }
	      finally{
	        try{
	            atm.savebalance();
	            }
	        catch(IOException e){
	        	System.out.println("Error updating balance :" + e.getMessage());
	             }
	         System.out.println("Available balance : " + atm.checkbalance());
	         sc.close();
	        }
	     }
	   }	      	           
