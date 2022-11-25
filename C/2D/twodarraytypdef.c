#include <stdio.h>

int main(void) 
{
    enum { M = 2, N = 3 };
    typedef int X_t[N];
    
    printf( "sizeof( X_t ) = %zu\n", sizeof( X_t ) );
    
    putchar( '\n' );
    
    X_t A[M] = { {1,2,3}, {4,5,6} };

    for (int i = 0; i < 2; i++) {
	    for (int j = 0; j < 3; j++) {
		    printf("%d  ", A[i][j]);
	    }
	    printf("\n");
    }
    
    printf( "sizeof( A ) = %zu\n", sizeof( A ) );
    printf( "sizeof( A[0] ) = %zu\n", sizeof( A[0] ) );
    printf( "sizeof( A ) / sizeof( A[0] ) = %zu\n", sizeof( A ) / sizeof( A[0] ) );
    

    return 0;
}
