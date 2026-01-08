// LC 355: Design Twitter | Pattern: Heap + HashMap
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter {
    int timestamp = 0;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> [(time, tweetId)]
    unordered_map<int, unordered_set<int>> following;  // userId -> set of followees
    
public:
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        // Add own tweets
        for (auto& [time, id] : tweets[userId]) pq.push({time, id});
        // Add followees' tweets
        for (int followeeId : following[userId])
            for (auto& [time, id] : tweets[followeeId]) pq.push({time, id});
        
        vector<int> result;
        while (!pq.empty() && result.size() < 10) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    cout << "News feed: " << twitter.getNewsFeed(1).size() << " tweets\n";
    return 0;
}
