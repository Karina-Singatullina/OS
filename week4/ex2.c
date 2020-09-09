#include <stdio.h>
#include <stdlib.h>

// 3 fork()'s - 2^3 = 8 processes are executed.
// 5 fork()'s - 2^5 = 32 processes are executed.
int main(){
	for(int i = 0; i < 5; i++){
		fork();
	}
	sleep(5);
	return 0;
}
