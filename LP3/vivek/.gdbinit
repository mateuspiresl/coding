define _check
	printf "b/e %d %d: %d %d\n", begin, end, array[begin], array[end]
	printf "l/r %d %d: %d %d\n", left, right, array[left], array[right]
	x/8dw array
end