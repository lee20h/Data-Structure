// 201610674 ��ǻ�Ͱ��к� �̿��� 

#include "ArrayStack.h"
#pragma warning(disable: 4996)

bool checkMatching(char* filename) {
	FILE *fp = fopen(filename, "r");
	if(fp == NULL) error("Error: ���� �������� �ʽ��ϴ�.\n");
	
	int nLine = 1;
	int nChar = 0;
	ArrayStack stack;
	char ch;
	char prech;
	bool little_open_check = false;
	bool big_open_check = false;
	bool inverse_slash_check = false;
	bool multiline_remark = false;
	bool oneline_remark = false;
	
	
	while((ch=getc(fp)) != EOF) {
		if(ch == '\n')  {
			nLine++;
		}
		nChar++;
		if (ch == '\"' && big_open_check == false) {
			big_open_check = true;
		}
		else if (ch == '\"' && big_open_check == true) {
			big_open_check = false;
		}
		if (ch == '\'' && little_open_check == false) {
			little_open_check = true;
		}
		else if (ch == '\'' && little_open_check == true) {
			little_open_check = false;
		}
				
		if (inverse_slash_check == true) {
			inverse_slash_check = false;
		}
		if (ch == '\\' && little_open_check == true) {
			if (inverse_slash_check == false) {
				inverse_slash_check = true;
			}
		}
		
		if (prech=='/' && ch=='/' && oneline_remark == false)
			oneline_remark = true;
		if (oneline_remark == true && ch=='\n')
			oneline_remark = false;
		if (prech=='/' && ch=='*' && multiline_remark == false)
			multiline_remark = true;
		if (prech=='*' && ch=='/' && multiline_remark== true)
			multiline_remark = false;
			
		prech=ch;
		
		if (little_open_check == false && big_open_check == false && oneline_remark == false && multiline_remark == false) {
			if( ch == '[' || ch == '(' || ch == '{' )
				stack.push(ch);
			else if(ch == ']' || ch == ')' || ch == '}') {
				int prev = stack.pop();
				if( (ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{') ) break;
			}
		}
	}
	fclose(fp);
	printf("[%s] ���� �˻���:\n", filename);
	if(!stack.isEmpty()) {
	
		printf("Error: �����߰�!(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	}
	else
		printf(" OK : ��ȣ�ݱ�����(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	return stack.isEmpty(); 
}

int main() {
	checkMatching("ArrayStack.h");
	checkMatching("pg1_stack.cpp");
	checkMatching("test.txt"); 
}
