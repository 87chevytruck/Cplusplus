#include <stdio.h>
#include <stdlib.h>
/* function main begins program execution */
int main(void) {
	int i; /* counter */

	printf("%d\n", RAND_MAX);

	int x = 1 + (rand() % 4);

	printf("%d\n\n\n\n\n", x);
		   /* loop 20 times */
	//for (i = 1; i <= 20; i++) {
		/* pick random number from 1 to 6 and output it */
		//printf("%d ", 1 + (rand() % 55));
		/* if counter is divisible by 5, begin new line of output */
		//if (i % 5 == 0) {
		//	printf("\n");
	//	} /* end if */
	//} /* end for */


	while (1);

	return 0; /* indicates successful termination */
} /* end main */