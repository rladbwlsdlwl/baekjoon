import java.util.Scanner;
import java.math.*;

public class P11443{

	BigInteger fibo(BigInteger n){
		double phi=(1+Math.sqrt(5));
		return Math.round(Math.pow(phi,n)/Math.sqrt(5));
	}

	public static void main(String[] args){
		P11443 p=new P11443();
		
		Scanner sc=new Scanner(System.in);
		BigInteger n=new BigInteger(sc.next());
		System.out.printf("%d",p.fibo(n));

	}
}
