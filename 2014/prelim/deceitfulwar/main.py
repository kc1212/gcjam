
def compare_list(l1, l2):

	l = []
	for i,j in zip(l1,l2):
		if i > j:
			l.append(1)
		else:
			l.append(-1)
	return l


def dwar(w1, w2):

	w1.sort()
	w2.sort()
	
	while len(w1) > 0:
		l = compare_list(w1, w2)
		lset = list(set(l))

		if len(lset) == 1 and lset[0] == 1:
			return len(w1)

		w1.pop(0)
		w2.pop(-1)
	return 0


def war(w1, w2):

	score = 0
	w2.sort()
	for weight1 in w1:
		optimal_weight = choose_block(w2, weight1)
		if weight1 > optimal_weight:
			score += 1
		w2.pop(w2.index(optimal_weight))
	return score


def choose_block(w, b):
	# we expect w to be sorted
	if b > w[-1]:
		# use the minimum
		return w[0]

	# use the minimum that's higher than b
	l = [x if x > b else 100 for x in w]
	l.sort();
	return l[0]


def main():
	T = int(raw_input())

	for i in range(T):
		n = int(raw_input())
		w1 = [float(a) for a in raw_input().split(" ")]
		w2 = [float(a) for a in raw_input().split(" ")]
		ww1 = w1[:] # copy list
		ww2 = w2[:] # copy list
		w1.sort()
		w2.sort()
		print("Case #%d: %d %d" % (i+1, dwar(w1, w2), war(ww1, ww2)))
		


if __name__ == "__main__":
	main()
