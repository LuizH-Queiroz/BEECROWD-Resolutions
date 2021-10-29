#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int main(){
    char c;
    bool upperCase;


    upperCase = true;
    while ((c = getchar()) != EOF)
    {
        if (c == ' '){
            printf("%c", c);
        }
        else if (c == '\n'){
            printf("%c", c);
            upperCase = true;
        }
        else if (upperCase){
            printf("%c", toupper(c));
            upperCase = false;
        }
        else {
            printf("%c", tolower(c));
            upperCase = true;
        }
    }


    return 0;
}