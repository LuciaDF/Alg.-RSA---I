import resource
def cifrar (a,b,c):
    return resource.exp_Mod(a, b, c)

def descifrar(a,b,c):
    return resource.exp_Mod(a, b, c)


p = resource.randomgen_primos(32)
q = resource.randomgen_primos(32)
n = p * q
fi = resource.gen_fi(p,q)
e = resource.gen_e(fi)
d = resource.gen_d(e,fi)
m = resource.randomgen_primos(32)

print("p = ", p)
print("q = ", q)
print("n = ", n)
print("ϕ(n) = ", fi)
print("e = ", e)
print ("d = ",d)

print(cifrar(m,e,n))
print(descifrar(m,d,n))

