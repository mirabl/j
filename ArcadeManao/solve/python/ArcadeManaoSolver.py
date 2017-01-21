#! /usr/bin/python3

import os, sys
import ArcadeManao

def init():
    default_path = os.path.join(os.getenv("HOME"), ".gettc")
    gettc_home = os.path.abspath(os.getenv("GETTC_HOME", default_path))
    include_dir = os.path.join(gettc_home, "include/python")
    sys.path.append(include_dir)

def main():
    import topcoder as tc
    with open(sys.argv[1], "r") as fi:
        input = fi.read()
        reader = tc.Reader(input)

        level = reader.next("String[]")
        reader.next()
        coinRow = reader.next("int")
        reader.next()
        coinColumn = reader.next("int")

    result = ArcadeManao.shortestLadder(level, coinRow, coinColumn)
    with open(sys.argv[2], "w") as fo:
        fo.write(tc.write(result, "int"))

if __name__ == "__main__":
    init()
    main()
