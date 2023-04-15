for i in range(3):
    ans = 0
    n = int(input())
    for j in range(n):
        a = int(input())
        ans += a
    if ans > 0:
        print('+')
    elif ans < 0:
        print('-')
    else:
        print('0')
