"""

�����쳣�Ĵ��� --- �ô���Ӱ�����ļ������У������� �׳� �쳣  ---�����ڳ����д���

"""

try:
    num = int(input("������һ������"))
    number = 8 / num

    print(number)

except ValueError:
    print("������ʵʵ������һ������")
except Exception as result:
    print("δ֪���� %s" % result)

else:
    print("ִ�гɹ���������")
finally:
    print("��������Ҷ���")
