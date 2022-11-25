#include <stdio.h>

/* This works on 32 and 64-bit systems. See [[Inline assembler#In actual compilers]] for hints on reading this code. */
int main()
{
  /* The four registers do not need to be initialized as the processor will write over it. */
  int infotype, a, b, c, d;

  for (infotype = 0; infotype < 5; infotype ++)
  {
    __asm__("cpuid"
            : "=a" (a), "=b" (b), "=c" (c), "=d" (d)   // The output variables. EAX -> a and vice versa.
            : "0" (infotype));                         // Put the infotype into EAX.
    printf ("InfoType %x\nEAX: %x\nEBX: %x\nECX: %x\nEDX: %x\n", infotype, a, b, c, d);
  }

  return 0;
}
