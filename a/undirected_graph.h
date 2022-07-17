
#include<bits/stdc++.h> 

using namespace std;


/////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class vertex {

public:
	int id;
	T weight; 

	vertex(int x, int y = 0) : id(x), weight(y) {}
	bool matches(const int&) const; 
	int getId() const; 
	T getWeight() const; 

};

template<typename T>
bool vertex<T>::matches(const int &u_id) const{	return (this->id == u_id); }

template<typename T> 
int vertex<T>::getId() const{	return this->id; }

template<typename T> 
T vertex<T>::getWeight() const{   return this->weight; }

///////////////////////////////////////////////////////////////////////////////////////////////////////// 

class edge{

public:
	int from;
	int to;
	int weight;

	edge(int a,int b, int c) : from(a), weight(b), to(c) {}
	
	// necessary for set，for "set.insert()" 
	friend bool operator < (const edge& lhs, const edge& rhs);
	

};

// 双参数的重构函数需要特定的方式构造！ friend 
//	bool operator < (const edge& lhs, const edge& rhs)
//	{
//  		return lhs.start < rhs.start || lhs.end < rhs.end;
//	}
bool operator < (const edge& lhs, const edge& rhs){
  	return lhs.from < rhs.from || lhs.to < rhs.to;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class undirected_graph {

private:
	vector< vertex<T> > vertices;
	vector< vector<T> > adj_matrix;

public:
	unordered_map<int,int>color;
    unordered_map<int,int>status;

	undirected_graph(); 
	undirected_graph(vector<vector<int> >  arr);
	undirected_graph(vector<vector<vector<int> > > arr);
	~undirected_graph(); 

	bool contains(const int&) const; //判断图是否包含给定的vertex_id
	bool adjacent(const int&, const int&) const; //判断第一个顶点与第二个顶点是否相邻
	int find_vertex(const int&) const; //查找顶点ID  --- 并输出顶点在数组中的索引 
	
	void add_vertex(const vertex<T>&); //添加顶点到图中
	void add_edge_fortree(const int&, const int&, const T&); 
	void add_edge(const edge& e);
	void remove_vertex(const int&); //删除给定的顶点。还应清除所有相关边。
	void remove_edge(const int&, const int&); //删除两个顶点之间的边（如果存在）
	
	
	
	void operator+ (const vertex<T>&);
	void operator+ (const edge&);
	void operator- (const edge&);
	void operator- (const int&); // 减点 int为节点的id 
	void operator delete[] (void *p);

	size_t num_vertices() const; //返回图中的总顶点数
	size_t num_edges() const; //返回图中的总边数。

	vector<vertex<T> >  get_vertices(); //返回向量，该向量包含所有顶点。
	bool reachable(const int&, const int&); //判断是否可以沿着边缘的路径从第一个顶点到达第二个顶点
	bool contain_cycles(); //判断图是否包含循环（存在从任何顶点直接/间接回到自身的路径）
	//vector<vertex<T> > path_reachable2(const int&, const int&);
	//vector<vector<vertex<T> > >  path_reachable(const int&, const int&);
	
	pair<vertex<T>, T > findMinEdge(vector<pair<vertex<T>, T> >);
	undirected_graph<T> out_tree(const int&); //返回使用边缘从给定顶点开始的图的生成树 
	
	
	size_t in_degree(const int&) const; //返回顶点入度。
	size_t out_degree(const int&) const; //返回顶点出度 
	size_t degree(const int&) const; //返回顶点的度数（入边和出边）。
	vector<vertex<T> > get_neighbours(const int&); //返回向量，该向量包含给定顶点的所有邻居。顶点不被视为自身的邻居。


	void for_color(int v, bool visited[]); 
	void COLOR(vertex<T> ver);
	void printVertices();
	void printMatrix();
	void printAll();
	
	void find_cycle();
	void turn_graph(vector<vector<int> >&i_graph ); 
	
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////
