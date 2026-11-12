
from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad

key = b'12345678'

msg = input("Enter message: ")

# Encryption
cipher = DES.new(key, DES.MODE_ECB)
encrypted = cipher.encrypt(pad(msg.encode(), 8))

print("Encrypted:", encrypted.hex())

# Decryption
decipher = DES.new(key, DES.MODE_ECB)
decrypted = unpad(decipher.decrypt(encrypted), 8)

print("Decrypted:", decrypted.decode())
