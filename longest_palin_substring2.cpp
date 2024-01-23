#include<iostream>
String longest_palindrome_substring(String str){
    if(str.length() <=1)
    return str;
String LPS="";
for(i=1;i<str.length();i++){
    int low=i;
    int high=i;

    while(str.charAt(low)==str.charAt(high)){
        low--;
        high++;

        if(low==-1 || high==str.length())
        break;

    }
    String palindrome=str.substring(low+1,high);
    if(palindrome.length()>LPS.length())
    LPS=palindrome;
}
 low=i-1;
 high=i;
  while(str.charAt(low)==str.charAt(high)){
        low--;
        high++;

        if(low==-1 || high==str.length())
        break;

    }
    String palindrome=str.substring(low+1,high);
    if(palindrome.length()>LPS.length())
    LPS=palindrome;

return LPS;
        }
