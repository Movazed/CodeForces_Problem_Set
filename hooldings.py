#!/bin/python3

import sys

# Complete the 'getMaxEarnings' function below.
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. STRING schedule
#  2. INTEGER k
#  3. INTEGER fixedPay
#  4. INTEGER bonus
def getMaxEarnings(schedule, k, fixedPay, bonus):
    n = len(schedule)
    zeros_total = schedule.count('0')
    ones = n - zeros_total

    # If there are no workdays initially
    if ones == 0:
        used = min(k, n)
        if used == 0:
            return 0
        # One run if we flip at least one day
        return fixedPay * used + bonus * (used - 1)

    # Count runs of '1' and collect lengths of internal zero gaps
    gaps = []
    runs = 0
    i = 0
    while i < n:
        if schedule[i] == '1':
            runs += 1
            while i < n and schedule[i] == '1':
                i += 1
        else:
            l = i
            while i < n and schedule[i] == '0':
                i += 1
            r = i
            # Internal gap if bounded by '1' on both sides
            if l > 0 and r < n and schedule[l - 1] == '1' and schedule[r] == '1':
                gaps.append(r - l)

    # Use flips: first fill smallest internal gaps to merge runs
    k_use = min(k, zeros_total)
    merges = 0
    used = 0
    gaps.sort()
    for g in gaps:
        if k_use >= g:
            k_use -= g
            used += g
            merges += 1
        else:
            break

    # Use remaining flips to extend runs (no further change to run count)
    used += min(k_use, zeros_total - used)

    newOnes = ones + used
    newRuns = runs - merges

    # Earnings = fixedPay * totalOnes + bonus * (ones that have a previous day worked)
    return fixedPay * newOnes + bonus * (newOnes - newRuns)


if __name__ == '__main__':
    data = []
    for line in sys.stdin:
        t = line.strip()
        if t != '':
            data.append(t)

    schedule = data[0]
    k = int(data[1])
    fixedPay = int(data[2])
    bonus = int(data[3])

    result = getMaxEarnings(schedule, k, fixedPay, bonus)
    print(result)
