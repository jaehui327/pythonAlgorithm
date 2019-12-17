def bruteForce(p,t,k):
  M = len(p)
  N = len(t)
  i = k
  j = 0
  while i < N and j < M:
    if t[i] != p[j]:
      i = i-j
      j = -1
    i += 1
    j += 1
  if j == M:
    return i-M
  else:
    return i

pattern = 'mailto:'
text = '''<ul> <li> <a href="mailto:gdhong@hanmail.net">Gildong Hong</a> <li> <a
href="mailto:gsjang@yahoo.co.kr">Gilsan Jang</a> <li> <a
href="mailto:yhkim@naver.com">Younghee Kim</a> <li> <a
href="mailto:cslee@gmail.com">Cheolsu Lee</a> </ul>'''

M = len(pattern)
N = len(text)
K = 0
while True:
  pos = bruteForce(pattern, text, K)
  K = pos + M
  if K < N:
    # print('패턴이 나타난 위치 : ', pos)
    l = pos + M
    while(text[l] != '\"'):
        print(text[l], end='')
        l += 1
    print()
  else :
    break
# print('스트링 탐색 종료')