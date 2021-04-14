#include <string>
#include <vector>
#include <iostream>
using namespace std;

class trie {
private: 
    trie* next[26] = {nullptr};
    bool is_string = false;
public:
    //? 构造函数
    trie(){
        is_string = false;
    };


    //? 插入
    void insert(const string& s) {
        trie* root = this;
        for (auto c : s) {
            if (root->next[c - 'a'] == nullptr) {
                //? 说明还没有这个字母
                root->next[c - 'a'] = new trie();
            }
            //? 更新root
            root = root->next[c - 'a'];
        }
        root->is_string = true;
    }

    //? 查找
    bool search(const string& s) {
        trie* root = this;
        for (auto c : s) {
            if (root->next[c -'a'] == nullptr) return false;
            else {
                root = root->next[c - 'a'];
            }
        }
        if (root->is_string == true) return true;
        else return false;
    }

    //? 查找前缀
    bool startsWith(const string& prefix)//
	{
		trie* root = this;
		for (const auto& p : prefix) {
			if (root->next[p - 'a'] == nullptr)return false;
			root = root->next[p - 'a'];
		}
		return true;
	}


};