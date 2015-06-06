import java.math.BigInteger;

/**
 * Created with IntelliJ IDEA.
 * User: zihaowang
 * Date: 17/1/13
 * Time: 10:30 下午
 * To change this template use File | Settings | File Templates.
 */
public class Q57 {
    public static void main(String args[]){
        BigInteger numerator = new BigInteger("3");
        BigInteger denominator = new BigInteger("2");
        BigInteger memory = new BigInteger("0");
        int count = 0;
        for(int i = 2; i <= 1000; i++){
            numerator = numerator.add(denominator);
            memory = denominator;
            denominator = numerator;
            numerator = memory;
            numerator = numerator.add(denominator);
            if(digit(numerator) > digit(denominator))
                count++;
        }
        System.out.println(count);
    }

    public static int digit(BigInteger number){
        String line = number.toString();
        return line.length();
    }
}
