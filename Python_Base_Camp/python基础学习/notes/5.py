"""

�����Ĳ������ͣ�
 1����ѡ���� 2��Ĭ�ϲ��� 3���ɱ���� 4������(�޶�)�ؼ��ʲ��� 5���ؼ��ʲ���


"""


def f1(a, b, *args, **kw):
    print(a, b, args, kw)

f1(1, 2, 12, 35, 12, 65, x=2, y ="3")


def f2(a, b, *, right1, right2, **kw):
    pass


def f3(a, b, *args, city, hobby, **kws):
    print(a, b, args, "city:", city, "hobby:", hobby, kws)

# ʹ������ؼ���ʱ���ò���������key
# �ƶ���֮�������еĹؼ��ֲ�������Ҫkey
f3(1, 2, 3, 42, city ="beijing", hobby = "badmindon", k = "kfc", l = "lol")
# ��һ�ַ�ʽ������������ú���
# list1 = [1,12,3,4,5,7]
# list2 = {"first": 1, "second": 2, "third": 3, "fourth":4}
tuple = (1,12,3,4,5,7)
dict = {"city": "beijing", 'hobby': "badmindon", "first": 1, "second": 2, "third": 3, "fourth":4}
f3(*tuple, **dict)


=========================================================
"""

��������
����򵥺������еļ򵥹���

lambda ����������ʽ  == f��x�� = x+2...

"""
list1 = map(lambda x: x * x, [1,2,3,4,5,6,7,8,9,10])
print(list(list1))
list2 = map(lambda x: x + 2 , [1,2,3,4,5])
# r = list(list2)
# print(r)
r = next(list2)
r1 =next(list2)
print(r1)


list_4 = [1,2,3,4,5,6,7,8,9,0,12]
list_3 = [i for i in list_4 if i%2 == 0]
list_10 = list(filter(lambda x:x%2 == 0, range(1, 20)))
print(list_10)


==================================================
"""

1,�ַ������ַ���֮��/����������֮�䣨��ͬ����û��ϵ����ֵΪ1��0���ֱ���Խ��в���
  �����ַ��������ֽ��в���������ý��У�����ת������

2��ʲô�Ǻ�����
    �Ѿ���װ�õĴ��룬����ֱ�ӵ���

3����¼����
�ַ������� = input(����ʾ���ݡ�)
ע�⣺���صĶ����ַ�������

4������ת������
int()
float()
str()
set()---ת��Ϊ����

5�������������̨��ʹ��
��� - ���� - F8

6�������ĸ�ʽ�����
����ʽ��������%�ŵ��ַ���������ʽ��������
  %s %d %f  ("" % ����1)
            ("" % (����1�� ����2))
  % x d С����ǰ��xλ��ԭ������xλ��0ռλ��ȫ������xλ��ʧЧ��
  % y f С�������yλ

7������������
�ؼ��ֺͱ�ʶ��
��ʶ�� --- �������ͺ���������Ҫ����֪�壩
�ؼ��� --- �ڲ��Ѿ���ǰʹ�õı�����
������ ���շ������� �����շ� С�շ壩   �µ�������ĸ��д


"""

# import keyword

# print(keyword.kwlist)



# ---������ת��
price= float(input("���뵥��"))
weight = float(input("��������"))
# price = float(price_str)
# weight = float(weight_str)

money = price * weight
print("%12f  ,%.02f  ,%0.2f" % (money,money,money))

========================================================
"""

if���


"""

import random

num = {}
num[1] = "ʯͷ"
num[2] = "����"
num[3] = "��"

def SJB():
    player = input("����ʯͷ��")
    i = random.randint(1,3)
    computer = num[i]


    if computer == "ʯͷ":
        print("�Է�����---[%s]" % computer)
        if player == "ʯͷ":
            print("ƽ��")
        elif player == "����":
            print("lose")
        elif player == "��":
            print("win")
    elif computer == "����":
        print("�Է�����---[%s]" % computer)
        if player == "ʯͷ":
            print("win")
        elif player == "����":
            print("ƽ��")
        elif player == "��":
            print("lose")
    else:
        print("�Է�����---[%s]" % computer)
        if player == "ʯͷ":
            print("lose")
        elif player == "����":
            print("win")
        elif player == "��":
            print("ƽ��")

SJB()
==================================================
"""
���ɱ������ܣ��ַ�����������Ԫ��
�ɱ�����б�

�й��б�

�б�ĳ��÷�����
�� append("str")  insert(index, "str") extend([list])
ɾ del list[index]/ del(list[index])   remove[value]  pop[index]
�� list[index] = new_value
�� sort() sort(reverse = True) reverse()
�� len(list)   --- һ ��õĳ���Ϊ n(���һ������ֵ) + 1
                   �� �Ҵ�0��ʼ������
   count(value)



Ԫ��ĳ��÷�����
�� count() len()

Ԫ�����б�֮���ת����  ���ҽ�����Ԫ�����б�֮��ת��
list��tuple��
tuple��list��

�йؼ��� --- �������ظ�Ԫ��
set(list) = {} Ҫͨ����������������
�ɽ��н������������Ĳ���  &�� | ��


�й��ֵ�
�ֵ�ĳ��÷�����
�� dic[key] = value keyԭ������  dic[key] = setdefault(key, value) ���Ŀ���  dic.update(new_dic)
�� dic[key] = value keyԭ��������
ɾ del dic[key]/del(dic[key])   dic.pop[key]
�� len()---��ֵ�Ե�����


�й��ַ���
�ַ����ĳ��÷���
���������
һ�ࣺis��  isspace(��ʶ��Ҳ�ǿո��ַ�) isalnum() isalpha() isdecimal() istitle()
���ࣺ�������滻  startswith("str") endswith("str")
        ����-1find/rfind/����index/rindex("str", start = 0, end = len(str))
        replace(old_str, new_str, num = string.count(old_str))
���ࣺ��Сдת�� capitalize()/title()/upper()  lower()
���ࣺ�ı����� ljust(width)/rjust(width) center(width)
���ࣺȥ���հ��ַ� lstrip/rstrip/strip
���ࣺ���������  partition(str)-ǰ�к� rpartition(str)
                split(str="str", num = number) - һstrΪ�ָ����֣�num+1���ַ���
                Ψһ�ĺϲ� join(seq)


�ַ�������Ƭ
���䶼������ҿ���
������Ϊ��ʱ���ַ����͵����ɵ�����һ������

����
len() in / not in / + / *
"""
string = "hello,myfriend"
string1 = "123456789n"
print("|" + string.center(50) + "|")

str = string.join(string.partition("llo"))
print(str)

print(string[6:4:-1])

===================================================
"""


������
��������Ҫ���������ж����Ե��б��е��ǲ�˵��һ����һ������next�����������о�û���������
���������� �б�����ʽ�ķ����Ÿ�ΪԲ���� --- ����ʽ�ͱ����������
��ѭ��ʱͨ����ӡ��� �� ��ѭ��ʱͨ��next(generator)һ�����ط�����һ��ֵ��ԭ������ genetator�е� yield ʱ�ʹ浵���أ�
�������Ĵ������� ��1 ����ʽ��forѭ��  2 ���ú��� ������ʹ��yield next



������
�����ڵ������������ͽ���������
������һ���ǵ���������������һ����������

"""

from collections import Iterable
from collections import Iterator

print(isinstance(iter("abc"), Iterator))
=======================================================
"""

���������θ�ϰ   --- �����������ò�û�������е���ô�����ֻ�����ǡ���ͣ�����ܣ���ʵ��һ�ֿռ�Ķ�̬����
����������һ�� �����ź�����ֵ�� ���������(���Լ���)
�����궼���Ի�����н�����ǣ���ʹ�ú����γɽ׶��Է�ֵ�Ĺ���(ɥʧһ���Է�ֵ�Ĺ���)

��������generator������ ��һ���������б�����㷨һ�߶��Լ���Ļ���
                        ��Ϊ�����꣬���������˴���ȫ�����Ŀ����� ��������������ʵ�֣�
������������������㷨�ϼ�ʱ---1���б�����ʽ��װ
         ��������㷨�ϸ���ʱ---2��ͨ��������װ   --- �γɽ׶��Է�ֵ�Ĺ���

��ӡ������1, print(next())�����һ����ֵ
         2,ͨ��ѭ��print


"""
# first_step : create a generator
list_ex = [1,2,3,4,5,6,7,8,9]
list_1 = [i for i in list_ex]
generator_1 = (i for i in list_ex)
print(list_1)
# ���´���ķ��ؽ��Ϊ��StopIteration
# print(list(generator_1))
# print(next(generator_1))

# ���´���ķ��ؽ��Ϊ��
# 1
# [2, 3, 4, 5, 6, 7, 8, 9]
# �ɵó�next����--- have the ability to get and pop a value!
print(next(generator_1))
print(list(generator_1))

# second_step 쳲���������


def fib(max):
    """����������쳲���������"""
    n, a, b = 0, 0, 1
    while n < max:
        print(b)
        # ע���ֵ��ֵ���  ==> t[0],t[1] = (b, a+b) ��Ԫ�鱣�����ݣ�
        a, b = b, a + b   # �˴���a+b ֵ�����ܵ�ǰ��a��b������Ӱ�죡
        n += 1
    return


def fib_2(max):
    n, a, b  = 0, 0, 1
    while n < max:
        yield(b)
        a, b = b ,a + b
        n += 1
    return

generator_2 = fib_2(5)
# print(next(fib_2(5)))
print(list(generator_2))


# �˽���ϰ��


def sanjiao():
    """ʹ����������������������㷨"""
    # n = 1
    # L = [0] + [1] + [0]
    # while n < low:
    #     yield L
    #     n += 1
    #     L = [L[i] + L[i + 1] for i in range(len(L))]

    # L = [1]
    # while 1:
    #     yield [0] + L + [0]
    # ���������[0]���������������³���Ӧ���º��ټ���
    #     L = [L[i] + L[i + 1] for i in range(len(L) - 1)]

    L = [1]
    while 1:
        yield L
        L = [0] + L + [0]
        L = [L[i] + L[i + 1] for i in range(len(L) - 1)]


generator_YangHuiTriangle = sanjiao()
for i in range(100):
    print(str(next(generator_YangHuiTriangle)).center(150))

=====================================================
"""

װ����
�ڴ��붯̬���������ӹ��ܵķ�ʽ�� ����װ����decorator


"""


# װ��(����)��
def log(func):
    def wraper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw)
    return wraper()

@log
def now():
    print("2019-09-20")

now()
# @log
# def sum(l):
#     sum = 0
#     for i in l:
#         sum = sum + i
#
# print(log(sum([1,8,5,5,6,9])))
======================================================
"""

 �������б�����ʽ

�������ڵ�����---�������е�ÿһ�����ݶ�����һ�β���
                ����б�����б�Ԫ���ֵ���в������ø��Եķ�����Ҳ���ñ��������
                һ��ȫ�� ������ȡ

�б�����ʽ
�ܽ᣺����һ���б���˵����һ����Ҫ���Ԫ��(���������) �ڶ���ÿ��Ԫ����ʲô������ʽ
    �б�����ʽĬ���ں�append��������һ���б� ---for..in.. / if / append(��ʽ)
    ʹ����ѭ�����˫�������Ի��ȫ����


"""

list = []
for i in range(1,11):
    if i % 2 == 0:
        list.append(str(i) + "*" + str(i))
print(list)

list_2 = [i * i for i in range(1,11) if i%2 == 0]
print(list_2)

#
list_3 =[m + n for m in "ABC" for n in "abc"]
del(list_3[0])
# del list_3[0]
print(list_3)

list_4 = [m*n for m in range(1,10) for n in range(1,10)]
print(list_4)

# ���б�����ʽ ���б������ֵ����ʽ
dic = {"a":1, "b":2, "c":3, "d":5}
del(dic["a"])
del dic["b"]
print(dic)
print(dic)

#��Ҫ���б��е��ַ����ǽ��в��� --- ��������ȡ
list_5 = ["Tom", "Peter", "Bob"]
print([l.lower() for l in list_5])

#���б��в��������ַ�������������������ʱ ---
list_6 = ["Tom", 18, "man"]
# num = str(list_6[1])
# print(num)
# print([i.upper() for i in list_6])
print([str(i).upper() for i in list_6])
==================================================
"""

���غ���   --- ���γɱհ��Ľṹ��������ز����������ڷ��صĺ�����
��һ����������һ�������Ǿ��Ǳհ�����
�հ������к����Ĳ���ֻ���ڷ��غ���ʱ������Ϊ�����������������ں����е���
����������һ��Ҫ����ʹ�ú����仯����������Ҫʹ�����º����󶨵�ǰֵ

��������һ������Ϊ���������ҷ���һ�������ĸ߼�����

"""


# def lazy_sum(*args):
#     def sum():
#         ax = 0
#         for n in args:
#             ax = ax + n
#         return ax
#     return sum
# print(sum([1,2,3,4,5]))
# print(lazy_sum(1,2,3,4,5,6,7))

# # ����ʾ�����ڱհ��д���ʹ�øı������
# def count_error():
#     fs = []
#     for i in range(1,4):
#         def f():
#             return i * i
#         fs.append(f)
#
#     return fs
#
# f1, f2, f3= count_error()
# print(f1)
# print(f1())
# print(f2())
# print(f3())
#
# def count():
#     # ��Ȼ�հ�ֻ�ܷ���һ������ֵ����ô��ÿһ������һ���հ���ÿһ��ֵ����Ϊ�����ص�����ֵ
#     def f(j):
#         def g():
#             return j * j
#         return g
#     fs = []
#     for i in range(1,4):
#         fs.append(f(i))
#     return fs
#
# f1, f2, f3 = count()
# print(f1())

"""

���ñհ�����һ��������������ÿ�ε��������ص���������

"""
import time

# def countdown():
#     def count_down(count):
#         def down():
#             return count
#         return down
#
#     for i in range():
#         count -= 1
#         print(count)
#
# ft = countdown()

def countdown():
    # !!!�հ��������ͱ����޷���������
    # t = 1
    # def counter():
    #     t = t + 1

    # !!!�հ��п��Խ��б������У�
    s = [0]
    def counter():
        s[0] = s[0] + 1
        return s[0]
    return counter()

ft = countdown()
print(ft)


===================================================
"""

�߽׺���
��������Ϊ�������룬�ú����Ĳ�����һ������
������ --- ��һ��ָ�����ú��������� eg:abs

�߽׺���֮�� ---sorted()
��������ֵ������������еĸ��ַ�ʽ
--- Ĭ�ϣ�for...in...���������еĸ���Ԫ�� �Ƚ���key���������Ĭ��(sort)����  = sort()+map()
sorted(iterable, key = ����) eg : ����һ����ȥ���Ƚ�/������str��Ϊ��д��
"""

def add(x, y, f):
    return f(x) + f(y)
print(add(-1,-2,abs))

#----------------------------------------------------------------------------
def _add_iter():
    """����һ��3��ʼ���������� ������"""
    n = 1
    while True:
        n = n + 2
        yield n


# def _not_divisible(n):
#     """���첢����   ѡ���n�����б���"""
#     return lambda x: x % n > 0
#
# def primes():
#     """�ҳ������������������г�ȥ���ǵı���"""
#     yield 2
#     # ��������ʹ�ÿ��Խ�����Ҫ��������next����ȥ���������һ������ɾ����
#     # ʹ����������Ϊ����while��ʹ��next�� ���ֱ���(λ�ڵ�һλ) �����,ʹ֮����ɸѡ�б���
#     it = _add_iter()
#     while True:
#         n = next(it)
#         yield n
#         it = filter(_not_divisible, it)
# for n in primes():
#     if n < 1000:
#         print(n)
#     else:
#         break
#



#-------------------------------------------------------------------------
# def fnnn(x):
#     return x % 2 == 0
#
# def asd():
#     f = (i for i in range(1000))
#     while True:
#         n = next(f)
#         print(n)
#         if f:
#             break
# asd()
#
# # print(next(f))
# # print(next(f))
# # print(next(f))
# # print(list(f))

"""

����������һ��tuple��ʾѧ�����ֺͳɼ���

L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]
����sorted()�������б�ֱ���������

"""
L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]
def fnnnn(t):
    return t[0]


print(sorted(L, key= fnnnn))


def fN(t):
    return t.upper()
print(sorted(['bob', 'about', 'Zoo', 'Credit'], key=fN))


