

import math
import sys
low = 1
high = 1e9
mid = 0
while(low <= high):
    mid = math.floor((high+low)/2)
    print("Q "+str(mid));
    sys.stdout.flush()
    x = input()
    if x == '<':
        high = mid - 1
    elif x =='>':
        low = mid + 1
    else:
        break