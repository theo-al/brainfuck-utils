#include <stdio.h>
#include <limits.h>
#include <ctype.h>

typedef long unsigned int ulong;

static char  mem[USHRT_MAX>>6];
static short ptr;

int interpret (FILE*);
int loop      (FILE*);

int main (int argc, char** argv) {

	FILE* file; 
	char* path; if (argc > 1) path = argv[1];
	else { printf("argument expected"); return -1; }

	file = fopen(path, "rt");
	
	while (interpret(file)); //step through program unless EOF

	return fclose(file);
}

int interpret (FILE* file) {
	
	switch (fgetc(file)) {

		case '+': mem[ptr]++;           break;
		case '-': mem[ptr]--;           break;
		case '>': ptr++;                break;
		case '<': ptr--;                break;
		case '.': putchar(mem[ptr]);    break;
		case ',': mem[ptr] = getchar(); break;
		case '[':
			if (mem[ptr]) return loop(file);
			else while (fgetc(file) != ']'); ; break;
		case ']': return -1;

		case EOF: return 0;
		default : break;

	} return 1;

}

int loop (FILE* file) {
	fpos_t pos; fgetpos(file, &pos); 

	int i; while ((i = interpret(file)) != -1);

	fsetpos(file, &pos); ungetc('[', file);

	return !!i; //return bool(i) [i?1:0]
}
