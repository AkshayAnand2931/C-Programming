#include <stdio.h>
int main()
{
    char str[80], ch;

    scanf("%s", str);
    ch = getchar();
 
    printf("%s\n", str);
    printf("%c", ch);
 
    return 0;
}