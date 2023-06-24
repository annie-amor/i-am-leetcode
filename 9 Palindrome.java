class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        String number = String.valueOf(x);
        String reverse = "";
        for(int i = number.length()-1; i >= 0; i--){
            reverse += String.valueOf(number.charAt(i));
        }

        if(number.equals(reverse))
            return true;
        return false;
    }
}
