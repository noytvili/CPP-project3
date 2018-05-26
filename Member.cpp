#include "Member.h"
#include <iostream>
using namespace std;

int Member:: counter = 0;
     
Member:: Member(){  //constructor
    num_Followers = 0;
    num_Following = 0;
    counter++;
}

Member:: ~Member() {  //distructor
    if(counter > 0){
       counter--; 
    }
    for (int i = 0; i < num_Followers; i++) {
        arr_follower[i]->unfollow(*this);
    }
    for (int i = 0; i < num_Following; i++) {
        unfollow(*arr_following[i]);
    }
}

int Member:: count(){
    return counter;
}
    
void Member:: follow(Member& name){
    bool flag = false;
    if(this == &name) flag = true;
    for(int h = 0; h <= name.num_Followers; h++){  //check if the object exist in follower array
        if(this == name.arr_follower[h]){
            flag = true;
            break;
        }
    }
    if(flag == false){ // the object not exist in follower array
        for(int j = 0; j <= name.num_Followers; j++){ //
            if(name.arr_follower[j] == nullptr){
                name.arr_follower[j] = this;
            }
        }
        name.num_Followers++;

        for(int f = 0; f <= this->num_Following; f++){  // go over the array of the object following
            if(&name!= this->arr_following[f]){  
                for(int k = 0; k <= this->num_Following; k++ ){
                    if(this->arr_following[k] == nullptr){
                       this->arr_following[k] = &name;
                    }
                }
            }
        }
        this->num_Following++;
    }
 }
     
void Member::unfollow(Member& name){
    bool flag = false;
    for(int h = 0; h < name.num_Followers; h++){  //check if the object exist in follower array
        if(this == name.arr_follower[h]){
            flag = true;
            break;
        }
    }
    
    if(flag == true){
        for(int i = 0; i < name.num_Followers; i++){  
            if (this == name.arr_follower[i]){
                name.arr_follower[i] = nullptr;
                name.num_Followers--;
                break;
            }
        }
           for(int j = 0; j < this->num_Following; j++){
        if(&name == this->arr_following[j]){
            this->arr_following[j] = nullptr;
            this->num_Following--;
            break;
            }   
        }
    }
    else if(this == &name) flag = false;  //make sure that the member don't follow after himself
    else { 
       cout << "ERROR- no followers for this member!\n";
       
    }
}
     
int Member::numFollowers(){
    return num_Followers;
}
    
int Member::numFollowing(){
    return num_Following;
}
