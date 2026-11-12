data = input("Enter 4 data bits: ")

# Positions: 1, 2, 4 are parity bits
# Positions: 3, 5, 6, 7 are data bits

code = ['0'] * 8

code[3] = data[0]
code[5] = data[1]
code[6] = data[2]
code[7] = data[3]

# Calculate even parity
code[1] = str(int(code[3]) ^ int(code[5]) ^ int(code[7]))
code[2] = str(int(code[3]) ^ int(code[6]) ^ int(code[7]))
code[4] = str(int(code[5]) ^ int(code[6]) ^ int(code[7]))

print("Hamming Code:", ''.join(code[1:]))

# Receiver side
received = input("Enter received code: ")

r = ['0'] + list(received)

# Calculate syndrome
s1 = int(r[1]) ^ int(r[3]) ^ int(r[5]) ^ int(r[7])
s2 = int(r[2]) ^ int(r[3]) ^ int(r[6]) ^ int(r[7])
s4 = int(r[4]) ^ int(r[5]) ^ int(r[6]) ^ int(r[7])

error = s1 + s2 * 2 + s4 * 4

print("Error Position:", error)

if error != 0:
    r[error] = '1' if r[error] == '0' else '0'
    print("Error Corrected")
else:
    print("No Error")

print("Corrected Code:", ''.join(r[1:]))
