import sys

alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def rev(n):
	if n <= 26:
		return str(alpha[n - 1])
	
	elif n <= 702:
		n -= 1
		k = n % 26
		j = (n - k) / 26 - 1
		
		#sys.stdout.write(str(i) + ' ' + str(j) + ' ' + str(k) + ' : ')

		return str(alpha[j]) + str(alpha[k])

	else:
		n -= 1
		k = n % 26
		n = (n - k) / 26
		j = n % 26
		n = (n - j) / 26
		i = n % 26 - 1
		
		#sys.stdout.write(str(i) + ' ' + str(j) + ' ' + str(k) + ' : ')

		try:
			return str(alpha[i - 1]) + str(alpha[j - 1]) + str(alpha[k])
		except IndexError:
			raise NameError(str(i) + ' ' + str(j) + ' ' + str(k))

hey = 1

for k in range(26):
	n = k + 1

	if hey != n:
		print('HEEY ' + str(hey) + '  ' + str(n))
	hey += 1

	g = str(alpha[k])

	if g != rev(n):
		sys.stdout.write('xx xx ' + str(k) + ' : ')
		sys.stdout.write(str(n) + ' : \t')
		print(g + ' / ' + rev(n))

offset = hey

for j in range(26):
	for k in range(26):
		n = offset + (j * 26) + k

		if hey != n:
			print('HEEY ' + str(hey) + '  ' + str(n))
		hey += 1

		g = str(alpha[j])
		g += str(alpha[k])

		if g != rev(n):
			sys.stdout.write('xx ' + str(j) + ' ' + str(k) + ' : ')
			sys.stdout.write(str(n) + ' : \t')
			print(g + ' / ' + rev(n))

offset = hey

for i in range(26):
	for j in range(26):
		for k in range(26):
			n = offset + (i * 26 * 26) + (j * 26) + k

			if hey != n:
				print('HEEY ' + str(hey) + '  ' + str(n))
			hey += 1

			g = str(alpha[i])
			g += str(alpha[j])
			g += str(alpha[k])

			if g != rev(n):
				sys.stdout.write(str(i) + ' ' + str(j) + ' ' + str(k) + ' : ')
				sys.stdout.write(str(n) + ' : \t')
				print(g + ' / ' + rev(n))