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


bruteforce?
