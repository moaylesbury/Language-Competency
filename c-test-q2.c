#include <stdio.h>
#include <string.h>

char *f(int m){
	char buf[6];
	int x;
	if (m == 1 && x--){
		strcpy(buf, "AAAAAA");
		return buf;
	} else if (m == 2) {
		char *msg = (char *)malloc(100);
		strcpy(msg, "BBBBBB");
		return msg;
	}
}

int main(int argc, char **argv){
	char *m;
	m = f(argc);
	putchar(m[0]);
	return 0;
}





//	 x variable is used uninitialised in function f first condition: x-- will always be true
//	 if neither condition is true in f function then there is no return
//	 buf is a char not a char*
//	 if msg is returned with dynamic memory allocation then putchar works
//	 if buf is returned with static memory allocation then putchar will have undefined behaviour
//	 memory allocated to msg is not freed
//	 #include <stdlib.h> is needed to use malloc
