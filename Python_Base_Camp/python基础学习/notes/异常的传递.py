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
