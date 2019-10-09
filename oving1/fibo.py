def isFibonacciNumber(n):
	a = 0
	b = 1
	while (b<n):
		temp = b
		b = b+a
		a = temp
	print (b == n)
	return b == n

i = 2
while(i<14):
	print(i, isFibonacciNumber(i))
	i += 1