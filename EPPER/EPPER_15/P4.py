# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
def solution(user_input):
	user_input = list(map(int, user_input.split()))
	list_sum = sum(user_input)
	for i in range(8):
		for j in range(i+1, 9):
			if (list_sum - user_input[i] - user_input[j]) == 100:
				user_input.remove(user_input[j])
				user_input.remove(user_input[i])
				ans = " ".join(map(str, user_input))
				return ans
				
	
user_input = input()
print (solution(user_input))
