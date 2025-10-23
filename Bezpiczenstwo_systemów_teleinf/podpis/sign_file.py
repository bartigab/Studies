from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding
import sys
import base64

if len(sys.argv) < 2:
    print("Użycie: python sign_file.py <plik_do_podpisu>")
    sys.exit(1)

input_filename = sys.argv[1]
sig_filename = input_filename + ".sig"

# priv key
with open("rsa_priv.pem", "rb") as f:
    private_key = serialization.load_pem_private_key(f.read(), password=None)

with open(input_filename, "rb") as f:
    data = f.read()
print("Dane wejściowe:", data)

# obliczanie hashu SHA3-256
digest = hashes.Hash(hashes.SHA3_256())
digest.update(data)
hash_val = digest.finalize()
print("Hash SHA3-256:", hash_val.hex())

signature = private_key.sign(
    hash_val,
    padding.PKCS1v15(),
    hashes.SHA3_256()
)
print("Podpis (base64):", base64.b64encode(signature).decode())

with open(sig_filename, "wb") as f:
    f.write(signature)

print(f"Podpis zapisany jako {sig_filename}")
