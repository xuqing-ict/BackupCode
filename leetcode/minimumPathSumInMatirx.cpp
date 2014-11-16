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

        //queue ���������ڵ㡣
        while(!q.empty())
        {
            UndirectedGraphNode *prev = q.front();
            q.pop();

            //����ýڵ��Ѿ��������(��ʾ�����ھӽڵ��Ѿ�������)��ֱ�ӷ���
            if(exist.find(prev) != exist.end())
            {
                continue;
            }

            unordered_map< UndirectedGraphNode *, UndirectedGraphNode * >::iterator it = pairs.find(prev);
            UndirectedGraphNode *now = NULL;

            //if node �ǵ�һ�η��ʣ�����û�д����½ڵ�
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
