#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res,tmp;
        string t,ts;
        int cur=0,cnt=0,sp,n,x;
        for(int i=0;i<words.size();i++)
        {
            // cout<<cur<<','<<words[i].size()<<endl;
            if((cur+words[i].size())>maxWidth)
            {
                ts = t = "";
                n = tmp.size()-1;
                sp = maxWidth-cnt;
                if(n==0)
                {
                    for(int i=0;i<sp;i++)
                    ts+=' ';
                    t = tmp[0]+ts;
                }else
                {
                    x = sp%n;
                    sp/=n;
                    for(int i=0;i<sp;i++)
                        ts+=' ';
                    t = tmp[0];
                    for(int i=1;i<=n;i++)
                    {
                        t+=ts;
                        if(x)
                        {
                            t+=' ';
                            x--;
                        }
                        t+=tmp[i];
                    }
                }
                cur = cnt = 0;
                tmp.clear();
                res.push_back(t);
            }
            cnt+=words[i].size();
            cur+=words[i].size()+1;
            tmp.push_back(words[i]);
        }
        if(tmp.size())
        {
            t = tmp[0];
            for(int i=1;i<tmp.size();i++)
            {
                t += ' ';
                t += tmp[i];
            }
            while(t.size()<maxWidth)
                t+=' ';
            res.push_back(t);
        }
        return res;
    }
};