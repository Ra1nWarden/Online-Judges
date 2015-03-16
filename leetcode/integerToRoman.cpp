class Solution {
private:
    string convert(int n, string one, string five, string ten) {
        string res = "";
        if(n < 4) {
            while(n--)
                res += one;
        } else if (n == 4)
            res = one + five;
        else if (n == 5)
            res = five;
        else if (n < 9) {
            res = five;
            n -= 5;
            while(n--)
                res += one;
        } else {
            res = one + ten;
        }
        return res;
    }
public:
    string intToRoman(int num) {
        string res = "";
        int thousand = num / 1000;
        for(int i = 0; i < thousand; i++)
            res += "M";
        num -= thousand * 1000;
        res += convert(num / 100, "C", "D", "M");
        res += convert((num % 100) / 10, "X", "L", "C");
        res += convert(num % 10, "I", "V", "X");
        return res;
    }
};
