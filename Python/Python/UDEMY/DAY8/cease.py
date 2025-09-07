alpha = list(chr(n + 97) for n in range(26))
def encrypt():
    mess = input("Enter the message: ")
    message = list(mess)
    index = []
    for k in range(len(message)):
        index.append(alpha.index(message[k]))
    shift = int(input("Enter the shift number: "))
    if shift>26:
        shift %= 26
    shifted_alpha = alpha[shift:] + alpha[:shift]
    encrypted_message = []
    for j in range(len(message)):
        encrypted_message.append(shifted_alpha[index[j]])
    print("Encrypted message:")
    for i in range(len(encrypted_message)):
        print(encrypted_message[i],end='')
def decrypt():
    mess = input("Enter the message: ")
    message = list(mess)
    index = []
    for k in range(len(message)):
        index.append(alpha.index(message[k]))
    shift = int(input("Enter the shift number: "))
    if shift>26:
        shift %= 26
    shifted_alpha = alpha[-shift:] + alpha[:-shift]
    decrypted_message = []
    for j in range(len(message)):
        decrypted_message.append(shifted_alpha[index[j]])
    print("Decrypted message:")
    for i in range(len(decrypted_message)):
        print(decrypted_message[i],end='')
while True:
    ask = input("\nType 'encode' to encrypt, 'decode' to decrypt, or '0' to stop: ")
    if ask == 'encode':
        encrypt()
    elif ask == 'decode':
        decrypt()
    elif ask == '0':
        break
