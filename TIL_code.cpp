//#include <iostream>
//#include <string>
//#include <stdio.h>
//using namespace std;
//
//int main(void) {
//	static char table[] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '?' };
//	char* p;
//	char* pass = 'KSOIDHEPZ';
//	int idx;
//	p = pass;
//	while (*p != '\n') {
//		if ('A' <= *p && *p <= 'Z')
//			idx = *p - 'A';
//		else
//			idx = 26;
//		putchar(table[idx]);
//		p++;
//	}
//	return 0;
//}