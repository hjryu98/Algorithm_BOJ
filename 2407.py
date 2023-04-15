n, m = map(int, input().split())
ans = div = 1
for i in range(m):
    ans *= (n - i)
    div *= (i + 1)
print(ans // div)