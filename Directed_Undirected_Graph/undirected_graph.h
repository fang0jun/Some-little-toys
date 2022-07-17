
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
	
	// necessary for set��for "set.insert()" 
	friend bool operator < (const edge& lhs, const edge& rhs);
	

};

// ˫�������ع�������Ҫ�ض��ķ�ʽ���죡 friend 
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

	bool contains(const int&) const; //�ж�ͼ�Ƿ����������vertex_id
	bool adjacent(const int&, const int&) const; //�жϵ�һ��������ڶ��������Ƿ�����
	int find_vertex(const int&) const; //���Ҷ���ID  --- ����������������е����� 
	
	void add_vertex(const vertex<T>&); //��Ӷ��㵽ͼ��
	void add_edge_fortree(const int&, const int&, const T&); 
	void add_edge(const edge& e);
	void remove_vertex(const int&); //ɾ�������Ķ��㡣��Ӧ���������رߡ�
	void remove_edge(const int&, const int&); //ɾ����������֮��ıߣ�������ڣ�
	
	
	
	void operator+ (const vertex<T>&);
	void operator+ (const edge&);
	void operator- (const edge&);
	void operator- (const int&); // ���� intΪ�ڵ��id 
	void operator delete[] (void *p);

	size_t num_vertices() const; //����ͼ�е��ܶ�����
	size_t num_edges() const; //����ͼ�е��ܱ�����

	vector<vertex<T> >  get_vertices(); //�����������������������ж��㡣
	bool reachable(const int&, const int&); //�ж��Ƿ�������ű�Ե��·���ӵ�һ�����㵽��ڶ�������
	bool contain_cycles(); //�ж�ͼ�Ƿ����ѭ�������ڴ��κζ���ֱ��/��ӻص������·����
	//vector<vertex<T> > path_reachable2(const int&, const int&);
	//vector<vector<vertex<T> > >  path_reachable(const int&, const int&);
	
	pair<vertex<T>, T > findMinEdge(vector<pair<vertex<T>, T> >);
	undirected_graph<T> out_tree(const int&); //����ʹ�ñ�Ե�Ӹ������㿪ʼ��ͼ�������� 
	
	
	size_t in_degree(const int&) const; //���ض�����ȡ�
	size_t out_degree(const int&) const; //���ض������ 
	size_t degree(const int&) const; //���ض���Ķ�������ߺͳ��ߣ���
	vector<vertex<T> > get_neighbours(const int&); //����������������������������������ھӡ����㲻����Ϊ������ھӡ�


	void for_color(int v, bool visited[]); 
	void COLOR(vertex<T> ver);
	void printVertices();
	void printMatrix();
	void printAll();
	
	void find_cycle();
	void turn_graph(vector<vector<int> >&i_graph ); 
	
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////
