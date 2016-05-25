import sys

alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def rev(n):
	i = n % 27
	n -= i
	if n == 0:
		return str(alpha[i])

	n /= 27
	j = n % 27
	n -= j

		#sys.stdout.write(str(i) + ' ' + str(j) + ' ' + str(k) + ' : ')
	if n == 0:
		return str(alpha[j]) + str(alpha[i])

	n /= 27
	k = n % 27

		#sys.stdout.write(str(i) + ' ' + str(j) + ' ' + str(k) + ' : ')
	
	return str(alpha[k]) + str(alpha[j]) + str(alpha[i])

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
