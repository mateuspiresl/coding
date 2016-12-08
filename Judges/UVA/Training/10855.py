def rotate(matrix):
	rotated = []
	size = len(matrix)

	for col in xrange(size):
		rotated.append([ matrix[row][col] for row in xrange(size - 1, -1, -1) ])

	return rotated

def print_matrix(matrix):
	for row in matrix:
		print row


while True:
	# Input

	raw_in = raw_input().split()
	biggest_size = int(raw_in[0])
	smallest_size = int(raw_in[1])

	if biggest_size <= 0 and smallest_size <= 0: break

	biggest = []
	for i in xrange(biggest_size):
		biggest.append(list(raw_input()))

	smallest = []
	for i in xrange(smallest_size):
		smallest.append(list(raw_input()))

	# print 'biggest'
	# print_matrix(biggest)

	# Process

	matches = [0] * 4

	for i in xrange(4):
		if i > 0: smallest = rotate(smallest)
		
		# print 'smallest rotated ' + str(i * 90)
		# print_matrix(smallest)

		for row in xrange(biggest_size - smallest_size + 1):
			for col in xrange(biggest_size - smallest_size + 1):
				supposed = True

				for row_offset in xrange(smallest_size):
					if supposed:
						for col_offset in xrange(smallest_size):
							if biggest[row + row_offset][col + col_offset] != smallest[row_offset][col_offset]:
								supposed = False
								break

				if supposed: matches[i] += 1

	print ' '.join([ str(match) for match in matches ])