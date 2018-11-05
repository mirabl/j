#!/bin/python3

import math
import os
import random
import re
import sys

from collections import *



# Complete the maximumPeople function below.
def maximumPeople(p, x, y, r):
    # Return the maximum number of people that will be in a sunny town after removing exactly one cloud.
    m = len(y)
    coveredBy = defaultdict(list)
    print(p)
    print(x)
    print(y)
    print(r)
    cities = [(coo, pop) for pop, coo in zip(p, x)]
    cities.sort()
    # print('cities', cities)
    clouds = [(yi - ri, yi + ri) for yi, ri in zip(y, r)]
    clouds.sort()
    # print('clouds', clouds)
    firstPossibleCity = 0
    currentCloud = 0
    while currentCloud < m and firstPossibleCity < n:
        # print(coveredBy)
        cloud = clouds[currentCloud]
        # print('cloud', cloud)
        # print('fPC', firstPossibleCity)
        firstPossiblityCityX = cities[firstPossibleCity][0]
        if firstPossiblityCityX < cloud[0]: # can't cover
            # print('cant cover')
            firstPossibleCity += 1
        else:
            # add all covered
            # print('can cover')
            currentCity = firstPossibleCity
            while currentCity < n and cities[currentCity][0] >= cloud[0] and cities[currentCity][0] <= cloud[1]:
                # print('innn')
                coveredBy[currentCity].append(currentCloud)
                # print(coveredBy[currentCity])
                currentCity += 1
            currentCloud += 1
    # print('covB', coveredBy)
    citiesWithOneCloud = [x for x in coveredBy if len(coveredBy[x]) == 1]
    # print('ciwoc', citiesWithOneCloud)
    scoreCloud = defaultdict(int)
    for city in citiesWithOneCloud:
        scoreCloud[coveredBy[city][0]] += cities[city][1]
    # print('scorecloud', scoreCloud)
    l = [(scoreCloud[x], x) for x in scoreCloud]
    l.sort()
    l.reverse()
    gain = 0
    if len(l) > 0:
        gain = l[0][0]
    popAlreadySunny = sum([cities[x][1] for x in range(len(cities)) if x not in coveredBy])
    return gain + popAlreadySunny
    
if __name__ == '__main__':

    n = int(input())

    p = list(map(int, input().rstrip().split()))

    x = list(map(int, input().rstrip().split()))

    m = int(input())

    y = list(map(int, input().rstrip().split()))

    r = list(map(int, input().rstrip().split()))

    result = maximumPeople(p, x, y, r)

    print(result)