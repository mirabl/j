#!/usr/bin/env python3
import sys

for f in sys.argv[1:]:
    for l in open(f):
        t = l.strip().split('\t')
        if len(t) != 2:
            print('Error: ', t)
