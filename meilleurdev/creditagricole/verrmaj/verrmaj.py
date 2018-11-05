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

sys.setrecursionlimit(10500)

def dprint(*args):
	print(args)

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))

word = lines[1]

shift = 7
lock = 13

cache = {}

def mT(w, locked):
	if (w, locked) in cache:
		return cache[(w, locked)]
	if len(w) == 0:
		return 0
	islow = w[0].lower() == w[0]
	if islow and not locked or (not islow and locked):
		cache[(w, locked)] = 10 + mT(w[1:], locked)
	else:
		cache[(w, locked)] = 10 + min(shift + mT(w[1:], locked), lock + mT(w[1:], not locked))
	
	return cache[(w, locked)]

dprint(mT(word, False))