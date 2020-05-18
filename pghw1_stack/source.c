#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define DATA_LENGTH 66
#define BUFFER_SIZE 6
//bool 타입 사용
typedef int bool;
enum { false, true, empty };

int i, chk, run, last;
int buffer[BUFFER_SIZE];
bool frozen[BUFFER_SIZE];
FILE *ifp, *ofp;
char* output[20];

void new_run() {
	sprintf(output, "RUN%d.txt", ++run);
	ofp = fopen(output, "w+");

	for (i = 0; i < BUFFER_SIZE; i++)
		if (frozen[i] != empty) 
			frozen[i] = false;
}

int main() {
	int min_idx;
	//랜덤 파일 생성
	FILE* datap = fopen("random.txt", "w+");
	
	srand(time(NULL));
	for (i = 0; i < DATA_LENGTH; i++) 
		fprintf(datap, "%d ", (rand() % 100 + 1));
	fclose(datap);
	
	run = 0;
	new_run();
	ifp = fopen("random.txt", "r+");
	for (i = 0; i < BUFFER_SIZE; i++)
		if (fscanf(ifp, "%d", &buffer[i]) == EOF)
			frozen[i] = empty;
	while (1) {
		min_idx = -1;
		chk = 0;
		for (i = 0; i < BUFFER_SIZE; i++) {
			if (frozen[i] != false) {
				if(frozen[i] == empty) chk++;
			}
			else if (min_idx == -1 || buffer[min_idx] > buffer[i])
				min_idx = i;
		}

		if (min_idx == -1) {
			fclose(ofp);
			if (chk >= BUFFER_SIZE) {
				fclose(ifp);
				break;
			}
			new_run();
			continue;
		}
		else {
			fprintf(ofp, "%d ", buffer[min_idx]);
			last = buffer[min_idx];
			if ((fscanf(ifp, "%d", &buffer[min_idx])) == EOF)
				frozen[min_idx] = empty;
			else if (last > buffer[min_idx]) frozen[min_idx] = true;
		}
	}
	
}