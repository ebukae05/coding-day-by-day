def get_number():
    number = int(input("Put number here: "))
    return number

def is_prime(number):
    is_prime = True
    if number > 1:
        for divisor in range(2, number):
            if (number % divisor) == 0:
                is_prime = False
                break
    return is_prime

def prime_up_to(n):
    primes = []
    for number in range(2,n + 1):
        if is_prime(number):
            primes.append(number)
    return primes

def nth_prime(n):
    counter = 0
    number = 1
    while counter < n:
        number += 1
        if is_prime(number):
            counter += 1
    return number

def prime_factors(n):
    factors = []
    primes = prime_up_to(n)
    for i in primes:
        while n % i == 0:
            factors.append(i)
            n //= i
        if n == 1:
            break
    return factors

if __name__ == "__main__":
    num = get_number()             
    if is_prime(num):
        print(num, "is prime")
    else:
        print(num, "is not prime")
    primes_up_to_num = prime_up_to(num)
    print("Primes up to", num, ":", primes_up_to_num)
    nth = nth_prime(num)
    print("The", num, "th prime is:", nth)
    fact = prime_factors(num)
    print("Prime factors of", num, ":", fact)
