#!/bin/python3

import sys

c = {}


def passwordCracker(passwords, attempt):
    n = len(attempt)
    M = [[]] + [None] * n
    for i in range(n):
        if M[i] is None:
            continue
        for password in passwords:
            if attempt[i:].startswith(password):
                M[i + len(password)] = M[i] + [password]
        
    if M[n] is not None:
        return ' '.join(M[n])
    else:
        return 'WRONG PASSWORD'
        

if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        n = int(input().strip())
        passw = input().strip().split(' ')
        attempt = input().strip()
        result = passwordCracker(passw, attempt)
        print(result)
