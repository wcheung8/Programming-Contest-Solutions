n, k = [int(x) for x in input().split()]
x = [int(x) for x in input().split()]

ans = []
ppl = []
for i, v in enumerate(x):
	if v not in ppl:
		ppl.append(v)
		ans.append(i+1)

	if len(ans) >= k:
		print("YES")
		print(" ".join([str(x) for x in ans]))
		exit()
print("NO")