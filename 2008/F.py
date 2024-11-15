MOD = 10**9 + 7

def mod_inv(x, mod):
    return pow(x, mod-2, mod)

def expected_value(n, arr):
    S = sum(arr) % MOD
    S2 = sum(x * x for x in arr) % MOD
    

    P = (S * S - S2) % MOD
    P = (P * mod_inv(2, MOD)) % MOD

    Q = (n * (n - 1) // 2) % MOD
    

    result = (P * mod_inv(Q, MOD)) % MOD
    
    return result


t = int(input())
results = []
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    results.append(expected_value(n, arr))


for result in results:
    print(result)
