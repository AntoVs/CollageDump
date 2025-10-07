import java.io.*;

public class Encrypt{
	public static void main(String[] args) throws Exception{
		FileReader fr = new FileReader("decrypt.txt");
		FileReader pp = new FileReader("decrypt.txt");
		FileWriter fw = new FileWriter("encrypt.txt");
		int ch;
		char c;
		System.out.print("inputText : ");
		while((ch=pp.read())!=-1){
			c = ((char)ch);
			System.out.print(c);}
		System.out.print("EncryptedText : ");
		while((ch=fr.read())!=-1){
			c = ((char)ch);
			if(Character.isLetter(c)){
				if (Character.isLowerCase(c)){
					c += 3;
					if (c > 'z')
						c -= 26;
				}else if(Character.isUpperCase(c)){
					c += 3;
					if (c > 'Z')
						c -= 26;
				}
			fw.write(c);
			System.out.print(c);
			}
		}
	System.out.println();
	pp.close();
	fr.close();
        fw.close();
	}
}
