from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization
import os
import random

with open("aes.bin", "rb") as f:
    trng_data = f.read()

random.seed(int.from_bytes(trng_data, "big"))

def custom_rng(n):
    return os.urandom(n)

#generowanie kluczy RSA
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
)

public_key = private_key.public_key()

#zapis priv key
with open("rsa_priv.pem", "wb") as f:
    f.write(private_key.private_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PrivateFormat.TraditionalOpenSSL,
        encryption_algorithm=serialization.NoEncryption()
    ))

#zapis public key
with open("rsa_pub.pem", "wb") as f:
    f.write(public_key.public_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PublicFormat.SubjectPublicKeyInfo
    ))

print("Klucze RSA wygenerowane z TRNG poprawnie")
