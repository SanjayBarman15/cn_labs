
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad

key = b'0123456789abcdef'

msg = input("Enter message: ")

# Encryption
cipher = AES.new(key, AES.MODE_ECB)
encrypted = cipher.encrypt(pad(msg.encode(), 16))

print("Encrypted:", encrypted.hex())

# Decryption
decipher = AES.new(key, AES.MODE_ECB)
decrypted = unpad(decipher.decrypt(encrypted), 16)

print("Decrypted:", decrypted.decode())
