import random
import math

def euclides(a,b):
    if b == 0:
        return a
    return euclides(b, a%b)  

def euclides_ext(a,b):
    if a == 0 : 
        return b, 0, 1
            
    gcd, x1, y1 = euclides_ext(b%a, a)
    x = y1 - (b//a) * x1
    y = x1
    
    return gcd, x, y

def exp_Mod(a, x, n):
    if x == 0:
        return 1
    elif x % 2 == 0:
        t = exp_Mod(a, x / 2, n)
        return (t * t) % n
    else:
        t = exp_Mod(a, x - 1, n)
        return (t * (a % n)) % n

def es_compuesto(a,n,t,u):
    x = exp_Mod(a, u, n)
    if x == 1 or x == n - 1:
        return False
    for i in range(1, t + 1):
        x = exp_Mod(x, 2, n)
        if x == n - 1:
            return False
    return True

def miller_rabin(n,s):
    t = 0
    u = n-1
    while u % 2 == 0:
        t += 1
        u //=2
    for j in range (s):
        a = random.randrange(2,n-1)
        if es_compuesto(a, n, t, u):
            return False
    return True

def random_bits (b):
    n = random.randint(2,pow(2,b)-1)
    m = pow(2,b-1) + 1
    n = n | m
    return n

def randomgen_primos(b):
    n = random_bits(b) 
    while miller_rabin(n, 4) == False:
        n += 2
    return n

def gen_primos(n):
    s = 40
    if n % 2 == 0:
        n += 1
    else:
        n = (n + 1) - (n % 2)
    while miller_rabin(n,s) == False:
        n += 2
    return n

def gen_fi(a,b):
    return (a-1)*(b-1)


def gen_e(a):
    e = random.randint(2,a)
    while (euclides(e,a) != 1 ):
        e = random.randint(2,a)
    return e

def gen_d(a,b):

    l, m ,n= euclides_ext(a,b)
    return m % b


p = randomgen_primos(4)
q = randomgen_primos(4)
n = p * q
fi = gen_fi(p,q)
e = gen_e(fi)
d = gen_d(e,fi)

print("p = ", p)
print("q = ", q)
print("n = ", n)
print("fi = ", fi)
print("e = ", e)
print ("d = ",d)
