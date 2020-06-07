#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>
#include<string>

#include<iostream>

using namespace std;

class Solution1 {
public:
    vector<vector<string>> ans;
    unordered_map<string, int> vis;
    int minSeq;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(!s.count(endWord)) return {};
        s.insert(beginWord);
        
        unordered_map<string, vector<string> > map;
        for(auto vertex = s.begin(); vertex!=s.end();++vertex){
            for(auto it = vertex; it!=s.end(); ++it){
                if(canConvert(*vertex, *it)){
                    map[*vertex].push_back(*it);
                    map[*it].push_back(*vertex);
                }
            }
        }
        vector<string> tmp;
        tmp.push_back(beginWord);
        for(auto && it:s){
            vis[it] = 0;
        }
        vis[beginWord] = 1;
        minSeq = INT_MAX;
        bfs(beginWord, endWord, tmp, map);
        return ans;
    }
    void bfs(string& start, string& endWord, vector<string> tmp,unordered_map<string, vector<string> >& map){
        if(start == endWord){
            if(tmp.size() < minSeq){
                ans.clear();
                minSeq = tmp.size();
            }
            ans.push_back(tmp);
            return;
        }
        for(auto vertex:map[start]){
            if(vis[vertex] == 0 && tmp.size() < minSeq){
                vis[vertex] = 1;                
                tmp.push_back(vertex);
                bfs(vertex, endWord, tmp, map);
                tmp.pop_back();
                vis[vertex] = 0;
            }
        }           
        return;
    }

    bool canConvert(string s1, string s2){
        if(s1.size()!=s2.size()) return false;
        int count = 0;
        for(int i=0; i< s1.size(); ++i){
            if(s1[i] != s2[i]) ++count;
        }
        return count == 1;
    }
};


class Solution2 {
public:
    vector<vector<string>> ans;
    unordered_map<string, int> vis;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(!s.count(endWord)) return {};
        s.insert(beginWord);
        unordered_map<string, vector<string> > map;
        for(auto vertex = s.begin(); vertex!=s.end();++vertex){
            for(auto it = std::next(vertex, 1); it!=s.end(); ++it){
                if(canConvert(*vertex, *it)){
                    map[*vertex].push_back(*it);
                    map[*it].push_back(*vertex);
                }
            }
        }
        
        for(auto && it:s){
            vis[it] = 0;
        }
        auto path = bfs(beginWord, endWord, map);
        for(auto && it:s){
            vis[it] = 0;
        }
        vector<string> tmp;
        tmp.push_back(beginWord);
        dfs(0, beginWord, endWord, tmp, map, path);
        return ans;
    }

    void dfs(int depth, string& start, string& endWord, vector<string>& tmp,unordered_map<string, vector<string> >& map, vector<unordered_set<string>> path){
        if(start == endWord){
            ans.push_back(tmp);
            return;
        }
        if(depth >= path.size()) return;
        for(auto vertex:map[start]){
            if(vis[vertex] == 0 && path[depth].count(vertex)){
                vis[vertex] = 1;                
                tmp.push_back(vertex);
                dfs(depth+1, vertex, endWord, tmp, map, path);
                tmp.pop_back();
                vis[vertex] = 0;
            }
        }           
        return;
    }

    vector<unordered_set<string>> bfs(string& start, string& endWord,unordered_map<string, vector<string> >& map){
        queue<string> q;
        q.push(start);
        vector<unordered_set<string>> path;
        int curLevel=1;
        bool found = false;
        while(!q.empty() && !found){
            int nextLevel=0;
            unordered_set<string> tmp;
            while(curLevel--){
                auto v = q.front();
                q.pop();
                vis[v] = 1;
                for(auto && vertex: map[v]){
                    if(vertex == endWord){
                        found = true;
                    }
                    if(vis[vertex] == 0){
                        q.push(vertex);
                        tmp.insert(vertex);
                        nextLevel++;
                    }
                }
            }
            path.push_back(tmp);
            curLevel = nextLevel;
        }
        return path;
    }
    bool canConvert(string s1, string s2){
        if(s1.size()!=s2.size()) return false;
        int count = 0;
        for(int i=0; i< s1.size(); ++i){
            if(s1[i] != s2[i]) ++count;
        }
        return count == 1;
    }
};

class Solution1 {
public:
    vector<vector<string>> ans;
    unordered_map<string, int> vis;
    using idx = int;
    using Path = pair<int, string>;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(!s.count(endWord)) return {};
        s.insert(beginWord);
        
        unordered_map<string, vector<string> > map;
        for(auto vertex = s.begin(); vertex!=s.end();++vertex){
            for(auto it = std::next(vertex, 1); it!=s.end(); ++it){
                if(canConvert(*vertex, *it)){
                    map[*vertex].push_back(*it);
                    map[*it].push_back(*vertex);
                }
            }
        }
        
        for(auto && it:s){
            vis[it] = 0;
        }
        auto path = bfs(beginWord, endWord, map);
        recoverPath(beginWord, endWord, path);
        return ans;
    }
    void recoverPath(string & start, string& endWord ,vector<vector<Path>> & path){
        int level = path.size()-1;
        for(auto && p:path[level]){
            vector<string> tmp;
            if(p.second == endWord){
                tmp.push_back(endWord);
                int l = level-1;
                int idx = p.first;
                while(l>=0){
                    Path preLevel = path[l][idx];
                    tmp.push_back(preLevel.second);
                    idx = preLevel.first;
                    l--;
                }
                tmp.push_back(start);
                std::reverse(tmp.begin(), tmp.end());
                ans.push_back(tmp);
            }
        }
    }

    vector<vector<Path>> bfs(string& start, string& endWord,unordered_map<string, vector<string> >& map){
        queue<string> q;
        q.push(start);
        vector<vector<Path>> path;

        int curLevel=1;
        bool found = false;
        while(!q.empty() && !found){
            int nextLevel=0;
            vector<Path> tmp;
            int i=0;
            while(i < curLevel){
                auto v = q.front();
                q.pop();
                vis[v] = 1;
                for(auto && vertex: map[v]){
                    if(vertex == endWord){
                        found = true;
                    }
                    if(vis[vertex] == 0){
                        q.push(vertex);
                        tmp.push_back({i, vertex});
                        nextLevel++;
                    }
                }
                i++;
            }
            path.push_back(tmp);
            curLevel = nextLevel;
        }
        return path;
    }

    bool canConvert(string s1, string s2){
        if(s1.size()!=s2.size()) return false;
        int count = 0;
        for(int i=0; i< s1.size(); ++i){
            if(s1[i] != s2[i]) ++count;
        }
        return count == 1;
    }
};


class Solution2
{
public:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> hash;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dirc(wordList.begin(), wordList.end());
        if (dirc.find(endWord) == dirc.end())
            return res;
        unordered_set<string> beginw{beginWord};
        unordered_set<string> endw{endWord};
        int flag1 = 0, flag2 = 0;//第一个是否找到最短序列标志, 第二个是否反转标志。 
        while (!beginw.empty())
        {
            unordered_set<string> next;
            for (auto str : beginw)
                dirc.erase(str);
            for (auto str : beginw)
            {
                
                for (int i = 0; i < str.size(); ++i)
                {
                    string s = str;
                    for (char j = 'a'; j <= 'z'; ++j)
                    {
                        s[i] = j;

                        if (!dirc.count(s))
                            continue;
                        if (endw.count(s)) //如果两个set相遇了
                            flag1 = 1;
                        else
                            next.insert(s);
                        flag2 ? hash[s].push_back(str) : hash[str].push_back(s); //反转，始终保证hash里key是原string，value是被替换后的string (保证之后树dfs遍历的时候是从beginWord到endWord的顺序)
                    }
                }
            }
            if (flag1) ////已经找到最短序列退出循环。
                break; 
            beginw = next;
            if (beginw.size() > endw.size())
            {
                swap(beginw, endw);
                flag2 = !flag2; //这里需要使用！反转。
            }
        }
        vector<string> ans = {beginWord};
        dfs(ans, beginWord, endWord);
        return res;
    }

    void dfs(vector<string> &ans, string &begin, string &end)
    {
        if (begin == end)
        {
            res.emplace_back(ans);
            return;
        }
        if (!hash.count(begin))
            return;
        for (auto str : hash[begin])
        {
            ans.emplace_back(str);
            dfs(ans, str, end);
            ans.pop_back();
        }
    }
};


class Solution {
public:

    void dfs(string &beginWord,string &curr,vector<string> path,unordered_map<string,vector<string>> &neighbor,vector<vector<string>> &res){
        if(curr==beginWord){
            //到达了迭代终点
            path.push_back(curr);
            reverse(path.begin(),path.end());
            res.push_back(path);
            return;
        }
        //这里的path记录状态，这是c++的一个技巧，状态使用传值，则每个节点都是一个全新的状态，无需状态重置。
        path.push_back(curr);
        for(auto word:neighbor[curr]){
            //对于邻接节点
            dfs(beginWord,word,path,neighbor,res);
        }
        
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<string> path;
        unordered_set<string> dicts(wordList.begin(),wordList.end());
        if(dicts.count(endWord)==0)
            return res;

        unordered_map<string,int>depth;
        unordered_map<string,vector<string>> neighbor;

        depth[beginWord]=1;
        queue<string> Q;
        Q.push(beginWord);

        while(!Q.empty()){
            string curr=Q.front();
            Q.pop();

            for(int i=0;i<curr.size();i++){
                string temp=curr;
                for(int j=0;j<26;j++){
                    temp[i]=j+'a';

                    if(dicts.count(temp)!=0){
                        if(depth[temp]==0){
                            Q.push(temp);
                            depth[temp]=depth[curr]+1;
                            neighbor[temp].push_back(curr);
                        }else if(depth[temp]==depth[curr]+1)
                            neighbor[temp].push_back(curr);
                    }
                }
            }
        }


        dfs(beginWord,endWord,path,neighbor,res);
        return res;     
        
    }
};

int main(){
    Solution1 s;
    vector<string> wordList{"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
    s.findLadders("cet", "ism", wordList);

}
