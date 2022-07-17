#include "directed_graph.h"

	
template <typename T>
void directed_graph<T>::get_edges(const int& u_id){
	vector<vertex<T> > neighbours = get_neighbours(u_id);
	cout << "the neighbours of " << u_id << ": " ; 
	for(int i = 0; i < neighbours.size(); i++){
		cout << neighbours[i].getId() << " ";
	}
	cout << endl;cout << endl;
}


template <typename T>
directed_graph<T>::directed_graph() {}


template <typename T>
directed_graph<T>::directed_graph(vector<vector<vector<int> > > arr) {
	
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
directed_graph<T>::~directed_graph() {}


template <typename T>
bool directed_graph<T>::contains(const int& u_id) const 
{
	for(const vertex<T> &v : this->vertices)
		if( v.matches(u_id) )
			return true;
	
	return false;
}


template <typename T>
int directed_graph<T>::find_vertex(const int& u_id) const
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
bool directed_graph<T>::adjacent(const int& u_id, const int& v_id) const 
{ 
	int u_pos = find_vertex(u_id);
    int v_pos = find_vertex(v_id);
    if( u_pos != -1 && v_pos != -1 )
		return (this->adj_matrix[u_pos][v_pos] > 0);

	return false;
}


template <typename T>
void directed_graph<T>::add_vertex(const vertex<T>& u) 
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
void directed_graph<T>:: operator+ (const vertex<T>& u){
    	add_vertex(u);
}



template <typename T>
void directed_graph<T>::add_edge(const edge& e) 
{
	int from_pos = find_vertex(e.from);
	int to_pos = find_vertex(e.to);
	
	if( from_pos != -1 && to_pos != -1 )
		this->adj_matrix[from_pos][to_pos] = e.weight;
    else
		cout << "one of the vertices are missing" << endl;

}



template <typename T>
void directed_graph<T>:: operator+ (const edge& e){
    	add_edge(e);
}




template <typename T>
void directed_graph<T>::remove_vertex(const int& u_id) 
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
void directed_graph<T>:: operator- (const int& u_id){
    	remove_vertex(u_id);
}



template <typename T>
void directed_graph<T>::remove_edge(const int& u_id, const int& v_id) 
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
size_t directed_graph<T>::in_degree(const int& u_id) const 
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
size_t directed_graph<T>::out_degree(const int& u_id) const 
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
size_t directed_graph<T>::degree(const int& u_id) const 
{
	int outDegreeEdges = out_degree(u_id);
	int inDegreeEdges = in_degree(u_id);
	return outDegreeEdges + inDegreeEdges;
}


template <typename T>
size_t directed_graph<T>::num_vertices() const 
{ 
	return this->vertices.size();
}


template <typename T>
size_t directed_graph<T>::num_edges() const 
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
vector<vertex<T>> directed_graph<T>::get_vertices() 
{ 
	return this->vertices;
}


template <typename T>
vector<vertex<T>> directed_graph<T>::get_neighbours(const int& u_id) 
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
bool directed_graph<T>::reachable(const int& u_id, const int& v_id)
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

 
//vector<vertex<T>> directed_graph<T>::path_reachable(const int& u_id, const int& v_id)
//{
//	vector<vertex<T>> result;  // 单条路径 
//	vector<vector<vertex<T> > > ret;  // 所有路径的集合 
//	vector<bool> visited(this->vertices.size(), false);
//	vertex<T> start = this->vertices[ find_vertex(u_id) ];
//
//
//	stack<vertex<T>> nodes;
//	nodes.push(start);
//	
//	while( !nodes.empty() )
//	{
//		
//		vertex<T> v = nodes.top();
//		result.push_back(v);
//		nodes.pop();
//		
//		int vertexId = v.getId();
//		int vertexPos = find_vertex( vertexId );
//
//		if( visited[vertexPos] == false )
//		{
//			visited[vertexPos] = true;
//			auto neighbours = get_neighbours( vertexId );
//
//			for(int i = 0; i < neighbours.size(); ++i) 
//			{
//				nodes.push( neighbours[i] );
//				
//				if( neighbours[i].matches(v_id) ){
//				 	result.push_back(vertices[find_vertex(v_id) ]);
//					return result;
//					}
//			}
//		}
//	}
//
//	return result;
//}

//
//template <typename T>
//vector<vector<vertex<T> > > directed_graph<T>::path_reachable(const int& u_id, const int& v_id)
//{
//	vector<vertex<T>> result;  // 单条路径 
//	vector<vector<vertex<T> > > ret;  // 所有路径的集合 
//	vector<bool> visited(this->vertices.size(), false);
//	vertex<T> start = this->vertices[ find_vertex(u_id) ];
//
//
//	stack<vertex<T>> nodes;
//	nodes.push(start);
//	visited[find_vertex(u_id)] == true;
//	
//	while( !nodes.empty() )
//	{
//		vertex<T> v = nodes.top();
//		//nodes.pop();
//		
//		int vertexId = v.getId();
//		int vertexPos = find_vertex( vertexId );
//		visited[vertexPos ] == true;
//		
//		if( vertexId = v_id ){
//			stack<vertex<T>> S = nodes;
//			cout << "empty?222" << nodes.empty() << endl;
//			while(!S.empty() ){  
//				vertex<T> s = S.top();
//				result.push_back(s);
//				S.pop();
//			}		
//			ret.push_back(result);
//			nodes.pop(); visited[vertexPos ] == false;
//			continue;
//		}
//
////		if( visited[vertexPos] == false )
////		{
////			visited[vertexPos] = true;
//		auto neighbours = get_neighbours( vertexId );
//
//		for(int i = 0; i < neighbours.size(); ++i) 
//		{
//				
//			if(visited[find_vertex(neighbours[i].getId()) ] == false){
//				visited[find_vertex(neighbours[i].getId()) ] ==  true;
//				nodes.push( neighbours[i] );
//				neighbours
//				break;
//				
//			}
//		}
//		
//	}
//
//	return ret;
//}



template <typename T>
bool directed_graph<T>::contain_cycles()
{ 
	for(const auto &v : this->vertices)
	{
		if( reachable(v.getId(), v.getId()) )
			return true;
			
	}
	return false;
}


//
///**
//*DFS实现，用分配堆栈数据结构的标准方法
//*并且执行以下过程：
//* 1.将根顶点推到堆栈，并在堆栈上迭代直到它为空
//* 2.当堆栈不为空时，检索最上面的元素并将其弹出堆栈
//* 3.检查当前顶点是否已被访问，如果未将其设置为“已访问”
//* 4.将这个顶点推到结果向量，并得到其对应的邻居。
//* 5.使用reverse_iterator循环遍历此顶点的每个邻居
//* 6.并将所有邻居推入堆栈
//* 7.重复2-6
//*/
//template <typename T>
//vector<vertex<T>> directed_graph<T>::depth_first(const int& u_id) 
//{
//	vector<bool> visited(this->vertices.size(), false);
//	vertex<T> start = this->vertices[ find_vertex(u_id) ];
//
//	vector<vertex<T>> result;
//	stack<vertex<T>> nodes;
//	nodes.push(start);
//
//	while( !nodes.empty() )
//	{
//		vertex<T> node = nodes.top();
//		nodes.pop();
//		int vertexId = node.getId();
//		int vertexPos = find_vertex( vertexId );
//
//		if( visited[vertexPos] == false )
//		{
//			visited[vertexPos] = true;
//			result.push_back(node);
//
//			auto neighbours = get_neighbours( vertexId );
//
//			typename vector<vertex<T>>::reverse_iterator itr;
//			for(itr = neighbours.rbegin(); itr != neighbours.rend(); ++itr)
//				nodes.push( *itr );
//            }
//
//	}
//	return result;
//}
//
///**
//*BFS实现类似于DFS，用标准队列数据结构
//*对其执行以下操作：
//* 1.将根顶点推入队列并遍历队列
//* 2.当队列不为空时，获取最前面的元素并将其弹出
//* 3.如果未访问检索到的顶点，则将其设置为Visited，否则将其忽略
//* 4.将这个顶点推到结果向量并检索其对应的邻居
//* 5.使用基于范围的for循环遍历每个邻居并将其推送到队列
//* 6.重复2-5
//*/
//
//template <typename T>
//vector<vertex<T>> directed_graph<T>::breadth_first(const int& u_id) 
//{
//	vector<bool> visited(this->vertices.size(), false);
//	vertex<T> start = this->vertices[ find_vertex(u_id) ];
//
//	vector<vertex<T>> result;
//	queue<vertex<T>> nodes;
//	nodes.push(start);
//
//	while( !nodes.empty() )
//	{
//		vertex<T> node = nodes.front();
//		nodes.pop();
//		int vertexId = node.getId();
//		int vertexPos = find_vertex( vertexId );
//
//		if( visited[vertexPos] == false )
//		{
//			visited[vertexPos] = true;
//			result.push_back(node);
//
//			auto neighbours = get_neighbours( vertexId );
//			for(const auto &neighbour : neighbours )
//				nodes.push( neighbour );
//		}
//	}
//	return result;
//}



/*find_cycle 的辅助函数：把数据转化进二维数组中方便操作 // for funtion “find_cycle ”
*/
template <typename T>
void directed_graph<T>::turn_graph(vector<vector<int> >&i_graph ){
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
void directed_graph<T>::find_cycle(){
	vector<vector<int> > i_graph;
	turn_graph(i_graph);
	cout<<"cycles in graph："<<endl;
	int N = num_vertices();
	for(int i=0;i<N;++i)
	{
		search(i_graph,i); 
	}
}





/**
*out_tree的 辅助函数，用于查找最小边，即向重量值最低的边 // for funtion “out_tree ”
*/ 
 
template <typename T>
pair<vertex<T>, T> directed_graph<T>:: findMinEdge(vector<pair<vertex<T>, T>> edges)
{
	pair<vertex<T>, T> minEdge = edges[0];

	for(const auto &edge : edges)
		if(edge.second < minEdge.second)
			minEdge = edge;

	return minEdge;
}

/**
*out_tree的 辅助函数，用于查找最小边，即向重量值最低的边  // for funtion “out_tree ” 
*/ 

template <typename T>
void directed_graph<T>::add_edge_fortree(const int& u_id, const int& v_id, const T& weight) 
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
*/

template <typename T>
directed_graph<T> directed_graph<T>::out_tree(const int& u_id) 
{
	directed_graph<T> tree;

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
*辅助功能可打印此图形对象中包含的所有当前顶点
*/

template <typename T>
void directed_graph<T>::printVertices()
{
	typename vector<vertex<T>>::iterator itr;
	for(itr = this->vertices.begin(); itr < vertices.end(); itr++)
	{
		cout << itr->getId() << "(" << itr->getWeight() << ")" << endl;
	}
	cout << endl;
}


/**
* helper函数打印邻接矩阵的当前状态
*/

template <typename T>
void directed_graph<T>::printMatrix()
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
ostream& operator<<(ostream& os, directed_graph<T>& g){  // 重载<<运算符 
	g.printVertices();
	g.printMatrix();
	return os;  
}




///////////////////////////////////////////////////////////////////////////////////////////////////////// 
