/* ==================================================
 *
 * author�������  ���ѧ�  ���ڧߧ�٧�ߧ�
 * date: 2020.12.19 - 20
 * explanation��homework OOP - task1 NO.6 graph - first part
 * others: In dev c++, you need to change the compiler g++ to "c++.exe -std=c++11"
 *
 ================================================== */ 


#include "undirected_graph.cpp"

int main() {
   vector<vector<vector<int> > > data = { {{0},{1},{2},{3},{4},{5} }, { {0,'a',5},{0,'a',1}, {5,'a',4},{1,'b',2},{4,'b',3},{2,'b',3},{5,'b',2},{1,'b',4},{4,'b',2},{5,'b',1}          }  };
   undirected_graph<int> un_graph(data);
   cout << un_graph << endl;
	
// NO.16: ��ڧܧ� �� �ԧ�ѧ�� 
//    vector<vector<vector<int> > > data_for_NO_16 = {{ {1},{2},{3},{4},{5},{6} }, { {1,'a',2}, {1,'b',4},{2,'c',3},{2,'d',4},{2,'e',5},{4,'f',3}            }  };
//    undirected_graph<int> un_graph2(data_for_NO_16);
//    cout << un_graph2 << endl;
//	  un_graph2.find_cycle();
	
	
//  NO.14: �������֧ߧڧ� �����ӧߧ�ԧ� �է֧�֧ӧ� �C�ާڧߧڧާѧݧ�ߧ�ԧ� ��� ����ڧާ����
//	undirected_graph<int> tree = un_graph.out_tree(0);
//	tree.printMatrix();
//	tree.printVertices();
	
	
//  NO.15: �ӧ֧��ڧߧߧѧ�/��֧ҧ֧�ߧѧ� ��ѧ�ܧ�ѧ�ܧ� 
//	un_graph.COLOR(0);

// NO.13:


    return 0;
}

