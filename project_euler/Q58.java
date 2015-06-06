import java.util.ArrayList;

/**
 * Created with IntelliJ IDEA.
 * User: zihaowang
 * Date: 17/1/13
 * Time: 10:40 下午
 * To change this template use File | Settings | File Templates.
 */
public class Q58 {
    public static void main(String args[]){
        int number = 1;
        int prime = 0;
        int totalnumber = 1;
        for(int i = 1; i > 0; i++){
            int side = 2*i + 1;
            number += 2*(i-1)+1+1;
            if(isprime(number))
                prime++;
            for(int j = 1; j <=3; j++){
                number += side - 1;
                if(isprime(number))
                    prime++;
            }
            totalnumber += 4;
            if(totalnumber * 0.1 > prime){
                System.out.println(side);
                System.exit(0);
            }
        }

    }
    public static boolean isprime(int number){
        if (number == 1)
            return false;
        else if (number == 2)
            return true;
        else{
            boolean prime = true;
            for (int i = 2; i <= Math.sqrt(number); i++){
                if(number % i == 0){
                    prime = false;
                    break;
                }
            }
            return prime;
        }
    }
}
