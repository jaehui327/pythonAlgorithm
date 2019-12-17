def encipher(p, k):
    c = ''
    for i in range(len(p)):
        a = ord(p[i])
        if a == 32: a = 64
        t = a + k
        if t > 90: t -= 27
        if t == 64: t = 32
        c += chr(t)
    return  c

def decipher(c, k):
    p = ''
    for i in range(len(c)):
        a = ord(c[i])
        if a == 64: a = 32
        t = a - k
        if t < 63: t += 27
        if t == 32: t = 64
        p += chr(t)
    return p


# plainText = 'SAVE PRIVATE RYAN'
# K = 1
# print('평 문 : ', plainText)
# cipherText = encipher(plainText, K)
# print('암호문: ', cipherText)

K = 0
while True:
    K = int(input('키 : '))
    if K == 999: break
    else:
        cipherText = input('암호문 : ')
        plainText = decipher(cipherText, K)
        print('평 문: ', plainText)
print('프로그램 종료')