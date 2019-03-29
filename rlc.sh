#!/bin/bash
# ./rlc.sh level
# level: 2 med, 3 hard

cat ../lc.json |jq ".stat_status_pairs | .[] | select(.status == null and .paid_only == false and .difficulty.level == $1) | .stat.question__title_slug" | tr -d '"'| sed 's|^|https://leetcode.com/problems/|' | sort -R | head -10 | xargs open
