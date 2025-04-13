import binascii

hex_str = str(input("what is the encrypted code?: "))
ascii_representation = binascii.unhexlify(hex_str).decode()
print(ascii_representation)