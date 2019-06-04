#include<stdio.h>
#include<ctype.h>

int main()
{
    char str[15] = "a1c3a13ed321ba";
    int map[26] = {0};
    int i = 0;

   while(str[i] != '\0')
    {
        int number = 1;
        char c;
        if(isalpha(str[i]))
        {
             c = str[i];
//        printf("%d" ,  c - '0');
  //           printf("%c\n " , str[i]);
        }
        i++;
         if(isdigit(str[i]))
             number = 0;

        while(str[i] != '\0' && isdigit(str[i]))
        {
//            printf("%d",str[i] - '0');
            number = number * 10 + str[i] - '0';
            i++;
        }
//        printf("%d\n", number);
        map[c - 'a'] += number; 
    }
    i = 0;
    
    while( i < 26)
    {
        if (map[i] != 0)
          printf("%c %d ", i + 'a', map[i]);
                
        i++;
    }

    return 0;
}
