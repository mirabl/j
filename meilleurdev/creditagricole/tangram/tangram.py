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

debug = True

def dprint(*args):
    if debug:
	    print(args)

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))

pieces = []
for line in lines[1:]:
	t = line.split(' ')
	pieces.append((t[0], int(t[1]), int(t[2])))



dprint(pieces)
n = len(pieces)

