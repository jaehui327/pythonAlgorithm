class node:
    def __init__(self, key=None, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right

class Dict:
    x = p = node

    z = node(key=0, left=0, right=0)
    z.left = z
    z.right = z
    head = node(key=0, left=0, right=z)

    def search(self, search_key):
        x = self.head.right
        while x != self.z:
            if x.key == search_key:
                print()
                return x.key
            if x.key > search_key:
                x = x.left
                print('left', end=' ')
            else:
                x = x.right
                print('right', end=' ')
        print()
        return -1

    def insert(self, v):
        x = p = self.head
        while (x != self.z):
            p = x
            if x.key == v:
                return
            if x.key > v:
                x = x.left
            else:
                x = x.right
        x = node(key=v, left=self.z, right=self.z)
        if p.key > v:
            p.left = x
        else:
            p.right = x

import random
import time
N = 8

key = [2, 1, 7, 8, 6, 3, 5, 4]
s_key = [2, 1, 7, 8, 6, 3, 5, 4]
d = Dict()
for i in range(N):
    d.insert(key[i])

while(True):
    a = int(input('탐색 키 입력: '))
    if a == 999:
        print('프로그램 종료')
        exit(1)
    else:
        result = d.search(a)
        if result == -1 or result != a:
            print('탐색 실패')
            print()
        else:
            print('탐색 성공')
            print()