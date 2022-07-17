/* ==================================================
 *
 * author£º·¿Áè¾ý  §¶§Ñ§ß  §­§Ú§ß§è§Ù§ð§ß§î
 * date: 2020.12.19 - 20
 * explanation£ºhomework OOP - task1 NO.6 graph - first part
 * others: In dev c++, you need to change the compiler g++ to "c++.exe -std=c++11"
 *
 ================================================== */ 

#include "directed_graph.cpp"

int main() {
   //vector<vector<vector<int> > > data = { {{0},{1},{2},{3},{4},{5} }, { {0,'a',5},{0,'a',1}, {5,'a',4},{1,'b',2},{4,'b',3},{2,'b',3},{5,'b',2},{1,'b',4},{4,'b',2},{5,'b',1}          }  };
   vector<vector<vector<int> > > data_for_NO_11 = {{ {1},{2},{3},{4},{5},{6} }, { {1,'a',2}, {1,'a',4},{2,'a',3},{2,'a',4},{2,'a',5},{4,'a',3}            }  };
   directed_graph<int> graph(data_for_NO_11);
//NO.1 : §Õ§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö (add ¨C§à§Õ§ß§Ñ §æ§å§ß§Ü§è§Ú§ñ §ã §â§Ñ§Ù§ß§í§Þ §ß§Ñ§Ò§à§â§à§Þ §Ñ§â§Ô§å§Þ§Ö§ß§ä§à§Ó): §Ó§Ö§â§ê§Ú§ß§í, §â§Ö§Ò§â§Ñ, §Õ§å§Ô§Ú
//NO.2 : §å§Õ§Ñ§Ý§Ö§ß§Ú§Ö (remove ¨C§à§Õ§ß§Ñ §æ§å§ß§Ü§è§Ú§ñ §ã §â§Ñ§Ù§ß§í§Þ §ß§Ñ§Ò§à§â§à§Þ §Ñ§â§Ô§å§Þ§Ö§ß§ä§à§Ó): §Ó§Ö§â§ê§Ú§ß§í, §â§Ö§Ò§â§Ñ, §Õ§å§Ô§Ú 
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

	
// NO.3 : §Ó§í§Ó§à§Õ §ã§á§Ú§ã§Ü§Ñ §Õ§å§Ô, §Ú§ã§ç§à§Õ§ñ§ë§Ú§ç §Ú§Ù §Ó§Ö§â§ê§Ú§ß§í;  
//	graph.get_edges(0); // node_id

	
// NO.4,5 :§à§á§Ö§â§Ñ§è§Ú§ñ+ /  §à§á§Ö§â§Ñ§è§Ú§ñ-
//  graph+a;
//  graph+b;
//  graph+c;
//  graph+d;
//  graph+a_b;
//	graph-6; // the id of "a" is 6, Through  id, the function is more convenient to use
	
// NO.7: §á§â§à§Ó§Ö§â§Ü§Ñ §Õ§à§ã§ä§Ú§Ø§Ú§Þ§à§ã§ä§Ú §à§Õ§ß§à§Û §Ó§Ö§â§ê§Ú§ß§í §Ú§Ù §Õ§â§å§Ô§à§Û 
//	if(graph.reachable(0, 5) ) cout << "reachable!" << endl; else cout << "can't reachable!" << endl;
	
// NO.8: §á§Ö§â§Ö§Ô§â§å§Ù§Ü§Ñ §à§á§Ö§â§Ñ§è§Ú§Ú<< ¨C§Ó§í§Ó§à§Õ §Ô§â§Ñ§æ§Ñ, §Ó §å§Õ§à§Ò§ß§à§Þ §Õ§Ý§ñ §é§ä§Ö§ß§Ú§ñ§Ó§Ú§Õ§Ö 
	cout << graph << endl;

// NO.9: 
//	graph.find_cycle();

// NO.11:  §è§Ú§Ü§Ý§à §Ó §Ô§â§Ñ§æ§Ö 
//	if(graph.contain_cycles() ) cout << "contain!" << endl; else cout << "no contain!" << endl;

// NO.12: §á§à§ã§ä§â§à§Ö§ß§Ú§Ö §à§ã§ä§à§Ó§ß§à§Ô§à §Õ§Ö§â§Ö§Ó§Ñ (§Ý§ð§Ò§à§Ô§à) 
//	directed_graph<int> tree = graph.out_tree(0);
//	tree.printMatrix();
//	tree.printVertices();
	

//vector<vertex<int>> dfs = graph.depth_first(1);
// vector<vertex<int>> bfs = graph.breadth_first(1);


  	


    return 0;
}

