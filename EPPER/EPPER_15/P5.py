# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

#프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
def solution(user_input) :
	ans = ''
	first_char = user_input[0]
	flag = first_char
	tmp = 0
	if first_char == '1':
		ans += '1'
	for s in user_input:
			if flag == s:
				tmp += 1
			else: # 0->1, 1->0
				flag = s
				ans += chr(tmp+64)
				tmp = 1
	ans += chr(tmp+64)
	return ans
	
user_input = input()
print(solution(user_input))
