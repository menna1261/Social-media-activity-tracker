#ifndef ACTIVITY_H
#define ACTIVITY_H
#include<iostream>
#include<ctime>
using namespace std;


class activity
{

    private :
    string activity_;
    time_t activity_time;

public:
    int hash_value;
    activity()
    {
        activity_time = time(0);
        hash_value = hash_function();
    }
    friend std::ostream& operator<<(std::ostream& os, const activity& a)
    {
        cout<<"activity : "<<a.activity_;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, activity& a)
    {
        cout<<"Add activities : "<<endl;
        cout<<"(1)"<<" Liked a post "<<endl;
        cout<<"(2)"<<" Liked a comment "<<endl;
        cout<<"(3)"<<" shared a post "<<endl;
        cout<<"(4)"<<" commented on a post "<<endl;
        //cout<<"(5)"<<username<<" shared a post "<<endl;
        int ch;
        cin>>ch;
        switch(ch)
        {
        case 1 :
        {
            a.activity_=" Liked a post";
        }
        break;
        case 2 :
        {
            a.activity_=" Liked a comment";

        }
        break;
        case 3 :
        {
            a.activity_=" Shared a post";

        }
        break;
        case 4 :
        {
            a.activity_=" commented on a post";
        }
        break;
        }
        return is;


    }
    bool is_expired(time_t t2)
    {
        if(difftime(t2,activity_time)>1209600)  // if the activity has been stored for more than 2 weeks then it's expired
        {
            return true;
        }
        return false;

    }
    unsigned int hash_function ()
    {

        unsigned int sum=0;
        for (size_t i = 0; i < activity_.length(); ++i) {
                 sum += static_cast<int>(activity_[i]);

    }
        // hash_value=sum;
       return sum%100;

    }


};

#endif // ACTIVITY_H




