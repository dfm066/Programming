import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;

public class FactorialDigitSum {
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        BigInteger fact = new BigInteger("1");
        BigInteger num =  new BigInteger("2");
        BigInteger incr = new BigInteger("1");
        char dec[];
        int sum[] = new int[1001];
        int tmp;
        for(int i = 0; i < 1000; i++){
            tmp = 0;
            dec = fact.toString().toCharArray();
            for(char j:dec){
                if(Character.getNumericValue(j) > 0){
                    tmp += Character.getNumericValue(j);
                }
            }
            sum[i+1] = tmp;
            fact = fact.multiply(num);
            num = num.add(incr);
        }
        Scanner sc = new Scanner(System.in);
        int t =  sc.nextInt();
        int n;
        while(t > 0){
            t--;
            n = sc.nextInt();
            System.out.println(sum[n]);
        }
    }
}
