#include <iostream>
#include <vector>
#include <string>
using namespace std;

class IUser;
class IChannel {
public:
    virtual void upload() = 0;
    virtual void notify() = 0;
    virtual void attachUser(IUser* user) = 0;
};

class IUser {
public:
    virtual void subscribe(IChannel* channel) = 0;
    virtual void update(string message) = 0;
};

class YoutubeChannel : public IChannel {
private:
    vector<IUser*> subscribers;
    string channelName;

public:
    YoutubeChannel(string name) : channelName(name) {}

    void upload() override {
        notify();
    }

    void notify() override {
        for (IUser* user : subscribers) {
            user->update("new video uploaded by " + channelName);
        }
    }

    void attachUser(IUser* user) override {
        subscribers.push_back(user);
    }
};

class YoutubeUser : public IUser {
private:
    string userName;

public:
    YoutubeUser(string name) : userName(name) {}

    void subscribe(IChannel* channel) override {
        channel->attachUser(this);
    }

    void update(string message) override {
        cout << "[" << userName << "]" << message << endl;
    }
};

int main(){
    int C, U;
    cin >> C >> U;
    IUser* users[U];
    IChannel* channels[C];
    for(int i = 0; i < U; ++i){
        users[i] = new YoutubeUser("user" + to_string(i));
    }

    for(int i = 0; i < C; ++i){
        channels[i] = new YoutubeChannel("channel" + to_string(i));
    }

    int c, u;
    while ((cin >> c >> u) && !cin.eof()){ 
        // call upload
        if(u == -1){
            channels[c]->upload();
        }
        else{
            users[u]->subscribe(channels[c]);
        }
    }
}
