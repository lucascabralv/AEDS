#ifndef TELEVISAO_H
#define TELEVISAO_H

#include <iostream>

using namespace std;

class Televisao{
    private:
        int channel;
        int volume;

    public:
        Televisao();
        Televisao(int channel, int volume);
        void volumeUp();
        void volumeDown();
        void channelUp();
        void channelDown();
        void setVolume(int);
        void setChannel(int);
        int getChannel();
        int getVolume();
};


#endif // !TELEVISAO_H