#include <unistd.h> /*fork declared here*/
#include <stdio.h> /* printf declared here*/
int main() {
    int answer = 84 >> 1;
    // new line to below print makes lot of difference  try with or without it
    printf("Answer: %d\n", answer); 
    fork();
    
    return 0;
}
