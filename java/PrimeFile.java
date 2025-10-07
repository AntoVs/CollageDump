import java.io.*;
import java.util.Scanner;

public class PrimeFile{
	public static int prime(int n){
		if (n<=1)
			return 0;
		for(int i=2; i<=n/2; i++){
			if (n%i == 0)
				return 0;
		}
		return 1;
	}
	public static void main(String[] args)throws Exception{
		FileReader fr = new FileReader("input");
		FileWriter fw = new FileWriter("output");
		Scanner sc = new Scanner(fr);
		
		while (sc.hasNextInt()) {
			int n = sc.nextInt();
			if (prime(n) == 1){
				fw.write(n + "\n");
				System.out.println(n + " ");
				}
			}
	sc.close();
	fr.close();
	fw.close();
	}
}
