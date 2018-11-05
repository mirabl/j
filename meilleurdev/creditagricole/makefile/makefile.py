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

sys.setrecursionlimit(15000)

debug = False

def dprint(*args):
    if debug:
	    print(args)

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))

G = defaultdict(list)
modified = lines[0]
for i in range(int(lines[1])):
	child = lines[2 + 2 * i].split(' ')[0]
	parents = lines[2 + 2 * i + 1].split(' ')
	for parent in parents:
		G[parent].append(child)

dprint(G)

res = []
visited = set()
def dfs(root):
	global res
	if root in visited:
		return
	visited.add(root)
	res.append(root)
	for child in G[root]:
		dfs(child)

dfs(modified)

res = res[1:]

print(len(res))
print('\n'.join(res))





	