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

'''
Entrée

Ligne 1 : un entier H compris entre 6 et 1000, représentant le nombre de lignes de la grille.
Ligne 2 : un entier L compris entre 6 et 1000, représentant le nombre de colonnes de la grille.
Lignes 3 à H+2 : une ligne de la grille représentée par une chaîne de L caractères. Les caractères de la ligne sont soit * (une mine), soit . (case vide), soit x (position du clic initial ; ce caractère apparaît exactement une fois dans la grille).

Sortie

Un entier, représentant le nombre de cases que le premier clic va dévoiler sur la grille (en incluant la case du premier clic).
'''


def dprint(*args):
    if debug:
	    print(args)

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))

G = lines[2:]
nrows = len(G)
ncols = len(G[0])

rowx, colx = -1, -1
for row in range(nrows):
	for col in range(ncols):
		if G[row][col] == 'x':
			rowx = row
			colx = col



def dev(row, col):
	if G[row][col] == '*' or (row, col) in visited:
		return 0
	visited.add((row, col))
	allempty = True
	for r in range(row - 1, row + 2):
		for c in range(col - 1, col + 2):
			if r < 0 or r >= nrows or c < 0 or c >= ncols:
				continue
			if G[r][c] == '*':
				allempty = False
	v = 0
	if allempty:
		for r in range(row - 1, row + 2):
			for c in range(col - 1, col + 2):
				if r < 0 or r >= nrows or c < 0 or c >= ncols:
					continue
				v += dev(r, c)
	return 1 + v

visited = set()

res = dev(rowx, colx)
print(res)
