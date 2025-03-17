#include <iostream>
using namespace std;

class MediaFile{
    protected:
    string filepath;
    double size;
    public:
    MediaFile(string path,int sz ): filepath(path),size(sz) {

    }
    virtual void play(){
        cout<<"media file"<< filepath << " is played" << endl;
    }

    virtual void stop(){
        cout<<"media file"<< filepath <<" is stopped from playing";
    }

    virtual ~MediaFile(){};

};

class VisualMedia: virtual public MediaFile{
    protected :
    string resolution;

    public:
    VisualMedia(string path, int sz, string resolutions) : MediaFile(path,sz),resolution(resolutions)

    void displayInfo(){
        cout<<"resolution:"<<resolution<<endl;
    }
};

class AudioMedia : virtual public MediaFile{
    protected:

    int sample_rate;

    public :

    AudioMedia(string path,int sz,int rate ) : MediaFile(path,sz),sample_rate(rate){}

    void AudioInfo(){
        cout<<"sample rate :"<<sample sample_rate<<endl;
    }
};

//VideoFile, ImageFile, or AudioFile objects,

class VideoFile:public VisualMedia,public AudioMedia{
public :
  VideoFile(string path, int sz, string resolutions,int rate):VisualMedia(path,sz,resolutions),AudioMedia(string path, int sz,int rate),MediaFile(string path,int sz ){}

  void playvideo(){
    cout<<"video file"<<filepath<<"played"<<endl;
  }

  void stopvideo(){
    cout<<"video file"<<filepath<<"stopped"<<endl;
  }
};

class ImageFile:public VisualMedia{
public:
ImageFile(string path, int sz, string resolutions):VisualMedia(path,sz,resolutions),MediaFile(string path,int sz ){}

void playimage(){
    cout<< "displaying image file:"<<filepath;
}
};

class AudioFile :public AudioMedia {
    AudioFile(string path,int sz,int rate): MediaFile(string path,int sz),AudioMedia(string path,int sz,int rate){}

    void playaudio(){
        cout<< "running audio  file:"<<filepath;
    }

};

