from Crypto.Util.number import getPrime, bytes_to_long
from math import gcd

PRIME_BITS = 512
E = 3
FLAG = b"REDACTED"
M = bytes_to_long(FLAG)

def generate_modulus(bits):
    p = getPrime(bits)
    q = getPrime(bits)
    return p * q
    
while True:
    n1 = generate_modulus(PRIME_BITS)
    n2 = generate_modulus(PRIME_BITS)
    n3 = generate_modulus(PRIME_BITS)

    if gcd(n1, n2) != 1 or gcd(n1, n3) != 1 or gcd(n2, n3) != 1:
        continue

    c1 = pow(M, E, n1)
    c2 = pow(M, E, n2)
    c3 = pow(M, E, n3)

    if pow(M, E) < n1 * n2 * n3:
        break

with open("output.txt", "w") as f:
    f.write(f"e = {E}\n\n")
    f.write(f"n1 = {n1}\n")
    f.write(f"c1 = {c1}\n\n")
    f.write(f"n2 = {n2}\n")
    f.write(f"c2 = {c2}\n\n")
    f.write(f"n3 = {n3}\n")
    f.write(f"c3 = {c3}\n")

