#include "Post.hpp"
#include "General.hpp"
// #include "Poll.hpp"
// #include "Promotional.hpp"
#include "Account.hpp"
#include "Network.hpp"
#include "LinkedList.hpp" // project 4, LinkedList.hpp already included "Node.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <cassert>
using namespace std;



// main to test
int main(){

    Network<Account> hi;

    Account sue("piglovesasy", "1989o117!!");
    
    Account tony("lovehatetony", "tonypwd");


//     Account joe("2", "speycast21");
//     Account andy("3", "andypwd");
//     Account cathy("4", "cathypwd");


//     // cout << "Before adding anything is Network empty? " << hi.isEmpty() << endl;
//     hi.addAccount(&sue);
//     hi.addAccount(&tony);
//     hi.addAccount(&joe);
//     hi.addAccount(&andy);
//     hi.addAccount(&cathy);
//     // cout << "Size of network is now: " << hi.getSizeOfNetwork() << endl;

//     hi.authenticateFollow(sue, "1"); // sue is following tony
//     // hi.authenticateFollow(sue, "2"); // sue is following joe
//     // hi.authenticateFollow(sue, "3"); // sue is following andy
//     // hi.authenticateFollow(sue, "4"); // sue is following cathy

//     // cout << "Size of Sue's friend list is now: " << sue.viewFollowing().size() << endl;


//     // Post ok("Tony's title", "Tony' body", "lovehatetony");
//     // Post * parentPost = new Post; // throws an error
    
//     // when tony makes a post
//     // Post * childGeneral = new General("tony title 1", "tony body 1", "1"); // tony username is "1"
//     // Post * childGeneralr = new General("tony title 2", "tony body 2", "1"); // tony username is "1"
//     // Post * childGeneralrr = new General("tony title 3", "tony body 3", "1"); // tony username is "1"


//     // Post * childGeneral2 = new General("general title2", "general body2", "2"); // joe
//     // Post * childGeneral3 = new General("general title3", "general body3", "3"); // andy
//     // Post * childGeneral4 = new General("general title4", "general body4", "4"); // cathy

//     // childGeneral->setPriority(Post::MEDIUM); // oldest
//     // childGeneralr->setPriority(Post::MEDIUM);
//     // childGeneralrr->setPriority(Post::MEDIUM); // newest




    









    
   
//     // // General is a Post, thus we can point to General object using pointer to a parent class.
//     // vector<string> in_vect_option = {"hi", "hello"};
//     // Post *childPoll = new Poll("POLL title", "POLL the body", "lovehatetony", in_vect_option);
//     // // Post *childPromotional = new Promotional("Promotional title", "Promotiotinal body", "lovehate", "http://www.something.something");
    
    Post * low1= new General("low_1", "tony body 1", "1"); // tony username is "1"
    Post * low2 = new General("low_2", "tony body 2", "1"); // tony username is "1"
    Post * low3 = new General("low_3", "tony body 3", "1"); // tony username is "1"

    Post * med1= new General("med_1", "tony body 1", "1"); // tony username is "1"
    Post * med2 = new General("med_2", "tony body 2", "1"); // tony username is "1"
    Post * med3 = new General("med_3", "tony body 3", "1"); // tony username is "1"

    Post * high1= new General("high_1", "tony body 1", "1"); // tony username is "1"
    Post * high2 = new General("high_2", "tony body 2", "1"); // tony username is "1"
    Post * high3 = new General("high_3", "tony body 3", "1"); // tony username is "1"
    Post * high4 = new General("high_4", "tony body 3", "1"); // tony username is "1"

    low1->setPriority(Post::LOW);
    low2->setPriority(Post::LOW);
    low3->setPriority(Post::LOW);

    med1->setPriority(Post::MEDIUM);
    med2->setPriority(Post::MEDIUM);
    med3->setPriority(Post::MEDIUM);

    high1->setPriority(Post::HIGH);
    high2->setPriority(Post::HIGH);
    high3->setPriority(Post::HIGH);
    high4->setPriority(Post::HIGH);


//     // test likes:


//     low2->like();
//     low2->like();
//     low2->like();

//     low3->like();
//     low3->like();
//     low3->like();

//     high4->like();
//     high4->like();
//     high4->like();

    
    cout << med3->getLikes() << "hihi" << endl;

//     tony.addPost(med3);
//     tony.addPost(low1);
//     tony.addPost(low3);
//     tony.addPost(high4);
//     tony.addPost(high2);
//     tony.addPost(low2);








  


        



//     // cout << "high4 post has " <<high4->getLikes() << " likes" << endl;

//     // tony.viewPosts();



//     // cout << tony.getMinLikes()->getLikes() << " " << tony.getMinLikes()->getTitle() << endl;
//     // tony.removePost(med2);


//     // cout << tony.getMaxLikes()->getLikes() << " " << tony.getMaxLikes()->getTitle() << endl;



//     cout << "\n\nincrease_old_to_new: " << endl; 
//     vector<Post*> increase_old_to_new = tony.increasingPriorityOldestToNewest();
//     for (int i = 0; i < increase_old_to_new.size(); i++){
//         cout << i << " " << increase_old_to_new[i]->getTitle() << " " << increase_old_to_new[i]->getPriority() << endl;
//     }


//     cout << "\n\ndecrease_new_to_old: " << endl; 
//     vector<Post*> decrease_new_to_old = tony.decreasingPriorityNewestToOldest();
//     for (int i = 0; i < decrease_new_to_old.size(); i++){
//         cout << i << " " << decrease_new_to_old[i]->getTitle() << " " << decrease_new_to_old[i]->getPriority() << endl;
//     }


//     cout << "\n\ndecrease_old_to_new: " << endl; 
//     for (int i = 0; i < tony.decreasingPriorityOldestToNewest().size(); i++)
//     {
//         cout << i << " " << tony.decreasingPriorityOldestToNewest()[i]->getTitle() << " " << tony.decreasingPriorityOldestToNewest()[i]->getPriority() << endl;
//     }



//     cout << "\n\nincrease_new_to_old: " << endl; 
//     for (int i = 0; i < tony.increasingPriorityNewestToOldest().size(); i++)
//     {
//         cout << i << " " << tony.increasingPriorityNewestToOldest()[i]->getTitle() << " " << tony.increasingPriorityNewestToOldest()[i]->getPriority() << endl;
//     }


//     // cout << "\n\nincrease_old_to_new: " << endl; 
//     // vector<Post*> increase_old_to_new = tony.increasingPriorityOldestToNewest();    
//     // for (int i = 0; i < tony.increasingPriorityOldestToNewest().size(); i++){
//     //     cout << i << " " << increase_old_to_new[i]->getTitle() << " " << increase_old_to_new[i]->getPriority() << endl;
//     // }



//     // tony.removePost(med2);


//     // cout << "\n\nincrease_old_to_new: " << endl; 
//     // // vector<Post*> increase_old_to_new = tony.increasingPriorityOldestToNewest();    
//     // for (int i = 0; i < tony.increasingPriorityOldestToNewest().size(); i++){
//     //     cout << i << " " << increase_old_to_new[i]->getTitle() << " " << increase_old_to_new[i]->getPriority() << endl;
//     // }

//     // cout << tony.returnVector().size() << endl;
//     // tony.removePost(med1);
//     // cout << tony.returnVector().size() << endl;

//     // cout << "\n\nincrease_old_to_new: " << endl; 
//     // // vector<Post*> increase_old_to_new = tony.increasingPriorityOldestToNewest();    
//     // for (int i = 0; i < tony.increasingPriorityOldestToNewest().size(); i++){
//     //     cout << i << " " << increase_old_to_new[i]->getTitle() << " " << increase_old_to_new[i]->getPriority() << endl;
//     // }


//     // // tony.addPost(med3);
//     // cout << tony.returnVector().size() << endl;


//     // cout << "\n\nincrease_old_to_new: " << endl; 
//     // // vector<Post*> increase_old_to_new = tony.increasingPriorityOldestToNewest();    
//     // for (int i = 0; i < tony.increasingPriorityOldestToNewest().size(); i++){
//     //     cout << i << " " << increase_old_to_new[i]->getTitle() << " " << increase_old_to_new[i]->getPriority() << endl;
//     // }


//     // cout << "how many likes?: " << childGeneral->getLikes() << endl;
//     // cout << "how many likes?: " << childGeneralr->getLikes() << endl;
//     // cout << "how many likes?: " << childGeneralrr->getLikes() << endl;




//     // cout << "Compare the two post usernames, are they the same?: " << ((*childGeneral) < (*childGeneral)) << endl;
    
//     // int lala = 0;

//     // hi.bSortByUsername(std::less<Post>(), &lala);
//     // hi.printFeedForAccount(sue);

//     // cout << "------after sorting--------" << endl;
    
//     // LinkedList<Post*> first = hi.bSortByUsername(std::less<Post>(), &lala);
    
//     // Node<Post*> *temp = first.getHeadPtr();
//     // while(temp != nullptr){
//     //     cout << temp->getItem()->getUsername() << " <- ";
//     //     temp = temp->getNext();
//     // }

//     // cout << "tony?" << endl; 
//     // tony.viewPosts();
//     // hi.printFeedForAccount(tony);

// //    hi.printFeed();



//     // cout << "huh?    " << tony.removePost(childGeneral2) << endl;; // index 1
//     // cout << "huh?    " << tony.removePost(childGeneral) << endl; // index 1
//     // cout << "huh?    " << tony.removePost(childPoll) << endl;// index 1

//     // tony.updatePost(childGeneral, "ok", "ok2");

//     // tony.addPost(childPromotional);

//     // tony.viewPosts();

// //     tony.addPost(childPoll);
// // // //     hi.addToFeed(ok);
//     // tony.viewPosts();
//     // cout << "network list\n\n\n\n\n\n\n\n" << endl;
//     // hi.printFeedForAccount(sue);
//     // string lala = "general title2";
//     // hi.removeIfContains(lala);

//     // LinkedList<int> first;
//     // first.insert(1, 0);
//     // first.insert(2, 1);
//     // first.insert(3, 2);
//     // first.insert(4, 3);


//     // int index_to_remove = 1;
//     // cout << "Yes or no " << first.remove(index_to_remove) << endl;

//     // int to_be_removed_to_top = 4;

//     // first.moveItemToTop(to_be_removed_to_top);

//     // Node<int> *temp = first.getHeadPtr();
//     // while(temp != nullptr){
//     //     cout << "first_linkedlist_moveItemToTop: " << temp->getItem() << endl;
//     //     temp = temp->getNext();
//     // }


//     // cout << "Size of first list is: " << first.getSize() << endl;






//     // LinkedList<int> firstReversed;
//     // firstReversed.reverseCopy(first);

//     // Node<int> *temp = firstReversed.getHeadPtr();
//     // while(temp != nullptr){
//     //     cout << "firstReversed: " << temp->getItem() << endl;
//     //     temp = temp->getNext();
//     // }

//     // Node<int> *first_ptr = first.getHeadPtr();
//     // while(first_ptr != nullptr){
//     //     cout << "first: " << first_ptr->getItem() << endl;
//     //     first_ptr = first_ptr->getNext();
//     // }





// //     Network<Account> another;
// //     another.addAccount(&sue);
// //     hi.operator-=(another);


// //     hi.populateNetwork("accounts.txt");
// //     cout << "Size of network after adding from input file is now: " << hi.getSizeOfNetwork() << endl; // pass

// //     cout << hi.containsAccount("rocketman") << endl;
// //     cout << hi.containsAccount("tligorio") << endl;
// //     cout << hi.containsAccount("lunar6night789") << endl;


}









// Project -2 to test Post abstract class:
// #include "Post.hpp"
// #include "General.hpp"
// #include "Poll.hpp"
// #include "Promotional.hpp"
// #include <iostream>
// #include <vector>
// #include <string>
// #include <regex>
// using namespace std;




// int main(){

//     // Post * parentPost = new Post; // throws an error
//     Post * childGeneral = new General("This is the title", "This is the body", "This is the username"); // General is a Post, thus we can point to General object using pointer to a parent class.
//     childGeneral->displayPost();
//     cout << childGeneral->getUsername() << endl;

    // task 1 general
    // General general("This is the title", "This is the body", "This is the username");
    // general.displayPost();


    // task 2 poll 
    // vector<string> test{"option 1", "option 2"};


    // Poll poll("This is the title", "This is the body", "This is the username", test);
    

    // int num = 1; // get index 1
    // poll.votePoll(num); // add one vote 
    // poll.votePoll(num); // add one vote 
    // poll.votePoll(num); // add one vote 



    // string in = "Does not exist";
    // int nonexist = 11;
    // poll.changePollOption(in, nonexist);
    // poll.getPollOptions();
    // poll.votePoll(2);
    // poll.getPollOptions();

    // poll.displayPost();



    // task 3 promotional 




    // string link = "http://www.1.12";
    // Promotional promo("This is the title ", "This is the body ", "This is the username ", link);
    // promo.setLink(link);
    // promo.displayPost();



    // vector<string> test;
    // test.push_back("option_1");
    // test.push_back("option_2");


    // Poll poll("This is the title ", "This is the body ", "This is the username ", test);
    
    // int num = 0;
    // poll.votePoll(num);
    // poll.votePoll(num);
    // poll.votePoll(num);
    // cout << "Option 1 is: " <<poll.getPollVotes(num) << endl;

    // poll.displayPost();


    // string in = "hahaha";
    // int two = 11;
    // poll.changePollOption(in, two);
    // poll.getPollOptions();




//     General hello("This is the title ", "This is the body ", "This is the username ");
//     cout << hello.getTitle() << hello.getBody() << hello.getUsername() << endl;

//     hello.reactToPost(SAD);
//     hello.reactToPost(SAD);
//     hello.reactToPost(SAD);
//     hello.reactToPost(SAD);
//     hello.reactToPost(SAD);
//     hello.reactToPost(SAD);
//     hello.reactToPost(SAD);

//     hello.reactToPost(Reactions::LIKE);
//     // try {
//     //     hello.reactToPost(Reactions::NOPE);
//     // } throw ("wrong");

//     // catch (Reactions::NOPE);

//     hello.getReactions();
//     // hello.getReactions();

//     hello.displayPost();

//     // hello.reactToPost(DOWN);

// // int main() {

// // cout << "TASK 1: TEST POST CLASS" << endl;

// // // Test constructor
// // ArrayBag<std::string> bag;
// // cout << "testing the array-based bag: " << endl;

// // // Test constructor and accessor functions
// // std::cout << post1.getTitle() << std::endl;
// // std::cout << post1.getBody() << std::endl;
// // post1.getTimeStamp();

// // // Test mutator functions
// // post1.setTitle("Actually the egg came first!");
// // post1.setBody("Ok, maybe the decision is not final.");

// // // Test display
// // std::cout << std::endl;
// // post1.displayPost();


// // std::cout << std::endl << "TASK2: TEST ACCOUNT CLASS" << std::endl<< std::endl;

// //Test Constructor and mutator functions
// // Account yash;
// // yash.setUsername("yashi");
// // yash.setPassword("testing123");

// // //Test accessor functions:
// // std::cout << yash.getUsername() << std::endl;
// // std::cout << yash.getPassword() << std::endl;

// //Test parameterized constructor
// Account lenti("lenti", "testing456");
// std::cout << std::endl << lenti.getUsername() << std::endl;
// std::cout << lenti.getPassword() << std::endl << std::endl;

// // Test addPost and viewFeed
// std::cout << "PRINTING FEED: " << std::endl;
// lenti.addPost("The moon is made of cheese", "Scientific discoveries about the moon have finally revealed that the moon is actually made of cheese, confirmed.\nSource: Trust me G");
// lenti.addPost("Chicken came before the egg confirmed!","A new story just released where we finally get the answer of who came first.");
// lenti.viewPosts();


// }