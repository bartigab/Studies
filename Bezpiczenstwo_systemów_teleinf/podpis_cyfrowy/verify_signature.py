from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding, rsa
import base64
import sys

if len(sys.argv) < 3:
    print("Użycie: python verify_signature.py <plik_z_danymi> <plik_z_podpisem>")
    sys.exit(1)

data_filename = sys.argv[1]
sig_filename = sys.argv[2]


with open("rsa_pub.pem", "rb") as f:
    public_key = serialization.load_pem_public_key(f.read())


with open("rsa_priv.pem", "rb") as f:
    private_key = serialization.load_pem_private_key(f.read(), password=None)


try:
    pub_from_priv = private_key.public_key().public_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PublicFormat.SubjectPublicKeyInfo
    )
    pub_from_file = public_key.public_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PublicFormat.SubjectPublicKeyInfo
    )
    if pub_from_priv != pub_from_file:
        print("Klucz publiczny NIE pasuje do klucza prywatnego")
        sys.exit(1)
    else:
        print("Klucze RSA są zgodne")
except Exception as e:
    print(f"Błąd przy sprawdzaniu kluczy:{e}")
    sys.exit(1)


with open(data_filename, "rb") as f:
    data = f.read()
print("Dane wejściowe:", data)

with open(sig_filename, "rb") as f:
    signature = f.read()
print("Podpis (base64):", base64.b64encode(signature).decode())

#oblicznaie skrótu SHA3-256
digest = hashes.Hash(hashes.SHA3_256())
digest.update(data)
hash_val = digest.finalize()
print("Hash SHA3-256:", hash_val.hex())


try:
    public_key.verify(
        signature,
        hash_val,
        padding.PKCS1v15(),
        hashes.SHA3_256()
    )
    print("Podpis poprawny")
except Exception:
    print("Podpis niepoprawny!!!")
