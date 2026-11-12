data = input("Enter 8-bit binary numbers separated by space: ").split()

# Sender side
total = 0

for x in data:
    total = total + int(x, 2)

    # Add carry
    while total > 255:
        total = (total & 255) + (total >> 8)

# One's complement
check = format(255 - total, '08b')

print("Checksum:", check)

# Receiver side
received = input("Enter received data including checksum: ").split()

total = 0

for x in received:
    total = total + int(x, 2)

    while total > 255:
        total = (total & 255) + (total >> 8)

print("Final Sum:", format(total, '08b'))

if total == 255:
    print("No Error")
else:
    print("Error Detected")
