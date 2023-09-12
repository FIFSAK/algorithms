n = int(input())
primes = []
num = 2
while len(primes) < n:
    is_prime = True
    for p in primes:
        if num % p == 0:
            is_prime = False
            break
    if is_prime:
        primes.append(num)
    num += 1

print(primes[-1])
