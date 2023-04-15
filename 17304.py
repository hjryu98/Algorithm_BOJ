def test():
    for i in range(1 , n + 1):
        if check[i] == 0:
            if not v[i] or not dfs(i, 0):
                return 'NO'
    return 'YES'

def dfs(cur, prv):
    cycle = False
    if check[cur] == 1:
        return True
    check[cur] = 1
    for nxt in v[cur]:
        if nxt == prv:
            continue
        if dfs(nxt, cur):
            cycle = True

    return cycle

n, m = map(int, input().split())
v = [set() for _ in range(n + 1)]
check = [0] * (n + 1)
for i in range(m):
    a, b = map(int, input().split())
    v[a].add(b)

bi_dir = [] # 양방향 확인

for i in range(1, n + 1):
    for node in v[i]:
        if i not in v[node]:
            check[node] = 1
        else:
            if i > node:
                bi_dir.append([i, node])

v_copy = [[] for _ in range(n + 1)]
for i, j in bi_dir:
    if check[i] + check[j] == 1:
        check[i] = 1
        check[j] = 1
    elif check[i] + check[j] == 0:
        v_copy[i].append(j)
        v_copy[j].append(i)

v = [v_copy[i][:] for i in range(n + 1)]

print(test())
