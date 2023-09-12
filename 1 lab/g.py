def nth_prime(n):
    if n < 1:
        return None
    primes = []
    num = 2
    while len(primes) < n:
        is_prime = True
        for p in primes:
            if p * p > num:
                break
            if num % p == 0:
                is_prime = False
                break
        if is_prime:
            is_spuer_prime = True
            for p in primes:
                if p * p > num:
                    break
                if num % p == 0:
                    is_spuer_prime = False
                    break
            if is_spuer_prime:
                primes.append(num)
        num += 1

    return primes[-1]

n = int(input())
result = nth_prime(n)
print(result)
