#include <stdio.h>
#include <time.h>

void sleep(int speed){
    time_t start, end;
    double elapsed;

    time(&start); /* start the timer */

    do
    {
        time(&end);

        elapsed = difftime(end, start);
        /* For most data types one could simply use
            elapsed = end - start;
            but for time_t one needs to use difftime(). */
    } while (elapsed < speed); /* run for ten seconds */
}