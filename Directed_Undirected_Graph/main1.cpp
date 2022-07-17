/* ==================================================
 *
 * author�������  ���ѧ�  ���ڧߧ�٧�ߧ�
 * date: 2020.12.19 - 20
 * explanation��homework OOP - task1 NO.6 graph - first part
 * others: In dev c++, you need to change the compiler g++ to "c++.exe -std=c++11"
 *
 ================================================== */ 

#include "directed_graph.cpp"

int main() {
   //vector<vector<vector<int> > > data = { {{0},{1},{2},{3},{4},{5} }, { {0,'a',5},{0,'a',1}, {5,'a',4},{1,'b',2},{4,'b',3},{2,'b',3},{5,'b',2},{1,'b',4},{4,'b',2},{5,'b',1}          }  };
   vector<vector<vector<int> > > data_for_NO_11 = {{ {1},{2},{3},{4},{5},{6} }, { {1,'a',2}, {1,'a',4},{2,'a',3},{2,'a',4},{2,'a',5},{4,'a',3}            }  };
   directed_graph<int> graph(data_for_NO_11);
//NO.1 : �է�ҧѧӧݧ֧ߧڧ� (add �C��էߧ� ���ߧܧ�ڧ� �� ��ѧ٧ߧ�� �ߧѧҧ���� �ѧ�ԧ�ާ֧ߧ���): �ӧ֧��ڧߧ�, ��֧ҧ��, �է�ԧ�
//NO.2 : ��էѧݧ֧ߧڧ� (remove �C��էߧ� ���ߧܧ�ڧ� �� ��ѧ٧ߧ�� �ߧѧҧ���� �ѧ�ԧ�ާ֧ߧ���): �ӧ֧��ڧߧ�, ��֧ҧ��, �է�ԧ� 
//    vertex<int> a = vertex<int>(6);
//    vertex<int> b = vertex<int>(7);
//    vertex<int> c = vertex<int>(8);
//    vertex<int> d = vertex<int>(9);
//	edge a_b = edge(1,'a',3);
//	graph.add_vertex(a);
//	graph.add_vertex(b);
//	graph.add_vertex(c);
//	graph.add_vertex(d);
//	graph.add_edge(a_b);
//	graph.remove_vertex(6); // the id of "a" is 6, Through  id, the function is more convenient to use
//	graph.remove_vertex(7);
//	graph.remove_vertex(8);
//	graph.remove_vertex(9);
//  	graph.remove_edge(a_b);

	
// NO.3 : �ӧ�ӧ�� ���ڧ�ܧ� �է��, �ڧ���է��ڧ� �ڧ� �ӧ֧��ڧߧ�;  
//	graph.get_edges(0); // node_id

	
// NO.4,5 :���֧�ѧ�ڧ�+ /  ���֧�ѧ�ڧ�-
//  graph+a;
//  graph+b;
//  graph+c;
//  graph+d;
//  graph+a_b;
//	graph-6; // the id of "a" is 6, Through  id, the function is more convenient to use
	
// NO.7: ����ӧ֧�ܧ� �է���ڧاڧާ���� ��էߧ�� �ӧ֧��ڧߧ� �ڧ� �է��ԧ�� 
//	if(graph.reachable(0, 5) ) cout << "reachable!" << endl; else cout << "can't reachable!" << endl;
	
// NO.8: ��֧�֧ԧ��٧ܧ� ���֧�ѧ�ڧ�<< �C�ӧ�ӧ�� �ԧ�ѧ��, �� ��է�ҧߧ�� �էݧ� ���֧ߧڧ�ӧڧէ� 
	cout << graph << endl;

// NO.9: 
//	graph.find_cycle();

// NO.11:  ��ڧܧݧ� �� �ԧ�ѧ�� 
//	if(graph.contain_cycles() ) cout << "contain!" << endl; else cout << "no contain!" << endl;

// NO.12: �������֧ߧڧ� �����ӧߧ�ԧ� �է֧�֧ӧ� (�ݧ�ҧ�ԧ�) 
//	directed_graph<int> tree = graph.out_tree(0);
//	tree.printMatrix();
//	tree.printVertices();
	

//vector<vertex<int>> dfs = graph.depth_first(1);
// vector<vertex<int>> bfs = graph.breadth_first(1);


  	


    return 0;
}

