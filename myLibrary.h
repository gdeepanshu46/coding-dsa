#ifndef MYLIBRARY_H
#define MYLIBRARY_H

bool isPalindrome(string s){
    string t = s;
    reverse(t.begin(), t.end());
    
    return s == t;
}


#endif