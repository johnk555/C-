#include <iostream>
#include <string>
using namespace std;

class video {
private:
    string nameOfArtist;
    string nameOfAlbum;
    int duration;
public:
    void set_video(const string& in_nameOfArtist, const string &in_nameOfAlbum, int in_duration);
    string get_nameOfArtist() const;
    string get_nameOfAlbum() const;
    int getDuration() const;
    friend ostream& operator<<(ostream& left, const video& video);

};

class playlist {
protected:
    string name;
    string description;
    int duration;
    video videos[100];
    int numberOfVideos;
public:
    playlist(string in_name, string in_description);
    void setPlaylist(string in_name, string in_description,int in_duration);
    void addVideo(const video& in_video);
    friend ostream& operator<<(ostream& left, const playlist& playlist);
};
class classical_playlist : public playlist {
private:
    string era;
public:
    classical_playlist(string in_name, string in_description,string in_era);
    friend ostream& operator<<(ostream& left, const classical_playlist& classical_playlist);
};

int main() {
    classical_playlist l("my playlist","the best songs","rock");

    
    video temp;

    temp.set_video("Mpagianteras", "Sa magameneo to myalo mou",207);

    l.addVideo(temp);

    cout<<l;

    video temp2;

    temp2.set_video("Snik","Millionaire",278);

    l.addVideo(temp2);

    cout<<l;

    return 0;
}

void video::set_video(const string& in_nameOfArtist, const string& in_nameOfAlbum, int in_duration) {
    nameOfArtist = in_nameOfArtist;
    nameOfAlbum = in_nameOfAlbum;
    duration = in_duration;
}

string video::get_nameOfArtist() const {
    return nameOfArtist;
}
string video::get_nameOfAlbum() const {
    return nameOfAlbum;
}
string get_nameOfAlbum();

int video::getDuration() const {
    return duration;
}

playlist::playlist(string in_name, string in_description)
{
    name = in_name;
    description = in_description;
    duration = 0;
    numberOfVideos = 0;
}
void playlist::setPlaylist(string in_name, string in_description,int in_duration) {
    name = in_name;
    description = in_description;
    duration = in_duration;
}
void playlist::addVideo(const video& in_video) {
    if (numberOfVideos < 100) { // Check if there's space for another video
        videos[numberOfVideos] = in_video; // Add the video to the array
        numberOfVideos++; // Increment the count of videos
        duration += in_video.getDuration(); // Update the total duration
    } else {
        cout << "Cannot add video. Playlist is full!" << endl;
    }
}
ostream& operator<<(ostream& left, const video& video) {
    left<<"("<<video.nameOfArtist<<","<<video.nameOfAlbum<<","<<video.duration<<")";
    return left;
}
ostream& operator<<(ostream& left, const playlist& playlist) {
    left<<"["<<playlist.name<<","<<playlist.description<<","<<playlist.duration;
    for (int i=0; i<playlist.numberOfVideos; i++)
        left<<endl<<playlist.videos[i];

    left<<"]"<<endl;

    return left;
}

classical_playlist::classical_playlist(string in_name, string in_description,string in_era):
playlist(in_name,in_description)
{
    era = in_era;
}
ostream& operator<<(ostream& left, const classical_playlist& classical_playlist) {
    left<<"["<<classical_playlist.name<<","<<classical_playlist.description<<","<<classical_playlist.duration<<","<<classical_playlist.era;
    for (int i=0; i<classical_playlist.numberOfVideos; i++)
        left<<endl<<classical_playlist.videos[i];

    left<<"]"<<endl;

    return left;
}
