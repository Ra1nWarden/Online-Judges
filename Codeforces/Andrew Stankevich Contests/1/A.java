package com;
import java.math.BigInteger;
import java.util.Scanner;

public class A {

    public static void main(String args[]) {
	Scanner sc = new Scanner(System.in);
	BigInteger num = sc.nextBigInteger();
	BigInteger two = new BigInteger("2");
	if(num.mod(two).equals(BigInteger.ONE)) {
	    System.out.println(num.shiftRight(1));
	} else {
	    num = num.shiftRight(1);
	    num = num.subtract(BigInteger.ONE);
	    if(num.mod(two).equals(BigInteger.ONE))
		System.out.println(num);
	    else
		System.out.println(num.subtract(BigInteger.ONE));
	}
	System.exit(0);
    }

}
