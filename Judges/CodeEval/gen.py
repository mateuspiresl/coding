import sys

alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def rev(n):
	un = n
	
	k = n % 26
	if k == 0:
		k = 26

	ret = str(alpha[k - 1])

	if un <= 26:
		return ret

	n = (n - k) /26
	k = n % 26

	ret = str(alpha[k - 1]) + ret

	if un <= 702:
		return ret

	if (k == 0):
		k = 26

	n = (n - k) / 26
	k = n % 26

	ret = str(alpha[k - 1]) + ret

	return ret

showAll = True
hey = 1

for k in range(26):
	n = k + 1

	if hey != n:
		print('HEEY ' + str(hey) + '  ' + str(n))
	hey += 1

	g = str(alpha[k])

	if g != rev(n) or showAll:
		sys.stdout.write('0 0 ' + str(k + 1) + ' : ')
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

		if g != rev(n) or showAll:
			sys.stdout.write('0 ' + str(j + 1) + ' ' + str(k + 1) + ' : ')
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

			if g != rev(n) or showAll:
				sys.stdout.write(str(i + 1) + ' ' + str(j + 1) + ' ' + str(k + 1) + ' : ')
				sys.stdout.write(str(n) + ' : \t')
				print(g + ' / ' + rev(n))
