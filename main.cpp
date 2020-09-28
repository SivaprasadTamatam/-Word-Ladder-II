#include <iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

vector<vector<string> >  sol;
    
    set<string> getSet(vector<string>& wordList) {
        set<string> res;
        for(string str : wordList) {
            res.insert(str);
        }
        return res;
    }
    
    
    void dfs(string& beginWord, string& endWord, map<string, set<string> >& G, vector<string>  &V) {
        V.push_back(beginWord);
        if(beginWord == endWord) {
            sol.push_back(V);
            V.pop_back();
            return;
        }
        for(string x : G[beginWord]) {
            dfs(x, endWord, G, V);
        }
        V.pop_back();
    }
    
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, set<string> > resGraph;
        set<string> S = getSet(wordList);
        
        
        queue<string> Q;
               Q.push(beginWord);
               unordered_map<string, int> vis;
               vis[beginWord] = 0;
               while(!Q.empty()) {
                   string tp = Q.front();
            Q.pop();
            string ctp = tp;
            for(int i = 0; i < tp.size(); ++i) {
                for(char x = 'a'; x <= 'z'; ++x) {
                    if(ctp[i] == x) {
                        continue;
                    }
                    ctp[i] = x;
                    if(S.count(ctp) > 0) {
                        if(vis.count(ctp) == 0) {
                            vis[ctp] = vis[tp] + 1;
                            Q.push(ctp);
                            resGraph[tp].insert(ctp);
                        } else {
                            if(vis[ctp] == vis[tp] + 1) {
                                resGraph[tp].insert(ctp);
                            }
                        }
                    }
                    ctp[i] = tp[i];
                }
            }
        }
        vector<string> V;
        dfs(beginWord, endWord, resGraph, V);
        return sol;
        
    }

int main(int argc, const char * argv[]) {
    string beginWord = "hit", endWord = "cog";
    vector<string> v = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> res = findLadders(beginWord, endWord, v);
    for (auto v : res){
        for( auto s : v){
            cout<<s<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
