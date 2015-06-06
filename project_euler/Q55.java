import java.math.BigInteger;

/**
 * Created with IntelliJ IDEA.
 * User: zihaowang
 * Date: 16/1/13
 * Time: 6:59 下午
 * To change this template use File | Settings | File Templates.
 */
public class Q55 {
    public static void main(String[] args){
        int count = 9999;
        for(int i  = 1; i < 10000; i++){
            String number = Integer.toString(i);
            BigInteger current = new BigInteger(number);
            for (int j = 1; j <= 50; j++){
                BigInteger reversed = new BigInteger(reverse(current.toString()));
                BigInteger sum = current.add(reversed);
                if(checkpandi(sum.toString())){
                    count--;
                    break;
                }
                else if (j == 50)
                    System.out.println(sum);
                current = sum;
            }
        }
        System.out.println(count);
    }

    public static String reverse(String number){
        String reversed = "";
        for (int i = number.length()-1; i >= 0; i--){
            reversed += number.charAt(i);
        }
        return reversed;
    }

    public static boolean checkpandi(String number){
        boolean status = true;
        for(int i = 0; i < number.length()/2; i++){
            if(number.charAt(i) != number.charAt(number.length()-1-i)){
                status = false;
                break;
            }
        }
        return status;
    }
}
