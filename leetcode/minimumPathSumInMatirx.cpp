#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

 struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
 };

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        UndirectedGraphNode *new_node = NULL;

        unordered_map< UndirectedGraphNode *, UndirectedGraphNode * > pairs;
        unordered_set< UndirectedGraphNode * > exist;

        queue<UndirectedGraphNode *> q;
        q.push(node);

        UndirectedGraphNode *prev, *now;

        //queue 用来遍历节点。
        while(!q.empty())
        {
            UndirectedGraphNode *prev = q.front();
            q.pop();

            //如果该节点已经处理过了(表示它的邻居节点已经添加完毕)，直接返回
            if(exist.find(prev) != exist.end())
            {
                continue;
            }

            unordered_map< UndirectedGraphNode *, UndirectedGraphNode * >::iterator it = pairs.find(prev);
            UndirectedGraphNode *now = NULL;

            //if node 是第一次访问，即还没有创建新节点
            //visit prev first
            if( it == pairs.end())
            {
                now = new UndirectedGraphNode(prev->label);
                pairs[prev] = now;
                //exist.insert(prev);
            }
            else
            {
                now = it->second;
            }

            vector< UndirectedGraphNode *> neighbors = prev->neighbors;

            for(int i = 0 ; i < neighbors.size(); ++i)
            {
                it = pairs.find(neighbors[i]);
                UndirectedGraphNode *temp;
                if( it == pairs.end())
                {
                    temp = new UndirectedGraphNode(neighbors[i]->label);
                    pairs[neighbors[i]] = temp;
                }
                else
                {
                    temp = it->second;
                }

                (now->neighbors).push_back(temp);

                if(exist.find(neighbors[i]) == exist.end())
                {
                    q.push(neighbors[i]);
                }
            }
            exist.insert(prev);

        }
        return new_node;

    }
int main()
{

    return 0;
}
