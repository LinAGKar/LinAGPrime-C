#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if(argc < 2) {
		fprintf(stderr, "Must specify max, e.g. \"%s 10000000\"\n", argv[0]);
		return -1;
	} else if(argc > 2) {
		fprintf(stderr, "Too many arguments\n");
		return -1;
	}

	const int MAX = atoi(argv[1]); // Programmet hittar all primtal under MAX

	int len_allocated = 8;
	int* primes = malloc(len_allocated * sizeof(int));
	int* primes_square = malloc(len_allocated * sizeof(int));

	if(primes == NULL || primes_square == NULL) {
		fprintf(stderr, "Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	int len = 0;


	for(int i = 2; i < MAX; i++) {
		int divisible = 0;

		for(int j = 0; j < len; j++) {
			if(primes_square[j] > i) {
				break;
			}
			if(!(i % primes[j])) {
				divisible = 1;
				break;
			}
		}


		if(!divisible) {
			if(len >= len_allocated) {
				len_allocated *= 2;
				if((primes = realloc(primes, len_allocated * sizeof(int))) == NULL || (primes_square = realloc(primes_square, len_allocated * sizeof(int))) == NULL) {
					fprintf(stderr, "Failed to allocate memory\n");
					exit(EXIT_FAILURE);
				}
			}
			primes[len] = i;
			primes_square[len] = i * i;
			len++;
			printf("%d\n", i);
		}
	}

	return 0;
}
