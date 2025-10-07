abstract class Employee{
	String name;
	int employee_id;
	double salary;

	Employee(String n,int id, double sal){
		name = n;
		employee_id = id;
		salary = sal;
	}	
	
	abstract double calculate_bonus();
	abstract void display_info();
}

class Manager extends Employee{
	int team_size;
	
	Manager(String n,int id, double sal, int size){
		super (n, id, sal);
		team_size = size;
	}
	
	double calculate_bonus(){
		double bonus = (salary * (0.23*team_size));
		return bonus;
	}
	
	void display_info(){
		System.out.println("\nName :" + name + "\nEmplayee_id : " + employee_id + "\nSalary : " + salary +"\nTeam_size : " + team_size + "\nBonus = " + calculate_bonus());
	}
}

class SeniorManager extends Manager{
	int stock;
	SeniorManager(String n,int id, double sal, int size, int stk){
		super (n, id, sal, size);
		stock = stk;
	}
	
	double calculate_bonus(){
		double bonus = super.calculate_bonus()+ stock*10;
		System.out.println("Bonus = " + bonus);
		return bonus;
	}
	
	void display_info(){
		System.out.println("\nName :" + name + "\nEmplayee_id : " + employee_id + "\nSalary : " + salary +"\nTeam_size : " + team_size + "\nStock Options: " + stock);
	}
		

}

class Developer extends Employee{
	String plang;
	Developer(String n, int id, double sal, String lang){
		super(n, id, sal);
		plang = lang;
	}
	double calculate_bonus(){
		double bonus = (salary * 0.30);
		return bonus;
		}
		
	void display_info(){
		System.out.println("\nName :" + name + "\nEmplayee_id : " + employee_id + "\nSalary : " + salary + "\nLanguage : "+ plang + "\nBonus = " + calculate_bonus());
	}
	
	void AssignTask(){
		System.out.println(name + " assigned a tsk");
	};
	void AssignTask(String n){
		System.out.println(name + " assigned a task : " + n );
	};
}

class JuniorDeveloper extends Developer {
	String Mentor;
	
	JuniorDeveloper(String n, int id, double sal, String lang,String ment){
		super(n, id, sal,lang);
		Mentor = ment;
	}
	
	double calculate_bonus(){
		return super.calculate_bonus();
		}
	
	void display_info(){
		System.out.println("\nName :" + name + "\nEmplayee_id : " + employee_id + "\nSalary : " + salary + "\nLanguage : "+ plang + "\nBonus = " + calculate_bonus());
		}

}

class Intern extends Employee{
	int duration;
	Intern(String n,int id, double sal, int dur){
		super (n, id, sal);
		duration = dur;
	}
	
	double calculate_bonus(){
		double bonus = (salary * (0.103*duration));
		System.out.println("Bonus = " + bonus);
		return bonus;
	}
	
	void display_info(){
		System.out.println("\nName :" + name + "\nEmplayee_id : " + employee_id + "\nSalary : " + salary +"\nDuration : " + duration);
	}
}

public class Comp{
	public static void main(String[] args){
		Employee emp1 = new Manager("MngAszi",001,50000,4);
		emp1.display_info();
		emp1.calculate_bonus();	
		
		Employee emp2 = new Developer("DevHarry",002,90000,"C");
		emp2.display_info();
		emp2.calculate_bonus();
		
		Employee emp3 = new Intern("InterSanji",003,3000,20);
		emp3.display_info();
		emp3.calculate_bonus();
		
		Employee emp4 = new SeniorManager("SeniorAszi",004,50000,4,20);
		emp4.display_info();
		emp4.calculate_bonus();
		
		Employee emp5 = new JuniorDeveloper("JunDevHarry",005,50000,"C","garry");
		emp5.display_info();
		emp5.calculate_bonus();
		
		Developer D = new Developer("DevTaskHarry",8,70000,"JAva");
		D.AssignTask();
		D.AssignTask("Doing a thing in Eschelon");
	}
}
