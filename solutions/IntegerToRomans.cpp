class Solution {
public:
    string intToRoman(int num) {
        if(num <= 10){
            return convertUnits(num);
        }   
        else
        {
            int numberOfUnits       = num%10;
            int numberOfTens        = (num%100)/10;
            int numberOfCents       = (num%1000 - (num%100));
                numberOfCents       = (int) numberOfCents/100;
            int numOfThousands      = 0;
            if(num>999){
                numOfThousands = (num - (num%1000));
                numOfThousands = (int)numOfThousands/1000;
            }

            string romanNumber = "";
            romanNumber = romanNumber + convertThousands(numOfThousands);
            romanNumber = romanNumber + convertHundreds(numberOfCents);
            romanNumber = romanNumber + convertTens(numberOfTens);
            romanNumber = romanNumber + convertUnits(numberOfUnits);

            return romanNumber;
        }
    }
    string convertUnits(int nU){
        if(nU == 1)
            return "I";
        if(nU == 2)
            return "II";
        if(nU == 3)
            return "III";
        if(nU == 4)
            return "IV";
        if(nU == 5)
            return "V";
        if(nU == 6)
            return "VI";
        if(nU == 7)
            return "VII";
        if(nU == 8)
            return "VIII";
        if(nU == 9)
            return "IX";
        if(nU == 10)
            return "X";
        else{
            return "";
        }
    }
    string convertTens(int nT){
        if(nT == 0)
            return "";
        if(nT == 1)
            return "X";
        if(nT == 2)
            return "XX";
        if(nT == 3)
            return "XXX";
        if(nT == 4)
            return "XL";
        if(nT == 5)
            return "L";
        if(nT == 6)
            return "LX";
        if(nT == 7)
            return "LXX";
        if(nT == 8)
            return "LXXX";
        if(nT == 9)
            return "XC";
        else{
            return "";
        }
    }
    string convertHundreds(int nC){
        if(nC == 1)
            return "C";
        if(nC == 2)
            return "CC";
        if(nC == 3)
            return "CCC";
        if(nC == 4)
            return "CD";
        if(nC == 5)
            return "D";
        if(nC == 6)
            return "DC";
        if(nC == 7)
            return "DCC";
        if(nC == 8)
            return "DCCC";
        if(nC == 9)
            return "CM";
        else{
            return "";
        }
    }
    string convertThousands(int nT){
     
        if(nT == 1)
            return "M";
        if(nT == 2)
            return "MM";
        if(nT == 3)
            return "MMM";
        else{
            return "";
        }
    }

};
