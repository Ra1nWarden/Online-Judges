import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


public class Q54 {
	private static ArrayList<Character> sequence = new ArrayList<Character>();
	
	public Q54(){
		sequence.add('2');
		sequence.add('3');
		sequence.add('4');
		sequence.add('5');
		sequence.add('6');
		sequence.add('7');
		sequence.add('8');
		sequence.add('9');
		sequence.add('T');
		sequence.add('J');
		sequence.add('Q');
		sequence.add('K');
		sequence.add('A');
	}
	

	public static void main(String[] args) throws FileNotFoundException {
        Q54 now = new Q54();
        Scanner reader = new Scanner(System.in);
        int count = 0;
        while(reader.hasNextLine()){
            String line = reader.nextLine();
            String[] twoplayer = line.split(" ");
            ArrayList<String> firstp = new ArrayList<String>();
            ArrayList<String> secondp = new ArrayList<String>();
            for (int i  = 0; i < 5; i++){
                firstp.add(twoplayer[i]);
            }
            for (int i = 5; i < 10; i++){
                secondp.add(twoplayer[i]);
            }
            ArrayList<String> firstpresult = new ArrayList<String>();
            ArrayList<String> secondpresult = new ArrayList<String>();
            if(!checkroyalflush(firstp).equals(""))
                firstpresult.add(checkroyalflush(firstp));
            if(!checkroyalflush(secondp).equals(""))
                secondpresult.add(checkroyalflush(secondp));
            if(!checkstraightflush(firstp).equals(""))
                firstpresult.add(checkstraightflush(firstp));
            if(!checkstraightflush(secondp).equals(""))
                secondpresult.add(checkstraightflush(secondp));
            if(!checkfour(firstp).equals(""))
                firstpresult.add(checkfour(firstp));
            if(!checkfour(secondp).equals(""))
                secondpresult.add(checkfour(secondp));
            if(!checkfullhouse(firstp).equals(""))
                firstpresult.add(checkfullhouse(firstp));
            if(!checkfullhouse(secondp).equals(""))
                secondpresult.add(checkfullhouse(secondp));
            if(!checkflush(firstp).equals(""))
                firstpresult.add(checkflush(firstp));
            if(!checkflush(secondp).equals(""))
                secondpresult.add(checkflush(secondp));
            if(!checkstraights(firstp).equals(""))
                firstpresult.add(checkstraights(firstp));
            if(!checkstraights(secondp).equals(""))
                secondpresult.add(checkstraights(secondp));
            if(!checkthree(firstp).equals(""))
                firstpresult.add(checkthree(firstp));
            if(!checkthree(secondp).equals(""))
                secondpresult.add(checkthree(secondp));
            if(!checktwopair(firstp).equals(""))
                firstpresult.add(checktwopair(firstp));
            if(!checktwopair(secondp).equals(""))
                secondpresult.add(checktwopair(secondp));
            if(!checkpair(firstp).equals(""))
                firstpresult.add(checkpair(firstp));
            if(!checkpair(secondp).equals(""))
                secondpresult.add(checkpair(secondp));
            firstpresult.add(checkhigh(firstp));
            secondpresult.add(checkhigh(secondp));
            if(compete(firstpresult, secondpresult)){
                count++;
                System.out.println(firstpresult + " vs " + secondpresult + " -> " + compete(firstpresult,secondpresult));
            }
        }
        System.out.println(count);
	}

    public static boolean compete(ArrayList<String> firstp, ArrayList<String> secondp){
        if (firstp.get(0).equals(secondp.get(0))){
            boolean status = false;
            for(int i = 0 ; i < firstp.get(1).length(); i++){
                if(firstp.get(1).charAt(i) != secondp.get(1).charAt(i)){
                    status = (sequence.indexOf(firstp.get(1).charAt(i)) > sequence.indexOf(secondp.get(1).charAt(i)));
                    break;
                }
            }
            return status;
        }
        else{
            if(firstp.get(0).charAt(0) == secondp.get(0).charAt(0)){
                boolean status = false;
                for(int i = 0; i < firstp.get(0).length(); i++){
                    if(firstp.get(0).charAt(i) != secondp.get(0).charAt(i)){
                        status = (sequence.indexOf(firstp.get(0).charAt(i)) > sequence.indexOf(secondp.get(0).charAt(i)));
                        break;
                    }
                }
                return status;
            }
            else
                return (firstp.get(0).charAt(0) < secondp.get(0).charAt(0));
        }
    }
	
	public static String checkroyalflush(ArrayList<String> hand){
		String returnstr = "";
		if(checksuit(hand) && checkstraight(hand)){
			for(int i = 0; i < 5; i++){
				if(hand.get(i).charAt(1) == 'A')
					returnstr = "AA";
			}
		}
		return returnstr;
	}
	
	public static String checkstraightflush(ArrayList<String> hand){
        String returnstr = "";
        if (checksuit(hand) && checkstraight(hand)){
            int max = 0;
            for(int i = 0; i < 5; i++){
                int newindex = sequence.indexOf(hand.get(i).charAt(1));
                if(newindex > max)
                    max = newindex;
            }
            returnstr = "B" + sequence.get(max);
        }
        return returnstr;
	}

    public static String checkfour(ArrayList<String> hand){
        String returnstr = "";
        int[] index = new int[13];
        for(int i = 0; i < 5; i++){
            int currentindex = sequence.indexOf(hand.get(i).charAt(0));
            index[currentindex]++;
        }
        for(int i = 0; i < 13; i++){
            if(index[i] == 4)
                returnstr = "C" + sequence.get(i);
        }
        return returnstr;

    }

    public static String checkfullhouse(ArrayList<String> hand){
        String returnstr = "";
        int[] index = new int[13];
        for(int i = 0; i < 5; i++){
            int currentindex = sequence.indexOf(hand.get(i).charAt(0));
            index[currentindex]++;
        }
        for(int i = 0; i < 13; i++){
            if(index[i] == 3){
                for(int j = 0; j < 13; j++){
                    if(index[j] == 2)
                        returnstr = "D" + sequence.get(i) + sequence.get(j);
                }
            }

        }
        return returnstr;
    }

    public static String checkflush(ArrayList<String> hand){
        String returnstr = "";
        if(checksuit(hand)){
            int[] index = new int[13];
            for(int i  = 0; i < 5; i++){
                int currentindex = sequence.indexOf(hand.get(i).charAt(0));
                index[currentindex]++;
            }
            String appendix = "";
            for(int i = 12; i >=0; i--){
                int time = index[i];
                while(time != 0){
                    appendix += sequence.get(i);
                    time--;
                }
            }
            returnstr = "E" + appendix;
        }
        return returnstr;
    }

    public static String checkstraights(ArrayList<String> hand){
        String returnstr = "";
        if(checkstraight(hand)){
            int maxindex = 0;
            for(int i  = 0; i < 5; i++){
                int currentindex = sequence.indexOf(hand.get(i).charAt(0));
                if(currentindex > maxindex)
                    maxindex = currentindex;
            }
            returnstr = "F" + sequence.get(maxindex);
        }
        return returnstr;
    }

    public static String checkthree(ArrayList<String> hand){
        String returnstr = "";
        int[] index = new int[13];
        for(int i = 0; i < 5; i++){
            int currentindex = sequence.indexOf(hand.get(i).charAt(0));
            index[currentindex]++;
        }
        for(int i = 0; i < 13; i++){
            if(index[i] == 3){
                boolean found = false;
                for(int j = 0; j < 13; j++){
                    if(index[j] == 2)
                        found = true;
                }
                if(!found)
                    returnstr = "G" + sequence.get(i);
            }

        }
        return returnstr;

    }

    public static String checktwopair(ArrayList<String> hand){
        String returnstr = "";
        int[] index = new int[13];
        for(int i = 0; i < 5; i++){
            int currentindex = sequence.indexOf(hand.get(i).charAt(0));
            index[currentindex]++;
        }
        for(int i = 0; i < 13; i++){
            if(index[i] == 2){
                for(int j = 0; j < 13; j++){
                    if(j == i)
                        continue;
                    if(index[j] == 2) {
                        if (i > j)
                            returnstr = "H" + sequence.get(i) + sequence.get(j);
                        else
                            returnstr = "H" + sequence.get(j) + sequence.get(i);
                    }

                }
            }

        }
        return returnstr;
    }

    public static String checkpair(ArrayList<String> hand){
        String returnstr = "";
        int[] index = new int[13];
        for(int i = 0; i < 5; i++){
            int currentindex = sequence.indexOf(hand.get(i).charAt(0));
            index[currentindex]++;
        }
        for(int i = 0; i < 13; i++){
            if(index[i] == 2){
                boolean secondtwo = false;
                for (int j = 0; j < 13; j++){
                    if(j==i)
                        continue;
                    if(index[j] == 2 || index[j] == 3)
                        secondtwo = true;
                }
                if(!secondtwo)
                    returnstr = "I" + sequence.get(i);
            }
        }
        return returnstr;
    }

    public static String checkhigh(ArrayList<String> hand){
        String returnstr = "J";
        int[] index = new int[13];
        for(int i = 0; i < 5; i++){
            int currentindex = sequence.indexOf(hand.get(i).charAt(0));
            index[currentindex]++;
        }
        String appendix = "";
        for(int i = 12; i >= 0; i--){
            if(index[i] != 0)
                appendix += sequence.get(i);
        }
        return returnstr + appendix;
    }



	public static boolean checksuit(ArrayList<String> hand){
		char first = hand.get(0).charAt(1);
		boolean result = true;
		for (int i = 1; i < 5; i++){
			if(hand.get(i).charAt(1) != first){
				result = false;
				break;
			}
		}
		return result;
	}
	
	public static boolean checkstraight(ArrayList<String> hand){
		int[] indexs = new int[13];
        for(int i = 0; i < 5; i++){
            int currentindex = sequence.indexOf(hand.get(i).charAt(0));
            indexs[currentindex]++;
        }
        if(indexs[12] == 1 && indexs[0] == 1 && indexs[1] == 1 && indexs[2] == 1 && indexs[3] == 1)
            return true;
        else{
            boolean found = false;
            for(int i = 0; i < 9; i++){
                if(indexs[i] == 1 && indexs[i+1] == 1 && indexs[i+2] == 1 && indexs[i+3] == 1 && indexs[i+4] == 1)
                    found = true;
            }
            return found;
        }
	}
	

}
