#!/usr/bin/env python3
import sys
import glob

if len(sys.argv) == 1:
    filenames = glob.glob('./[0-9].*')
else:
    filenames = sys.argv[1:]

for f in filenames:
    for l in open(f):
        t = l.strip().split('\t')
        if len(t) != 2:
            print(f if len(sys.argv[1:]) > 1 else '' + 'Error: ', t)
