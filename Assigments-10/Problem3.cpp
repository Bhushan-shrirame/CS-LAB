#include <bits/stdc++.h>
using namespace std;


class Twitter {
    class Tweet {
        int user;
        int tweetId;
        public Tweet(int _user, int _tweetId) {
            this.user = _user;
            this.tweetId = _tweetId;
        }
    }
    HashMap<Integer, Set<Integer>> followings;
    List<Tweet> tweets;

    public Twitter() {
        this.followings = new HashMap<>();
        this.tweets = new ArrayList<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        this.tweets.add(new Tweet(userId, tweetId));
    }
    
    public List<Integer> getNewsFeed(int userId) {
        int n = this.tweets.size();
        List<Integer> ans = new ArrayList<>();
        Set<Integer> follows  = this.followings.get(userId);
        for(int i=n-1; i>=0; i--) {
            if(ans.size() >= 10) return ans;
            Tweet t = this.tweets.get(i);
            if(t.user == userId || (follows != null && follows.contains(t.user))) {
                ans.add(t.tweetId);
            }
        }
        return ans;
    }
    
    public void follow(int followerId, int followeeId) {
        Set<Integer> set;
        if(this.followings.containsKey(followerId)) {
            set = this.followings.get(followerId);
        } else {
            set = new HashSet<>();
            this.followings.put(followerId, set);
        }
        set.add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        Set<Integer> set = this.followings.get(followerId);
        if(set != null) set.remove(followeeId);
    }
}

int main(){
    Twitter sol;
    // Update the solve function as per the requirement
    sol.sovle();
    return 0;
}