#include <stdio.h>
// #define pc putchar
#define j int

// Uses bit-shifting to get powers of two.
int two_pow(int power){
	return (1 << power);
}

// Printing to stdout without stdio or putchar
void pc(char item, int len){
	int i;
	for (i = 0; i < len; ++i){
		write(1, &item, 1);
	}
}

// Prints a line with nodes on it.
void print_line(int sbuff, int seperator, int node_num, int node){
	int i = 0;
	pc(' ',sbuff-1);
	// for (i = 0; i < sbuff-1; ++i){
	// 	printf(" ");
	// }

	for (i = 0; i < node_num; ++i){
		// printf("%c", node);
		pc(node,1);
		// Don't print spacers on last node
		if (i < node_num){
			int x;
			// for (x = 0; x < seperator; ++x){
			// 	printf(" ");
			// }
			pc(' ',seperator);
		}
	}

	pc(' ',sbuff);
	// for (i = 0; i < sbuff; ++i){
	// 	printf(" ");
	// }
	pc('\n',1);
}


void print_tree(int height){
	int step, i, x;
	for (step = 0; step < height; ++step){
		int level =  height - step - 1;

		int levSqrd = two_pow(level);

		int sideBuffer = levSqrd;
		int seperator = two_pow(level+1);

		// Creates the arrays with the nodes and columns
		int nodeCount = two_pow(step);

		if (step){
			// Prints the "spanning" bars that connect nodes
			// for (i = 0; i < sideBuffer-1; ++i){
			// 	printf(" ");
			// }
			pc(' ',sideBuffer-1);

			for (i = 0; i < nodeCount; ++i){
				// Determines whether to print a bar or empty space
				if (i%2){
					// for (x = 0; x < seperator-1; ++x){
					// 	printf(" ");
					// }
					pc(' ',seperator-1);
				} else {
					// for (x = 0; x < seperator+1; ++x){
					// 	printf("=");
					// }
					pc('=',seperator+1);
				}
			}

			// for (i = 0; i < sideBuffer; ++i){
			// 	printf(" ");
			// }
			pc(' ',sideBuffer);
			pc('\n',1);
			// printf("\n");
			print_line(sideBuffer, seperator-1, nodeCount, '|');
		}
		print_line(sideBuffer, seperator-1, nodeCount, 'O');
	}
}


int main(int argc, char const *argv[]){

	// write(1, (char)65, 1);

	// Assume that any second argument will be a number
	int height=5;
	if (argc>1){
		height = atoi(argv[1]);
	}

	int x[25] = {
		285563184,
		1494092560,
		85463301,
		106508377,
		218961937,
		51645273,
		106497812,
		946803732,
		403116633,
		207163657,
		1494484746,
		335743501,
		89718797,
		1493899281,
		117791000,
		1867191316,
		1499027801,
		1499027801,
		1499027801,
		1499027801,
		660163660,
		403707160,
		118761817,
		186125325,
		1868126553
	};
	int i,n;
	for (i = 0; i < 25; ++i){
		for (n = 0; n < 4; ++n){
			pc(121 - (0x7F & x[i] >> 8 * n), 1);
		};
	};
	print_tree(height);
	return 0;
}
