data = input("Enter data bits: ")
gen = input("Enter generator: ")

n = len(gen)

# Append zeros
msg = list(data + '0' * (n - 1))

# XOR division
for i in range(len(data)):
    if msg[i] == '1':
        for j in range(n):
            msg[i+j] = str(int(msg[i+j]) ^ int(gen[j]))

# Get remainder
rem = ''.join(msg[-(n-1):])

# Transmitted code
code = data + rem

print("CRC Remainder:", rem)
print("Transmitted Code:", code)

# Receiver side
received = input("Enter received code: ")
msg = list(received)

for i in range(len(received) - n + 1):
    if msg[i] == '1':
        for j in range(n):
            msg[i+j] = str(int(msg[i+j]) ^ int(gen[j]))

rem = ''.join(msg[-(n-1):])

print("Receiver Remainder:", rem)

if '1' not in rem:
    print("No Error")
else:
    print("Error Detected")
