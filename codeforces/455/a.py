f, l = input().split()

def hey(f, l):
    s = f[0]
    for i in f[1:]:
        if i < l[0]:
            s += i
        else:
            s += l[0]
            return s
    s += l[0]
    return s


print(hey(f,l))