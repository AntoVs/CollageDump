import java.util.Scanner;

public class matrix{
	public static void main(String[] args){
		Scanner scnr = new Scanner(System.in);
		
		System.out.print("enter the number of rows : ");
		int rows = scnr.nextInt();
		System.out.print("enter the number of cols : ");
		int cols = scnr.nextInt();
		int[][] mat1 = new int[rows][cols];
		int[][] mat2 = new int[rows][cols];
		int[][] mat3 = new int[rows][cols];
		
		System.out.println("\nEnter the elements of matrix 1 :");
		for(int i = 0; i<rows; i++)
			for (int j = 0; j<cols; j++)
				mat1[i][j] = scnr.nextInt();
		
		System.out.println("Enter the elements of matrix 2 :");
		for(int i = 0; i<rows; i++)
			for (int j = 0; j<cols; j++)
				mat2[i][j] = scnr.nextInt();
		
		for(int i = 0; i<rows; i++){
			for (int j = 0; j<cols; j++){
				mat3[i][j] = mat1[i][j]+mat2[i][j];
		}}
		
		System.out.println("Resultant matrix is :");
		for(int i = 0; i<rows; i++){
			for (int j = 0; j<cols; j++){
				System.out.print(mat3[i][j] + "  ");
			}
		System.out.println();
		}
		
		System.out.println("Resultant transpose matrix is :");
		for(int i = 0; i<cols; i++){
			for (int j = 0; j<rows; j++){
				System.out.print(mat3[j][i] + "  ");
			}
		System.out.println();
		}
		
	scnr.close();
		
	}
}
