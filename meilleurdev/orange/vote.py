#!/usr/local/bin/python3
# 
# #*******
#* Read input from STDIN
#* Use echo or print to output your result, use the /n constant at the end of each result line.
#* Use:
#*      local_print (variable ); 
#* to display simple variables in a dedicated area.
#* ***/
import sys
from collections import *
import heapq 
import itertools

sys.setrecursionlimit(1500)

def dprint(*args):
	print(args)



lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))

N = len(lines) - 1
M = []
for line in lines[1:]:
	row = [int(x) for x in line.split(' ')]
	M.append(row)

dprint(M)
'''
maxcost = 0

def ccost(p):
	global M
	c = 0
	for i in range(len(p)):
		dprint('i=', i, M[p[i]][p[i]], M[p[i]][p[(i+1) % len(p)]])
		#if p == [0, 3, 1, 2]:
	#		import pdb; pdb.set_trace()
		c += M[p[i]][p[i]]
		c += M[p[i]][p[(i+1) % len(p)]]
		
	return c

for pe in itertools.permutations(list(range(1, N))):

	p = [0] + list(pe)
	cost = ccost(p)
	dprint('p=', p, 'c=', cost)
	maxcost = max(cost, maxcost)

print('maxccost', maxcost)
'''

source = 0
visited = [source]
remain = set(range(1, N))
d = [M[source][i] for i in range(N)]
dprint(d)
for i in range(N - 1):
	vmax = None
	for v in remain:
		if vmax is None or d[v] > d[vmax]:
			vmax = v
	remain.remove(vmax)
	visited.append(vmax)
	for w in remain:
		d[w] = max(d[w], d[vmax] + M[vmax][w])
	dprint(d)