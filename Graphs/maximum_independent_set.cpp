#include <bits/stdc++.h>
using namespace std;
#define big long long int
// Finding maximal independent sets of a simple graph using backtracking paradigm
set< set<int> > independentSets;
set< set<int> > maximalIndependentSets;

map< pair <int,int>, int > edges;
vector <int> vertices;
   void  printAllIndependentSets(){
       for(auto iter = independentSets.begin(); iter!= independentSets.end(); iter++)
       {
           cout << "{ ";
           for(auto iter2 = iter->begin(); iter2!=iter->end(); iter2++)
           {
               cout << *iter2 << " ";
           }
           cout << "}";
       }
       cout << endl;
   }
     void  printMaximalIndependentSets(){
         int maxCount = 0;
         int localCount =0;
       for(auto iter = independentSets.begin(); iter!= independentSets.end(); iter++)
       {

           localCount = 0;
           for(auto iter2 = iter->begin(); iter2!=iter->end(); iter2++)
           {
               localCount++;

           }
           if (localCount > maxCount)
           maxCount = localCount;

       }
              for(auto iter = independentSets.begin(); iter!= independentSets.end(); iter++)
       {

           localCount = 0;
            set<int> tempMaximalSet;
           
           for(auto iter2 = iter->begin(); iter2!=iter->end(); iter2++)
           {
               localCount++;
               tempMaximalSet.insert(*iter2);

           }
           if (localCount == maxCount)
           maximalIndependentSets.insert(tempMaximalSet);

       }
        for(auto iter = maximalIndependentSets.begin(); iter!= maximalIndependentSets.end(); iter++)
       {
           cout << "{ ";
           for(auto iter2 = iter->begin(); iter2!=iter->end(); iter2++)
           {
               cout << *iter2 << " ";
           }
           cout << "}";
       }
       cout << endl;
   }
bool isSafeForIndependentSet(int vertex, set<int> tempSolutionSet)
{
    for(auto iter = tempSolutionSet.begin(); iter!=tempSolutionSet.end(); iter++)
    {
        if (edges[make_pair(*iter,vertex)])
        {
            return false;
        }
    }
    return true;
}

void findAllIndependentSets(int mover, int setSize, set <int> tempSolutionSet)
{
    for(int i = mover; i<=setSize; i++)
    {
        if (isSafeForIndependentSet(vertices[i-1], tempSolutionSet)){
            tempSolutionSet.insert(vertices[i-1]);
            findAllIndependentSets(i+1, setSize, tempSolutionSet);
            tempSolutionSet.erase(vertices[i-1]);
        }
    }
    independentSets.insert(tempSolutionSet);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int numberOfVertices, numberOfEdges;
    cin >> numberOfVertices >> numberOfEdges;

    for(int i=1; i<=numberOfVertices; i++)
    vertices.push_back(i);

    pair<int,int> tempEdge;
    int x ,y;
    for(int i=1; i<=numberOfEdges; i++)
    {
        cin >> tempEdge.first;
        cin >> tempEdge.second;
        edges[tempEdge] = 1;
        int t = tempEdge.first;
        tempEdge.first = tempEdge.second;
        tempEdge.second = t;
        edges[tempEdge] = 1;
    }
    set<int> tempSolutionSet;
    findAllIndependentSets(1, numberOfVertices,tempSolutionSet);
    printAllIndependentSets();
    printMaximalIndependentSets();
	return 0;
}
