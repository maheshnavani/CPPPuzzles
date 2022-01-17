// Example program
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>

class Graph
{
    public:
        Graph(int e) :m_e(e) {
        }
        void add(int node, std::vector<int> edges) {
            m_g[node] = edges;
        }
        
        std::vector<int> bfs(int node) {
            std::vector<int> out;
            bool visited[m_e];
            std::queue<int> q;
            q.push(node);
            visited[node] = true;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                out.push_back(i);
                
                for ( auto &adj : m_g[i]) {
                    if  ( ! visited[adj])  {
                        q.push(adj);
                        visited[adj] = true;
                    }
                }
            }
            return out;
        }
        
        std::vector<int> dfs(int node) {
            std::vector<int> out;
            std::vector<bool>  visited(m_e,false);
            
            std::stack<int> s;
            s.push(node);
            printStack(s, "Step1") ;
            //visited[node] = true;
            while (!s.empty()) {
                int i = s.top();
                s.pop();
                printStack(s, "Step2") ;
                if ( !visited[i])      {
                    out.push_back(i);
                    visited[i] = true;
                }
                
                for ( auto &adj : m_g[i]) {
                    std::cout << adj << "|"<< visited[adj] << "\n";
                    if  ( ! visited[adj])  {
                        s.push(adj);
                        printStack(s, "Step3") ;
                    }
                }
            }
            return out;
            
        }
    void printStack(std::stack<int> s, std::string label){
        std::cout << label << ":" ;
    	while(!s.empty()){
          std::cout<<s.top()<<" ";
          s.pop();
        }
        std::cout<<"\n";
    }        
    private:
        int m_e;
        std::unordered_map<int,std::vector<int>> m_g;
};
int main()
{

    Graph g(5);
    g.add(1, {2,3,4});
    g.add(2,{1});
    g.add(3,{1,4,5});
    g.add(4, {1,3,5});
    g.add (5 , {3,4});
    
    for(auto i : g.bfs(2)) std::cout << i << "|" ;    std::cout << "\n";
    for(auto i : g.dfs(2)) std::cout << i << "|" ;    std::cout << "\n";

}
