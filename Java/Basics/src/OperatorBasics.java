<<<<<<< HEAD
import java.util.Scanner;

public class OperatorBasics implements Menu {
	private Scanner sc;
	public OperatorBasics(){
		sc = new Scanner(System.in);
	}
	public void shiftDemo(){
		int no = sc.nextInt();
		int shift = sc.nextInt();
		System.out.println(no+" shifted with logical >>> by "+shift+" = "+(no>>>shift));
		System.out.println(no+" shifted with arithmatic >> by "+shift+" = "+(no>>shift));
	}
	
	public static void run(){
		OperatorBasics runner = new OperatorBasics();
		runner.shiftDemo();
	}
}
=======
import java.util.Scanner;

public class OperatorBasics {
	private Scanner sc;
	public OperatorBasics(){
		sc = new Scanner(System.in);
	}
	public void shiftDemo(){
		int no = sc.nextInt();
		int shift = sc.nextInt();
		System.out.println(no+" shifted with logical >>> by "+shift+" = "+(no>>>shift));
		System.out.println(no+" shifted with arithmatic >> by "+shift+" = "+(no>>shift));
	}
	
	public static void run(){
		OperatorBasics runner = new OperatorBasics();
		runner.shiftDemo();
	}
}
>>>>>>> origin/master
