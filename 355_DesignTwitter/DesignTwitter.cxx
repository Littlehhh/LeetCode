#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Twitter {
vector< pair<int, int> > tweet;
unordered_map<int, unordered_set<int> > followed;

public:
    /** Initialize your data structure here. */
    Twitter() {
        tweet.clear();
        followed.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet.push_back({userId, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(int i = tweet.size()-1; i >=0 ; --i){
            if(ans.size() < 10){
                auto found = followed.find(userId);
                if(found != followed.end()){
                    auto userList = found->second;
                    int Id = tweet[i].first;
                    if(userList.find(Id)!=userList.end() || Id == userId)
                        ans.push_back(tweet[i].second);
                }
                else{
                    if(userId == tweet[i].first)
                        ans.push_back(tweet[i].second);
                }
                
            }
        }
        return ans;

    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        auto found = followed.find(followerId);
        if(found != followed.end()){
            if(found->second.find(followeeId) == found->second.end())
                (found->second).emplace(followeeId);
        }
        else{
            followed[followerId].clear();
            followed[followerId].emplace(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto found = followed.find(followerId);
        if(found != followed.end()){
           (found->second).erase(followeeId);
        }
        else{
            followed[followerId].clear();
            followed[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */