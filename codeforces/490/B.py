
x = int(input())
s = input()

def factors(x):
    # We will store all factors in `result`
    result = []
    i = 1
    # This will loop from 1 to int(sqrt(x))
    while i*i <= x:
        # Check if i divides x without leaving a remainder
        if x % i == 0:
            result.append(i)
            # Handle the case explained in the 4th
            if x/i != i:
                result.append(int(x/i))
        i += 1
    # Return the list of factors of x
    return result

f = sorted(factors(x))
for i in f:
    s = s[:i][::-1] + s[i:]

print(s)