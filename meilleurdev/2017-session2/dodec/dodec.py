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

'''
Entrée
Ligne 1 : un entier impair N compris entre 5 et 51 représentant la taille de la grille.

Sortie
N lignes comprenant N caractères représentant la grille avec les dodécagones empilés. Les dodécagones empilés sont de dimension N, N-2, ..., jusqu'à 3. Le plus grand est situé en dessous. Les cases vides sont représentées par le caractère . et les dodécagones sont remplis alternativement de caractères * et #. Le plus grand est rempli de caractères *, puis le suivant est rempli de caractères #, puis le suivant de caractères * et ainsi de suite. 
'''


debug = False

def dprint(*args):
    if debug:
	    print(args)

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))




N = int(lines[0])

G = []

def pprint(G):
	for row in G:
		print(''.join(row))

for row in range(N):
	r = []
	for col in range(N):
		r.append('.')
	G.append(r)		
		
dprint(G)

symbol = '*'


def coosq(side, N):
	centerrow, centercol = N // 2, N // 2
	v = (side - 1) // 2
	return (centerrow - v, centerrow + v, centercol - v, centercol + v)

for side in range(N, 2, -2):
	(rowfm, rowto, colfm, colto) = coosq(side, N)

	for row in range(rowfm, rowto + 1):
		for col in range(colfm, colto + 1):
			if (row, col) in ((rowfm, colfm), (rowfm, colto), (rowto, colfm), (rowto, colto)):
				continue
			G[row][col] = symbol
	if symbol == '*':
		symbol = '#'
	else:
		symbol = '*'

pprint(G)