"""

ip��ַ��Ч��
1��ʹ��input��ȡ�û�����
2���ж��û������Ƿ���� .

"""
adress = "111.222.333"
print(adress.replace(".", "[.]"))


=================================================

"""

�ж�ĳһ��ֵ�Ƿ��� ������ĳ����֮�ͣ�������뷵�����ǵ�ֵ���±�

"""
def twoSum(nums, target):
    pass

def high():
    pass





=================================================
"""

����һ���ƣ�ÿ�����϶�д��һ��������

��ʱ������Ҫѡ��һ������ X��ʹ���ǿ��Խ������ư���������ֳ� 1 �������飺

ÿ�鶼��?X?���ơ�
�������е����϶�д����ͬ��������
�������ѡ�� X >= 2 ʱ����?true��

X���������������ָ���

ʾ�� 1��
���룺[1,2,3,4,4,3,2,1]
�����true
���ͣ����еķ����� [1,1]��[2,2]��[3,3]��[4,4]
ʾ�� 2��
���룺[1,1,1,2,2,2,3,3]
�����false
���ͣ�û������Ҫ��ķ��顣
ʾ�� 3��
���룺[1]
�����false
���ͣ�û������Ҫ��ķ��顣
ʾ�� 4��

���룺[1,1]
�����true
���ͣ����еķ����� [1,1]
ʾ�� 5��

���룺[1,1,2,2,2,2]
�����true
���ͣ����еķ����� [1,1]��[2,2]��[2,2]

��ʾ��

1 <= deck.length <= 10000
0 <= deck[i] <?10000

"""
# �ҳ�X --- ��XΪ���� ��XΪż��
# ���� --- ���ֳ������� != len(list) / X


class Deck(object):
    def partition(self,list, size):
        return [list[i:i + size] for i in range(0, len(list), size)]


    def find_X(self, decks):
        X_list = 0
        for deck in decks:
            X = 0
            for i in range(len(decks) - 1):
                if deck == decks[i]:
                    X = X + 1
                    X_list = max(X_list, X)
        # return X_list
        if X_list % 2 == 0:
            if len(decks) % 2 != 0:
                return False
            else:
                decks.sort()

                # list = [decks[i:i + X_list] for i in range(len(decks) // X_list)]
                list = [decks[i:i + X_list] for i in range(0, len(decks), X_list)]
                print(list)

        if X_list % 2 != 0:

            if len(decks) % 2 == 0:
                return False
            else:
                print("right")



first = Deck()
print(first.find_X([1,2,3,1,2,3,1,2,3,1,2,3]))

class Solution(object):
    def hasGroupsSizeX(self, deck):
        count = collections.Counter(deck)
        N = len(deck)
        for X in xrange(2, N+1):
            if N % X == 0:
                if all(v % X == 0 for v in count.values()):
                    return True
        return False

deckk = Solution()
deckk.hasGroupsSizeX([1,2,3,1,2,3,1,2,3,1,2,3])

=================================================

 def shitou(S, J):
    return len([i for i in S if i in J])


print(shitou(["f", "i","s" ,"h"], ["h","i","s","h"]))
