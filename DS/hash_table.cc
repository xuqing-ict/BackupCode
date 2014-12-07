/**
 * @file hash_table.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-19
 */

//tackle the hash conflict by separate chaining
//define the node in list
template<class K ,class V>
struct listNode
{
    K key;
    V value;
    ListNode *next;
    listNode(int _key, int _value):key(_key),value(_value),next(nullptr){}
};

template<class K, class V>
class Hash
{
private:
    list<listNode<K,V> > items;
    const static int MAX = 10;
public:
    Hash()
    {
        items = new ListNode<K,V>[MAX];
    }
    int hashKey(K key)
    {
        //hash function
    }
    //add key
    void put(K key, V value)
    {
        int idx = hashKey(key);
        if(items[idx] == nullptr)
        {
            items[idx] = new ListNode<K,V>();
        }
        ListNode<K,V> *node = items[idx];
        ListNode<K,V> *tmp = nullptr;
        for(tmp = node; tmp; tmp=tmp->next)
        {
            if(tmp->key == key)
            {
                tmp->value = value;
                break;
            }
        }
        ListNode<K,V> node = new ListNode<K,V>(key,value);
        tmp.add(node);
    }

};
