// Pure Virtual Functions and Abstract Base classes in C++

#include <iostream>
#include <cstring>
using namespace std;

// designed only to inherit other classes from this class
// we can not create object for this class
// it has atleast 1 pure virtual function
class CodeWithHarry
{
protected:
    string video_title;
    float video_rating;

public:
    CodeWithHarry(string s, float r)
    {
        video_title = s;
        video_rating = r;
    }
    virtual void display() = 0; // do-nothing function --> pure virtual function 
    // i.e. aisa derived class na ban jayen jo mere redefine na karein
    // agar derived class mein redefined nahi karenge to error throw karega
};

class CodeWithHarryVideo : public CodeWithHarry
{
    float video_length;

public:
    CodeWithHarryVideo(string s, float r, float vl) : CodeWithHarry(s, r)
    {
        video_length = vl;
    }
    void display()
    {
        cout << "This as amazing video with video title " << video_title << endl;
        cout << "Ratings: " << video_rating << " out of 5 stars" << endl;
        cout << "Length of this video is : " << video_length << " minutes" << endl;
    }
};

class CodeWithHarryWebsite : public CodeWithHarry
{
    int words_on_website;

public:
    CodeWithHarryWebsite(string s, float r, int wc) : CodeWithHarry(s, r)
    {
        words_on_website = wc;
    }
    void display()
    {
        cout << "This as amazing website on video with title " << video_title << endl;
        cout << "Ratings of this website tutorial: " << video_rating << " out of 5 stars" << endl;
        cout << "No of words in this website tutorial is  : " << words_on_website << " words" << endl;
    }
};

int main()
{
    string title_video, title_website;
    float rating_video, rating_website, vlen;
    int words;

    // for code with harry video
    title_video = " virtual function tutorial";
    vlen = 4.56;
    rating_video = 4.89;
    CodeWithHarryVideo virtual_function_video(title_video, rating_video, vlen);
    // virtual_function_video.display();

    // for code with harry website
    title_website = "virtual function tutorial";
    words = 423;
    rating_website = 4.8;
    CodeWithHarryWebsite virtual_function_website(title_website, rating_website, words);
    // virtual_function_website.display();

    // calling display function using pointers
    CodeWithHarry *tut[2];
    tut[1] = &virtual_function_video;
    tut[2] = &virtual_function_website;
    tut[1]->display();
    tut[2]->display();

    return 0;
}

/*data members and methods of an abstract base class are just made to be used by objects of the derived class
Yes, that's correct. 
The data members and methods (including pure virtual functions) of an abstract base class are designed to be inherited by and used by objects of the derived class. 
The purpose of an abstract base class is to provide a common interface and shared functionality that is common among its derived classes.
*/