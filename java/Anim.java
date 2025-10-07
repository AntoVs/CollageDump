class Animal{
	String name;
	int age;
	String type;
	
	Animal(String name,int age, String type){
		this.name = name;
		this.age = age;
		this.type = type;
	}
}

class Herbivore extends Animal {
	Herbivore(String name, int age, String type){
		super(name,age,type);
	}
	void disp() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Type: " + type);
    }
}

class Carnivore extends Animal {
	Carnivore(String name, int age, String type){
		super(name,age,type);
	}
	
	void disp() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Type: " + type);
    }
}

public class Anim {
	public static void main(String[] args){
		Herbivore herb = new Herbivore("deer", 21,"Herbivore");
		Carnivore car = new Carnivore("Tiger", 20,"Catnivore");
				
		herb.disp();
		System.out.println();
		car.disp();				
	}
}
