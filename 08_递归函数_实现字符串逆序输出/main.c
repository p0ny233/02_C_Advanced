#include <stdio.h>

void func(char *pc)
{
    if (*pc == '\0')
        return ;
    
    func(pc+1);
    printf("%c, ", *pc);
}

int main(void)
{
    char string[] = "Hello World";
    func(string);

    return 0;
}
/*

d, l, r, o, W,  , o, l, l, e, H,

*/