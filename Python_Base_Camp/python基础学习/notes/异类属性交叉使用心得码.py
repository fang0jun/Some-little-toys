"""

ʿ��ͻ����������
�������������һ������İ����з����Ķ���ʱ

�������������������壬��һ����ǹ��ʿ��������ǹ��ak47 ���ӵ����ҿ��Խ��п�ǹ���Ҳ������䵯ҩ
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
# wangyufeng =Soilder("�����������")
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
        print("[������%s] ����ǹ [��%s] �ӵ���Ŀ +30 ����[%d]\n"%(self.soilder_name, self.gun.gun_name, self.gun.bullet_count))


class Gun(object):
    def __init__(self, gun_name, bullet_count):
        self.gun_name = gun_name
        self.bullet_count = bullet_count

gun = Gun("AK47",0)
wangyufeng =Soilder("�����������")
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
# wangyufeng =Soilder("�����������")
# wangyufeng.in_bullet(gun.gun_name, gun.bullet_count)
# wangyufeng.fire(gun.gun_name, gun.bullet_count)