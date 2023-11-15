#include "shell.h"

int main() {
		char *lineptr;
		size_t k;
		ssize_t getlyn;

		getlyn = getline(&lineptr, &k, STDIN_FILENO);
		if (getlyn == -1) {
			perror("getline did fail");
			exit(-1);
			}

		printf("%s\n", lineptr);

		return (0);

}
