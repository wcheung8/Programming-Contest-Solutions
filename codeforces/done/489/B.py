n = int(input())

arr = []
for i in range(n):
	arr.append(input())

arr = sorted(arr,key=lambda s: len(s))

for i in range(len(arr)-1):
	if arr[i+1].find(arr[i]) == -1:
		print("NO")
		exit()

print("YES")
for i in arr:
	print(i)