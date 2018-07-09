/*------------------------------------------------*/
// Uva Problem No: 787
// Problem Name: Maximum Sub-sequence Product
// Type: Max 1D Range Sum (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-02-11 12:07:01
// Runtime: 0.260s
// Universidade: Unicamp
/*------------------------------------------------*/

import java.util.Scanner;
import java.util.ArrayList;
import java.math.BigInteger;

public class Main {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        while(input.hasNext()) {
            ArrayList<Integer> array = new ArrayList<Integer>();

            while(true) {
                int n = input.nextInt();
                if (n == -999999) break;
                array.add(n);
            }

            BigInteger maxGlobal = new BigInteger("" + array.get(0));
            BigInteger maxCurrent = new BigInteger("" + array.get(0));
            BigInteger minCurrent = new BigInteger("" + array.get(0));
            for (int i = 1; i < array.size(); i++) {
                BigInteger savedCurrent = new BigInteger("" + maxCurrent);
                BigInteger v = new BigInteger("" + array.get(i));
                BigInteger b = savedCurrent.multiply(v);
                BigInteger c = minCurrent.multiply(v);

                maxCurrent = v.max(b.max(c));
                minCurrent = v.min(b.min(c));
                maxGlobal = maxGlobal.max(maxCurrent.max(minCurrent));
            }

            System.out.println(maxGlobal);
        }
    }
}
