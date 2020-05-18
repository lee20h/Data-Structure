#include <cstdio>
#include <cstring>
#pragma warning(disable:4996)
#define MAX_WORD_SIZE 40
#define MAX_MEANING_SIZE 200
class Record {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
public:
	Record(const char* w = "", const char* m = "") { set(w, m); }
	void set(const char* w, const char* m) {
		strcpy(word, w);
		strcpy(meaning, m);
	}
	int compare(Record* n) { return compare(n->word); }
	int compare(char* w) { return strcmp(w, word); }
	int compareMeaning(char* m) { return strcmp(meaning, m); }
	void display() { printf("%12s : %-40s\n", word, meaning); }
	void copy(Record *n) { set(n->word, n->meaning); }
	char* getmeaning() {
		return meaning;
	}
	char* getword() {
		return word;
	}
};
