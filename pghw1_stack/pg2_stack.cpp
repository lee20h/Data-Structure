// 201610674 컴퓨터공학부 이영훈 

#include "ArrayStack2.h"
#pragma warning(disable: 4996)

inline int precedence(char op) {
   switch (op) {
   case '(': case ')': return 0;
   case '+': case '-': return 1;
   case '*': case '/': return 2;
   }
   return -1;
}

void infix2Postfix(FILE* infp) {
   FILE* outfp = fopen("output.txt", "w+");
   char c, op, temp;
   double val;
   ArrayStack st;
   while ((c = fgetc(infp)) != EOF) {
      if ((c >= '0' && c <= '9')) {
         ungetc(c, infp);
         fscanf(infp, "%lf", &val);
         printf("%4.1f ", val);
         fprintf(outfp, "%4.1f ", val);
      }
      else if (c == '(') st.push(c);
      else if (c == ')') {
         while (!st.isEmpty()) {
            op = st.pop();
            if (op == '(') break;
            else {
               printf("%c", op);
               fprintf(outfp, "%c ", op);
            }
         }
      }

      else if (c == '+' || c == '-' || c == '*' || c == '/') {
         while (!st.isEmpty()) {
            op = st.peek();
            if (precedence(c) <= precedence(op)) {
               printf("%c", op);
               fprintf(outfp, "%c ", op);
               st.pop();
            }
            else break;
         }
         st.push(c);
      }
   }
   while (!st.isEmpty()) {
		temp = st.pop();
		printf("%c", temp);
		if( temp!='(')
			fprintf(outfp, "%c ", temp);
      }
   
   printf("\n");
   fclose(outfp);
}

double calcPostfixExpr(FILE* fp) {
   char c;
   OperandStack st;
   double val;
   while ((c = getc(fp)) != EOF) {
      if (c == '+' || c == '-' || c == '*' || c == '/') {
         double val2 = st.pop();
         double val1 = st.pop();
         switch (c) {
         case '+': st.push(val1 + val2); break;
         case '-': st.push(val1 - val2); break;
         case '*': st.push(val1 * val2); break;
         case '/': st.push(val1 / val2); break;
         }
      }
      else if (c >= '0' && c <= '9') {
         ungetc(c, fp);
         fscanf(fp, "%lf", &val);
         st.push(val);

      }
   }
   return (st.pop());
}

int main() {
   FILE* infp = fopen("input.txt", "a+");

   infix2Postfix(infp);
   fclose(infp);

   FILE* outfp = fopen("output.txt", "r");
   double res = calcPostfixExpr(outfp);
   printf("\n결과 : %4.1f\n", res);

   fclose(outfp);
   return 0;

}
