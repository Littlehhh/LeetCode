#include<vector>
#include<string>
using namespace std;


class Solution1 {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n=sentence.size();
        int dp[n+1];
        dp[0]=0;
        for(int i=0;i<n;++i){
            dp[i+1]=dp[i]+1;
            for(auto& word:dictionary){
                if(word.size()<=i+1){
                    if(word==sentence.substr(i+1-word.size(),word.size()))
                        dp[i+1]=min(dp[i+1],dp[i+1-word.size()]);
                }
            }
        }
        return dp[n];
    }
};


class Trie {
public:
    Trie* next[26] = {nullptr};
    bool isEnd;
    
    Trie() {
        isEnd = false;
    }

    void insert(string s) {
        Trie* curPos = this;

        for (int i = s.length() - 1; i >= 0; --i) {
            int t = s[i] - 'a';
            if (curPos->next[t] == nullptr) {
                curPos->next[t] = new Trie();
            }
            curPos = curPos->next[t];
        }
        curPos->isEnd = true;
    }
};

class Solution2 {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.length(), inf = 0x3f3f3f3f;

        Trie* root = new Trie();
        for (auto& word: dictionary) {
            root->insert(word);
        }

        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;

            Trie* curPos = root;
            for (int j = i; j >= 1; --j) {
                int t = sentence[j - 1] - 'a';
                if (curPos->next[t] == nullptr) {
                    break;
                } else if (curPos->next[t]->isEnd) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
                if (dp[i] == 0) {
                    break;
                }
                curPos = curPos->next[t];
            }
        }
        return dp[n];
    }
};


class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        // dp
        const int len = sentence.size();
        vector<int> dp(len + 1);
        for(int i = 1; i <= len; ++i)
        {
            dp.at(i) = dp.at(i - 1) + 1;
            for(const auto& word : dictionary)
            {
                if(word.size() <= i && 
                strEq(sentence, i - word.size(), i, word))
                // substr() 方法生成新的字符串内存消耗很大
                // word == sentence.substr(i - word.size(), word.size()))
                dp.at(i) = min(dp.at(i), dp.at(i - word.size()));
            }
        }
        return dp.back();
    }

    bool strEq(const string& str, int start, int end, const string& word)
    {
        if(end - start < 0 || end - start != word.size()) return false;
        for(int i = 0; start < end; ++i, ++start)
        {
            if(str.at(start) != word.at(i)) return false;
        }
        return true;
    }
};
