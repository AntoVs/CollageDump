class BankAccount{
	int balance;
	public BankAccount(int initalbalance){
		balance=initalbalance;
		}
	synchronized void updateBalance(int amt){
		balance+=amt;
		System.out.println(Thread.currentThread().getName() + "balance updated to " + balance);
		try{
		    Thread.sleep(1500);
		    }
		   catch(InterruptedException e){
		     System.out.println(Thread.currentThread().getName() + "Error ,interupted :" + e.getMessage());
	            }
	System.out.println(Thread.currentThread().getName() + "Balance <delay> " + balance);
		}
	}
	class DepositThread extends Thread{
	BankAccount account;
	DepositThread(BankAccount account){
		this.account=account;
		}
	public void run(){
		for(int i=0;i<5;i++){
			account.updateBalance(100);
		}
	    }
	}
	class WithdrawThread extends Thread{
	BankAccount account;
	WithdrawThread(BankAccount account){
		this.account=account;
		}
	public void run(){
		for(int i=0;i<5;i++){
			account.updateBalance(-50);
		}
	   }
	}
	public class BankSimulation{
		public static void main(String[] args){
		  BankAccount account =new BankAccount(1000);
		  DepositThread dt=new DepositThread(account);
		  WithdrawThread wt=new WithdrawThread(account);
		  dt.setName("DepositThread");
		  wt.setName("WithdrawThread");
		  dt.start();
		  wt.start();
		 }
	}
