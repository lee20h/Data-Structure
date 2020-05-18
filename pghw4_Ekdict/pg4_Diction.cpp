#include "pg4_Dictionary.h"
#include <conio.h>

void help() {
	printf("[����] i-�߰� d-���� w-�ܾ�˻� m-�ǹ̰˻� p-������� q-���� =>");
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
			case 'i' : 	printf(" > ���� �ܾ�:"); gets(word);
						printf(" > �ܾ� ����:"); gets(meaning);
						Engtree.insert( new BinaryNode(word, meaning));
						break;
			case 'd' : 	printf(" > ���� �ܾ�:"); gets(word);
						if(Engtree.searchWord(word) != NULL) {
							Hantree.remove(Engtree.search(word)->getmeaning());	
							Engtree.remove(word);
						}
						else {
							printf("���� ������ ��ϵ��� ���� �ܾ��Դϴ�.\n");
						}
						break;
			case 'p' : 	
						printf(" > ���� ����");
						Engtree.printAllWords();
						Engtree.CreateHan(&Hantree);
						printf(" > �ѿ� ����");
						Hantree.printAllWords();
						break;
			case 'w' : 	printf(" > �ܾ� �˻� :"); gets(word);
						Engtree.searchWord(word);
						break;
			case 'm' :	printf(" > �ǹ� �˻� :"); gets(word);
						Hantree.searchWord(word);
						break; 
		}
	}while(command != 'q');
}
