n = int(input())
primes = []
super_primes = []
num = 2
index = 1
flag = True
while len(super_primes) < n:
    is_prime = True
    for p in primes:
        if num % p == 0:
            is_prime = False
            break
    if is_prime:
        primes.append(num)
        flag = True
        for i in range(2, index):
            if index%i==0:
                flag = False
                break
        if flag and index>1:
            super_primes.append(num)
        index += 1
    num += 1

print(primes[-1])