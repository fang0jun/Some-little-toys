/* ==================================================
 *
 * author£º·¿Áè¾ý  §¶§Ñ§ß  §­§Ú§ß§è§Ù§ð§ß§î
 * date: 2020.12.19 - 20
 * explanation£ºhomework OOP - task1 NO.6 graph - first part
 * others: In dev c++, you need to change the compiler g++ to "c++.exe -std=c++11"
 *
 ================================================== */ 


#include "undirected_graph.cpp"

int main() {
   vector<vector<vector<int> > > data = { {{0},{1},{2},{3},{4},{5} }, { {0,'a',5},{0,'a',1}, {5,'a',4},{1,'b',2},{4,'b',3},{2,'b',3},{5,'b',2},{1,'b',4},{4,'b',2},{5,'b',1}          }  };
   undirected_graph<int> un_graph(data);
   cout << un_graph << endl;
	
// NO.16: §è§Ú§Ü§Ý §Ó §Ô§â§Ñ§æ§Ö 
//    vector<vector<vector<int> > > data_for_NO_16 = {{ {1},{2},{3},{4},{5},{6} }, { {1,'a',2}, {1,'b',4},{2,'c',3},{2,'d',4},{2,'e',5},{4,'f',3}            }  };
//    undirected_graph<int> un_graph2(data_for_NO_16);
//    cout << un_graph2 << endl;
//	  un_graph2.find_cycle();
	
	
//  NO.14: §á§à§ã§ä§â§à§Ö§ß§Ú§Ö §à§ã§ä§à§Ó§ß§à§Ô§à §Õ§Ö§â§Ö§Ó§Ñ ¨C§Þ§Ú§ß§Ú§Þ§Ñ§Ý§î§ß§à§Ô§à §á§à §ã§ä§à§Ú§Þ§à§ã§ä§Ú
//	undirected_graph<int> tree = un_graph.out_tree(0);
//	tree.printMatrix();
//	tree.printVertices();
	
	
//  NO.15: §Ó§Ö§â§ê§Ú§ß§ß§Ñ§ñ/§â§Ö§Ò§Ö§â§ß§Ñ§ñ §â§Ñ§ã§Ü§â§Ñ§ã§Ü§Ñ 
//	un_graph.COLOR(0);

// NO.13:


    return 0;
}

