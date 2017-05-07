#!/usr/bin/env python3
import sys
import random

rand = False
filename = 'mem.csv'

if len(sys.argv) >= 1:
	filename = sys.argv[1]
if len(sys.argv) >= 2:
	rand = True

entries = []
with open(filename) as f:
	for line in f:
		t = line.strip().split(';')
		entries.append((t[0], t[1]))

i = 0
N = len(entries)
while True:
	if rand:
		i = random.randint(0, N - 1)
	else:
		i = (i + 1) % N
	entry = entries[i]
	print('{}\n'.format(entry[0]))
	try:
		x = input('>')
	except EOFError:
		print('')
		sys.exit(1)
	print('  {}\n\n\n--------------\n'.format(entry[1]))
