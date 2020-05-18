#include "pg4_Dictionary.h"
#include <conio.h>

void help() {
	printf("[사용법] i-추가 d-삭제 w-단어검색 m-의미검색 p-사전출력 q-종료 =>");
}

int main() {
	char command;
	char word[80];
	char meaning[200];
	Dictionary Hantree;
	Dictionary Engtree;
	do{
		help();
		command = getche();
		printf("\n");
		switch(command) {
			case 'i' : 	printf(" > 삽입 단어:"); gets(word);
						printf(" > 단어 설명:"); gets(meaning);
						Engtree.insert( new BinaryNode(word, meaning));
						break;
			case 'd' : 	printf(" > 삭제 단어:"); gets(word);
						if(Engtree.searchWord(word) != NULL) {
							Hantree.remove(Engtree.search(word)->getmeaning());	
							Engtree.remove(word);
						}
						else {
							printf("영한 사전에 등록되지 않은 단어입니다.\n");
						}
						break;
			case 'p' : 	
						printf(" > 영한 사전");
						Engtree.printAllWords();
						Engtree.CreateHan(&Hantree);
						printf(" > 한영 사전");
						Hantree.printAllWords();
						break;
			case 'w' : 	printf(" > 단어 검색 :"); gets(word);
						Engtree.searchWord(word);
						break;
			case 'm' :	printf(" > 의미 검색 :"); gets(word);
						Hantree.searchWord(word);
						break; 
		}
	}while(command != 'q');
}
