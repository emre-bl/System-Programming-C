#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

unsigned long long int fibonacci(unsigned int n);
 
typedef struct FibMultiThreading {
    int x;
    long long int answer;
} fibonacci_thread;
 
void run(fibonacci_thread *f) {
    if (f->x == 0) f->answer = 0;
    else if( f->x == 1 || f->x == 2 ) f->answer = 1;
    else {
        fibonacci_thread f1 = {f->x-1, 0};
        fibonacci_thread f2 = {f->x-2, 0};
        run(&f1);
        run(&f2);
        f->answer = f1.answer + f2.answer;
        //printf("Fibonacci(%lld) = %lld + %lld = %lld\n" , f->x, f1.answer, f2.answer, f->answer);
    }
}


void main(void){
    int n = 50;
    fibonacci_thread f = {n, 0};
    time_t start = time(NULL);
    run(&f);
    time_t end = time(NULL);
    printf("2 thread ile Fibonacci(50) sonucu:%lld\n", f.answer);
    printf("2 Thread ile Fibonacci(50) calisma suresi: %f\n\n", difftime(end, start));

    start = time(NULL);
    printf("1 thread ile Fibonacci(50) sonucu:%lld\n", fibonacci(50));
    end = time(NULL);

    printf("1 Thread ile Fibonacci(50) calisma suresi: %f", difftime(end, start));
}


unsigned long long int fibonacci(unsigned int n)
 {
     // base case
     if (0 == n || 1 == n) {
        return n;
     }
     else { // recursive step
        return fibonacci(n - 1) + fibonacci(n - 2);
     }
 }
