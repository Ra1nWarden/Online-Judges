
public class Q17 {

	public static void main(String[] args) {
		long sum = 0;
		int one = 3,
			two = 3,
			three = 5,
			four = 4,
			five = 4,
			six = 3,
			seven = 5,
			eight = 5,
			nine = 4;
		int tenandbelow = 3+3+5+4+4+3+5+5+4+3;
		int eleven = 6,
			twelve = 6,
			thirteen = 8,
			fourteen = 8,
			fifteen = 7,
			sixteen = 7,
			seventeen = 9,
			eighteen = 8,
			nineteen = 8,
			twenty = 6;
		int twentyandbelow = tenandbelow+6+6+8+8+7+7+9+8+8+6;
		sum += twentyandbelow;
		int thirty = 6,
			forty = 5,
			fifty = 5,
			sixty = 5,
			seventy = 7,
			eighty = 6,
			ninety = 6;
		for (int i = 21; i < 100; i++){
			int ones = i % 10,
				tens = i / 10;
			switch (ones){
			case 1:
				sum += one;
				break;
			case 2:
				sum += two;
				break;
			case 3:
				sum += three;
				break;
			case 4:
				sum += four;
				break;
			case 5:
				sum += five;
				break;
			case 6:
				sum += six;
				break;
			case 7:
				sum += seven;
				break;
			case 8:
				sum += eight;
				break;
			case 9:
				sum += nine;
				break;
			}
			switch (tens){
			case 2:
				sum += twenty;
				break;
			case 3:
				sum += thirty;
				break;
			case 4:
				sum += forty;
				break;
			case 5:
				sum += fifty;
				break;
			case 6:
				sum += sixty;
				break;
			case 7:
				sum += seventy;
				break;
			case 8:
				sum += eighty;
				break;
			case 9:
				sum += ninety;
				break;
			}
		}
		long belowhundred = sum;
		int hundred = 7;
		for (int i = 1; i < 10; i++){
			switch (i){
			case 1:
				sum += (one+hundred)*100 + 3*99 + belowhundred;
				break;
			case 2:
				sum += (two+hundred)*100 + 3*99 + belowhundred;
				break;
			case 3:
				sum += (three+hundred)*100 + 3*99 + belowhundred;
				break;
			case 4:
				sum += (four+hundred)*100 + 3*99 + belowhundred;
				break;
			case 5:
				sum += (five+hundred)*100 + 3*99 + belowhundred;
				break;
			case 6:
				sum += (six+hundred)*100 + 3*99 + belowhundred;
				break;
			case 7:
				sum += (seven+hundred)*100 + 3*99 + belowhundred;
				break;
			case 8:
				sum += (eight+hundred)*100 + 3*99 + belowhundred;
				break;
			case 9:
				sum += (nine+hundred)*100 + 3*99 + belowhundred;
				break;
			}
		}
		int thousand = 8;
		sum += one + thousand;
		System.out.println(sum);

	}

}
