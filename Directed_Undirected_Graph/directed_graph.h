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
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class directed_graph {

private:
	vector< vertex<T> > vertices;
	vector< vector<T> > adj_matrix;

public:
	unordered_map<int,int>color;
    unordered_map<int,int>status;

	directed_graph(); 
	directed_graph(vector<vector<vector<int> > > arr);
	~directed_graph(); 

	bool contains(const int&) const; //�ж�ͼ�Ƿ����������vertex_id
	bool adjacent(const int&, const int&) const; //�жϵ�һ��������ڶ��������Ƿ�����
	int find_vertex(const int&) const; //���Ҷ���ID  --- ����������������е����� 
	
	void add_vertex(const vertex<T>&); //��Ӷ��㵽ͼ��
	void add_edge_fortree(const int&, const int&, const T&); //��Ӵӵ�һ�����㵽�ڶ�������ļ�Ȩ�ߡ�
	void add_edge(const edge& e);
	void remove_vertex(const int&); //ɾ�������Ķ��㡣��Ӧ���������رߡ�
	void remove_edge(const int&, const int&); //ɾ����������֮��ıߣ�������ڣ�
	
	
	void operator+ (const vertex<T>&);
	void operator- (const int&); // ���� intΪ�ڵ��id 
	void operator+ (const edge&);
	void operator- (const edge&);
	void operator delete[] (void *p);
	
	size_t num_vertices() const; //����ͼ�е��ܶ�����
	size_t num_edges() const; //����ͼ�е��ܱ�����

	void get_edges(const int&); //��ʾ�ɶ��������Ļ����б�
	vector<vertex<T> >  get_vertices(); //�����������������������ж��㡣
	bool reachable(const int&, const int&); //�ж��Ƿ�������ű�Ե��·���ӵ�һ�����㵽��ڶ�������
	//vector<vertex<T> > path_reachable2(const int&, const int&);
	//vector<vector<vertex<T> > >  path_reachable(const int&, const int&);
	
	bool contain_cycles(); //�ж�ͼ�Ƿ����ѭ�������ڴ��κζ���ֱ��/��ӻص������·����
	void find_cycle();
	void turn_graph(vector<vector<int> >&i_graph ); 
	
	pair<vertex<T>, T > findMinEdge(vector<pair<vertex<T>, T> >);
	directed_graph<T> out_tree(const int&); //����ʹ�ñ�Ե�Ӹ������㿪ʼ��ͼ�������� 
	
	
	size_t in_degree(const int&) const; //���ض�����ȡ�
	size_t out_degree(const int&) const; //���ض������ 
	size_t degree(const int&) const; //���ض���Ķ�������ߺͳ��ߣ���
	vector<vertex<T> > get_neighbours(const int&); //����������������������������������ھӡ����㲻����Ϊ������ھӡ�

	

	
	
	void printVertices();
	void printMatrix();
	void printAll();

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////



