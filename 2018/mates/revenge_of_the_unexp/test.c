#include <stdio.h>
#include <time.h>

int main()
{
   struct timespec tim, tim2;
   tim.tv_sec = 3;
   tim.tv_nsec = 0L;

   if(nanosleep(&tim , NULL) < 0 )
   {
      printf("Nano sleep system call failed \n");
      return -1;
   }

   printf("Nano sleep successfull \n");

   return 0;
}
