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

debug = True

def dprint(*args):
	global debug
	if debug:
		print(args)

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))

N = len(lines) - 1
M = []
for line in lines[1:]:
	t = [int(x) for x in line.split(' ')]
	M.append(t)

dprint(M)
edges = []
for i in range(N):
	for j in range(N):
		if i == j:
			continue
		edges.append((M[i][j], i, j))

edges.sort(reverse=True)
dprint(edges)

def canReach(fm, to, visited):
	global M
	if fm in visited:
		return False
	if to == fm:
		return True
	visited.add(fm)
	for j, w in enumerate(M[fm]):
		if w > 0:
			if canReach(j, to, visited):
				return True
	return False

'''
for edge in edges:
	dprint('looking at', edge)
	i = edge[1]
	j = edge[2]
	M[i][j] = 0
	M[j][i] = 0
	visited = set()
	if canReach(i, j, visited):
		dprint('can reach')
	else:
		dprint('can not reach')
		print(edge[0])
		sys.exit(0)
'''

T = list(range(N))

def dounion(i, j):
	global T
	T[dofind(i)] = dofind(j)

def dofind(i):
	global T
	if T[i] != i:
		T[i] = dofind(T[i])
	return T[i]

def finished():
	global T
	return len(set([dofind(i) for i in range(N)])) == 1

for edge in edges:
	dprint('T', T)
	dprint('looking at', edge)
	i = edge[1]
	j = edge[2]
	ti = dofind(i)
	tj = dofind(j)
	if ti != tj:
		dprint('adding edge')
		dounion(i, j)
		if finished():
			print(edge[0])
			sys.exit(1)
