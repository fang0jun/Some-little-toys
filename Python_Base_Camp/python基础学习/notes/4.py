import plane_sprite   #---����ʱ��Ҫģ����
from plane_sprite import module_1
from plane_sprite impot *   #---����ʱ����Ҫģ����

"""

ģ�鵼��ĵ���˳���ȵ�ǰĿ¼ / ��ϵͳĿ¼  ���ʲ�Ҫ������
if __name__ == "__main__"   ֻ�ڱ��ļ��н��в���

�ļ�������ģ�鵼��ʱ������û�������Ĵ��붼�ᱻִ��һ�� // ��Ҫ������ʹ�� if __name__ == "__main__"
��ʹ��__name__����---����һϵ���ַ������ڵ�ǰִ���ļ���Ϊ__main__ �ڱ������ļ���Ϊ����ģ���ģ������

"""
========================================================
"""

��̬������
һ�ַ����ж�����̬�����ڲ�ͬ������˵����������ͨ�����������ҵ���
һ����̬���Ը�������


ʵ�ַ��������ⲿ�����˸����еķ��������Ըø��������������Ϊ���� //

���ͣ�
������Ҫ�ܶ��������һ�ַ���ʱ��ֱ�ӵ��ø�������ַ����ͺ���
�Դ����øø���������������Զ������Լ��ķ�������һ���࣬������̬��

"""


class Animal(object):
    def run(self):
        print("Animal is running")


class Dog(Animal):
    def run(self):
        print("Dog is running")

dog1 = Animal()
dog_real = Dog()


def run_twice(animal):
    animal.run()
    animal.run()

run_twice(dog1)
run_twice(dog_real)




=================================================
"""

�쳣�Ĵ���

"""

def demo1():
    return int(input("������һ��������"))

def demo2():
    return demo1()
try:
    print(demo2())

except Exception as result:
    print("δ֪���󡣡���%s" % result)
else:
    print("������������")
finally:
    print("-" * 20)
#�������쳣�����ڵ�8�У����ǰ��쳣������13�У��������У� 8 - 11 - 13
#�����쳣�Ĵ����ԣ����쳣���ݵ����������������в����쳣,�Ծ������


=======================================================
"""

�����׳��쳣   ---���������������쳣
1�������쳣����2���׳��쳣����

����
�û������û������û���������ڵ���8λ������ �׳��쳣

"""


def into():
    password = input("���������룺")
    if len(password) >= 8:
        return password
    error = Exception("���볤�Ȳ���")   # ����һ��Ԫ�飬��Ϊ�쳣������
    raise error


try:
    print(into())

except Exception as result:
    print(result)


==================================================

"""

�����쳣�Ĵ��� --- �ô���Ӱ�����ļ������У������� �׳� �쳣  ---�����ڳ����д���

�ṹ try --- except��except Exception as result�� --- else --- finally
���ڿ��ܳ���ĵط� ����try��ȡ����
���ڿ��ܳ��ֵĴ������� ����except�ռ���ͬ���͵Ĵ��� + ����except Exception as result������������
                 else������޴�����ʱִ�еĴ����
"""

try:
    num = int(input("������һ������"))
    number = 8 / num

    print(number)

except ValueError as e:
    print("������ʵʵ������һ������,��������%s" % e)
except Exception as result:
    print("δ֪���� %s" % result)

else:
    print("ִ�гɹ���������")
finally:
    print("��������Ҷ���")


=============================================================
"""
��Զ���߼����

ʵ���������ڸ���ʵ�����У��������ţ�
���������������У�����ʵ������һ�����ԣ�


ʹ��@property�������Բ��� ����Ҫ�ǲ�����鹦�ܣ�
����ֱ�ӽ��������޸�                                   ---�쵫���ܲ���ȫ
�������޸� ת�� �����޸� // �����Ե��� �ĳ� ��������     ---������ȫ����
@propertyװ�������Ǹ����һ������������Ե��õ�         ---ʹ�����Բ����ֿ��ֹ�������



ʵ�ַ���������һ�����ԵĹ�����__init__��Ϊgetter��setter������
!!!ע������!!! ��property��ķ���������Ŀ����������self.xxx �Ǹ÷������ԣ�����Ŀ�����ԣ�Ҳ��������Ŀ����������
 ��һ��getter����������ԣ�ֻ��Ҫ����@property�Ϳ����ˣ�
 ��ʱ��@property�����ִ�������һ��װ����@score.setter�������һ��setter����������Ը�ֵ�����ǣ����Ǿ�ӵ��һ���ɿص����Բ���

 ֻ�����ԣ�ֻ����getter������������setter��������һ��ֻ������

 ���ؼ̳У�
 ���̳�ͨ���Ӵ�ļ̳����Ӷ�ȷ���̳й�ϵ��ȷ���̳еĹ���
 ��̳�ͨ��������(Xxxx, YyyyMixIN, ZzzzMixIn),��ȷ���̳й�ϵ

�����ࣺ
__iter__():ʹ�෵��һ���������� ��������list ���� tuple�� def __iter__(self): return self
__getitem__():ʹ����һ���б�
__setitem__()��ʹ����һ��dict
__delitem__()��
__call__()��ʹ�ഴ�������Ķ������ֱ�Ӷ��Լ����з�������  eg: name_instance()

ö���ࣺ
from enum import Enum
ͨ����Ա���ͳ�Աֵö�ٳ��������԰�Enum�࿴��һ���ֵ䣨����name �� value��ֵ�ԣ�
                                        ��Ҳ�ɽ���__members__�ֵ仯������������
Enum���Ա���ɱȽ�(IntEnum����ԱȽ�)
����ʱ�ͺ����ֵ�ĵ��ã�������  Gender["Male"] / Gender(index) ���ó���

type() 1�����Է���һ������ 2�����б�������ʱ����Զ�̬����һ���ࣨ���������� / �̳и��� / dict(������ = �Ѱ�װ������)��

"""
from enum import Enum, unique
@unique
class Color(Enum):
    red = 1
    green = 2
    blue = 3
    yellow = 4

print(Color.red)
member = Color.red
print(member.name + " he " + str(member.value))
for i in Color.__members__.values():
    print(i)
# ��Student��gender���Ը���Ϊö�����ͣ����Ա���ʹ���ַ�����


class Gender(Enum):
    Male = 0
    Female = 1


class Students(object):
    def __init__(self, name, gender):
        self.name = name
        self.gender = gender

student = Students("MC", Gender["Male"])
print(student.gender)

# ##
class Student(object):
    count = 0

    def __init__(self, name):
        self.name = name
        Student.count += 1


wyf = Student("wyf")
wyf2 = Student("wyf")
wyf22 = Student("wyf")
print(Student.count)


class Screen(object):
    @property
    def width(self):
        return self.text1

    @width.setter
    def width(self, value):
        # if not isinstance(value, float):
        #     raise ValueError("please input a number!")
        self.text1 = value

    @property
    def height(self):
        return self.text2

    @height.setter
    def height(self, value):
        # if not isinstance(value, float):
        #     raise ValueError("please input a number!")
        self.text2 = value

    @property
    def resolution(self):
        R = self.height * self.width
        return R


screen = Screen()
screen.height = 101
screen.width = 101
print(screen.width)
print(screen.height)




===================================================
#���ú���dir() ��ʹ�ã��鿴������Ե��õķ���  ����-�������ݱ�������һ������
#�»������÷���������  __new__ __init__ __del__ __str


 #��Ĵ����������Ե�����
#�����ഴ���һ��  -- �����������䣬��ʣ� - ����-�� ���ݴʣ��̶�/�����-����  ����-����
#��Զ����̵��ص�---��װ ����������ֻ�ö���ȥ�������������ľ���ϸ�ڣ�
#������ӷ��� 1�����ڲ�ͬ�Ķ��󣬴��������ƻ���һ�� 2��������Ƿ�����������
#������������ 1�����ڲ�ͬ�������Եĵ����ǹ̶��������
#   ---����������Զ������������÷���  ---����ռ䷽��new  ---��ʼ������init(Ϊ�������ó�ʼֵ)
#   ---��init����self.xxx = xxx �����(�̶�)����
#   ---����������ǲ��̶��ģ�����������ģ���self.xxx = �β�

"""

������ʼ������
del ����֮ǰ�Զ����һ�ε��ã�������������һ�κ�Ҳ�����һ�����٣�
str ������Ĵ�ӡ���ݻ�ױ���˷�������Ҫ����һ���ַ�����

"""

class Cat(object):

    def __init__(self, name):
        self.name = name

    def eat(self):
        print("%s������"%self.name)

    def drink(self):
        print("%sҪ��ˮ" % self.name)

    def __str__(self):
        return "����Сè[%s]"%self.name

tom = Cat("Tom")
lazy_cat = Cat("LAZY_CAT")

lazy_cat.eat()
tom.drink()
print(tom)

=======================================
"""

С�����ܲ�������ϰ
#�����ͬ����ķ���һ�£�ֻ�ǲ��������Բ�ͬ ---
#�����ͬ����ķ������Ƶ��ǲ���ȫ��ͬ����ʹ�ô��������෽����д��

"""
class Person(object):
    def __init__(self, name ,height):
        #��¼�Ժȴ���
        self.count = 0
        self.name = name
        self.height = height


    def run(self):
        self.height -= 0.5
        print("[%s] ������һ�� [�ܲ��˶�]"% self.name)
        print("[%s]������ - [0. 5kg],��ʱ����Ϊ [%f]" % (self.name, self.height))
        self.count += 0.5

    def eat(self):
        self.height += 1.0
        print("[%s] ������һ�� [�Է�]" % self.name)
        print("[%s]������ + [1. 0kg],��ʱ����Ϊ [%f]" % (self.name, self.height))
        self.count -= 1

    def __del__(self):
        if self.count > 0 :
            print("����[%s]�ļ��ʼƻ��ɹ����������� [%f]"%(self.name, self.count))
        if self.count <= 0:
            print("����[%s]�ļ��ʼƻ�ʧ�������������� [%f]"%(self.name, self.count))

wangyufeng = Person("�����", 75)

====================================================
class House(object):
    def __init__(self):
        self.house_type = "�����޵к�����"
        self.house_area = 150
        self.house_freearea = 150
        self.houseitem_list = []

    def __str__(self):
        return "���ݵ��ͺ�Ϊ[%s]���������[%.3f],�����üҾ�[],ʣ�෿�����[%.3f]"%(self.house_type, self.house_area, self.house_freearea)

    #���������Ķ���Ϊ�����е�����
    def add(self, name):
        self.houseitem_list.append(name)


class HouseItem(object):
    def __init__(self, name, area):
        self.name = name
        self.item_area = area

    #���˷���ֱ�����óɼҾߵķ�����ֱ��ԭ��Ϊ���Ҿߵ�������Դ���������Ҿ���֮��
    def reduce(self):
        house.house_freearea -= self.item_area




bed = HouseItem("ϯ��˼", 4)
table = HouseItem("����ľ��",3)
house = House()
house.add(bed.name)
house.add(table.name)
bed.reduce()
table.reduce()
print(house)
=================================================
"""

��Զ���ϰ�ƻ����������ѧ����Ȼ��������python����(*^_^*)��
�������Ŀ�滮��   1���������ѧ1-4��ppt�е�֪ʶ��Ͷ���  1h
 2����ˢһ����Ŀ��  2h
 3�����濴�� - ���������1h�����֡� 4h
 4����������Զ����ѧϰ  ����
 # 5,�˽�һ��ʲô�Ǹ���Ҷ����
 # 6���ƶ������ܵļƻ���һ��Ҫ�����ʵ��Ŀ�ѧ��Ӣ��ѧϰ�ƻ�

"""
import os

print("hello")
i = os.system("cls")
===============================================
"""

ʿ��ͻ����������
�������������һ������İ����з����Ķ���ʱ

�������������壬��һ����ǹ��ʿ��������ǹ��ak47 ���ӵ����ҿ��Խ��п�ǹ���Ҳ������䵯ҩ
�ࣺ����ǹ��ǹ�Ķ���Ϊʿ��������
���ԣ��ˣ����֣��������#��ǹ����Ҫ���ö���
     ǹ�����֣���������ӵ�����

#��������ʱ��Ҫ���ǵ��ģ����õ������Ƿ��Ǳ����еģ�/���õ������Ƿ��Ƿ�װ����������  �����Ǳ�ķ��������� vs ֱ�ӵ���һ����Ķ��������
����1.0���ˣ���䵯ҩ���ӵ���������������������ӵ��������� #fire������ǹ�����
        ǹ����

"""



# #����һ�������ж���-���Դ���  ����ֱ��ʹ�������������Խ��е���                                         ------�����Ƽ��ķ�ʽ��
# #���ӷ����������ڵ�֪ʶˮƽ�޷������ö�ȫ��ĵĽ��ͺͷ��������������ǲ���ô����ͱ���ô�ã���ͷ��ͷ���壩
# class Soilder(object):
#     def __init__(self, soilder_name):
#         self.soilder_name = soilder_name
#         # self.gun = None
#     def fire(self):
#         if gun.bullet_count == 0:
#             print("�ӵ����㣬��Ҫ�ϵ�")
#             return
#         gun.bullet_count -= 10
#         print("ͻ" * 10)
#         print("[%s] ����ǹ [%s] �ӵ�ʣ�� [%d]\n"%(self.soilder_name, gun.gun_name, gun.bullet_count) )
#
#     def in_bullet(self):
#         gun.bullet_count += 30
#         print("[%s] ����ǹ [%s] �ӵ���Ŀ +30 ����[%d]\n"%(self.soilder_name, gun.gun_name,gun.bullet_count))
#
#
# class Gun(object):
#     def __init__(self, gun_name, bullet_count):
#         self.gun_name = gun_name
#         self.bullet_count = bullet_count
#
# gun = Gun("AK47",0)
# wangyufeng =Soilder("�����")
# wangyufeng.in_bullet()
# wangyufeng.fire()

#���Զ������ж���-���Դ���  ʹ���������ת��Ϊ�����                                                          ------��Great!��
class Soilder(object):
    def __init__(self, soilder_name):
        self.soilder_name = soilder_name
        self.gun = None
    def fire(self):
        if gun.bullet_count == 0:
            print("�ӵ����㣬��Ҫ�ϵ�")
            return
        self.gun.bullet_count -= 10
        print("ͻ" * 10)
        print("[%s] ����ǹ [%s] �ӵ�ʣ�� [%d]\n"%(self.soilder_name, self.gun.gun_name, self.gun.bullet_count) )

    def in_bullet(self):
        gun.bullet_count += 30
        print("[%s] ����ǹ [%s] �ӵ���Ŀ +30 ����[%d]\n"%(self.soilder_name, self.gun.gun_name, self.gun.bullet_count))


class Gun(object):
    def __init__(self, gun_name, bullet_count):
        self.gun_name = gun_name
        self.bullet_count = bullet_count

gun = Gun("AK47",0)
wangyufeng =Soilder("�����")
wangyufeng.gun = gun
wangyufeng.in_bullet()
wangyufeng.fire()

# #��������������֮�以�����棬ֻ�ڷ�����ʹ���β�                                                 ------�����Ƽ��ķ�ʽ��
# #���ӷ��������ƣ����ܺܺõ���ϵ�����࣬�������������һ������ʱ������ִ�е�ʱ����Ҫÿ��д������Ĳ���
#         #���ƣ�������СС�ĵ���ʱ����ѡ��
# class Soilder(object):
#     def __init__(self, soilder_name):
#         self.soilder_name = soilder_name
#
#     def fire(self, gun_name, bullet_count):
#         if gun.bullet_count == 0:
#             print("�ӵ����㣬��Ҫ�ϵ�")
#             return
#         bullet_count -= 10
#         print("ͻ" * 10)
#         print("[%s] ����ǹ [%s] �ӵ�ʣ�� [%d]\n"%(self.soilder_name, gun_name, bullet_count) )
#
#     def in_bullet(self, gun_name, bullet_count):
#         gun.bullet_count += 30
#         print("[%s] ����ǹ [%s] �ӵ���Ŀ +30 ����[%d]\n"%(self.soilder_name, gun_name, bullet_count))
#
#
# class Gun(object):
#     def __init__(self, gun_name, bullet_count):
#         self.gun_name = gun_name
#         self.bullet_count = bullet_count
#
# gun = Gun("AK47",0)
# wangyufeng =Soilder("�����")
# wangyufeng.in_bullet(gun.gun_name, gun.bullet_count)
# wangyufeng.fire(gun.gun_name, gun.bullet_count)