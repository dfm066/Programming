def fact(n):
	f = 1
	for  i in range(2,n+1):
		f *= i
	return f

num = fact(int(input()))
print(num)
print(sum([int(i) for i in str(num)]))
