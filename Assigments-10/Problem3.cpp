#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bits/stdc++.h>

class Twitter {
private:
    int timestamp;
    std::unordered_map<int, std::vector<std::pair<int, int>>> user_tweets; // userId -> [(timestamp, tweetId)]
    std::unordered_map<int, std::unordered_set<int>> user_follows; // userId -> {followeeId}

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        user_tweets[userId].emplace_back(timestamp++, tweetId);
    }

    std::vector<int> getNewsFeed(int userId) {
        std::vector<std::pair<int, int>> feed;
        feed.insert(feed.end(), user_tweets[userId].begin(), user_tweets[userId].end());

        if (user_follows.find(userId) != user_follows.end()) {
            for (int followee : user_follows[userId]) {
                feed.insert(feed.end(), user_tweets[followee].begin(), user_tweets[followee].end());
            }
        }

        // Sort the feed by timestamp in descending order.
        std::sort(feed.begin(), feed.end(), std::greater<std::pair<int, int>>());

        std::vector<int> result;
        int count = 0;
        for (auto& tweet : feed) {
            result.push_back(tweet.second);
            if (++count == 10) break;
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            user_follows[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        user_follows[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    std::vector<int> feed1 = twitter.getNewsFeed(1);  // Output: [5]
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    std::vector<int> feed2 = twitter.getNewsFeed(1);  // Output: [6, 5]
    twitter.unfollow(1, 2);
    std::vector<int> feed3 = twitter.getNewsFeed(1);  // Output: [5]

    std::cout << "Feed 1: ";
    for (int tweet : feed1) {
        std::cout << tweet << " ";
    }
    std::cout << std::endl;

    std::cout << "Feed 2: ";
    for (int tweet : feed2) {
        std::cout << tweet << " ";
    }
    std::cout << std::endl;

    std::cout << "Feed 3: ";
    for (int tweet : feed3) {
        std::cout << tweet << " ";
    }
    std::cout << std::endl;

    return 0;
}
