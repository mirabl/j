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
import copy

sys.setrecursionlimit(15000)

debug = True

def dprint(*args):
    if debug:
	    print(args)

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))

heights = [int(x) for x in lines[1:]]
heights.sort()
n = len(heights)
small = heights[:n//2]
big = heights[n//2:]

i = 0
j = 0
r = []
while i < len(small) or j < len(big):
	if i < len(small):
		r.append(small[i])
		i += 1
	if j < len(big):
		r.append(big[j])
		j += 1
	
print(' '.join([str(x) for x in r]))


