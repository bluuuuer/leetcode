/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        this->t_id = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (this->t.find(userId) != this->t.end())                          // old user
            this->t[userId].push_back(make_pair(tweetId, this->t_id));
        else                                                                // new user
            this->t[userId] = {make_pair(tweetId, this->t_id)};
        this->t_id ++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> usersID = this->f[userId];
        usersID.push_back(userId);
        
        vector<pair<int, int> > news;
        for (int i = 0; i < usersID.size(); i ++) {
            vector<pair<int, int> > tweets = this->t[usersID[i]];
            news.insert(news.end(), tweets.begin(), tweets.end());
            sort(news.begin(), news.end(), comp);
        }
        
        vector<int> res;
        for (int i = 0; i < news.size(); i ++) {
            res.push_back(news[i].first);
            if (i == 9)
                return res;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            if (this->f.find(followerId) == this->f.end())
                this->f[followerId] = {followeeId};
            else {
                for (int i = 0; i < this->f[followerId].size(); i ++)
                    if (this->f[followerId][i] == followeeId)
                        return;
                this->f[followerId].push_back(followeeId);
            }
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId && this->f.find(followerId) != this->f.end()) {
            for (int i = 0; i < this->f[followerId].size(); i ++)
                if (this->f[followerId][i] == followeeId) {
                    this->f[followerId].erase(this->f[followerId].begin() + i);
                    break;
                }
        }
    }

private:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
    
    int t_id;
    map<int, vector<pair<int, int> > > t;
    map<int, vector<int> > f;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
