

    #include<iostream>
    #include<conio.h>
    #include<vector>
    using namespace std;
    class vertice{
        vector<class edge*> E;
    public:
        void setEdge(class edge* e)
        {
            E.push_back(e);
        }
        int deg()
        {
            return E.size();
        }
        vector<class edge*> getE()
        {
            return E;
        }
    };
    class edge{
        vertice* V[2];
    public:
        edge(vertice* v1,vertice* v2)
        {
            V[0]=v1;
            V[1]=v2;
        }
        void setVertice(vertice* v1,vertice* v2)
        {
            V[0]=v1;
            V[1]=v2;
        }
        vertice** getV()
        {
            return V;
        }
    };
    class graph{
        vector<vertice* > lv;
        vector<edge* > le;
    public:
        graph(int v,int e)
        {
            lv=vector<vertice*>(v);
            le=vector<edge*>(e);
        }
        int numV()
        {
            return lv.size();
        }
        int numE()
        {
            return le.size();
        }
        void insertEdge(int v1,int v2)
        {
            edge* e=new edge(lv[v1-1],lv[v2-1]);
            le.push_back(e);
            lv[v1-1]->setEdge(e);
            lv[v2-1]->setEdge(e);
        }
        int areAdjacent(int v1,int v2)
        {
            if(v1!=v2)
            {
                vector<edge*> v = lv[v1-1]->getE();
                vector<edge*>::iterator i;
                vertice** x;
                for(i=v.begin();i<v.end();i++)
                {
                    x=(*i)->getV();
                    if(x[0]==lv[v2-1]||x[1]==lv[v2-1])
                        return 1;
                }
                return 0;
            }
            return 0;
        }
    };
    int a[100]={0};
    void dfs(graph G,int v)
    {
        cout<<v<<" ";
        a[v-1]=1;
        for(int i=1;i<=G.numV();i++)
            if(G.areAdjacent(v,i))
                if(!a[i-1])
                    dfs(G,i);
    }
    void dfs(graph G)
    {
        for(int i=1;i<=G.numV();i++)
            if(!a[i-1])
                dfs(G,i);
    }
    int main()
    {
        int V,E;
        cout<<"Number of vertices ?";
        cin>>V;
        cout<<"Number of edges?";
        cin>>E;
        graph g(V,E);
        cout<<"Next,enter like this format:vertex-vertex,meaning that there is an edge between them"<<endl;
        int x,y;
        for(int i=1;i<=E;i++)
        {
            cin>>x>>y;
            g.insertEdge(x,y);
        }
        dfs(g);

    }


