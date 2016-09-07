import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class UnicodeDemo implements Menu {
	Scanner sc;
	protected UnicodeDemo(){
		sc = new Scanner(System.in);
	}
	protected void MarathiDemo(){
		String name;
		name =  sc.nextLine();
		Character.UnicodeBlock myscript = Character.UnicodeBlock.forName(name);
		final Set<Character> chars = new HashSet<Character>();
		for(int codePoint = Character.MIN_CODE_POINT; codePoint < Character.MAX_CODE_POINT; codePoint++){
			if(myscript == Character.UnicodeBlock.of(codePoint)){
				chars.add((char)codePoint);
			}
			
		}
		for(Character ch:chars){
			System.out.println(ch);
		}
	}
	public static void run(){
		UnicodeDemo runner  = new UnicodeDemo();
		runner.MarathiDemo();
	}
	
}