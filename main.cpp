#include <iostream>
#include <cassert>
#include "Member.h"
using namespace std;

Member avi, beni, chana;

void test1() {  //check constructor
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	assert(chana.numFollowers() == 0 && chana.numFollowing() == 1);
	assert(avi.numFollowers() == 1 && avi.numFollowing() == 0);
	assert(Member::count() == 4);
}

void test2(){  //check unfollow when there is zero followers
    avi.unfollow(beni); //ERROR
    assert(avi.numFollowers() == 0 && beni.numFollowing() == 0);
}

void test3(){  //check that duplicate follow has no effect
	chana.follow(avi);
	chana.follow(avi);
	assert(chana.numFollowers() == 0 && chana.numFollowing() == 1);
	assert(avi.numFollowers() == 1 && avi.numFollowing() == 0);
}

void test4(){ //check distructor
    assert(chana.numFollowers() == 0 && chana.numFollowing() == 1);
	assert(avi.numFollowers() == 1 && avi.numFollowing() == 0);
	assert(Member::count() == 3);
}

void test5(){  //check that member can't follow after himself
    chana.follow(chana);
    assert(chana.numFollowers() == 0 && chana.numFollowing() == 1);
}

void test6(){  //check that member can't unfollow after himself
    chana.unfollow(chana);
    assert(chana.numFollowers() == 0 && chana.numFollowing() == 1);
}

int main() {
	// cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	// avi.follow(beni);
	// cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	// cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	// cout << endl;

	// avi.follow(beni); // duplicate follow has no effect
	// cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	// avi.unfollow(beni);	
	// cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0     
	// cout << endl;

	// cout << chana.numFollowers() << " " << chana.numFollowing() << endl; // 0 0
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	// cout << chana.numFollowers() << " " << chana.numFollowing() << endl; // 0 0
	// cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	// cout << Member::count() << endl; // 3
}
