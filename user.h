#ifndef USER_H
#define USER_H
#include<iostream>
#include<activity.h>
#include<Queue.h>


class user
{
    public:
    user()
    {
        user_hash_value=hash_function();
        get_pass_word();
    }
    string return_name(){
    return username;
    }
    friend std::ostream& operator<<(std::ostream& os,const user& user)
    {
        os << "Username: " << user.username <<endl;
        user.display_activities();

        return os;
    }
    friend std::istream& operator>>(std::istream& is, user& user)
    {
        std::cout << "Enter username: ";
        is >> user.username;
        user.add_activites();
        //user.get_pass_word();
        return is;
    }
    string get_pass_word()
    {
        // Providing a seed value
        srand((unsigned) time(NULL));

        // Get a random number
        password = rand();

        // Print the random number
        return password;
    }
    void add_activites()
    {
        delete_expired();
        cout<<"ADD user activities : "<<endl;
        char ch='f';

         while(ch!='n'){
            activity c;
            cin>>c;

            q.enqueue(c);
            cout<<c;
            cout<<endl;

            cout<<"Add another activity ? (y/n) "<<endl;
            cin>>ch;
        }



    }
    void delete_expired()
    {
        if(q.q_size()>10)
            q.dequeue();

    }
    void remove_activities()
    {
        cout<<"Activities are  : "<<endl;
        q.display();
        char c = 'f';
        while(c!='n'){
             cout<<"Enter activity number to remove "<<endl;
        int num;
        cin>>num;
        q.remove_activity(num);
            cout<<"Do you want to remove another activity ? (y/n)"<<endl;
            cin>>c;
        }


    }
    void display_activities() const
    {

        q.display();
    }
    unsigned int hash_function ()
    {

        unsigned int sum=0;
        for (size_t i = 0; i < username.length(); ++i) {
                 sum += static_cast<int>(username[i]);

    }
        // hash_value=sum;
       return sum%100;

    }
    int return_q_size(){
      return q.q_size();
    }


protected:

private:
    Queue<activity> q;
    string username;
    string password;
    int user_hash_value;


};

#endif // USER_H
