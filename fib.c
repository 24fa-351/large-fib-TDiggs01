#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int fib_recursion_wrapper( unsigned long long int nth_term ) {

   /*Recursive Fibonacci*/
   if( nth_term == 0 ) {
      return 0;
   }
   else if( nth_term == 1 ) {
      return 1;
   }
   return fib_recursion_wrapper( nth_term - 1 ) + fib_recursion_wrapper( nth_term - 2 );
}



unsigned long long int fib_iterative_wrapper( unsigned long long int nth_term ) {

   /*Iterative Fibonacci*/
   unsigned long long int previous_a;

   unsigned long long int previous_b = 1;   
   
   unsigned long long int current = 0;

   if( nth_term == 0 ) { 
      return 0;
   }
   else if( nth_term == 1 ) {
      return 1;
   }

   for( int ix = 1; ix < nth_term; ix++ ) {
      previous_a = previous_b;
      previous_b = current;
      current = previous_a + previous_b;
   }
   
   return current;
}



int main( int argc, char *argv[] ) {

   unsigned long long int N;
   
   unsigned long long int int_in_file;

   int _TWO = 2;

   unsigned long long int fib_Number;

   /*Adding first argument with integer in file*/
   N = atoi( argv[1] );

   /*Computing Nth Fibonacci*/
   if(strcmp( argv[_TWO], "r" ) == 0) {
      fib_Number = fib_recursion_wrapper( N - 1 );
      printf( "%llu", fib_Number );
   }
   else if( strcmp( argv[_TWO], "i") == 0 ) {
      fib_Number = fib_iterative_wrapper( N );
      printf( "%llu", fib_Number );
   }

   return 0;
}