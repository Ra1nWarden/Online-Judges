import java.math.BigInteger;

/**
 * Created with IntelliJ IDEA.
 * User: zihaowang
 * Date: 16/1/13
 * Time: 7:27 下午
 * To change this template use File | Settings | File Templates.
 */
public class Q56 {
    public static void main(String[] args){
        int maxsum = 0;
          for (int i = 1; i < 100; i++){
              BigInteger base = new BigInteger(Integer.toString(i));
              for (int j = 1; j < 100; j++){
                  BigInteger result = base.pow(j);
                  int digitsum = digitsum(result);
                  if(digitsum > maxsum)
                      maxsum = digitsum;
              }
        }
        System.out.println(maxsum);
    }
    public static int digitsum(BigInteger num){
        String line = num.toString();
        int sum = 0;
        for(int i = 0; i < line.length(); i++){
            sum += Integer.parseInt(line.substring(i, i+1));
        }
        return sum;
    }
}
