class Solution {
    public String addStrings(String num1, String num2) {
        StringBuffer ans = new StringBuffer();
        int i = num1.length()-1;
        int j = num2.length()-1;
        int val = 0;
        int val1 = 0;
        int val2 = 0;

        while( i>=0 || j>=0 || val>0 ) {
            val1 = i>=0 ? num1.charAt(i)-'0' : 0 ;
            val2 = j>=0 ? num2.charAt(j)-'0' : 0;
            i--;
            j--;

            val += val1 + val2;
            ans.append(val % 10);
            val = val/10;
        }

        ans.reverse();
        return ans.toString();
    }
}