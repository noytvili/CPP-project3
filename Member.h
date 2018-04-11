
using namespace std;

class Member{
    private :
        static int counter;
        int num_Followers;
        int num_Following;
        Member* arr_follower [1000]= {nullptr};
        Member* arr_following [1000] = {nullptr};

    public : 
        Member();
        ~Member();
        void follow(Member&);
        void unfollow(Member&);
        int numFollowers();
        int numFollowing();
        static int count();
};
