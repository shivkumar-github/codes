// Virtual Functions Examples + Creation Rules in C++

#include <iostream>
#include <cstring>
using namespace std;
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
    virtual void display() {}
    /* if we don't write vitual then this display
       function will be invoked when we call display()
       for pointer of derived class and
       ... if there is no display() function in derived class
       then display() function of base class will be invoked */
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


/*Rules for virtual function
1. They can not be static
2. They are accessed by object pointers
3. Virtual function can be a friend of another class
4. A virtual function in base class might not be used
5. If a virtual function is defined in a base class,
   there is no necessity of redifining it in the derived class 
   
   
   
   
   */