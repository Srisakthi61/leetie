// ──────────────────────────────────────────────────
// Problem  : 150. Evaluate Reverse Polish Notation
// Difficulty: Medium
// Tags     : Array, Math, Stack
// Link     : https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10492000 (beats 40%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int evalRPN(char** tokens, int tokensSize) {
int* stack = (int*)malloc(sizeof(int) * tokensSize);
int top = -1;

for (int i = 0; i < tokensSize; i++) {
char* token = tokens[i];

if ((token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') && token[1] == '\0') {
int b = stack[top--];
int a = stack[top--];

switch (token[0]) {
case '+':
stack[++top] = a + b;
break;
case '-':
stack[++top] = a - b;
break;
case '*':
stack[++top] = a * b;
break;
case '/':
stack[++top] = a / b;
break;
}
} else {
stack[++top] = atoi(token);
}
}

int result = stack[top];
free(stack);
return result;
}
