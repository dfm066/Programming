import java.awt.Frame;
import java.util.Arrays;
import java.util.Scanner;

public class DecryptTheCrypt {
	public static void main(String []args)
	{
		Scanner s = new Scanner(System.in);
		String Encodedpass = s.nextLine();
		String chars = s.next();
		int len;
		if(chars.length()<10)
		{
			System.out.println("-1");
		}
		else
		{
			int frame = Encodedpass.indexOf("||");
			String msg = Encodedpass.substring(0,frame);
			//System.out.println(msg);
			String subindex = Encodedpass.substring(frame+2,Encodedpass.length()-1);
			int firstno=Integer.parseInt(subindex.charAt(subindex.length()-1)+"");
			//System.out.println(subindex+" "+firstno);
			msg=msg.replaceAll("[|]"," ");
			String [] arr = msg.split(" ");
			String tmp;
			int no;
			int []intarr= new int[10];
			//System.out.println(Arrays.toString(arr));
			for(int i=0;i<arr.length;i++)
			{
				//arr[i].toString();
				if(arr[i].length()>1)
				{
					tmp = arr[i].substring(0,arr[i].length()-1);
					no = Integer.parseInt(arr[i].charAt(arr[i].length()-1)+"");
					//System.out.println(tmp+" "+no);
					for(int j=0;j<tmp.length();j++)
					{
						intarr[Integer.parseInt(tmp.charAt(j)+"")]=no;
					}
					//System.out.println(Arrays.toString(intarr));
				}
				
				//System.out.println(arr[i]+"");
			}
			//System.out.println(Arrays.toString(intarr));
			for(int i=0;i<subindex.length()-1;i++)
			{
				intarr[Integer.parseInt(subindex.charAt(i)+"")]+=10;
			}
			//System.out.println(Arrays.toString(intarr));
			int xxx[] = new int[intarr.length];
			xxx[0]=firstno;
			for(int i=0;i<intarr.length-1;i++)
			{
				xxx[i+1]=intarr[i]-xxx[i];
			}
			for(len=0;len<10;len++)
			{
				if(intarr[len]==0)
				{
					break;
				}
			}
			//System.out.println(Arrays.toString(xxx)+" "+len);
			//System.out.println("e:"+Encodedpass);
			for(int i=0;i<len;i++)
			{
				System.out.print(chars.charAt(xxx[i]));
			}
		}
	}
}
