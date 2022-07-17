==================================================
"""

���ֲ���

"""
def bin_find(item, list):
    up = len(list) - 1
    low = 0
    while low <= up:
        mid = (up + low) // 2
        guess = list[mid]
        if guess == item:
            return mid
        elif guess > item:
            up = mid - 1
        else:
            low = mid + 1

    return None

print(bin_find(7,[1,3,4,5,7,9,12,23,45,54,67]))

====================================================
"""

����ȳ������ݽṹΪջ /����֮��Ӧ�����Ƚ��ȳ��Ķ��У�

һ���߶���ջ������   һ����������---һ�ն�������
�ڵݹ�����Ҫ����
1����Ϊ��ֹ�Ļ���
2������õ�ջ�Կ�������
3������ʱ���߼�

�ݹ�СĿ�꣺���ŷ������㷨
"""


def countdown(i):
    if i == 0:
        print(0)
    else:
        print(i)
        countdown(i-1)

countdown(5)

def number(i):
    if i == 1:
        return 1
    else:
        result = i * number(i - 1)
    return result
print(number(5))

def sum(arr):
    #�����Ҷ��ˣ�������ֹ�����ã�����������������
    if len(arr):
        return arr[0] + sum(arr[1:])
    else:
        return 0

print(sum([1,2,3,4,5,7,8]))
============================================
"""

��̬�滮�㷨
��һ������������Ա��ֽ�Ϊ��������ɢ��������ʱ��ʹ�ö�̬�滮��⣬��ȡ���ƶ�����Ϳɷֽ���������Ż�ָ������
���裺
1����̬�滮��Ҫһ������ һ����Ԫ���ֵ��ʲô�����Ż�ֵ��  ������ν�������⻮��Ϊ�����⣨��Ԫ������������

"""

==============================================
"""

��������㷨
��Ա���Ȩ�ص�ͼ���Ǽ�Ȩͼ����ֻ��������������������С��·��

"""
from collections import deque


# ʵ�� ͼ
picture = {}
picture["you"] = ["bob", "alice", "claire"]
picture["bob"] = ["anuj", "peggy",]
picture["alice"] = ["prggy"]
picture["claire"] = ["thom", "jonny"]


picture["anuj"] = []
picture["penny"] = []
picture["jonny"] = []
picture["thom"] = []
picture["alice"] = []

def person_is_seller(name):
    return name[-1] == "m"


def search(name):
    search_deque = deque()
    search_deque += picture[name]
    while search_deque:
        person_first = search_deque.popleft()
        #�ڴ� person_first ��Ϊһ��ֵ�����������ж�
        if person_is_seller(person_first):
            print(person_first + " is a mongo seller!")
            return True
        #�ڴ� person_first ֻ��Ϊ����������Ӧֵ
        else:
            search_deque += picture[person_first]
    return False

search("you")
==============================================
"""

��������   ĸ�����׼��

qiuck�����ʵ����ʵ����   �Ƚϴ�С+����λ��

"""

#������Ϊ����ʱ�������鵥�����в���
def quicksort(arr):
    if len(arr) < 2:
        return arr
    else:
        pivot = arr[0]
        less = [i for i in arr[1:] if i <=pivot]
        greater = [i for i in arr[1:] if i > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)
print(quicksort([1,2,4,5,6,4,1,4,6,83,21,3,5,35]))
============================================
"""

�ҿ�˹�����㷨
��� �����޻�����Ȩͼ�������Ȩ����С��·��
�㷨ԭ��   ����õ�һ�ݶӸ��ڵ������һ�ݶӸ��ڵ��Ȩ�أ�
            Ȼ�����������ݶӵ���СȨ�ز��Ե�һ�ݶӵ�ĳ�ڵ�Ϊ�µĸ��ڵ㣬ֱ���յ�
���岽�裺
1���ұ��ݶӽ�����һ�ݶ���СȨ�صĽڵ�
2�������ھӼ��---����ǰ����һ�ݶӽ�֮���̵�·��������¿���
3,��ͬһ�ݶӵĽڵ��ظ���ֱ����ý�����һ�ݶӵ�·�������¸��ڵ���Ȩ��ֵ��
�����ݶӸ��ڵ�·��Ȩ�ضԱ� + ���£�---�ظ�

"""
#ʵ���޻�����Ȩͼ
graph = {}
graph["start"] = {}
graph['start']["a"] = 6
graph["start"]["b"] = 2

graph["a"] = {}
graph["a"]["end"] = 1

graph["b"] = {}
graph["b"]["a"] = 3
graph["b"]["end"] = 5

graph["end"] = {}

#ÿһ�ݶӵĽڵ����Ȩ���б�
infinity = float("inf") #�������
costs = {}
costs["a"] = 6
costs["b"] = 2
costs["end"] = infinity

#ÿһ�ݶӵĸ��ڵ��б�
parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["end"] = None

#��¼�Ѿ�������Ľڵ�
processed = []


def find_lowest_cost_node(costs):
    """�ҵ���С·��

    :param costs: Ȩ��
    :return:
    """
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        global processed
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node


def diKeSiTeLa(costs):
    """�ҿ�˹�����㷨"""
    node = find_lowest_cost_node(costs)
    while costs is not None:
        cost = costs[node]
        neighbors = graph[node]   #�ھ�����һ���б����
        for n in neighbors.keys():
            new_cost = cost + neighbors[n]
            if costs[n] > new_cost:
                costs[n] = new_cost
                parents[n] = node
        processed.append(node)
        node = find_lowest_cost_node(costs)


diKeSiTeLa([costs])

================================================
"""

̰���㷨  --- ���NP��ȫ����
����ÿһ���������˾ֲ����Ž�ʱ������ܻ�ýӽ�ȫ�����Ž�Ľ��


"""
# #���ϲ���
# fruits = ["a", "b", "c"]
# vegetables = ["a","d", "e", "f"]
# fruit = set(fruits)
# vegetable = set(vegetables)
# print(vegetable-fruit)

states_neededs = ["mt", "wa", "or", "id", "nv", "ut", "ca", "az"]
states_needed = set(states_neededs)
stations = {}
kones = ["id", "nv", "ut"]
ktwos = ["wa", "id", "mt"]
kthrees = ["or", "nv", "ca"]
kfours = ["nv", "ut"]
kfives = ["ca", "az"]
kone = set(kones)
ktwo = set(ktwos)
kthree = set(kthrees)
kfour = set(kfours)
kfive = set(kfives)
stations["kone"] = kone
stations["ktwo"] = ktwo
stations["kthree"] = kthree
stations["kfour"] = kfour
stations["kfive"] = kfive
final_stations = set()
while states_needed:
    best_station = None
    states_covered = set()

    for station,states_for_station in stations.items():
        covered = states_needed & states_for_station
        if len(covered) > len(states_for_station):
            best_station = station
            states_covered = covered
    states_needed -= states_covered
    final_stations.add(best_station)
    del stations[best_station]
# print(final_stations)
print(final_stations)
==========================================
# """
#
# ѡ������
#
# """
#
# def findSmall(arr):
#     small = arr[0]
#     small_index = 0
#     for i in range(len(arr)):
#         if arr[i] < small:
#             small = arr[i]
#             small_index = i
#     return (small_index, small)
#
# def selectionSelect(arr):
#     newArr = []
#     for i in range(len(arr)):
#         small_index = findSmall(arr)[0]
#         newArr.append(arr.pop(small_index))
#     return newArr
#
# print(selectionSelect([1,34,5,6,7,43,8,5,4.78]))
def findSmall(arr):
    small = arr[0]
    small_index = 0
    for i in range(len(arr)):
        if arr[i] < small:
            small = arr[i]
            small_index = i
    return small_index

def seletion(arr):
    newArr = []
    for i in range(len(arr)):
        small_index = findSmall(arr)
        newArr.append(arr.pop(small_index))
    return newArr

print(seletion([123,4,5,756,85,38,22]))