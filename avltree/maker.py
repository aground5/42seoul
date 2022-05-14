import random

file = open("AVL.in", "w")

list = []
numrange = 1000
numcnt = 1000

for i in range(numcnt) :
	while True:
		candidate = random.randrange(numrange)
		if not candidate in list :
			list.append(candidate)
			break
for i in range(numcnt) :
    file.write("I " + str(list[i]) + "\n")

file.close()