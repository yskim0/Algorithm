
# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

#프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
def solution(m, string) :
	stack = []
	for ch in string:
		if ch == '+':
			op1 = stack.pop()
			op2 = stack.pop()
			stack.append(int(op2+op1))
		elif ch == '-':
			op1 = stack.pop()
			op2 = stack.pop()
			stack.append(int(op2-op1))
		elif ch == '*':
			op1 = stack.pop()
			op2 = stack.pop()
			stack.append(int(op2*op1))
		elif ch == '/':
			op1 = stack.pop()
			op2 = stack.pop()
			stack.append(int(op2/op1))
		else:
			stack.append(int(ch))
	return stack
m = input()
string = input().split()
print(*solution(m,string))
