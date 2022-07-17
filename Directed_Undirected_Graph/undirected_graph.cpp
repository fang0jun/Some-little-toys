#include "undirected_graph.h"

template <typename T>
undirected_graph<T>::undirected_graph() {}


template <typename T>
undirected_graph<T>::undirected_graph(vector<vector<vector<int> > > arr) {
	
	for(int i = 0; i < arr[0].size(); i++){
		vertex<int> a = vertex<int>(arr[0][i][0], 0);
		add_vertex(a);
	}
	
	for(int n = 0; n < arr[1].size(); n++)
	{
			edge e = edge(arr[1][n][0],arr[1][n][1],arr[1][n][2]);
			add_edge(e);
		} 
	
}


template <typename T>
undirected_graph<T>::~undirected_graph() {}


template <typename T>
bool undirected_graph<T>::contains(const int& u_id) const 
{
	for(const vertex<T> &v : this->vertices)
		if( v.matches(u_id) )
			return true;
	
	return false;
}


template <typename T>
int undirected_graph<T>::find_vertex(const int& u_id) const
{
	if( contains(u_id) )
	{
        for(int i = 0; i < this->vertices.size(); ++i)
            if( this->vertices[i].matches(u_id) )
                return i;
	}
	return -1;
}


template <typename T>
bool undirected_graph<T>::adjacent(const int& u_id, const int& v_id) const 
{ 
	int u_pos = find_vertex(u_id);
    int v_pos = find_vertex(v_id);
    if( u_pos != -1 && v_pos != -1 )
		return (this->adj_matrix[u_pos][v_pos] > 0);

	return false;
}


template <typename T>
void undirected_graph<T>::add_vertex(const vertex<T>& u) 
{
	if( !contains(u.getId()) )
	{
		//加入新顶点
		this->vertices.push_back(u);

		//调整矩阵
		vector<T> vec(this->vertices.size()-1, 0);
		this->adj_matrix.push_back(vec);
      
		typename vector< vector<T> >::iterator row;
		for(row = this->adj_matrix.begin(); row < this->adj_matrix.end(); row++)
		{
        	row->push_back(0);
		}
	} else {
		cout << "warning: duplicate vertex detected" << endl;
	}
}

template <typename T>
void undirected_graph<T>:: operator+ (const vertex<T>& u){
    	add_vertex(u);
}



template <typename T>
void undirected_graph<T>::add_edge(const edge& e) 
{
	int from_pos = find_vertex(e.from);
	int to_pos = find_vertex(e.to);
	
	vertices[from_pos].weight = -1;
	vertices[to_pos].weight = -1;
	if( from_pos != -1 && to_pos != -1 ){
		this->adj_matrix[from_pos][to_pos] = e.weight;
		this->adj_matrix[to_pos][from_pos] = e.weight;  // 使用该语句，有向图变无向图 
	}
    else
		cout << "one of the vertices are missing" << endl;

}


template <typename T>
void undirected_graph<T>:: operator+ (const edge& e){
    	add_edge(e);
}



template <typename T>
void undirected_graph<T>::remove_vertex(const int& u_id) 
{
	
	int u_pos = find_vertex(u_id);

	for(int i = 0; i < this->vertices.size(); i++)
    {
    	if( this->vertices[i].matches(u_id) )
		{
            this->vertices.erase( this->vertices.begin() + i ); 
			break;
		}
    }
	
	for(int i = 0; i < this->adj_matrix.size(); i++) 
        this->adj_matrix[i].erase( this->adj_matrix[i].begin() + u_pos);

    this->adj_matrix.erase( this->adj_matrix.begin() + u_pos);
}

template <typename T>
void undirected_graph<T>:: operator- (const int& u_id){
    	remove_vertex(u_id);
}



template <typename T>
void undirected_graph<T>::remove_edge(const int& u_id, const int& v_id) 
{
	if( adjacent(u_id, v_id) )
	{
		int u_pos = find_vertex(u_id);
		int v_pos = find_vertex(v_id);
		
		if(u_pos != -1 && v_pos != -1)
        	this->adj_matrix[u_pos][v_pos] = 0;
	}
}



template <typename T>
size_t undirected_graph<T>::in_degree(const int& u_id) const 
{
	int result = 0;
	for(int i = 0; i < this->vertices.size(); ++i)
	{
		int v_id = this->vertices[i].getId();
		if( adjacent(v_id, u_id) ) result++;
	}
	return result;
}


template <typename T>
size_t undirected_graph<T>::out_degree(const int& u_id) const 
{
	int result = 0;
    int u_pos = find_vertex(u_id);

    for(int i = 0; i < this->vertices.size(); ++i)
    {
		int v_id = this->vertices[i].getId();
		if( adjacent(u_id, v_id) ) result++;
    }

    return result;
}


template <typename T>
size_t undirected_graph<T>::degree(const int& u_id) const 
{
	int outDegreeEdges = out_degree(u_id);
	int inDegreeEdges = in_degree(u_id);
	return outDegreeEdges + inDegreeEdges;
}


template <typename T>
size_t undirected_graph<T>::num_vertices() const 
{ 
	return this->vertices.size();
}


template <typename T>
size_t undirected_graph<T>::num_edges() const 
{ 
	int result = 0;
    typename vector< vector<T> >::const_iterator row;
    typename vector<T>::const_iterator col;

    for(row = this->adj_matrix.begin(); row < this->adj_matrix.end(); row++)
    {
        for(col = row->begin(); col < row->end(); col++)
            if( *col > 0 ) result++;
    }
    return result;
}


template <typename T>
vector<vertex<T>> undirected_graph<T>::get_vertices() 
{ 
	return this->vertices;
}


template <typename T>
vector<vertex<T>> undirected_graph<T>::get_neighbours(const int& u_id) 
{
	vector<vertex<T>> neighbours;
	for(const auto &v : this->vertices )
    {
		if( adjacent(u_id, v.getId()) && u_id != v.getId() )
			neighbours.push_back(v);
    }
	return neighbours;
}

template <typename T>
bool undirected_graph<T>::reachable(const int& u_id, const int& v_id)
{
	
	vector<bool> visited(this->vertices.size(), false);
	vertex<T> start = this->vertices[ find_vertex(u_id) ];

	stack<vertex<T>> nodes;
	nodes.push(start);

	while( !nodes.empty() )
	{
		vertex<T> v = nodes.top();
		nodes.pop();
		int vertexId = v.getId();
		int vertexPos = find_vertex( vertexId );

		if( visited[vertexPos] == false )
		{
			visited[vertexPos] = true;
			auto neighbours = get_neighbours( vertexId );

			for(int i = 0; i < neighbours.size(); ++i) 
			{
				nodes.push( neighbours[i] );
				if( neighbours[i].matches(v_id) )
					return true;
			}
		}
	}

	return false;
}



template <typename T>
bool undirected_graph<T>::contain_cycles()
{ 
	for(const auto &v : this->vertices)
	{
		if( reachable(v.getId(), v.getId()) )
			return true;
			
	}
	return false;
}




/**
*辅助函数 用于查找最小边，即向重量值最低的边
*/ 
// for funtion “out_tree ” 
template <typename T>
pair<vertex<T>, T> undirected_graph<T>:: findMinEdge(vector<pair<vertex<T>, T>> edges)
{
	pair<vertex<T>, T> minEdge = edges[0];

	for(const auto &edge : edges)
		if(edge.second < minEdge.second)
			minEdge = edge;

	return minEdge;
}

// for funtion “out_tree ” 
template <typename T>
void undirected_graph<T>::add_edge_fortree(const int& u_id, const int& v_id, const T& weight) 
{
	int u_pos = find_vertex(u_id);
	int v_pos = find_vertex(v_id);
	
	if( u_pos != -1 && v_pos != -1 )
		this->adj_matrix[u_pos][v_pos] = weight;
    else
		cout << "one of the vertices are missing" << endl;

}

/**
*out_tree实现，使用队列遍历每个顶点
* 1.声明一个树对象，然后将起始顶点推到要处理的队列中
* 2.当队列不为空时，检索最前面的元素并将其从队列中删除
* 3.此顶点是被访问的顶点吗？ 如果不是，则将其设置为已访问。
* 4.将此顶点添加到树中，并声明“ edges”矢量
* 5.检索该顶点的相应邻居并对其进行迭代
* 6.为邻居内的每个邻居创建一对顶点和权重
* 7.将此对推到“边缘”向量，并将邻居推入堆栈。
* 8.重复4-7，直到邻居循环结束
* 9.一旦生成边缘列表，就使用'findMinEdge'来获得权重最小的边缘。
* 10.将邻居顶点推到树上，并从根到该邻居添加一条边。
* 11.重复2-10
*/

template <typename T>
undirected_graph<T> undirected_graph<T>::out_tree(const int& u_id) 
{
	undirected_graph<T> tree;

	vector<bool> visited(this->vertices.size(), false);
	vertex<T> start = this->vertices[ find_vertex(u_id) ];

	queue<vertex<T>> nodes;
	nodes.push(start);

	while( !nodes.empty() )
	{
		vertex<T> node = nodes.front();
		nodes.pop();

		int vertexId = node.getId();
		int vertexPos = find_vertex( vertexId );

		if( visited[vertexPos] == false )
		{
			visited[vertexPos] = true;
			tree.add_vertex(node);
			vector<pair<vertex<T>, T>> edges;//neighbour vertex and weight;

			auto neighbours = get_neighbours( vertexId );
			for(const auto &neighbour : neighbours)
			{
				int neighbourPos = find_vertex( neighbour.getId() );
				T weight = this->adj_matrix[vertexPos][neighbourPos];
				edges.push_back(make_pair(neighbour, weight));
				nodes.push(neighbour);
			}
			if( edges.size() > 0 )
			{
				pair<vertex<T>, T>   minEdge = findMinEdge(edges);
				vertex<T>            neighbour = minEdge.first;
				T                    weight = minEdge.second;
				tree.add_vertex(neighbour);
				tree.add_edge_fortree(vertexId, neighbour.getId(), weight); 
			}
		}
	}
	return tree;
}


/**
* 打印此图形对象中包含的所有当前顶点
*/
template <typename T>
void undirected_graph<T>::printVertices()
{
	typename vector<vertex<T>>::iterator itr;
	for(itr = this->vertices.begin(); itr < vertices.end(); itr++)
	{
		cout << itr->getId() << "(" << itr->getWeight() << ")" << endl;
	}
	cout << endl;
}


/**
* 打印邻接矩阵的当前状态
*/
template <typename T>
void undirected_graph<T>::printMatrix()
{
	typename vector< vector<T> >::iterator row;
	typename vector<T>::iterator col;

	for(row = this->adj_matrix.begin(); row < this->adj_matrix.end(); row++)
	{
            for(col = row->begin(); col < row->end(); col++)
               cout << *col <<" ";
            cout << endl;
	}
	cout << endl;
}


template <typename T>
ostream& operator<<(ostream& os, undirected_graph<T>& g){  // 重载<<运算符 
	g.printVertices();
	g.printMatrix();
	return os;  
}


/*
为具有n个顶点的图G着色
1.按一定顺序排列图形的顶点。
2.选择第一个顶点，并用第一种颜色对其进行着色。
3.选择下一个顶点，并用与其相邻的任何顶点上未着色的编号最小的颜色进行着色。 
如果所有相邻的顶点都以此颜色上色，请为其分配新的颜色。 重复此步骤，直到所有顶点都着色为止。
*/ 
template <typename T>
void undirected_graph<T>::for_color(int v, bool visited[]){
	visited[v]= true;
	vertex<T>& ver = vertices[v];
	if(ver.weight==-1){
        set<int> status;
        vector<vertex<T> > neighbours = get_neighbours(ver.id);
        for (auto x : neighbours){
            if(x.weight!=-1){
                status.insert(x.weight);
            }        
        }
        int val=1;
        for(auto itr=status.begin();itr!=status.end();itr++){
            if(*itr!=val){
                break;
            }
            val++;
        }
        ver.weight=val;
        
    }
    
    cout << "the color of: "<< v<<"     ==>     "<< "color:"<< ver.weight<<endl;
	vector<vertex<T> > neighbours1 = get_neighbours(ver.id);
	for(int i = 0; i < neighbours1.size(); ++i)
		if ( ! visited[  find_vertex( neighbours1[i].getId())  ] ){
			for_color(find_vertex( neighbours1[i].getId()), visited);
		}
} 
	

template <typename T>
void undirected_graph<T>::COLOR(vertex<T> ver){
	int V = num_vertices();
	int v =  find_vertex(ver.getId());
	bool *visited=new bool[V]; // 起始节点在数组中的位置 
	for(int i=0;i<V;i++){
		visited[i]=false;
	}
	for_color(v, visited); 
	
}



/*find_cycle 的辅助函数：把数据转化进二维数组中方便操作 // for funtion “find_cycle ”
*/
template <typename T>
void undirected_graph<T>::turn_graph(vector<vector<int> >&i_graph ){
	vector<int>temp;
	int i,j;
	int N = num_vertices();
	for(i=0;i<N;++i)
	{
		temp.clear();
		for(j=0;j<N;++j)
			temp.push_back(adj_matrix[i][j]);
		i_graph.push_back(temp);
	}
}

/*find_cycle 的辅助函数：找出指定某个节点的环  // for funtion “find_cycle ”
*/
void search(vector<vector<int> >i_graph,int x){
	int i;
	int size=i_graph.size();      
	vector<int> compare;   //存储点x通向的点
	vector<int> visit;
	vector<int> stack;
	int top=-1;
	compare.clear();
	for(int k1=0;k1<size;++k1)
	{		
		compare.push_back(0);
	}
	for( i=0;i<size;++i)     
	{
		if(i_graph[x][i]>0)    //将点x通向的点，存储到compare中
          compare[i]=1;
	}
 
	for( i=0;i<size;++i)     //对点x的每个点进行遍历
	{
		//初始化
		visit.clear();
		stack.clear();
		for(int k1=0;k1<size;++k1)     
	    {
		  visit.push_back(0);
		  stack.push_back(0);
	    }
		top=-1;
//		stack.push_back(x);
	    stack[++top]=x;
		visit[x]=1;
 
		if(i_graph[x][i]>0)    //若有连接
		{
			stack[++top]=i;
			visit[i]=1;
			while(top!=0)    //根节点x不应该出栈
			{
				int k1;
				i=stack[top];
				for( k1=0;k1<size;++k1)
				{
					if(i_graph[i][k1]>0&&!visit[k1])
					{
						stack[++top]=k1;
						visit[k1]=1;
						break;
					}
				}
				if(k1==size)              //若没有与其它节点相连的，就输出stack中所有的元素
				{ 
					if(top>1)
					{
				  	 for(int k2=0;k2<=top;++k2)
					 {
						 cout<<stack[k2];
					 }
					 if(compare[stack[top]]==1)
						 cout<<"  环√"<<endl;
					 else 
						 cout<<endl;
					 }
					 --top;
				}
 
			}
 
 
 
		}
 
	}
}


template <typename T>
void undirected_graph<T>::find_cycle(){
	vector<vector<int> > i_graph;
	turn_graph(i_graph);
	cout<<"cycles in graph："<<endl;
	int N = num_vertices();
	for(int i=0;i<N;++i)
	{
		search(i_graph,i); 
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////// 









