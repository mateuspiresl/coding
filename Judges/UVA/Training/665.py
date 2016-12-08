class struct: pass

cases = input()

for c in xrange(cases):
	raw_input()

	raw_in = raw_input().split()
	n_coins = int(raw_in[0])
	n_weightings = int(raw_in[1])

	# print 'case: ' + str(c)
	# print '\tn_coins: ' + str(n_coins)
	# print '\tn_weightings: ' + str(n_weightings)

	# Vars
	coins = [ False for i in xrange(n_coins) ]
	weightings = []

	for w in xrange(n_weightings):
		raw_in = raw_input().split()

		weighting = struct()
		weighting.n_coins = int(raw_in.pop(0))
		weighting.left = [ int(coin) - 1 for coin in raw_in[: weighting.n_coins] ]
		weighting.right = [ int(coin) - 1 for coin in raw_in[weighting.n_coins :] ]
		weighting.signal = raw_input()

		# print '\t\tn_coins: ' + str(weighting.n_coins)
		# print '\t\tleft: ' + str(weighting.left)
		# print '\t\tright: ' + str(weighting.right)
		# print '\t\tsignal: ' + weighting.signal
		# print ''

		# Processing =
		
		if weighting.signal == '=':
			for coin in weighting.left:
				coins[coin] = True
			for coin in weighting.right:
				coins[coin] = True
		else:
			weightings.append(weighting)

	# Cases where the coins are light and heavy
	coins_cases = [ list(coins), list(coins) ]

	for weighting in weightings:
		if weighting.signal == '<':
			for coin in weighting.left:
				coins_cases[0][coin] = True
			for coin in weighting.right:
				coins_cases[1][coin] = True
		else:
			for coin in weighting.left:
				coins_cases[1][coin] = True
			for coin in weighting.right:
				coins_cases[0][coin] = True

	# print 'coins_cases[0]: ' + str(coins_cases[0])
	# print 'coins_cases[1]: ' + str(coins_cases[1])

	false_coin = [0] * len(coins_cases)

	for i_case in xrange(len(coins_cases)):
		coins_case = coins_cases[i_case]

		for i_coin in xrange(len(coins_case)):
			if not coins_case[i_coin]:
				if false_coin[i_case] == 0:
					false_coin[i_case] = i_coin + 1
				else:
					false_coin = 0
					break

		if false_coin == 0:
			break

	if false_coin != 0:
		if false_coin[0] > 0 and false_coin[1] > 0:
			if false_coin[0] == false_coin[1]:
				false_coin = false_coin[0]
			else:
				false_coin = 0
		else:
			false_coin = false_coin[0] + false_coin[1]
	
	# Break line
	if c > 0: print ''

	print false_coin