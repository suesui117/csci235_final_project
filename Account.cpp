/****************************************************************************************************************************
Title         :   Account.hpp
Author        :   Dream Team
Description   :   header/interface files for Account class
****************************************************************************************************************************/

#include "Account.hpp"
using namespace std;

//default constructor
//@post:  set username and password to ""
//        creates an empty vector of post objects to store into feed_
Account::Account()
{
    username_ = "";
    password_ = "";
    posts_ = LinkedList<Post*>();
    following_ = {};
    minLikes_ = {};
    maxLikes_ = {};

}


/**
    Parameterized Constructor
    @param username  : username of the account, stored into username_
    @param password  : password of the account, stored into password_
    @post:             sets the private members to the value of the parameters
*/
Account::Account(std::string username, std::string password) : username_(username), password_(password), posts_(LinkedList<Post*>()), following_({}), net_(nullptr) { }

/**
  @return:     the username of the Account
*/
std::string Account::getUsername() const { return username_; }


/**
  @param:     a reference to the username of the Account
  @psot:      sets the parameter to the value of the private member
*/
void Account::setUsername(const std::string& username) { username_ = username; }


/**
  @return:     the password of the Account
*/
std::string Account::getPassword() const { return password_; }


/**
  @param a reference to the password of the Account
  @post:      sets the private member to the value of the parameter
*/
void Account::setPassword(const std::string& password) { password_ = password; }


/**
      Accessor function
      @return           :   the pointer to the Network the account is in
   */
Network<Account>* Account::getNetwork() const { return net_; }


/**
      Mutator function
      @param            :   a pointer to a Network
      @post             :   the Network pointer private member points to the input Network
   */
void Account::setNetwork(Network<Account>* network) { net_ = network; }


/**
    @param newPost   : The pointer to the Post object that will be added to its list
    @return          : Will return true if a post gets added sucesfully to the vector

    @post:           " Adds post to posts_ and its Networks feed_
*/
bool Account::addPost(Post* newPost){
    posts_.insert(newPost, 0);

/*******************************MODIFICATION********************************/

    vecPriority.push_back( newPost );


/*******************************MODIFICATION********************************/

    // newPost->displayPost();
    net_->addToFeed(newPost);
    return true;
}



/*
    @post:      Prints the feed_ that contains the post objects by calling their display function
*/
void Account::viewPosts() const {

    Node<Post*>* itt = posts_.getHeadPtr();

    while (itt != nullptr) {
        itt->getItem()->displayPost();
        itt = itt->getNext();
    }

}



/**
      @param            :   the username of the Account to follow
      @return           :   true if the account was successfully able to follow, false otherwise
      @post             :   adds the username to the vector of following accounts only if
                            it is affiliated to a Network AND it is not already following an account
                            with the same username.
   */
bool Account::followAccount(const std::string username){

    bool exists = false;

    for(std::string un : following_) {
        if(un == username) {
            exists = true;
        }
    }

    if(!exists && net_ != nullptr) {
        following_.push_back(username);
        return true;
    }

    return false;
}


/**
      @return           :   the vector of usernames the Account is following
   */
std::vector<std::string> Account::viewFollowing() const {
    return following_;
}


/**
  @return           :  true if account has same private members as parameter,
                       false otherwise
*/
bool Account::operator==(const Account &acc) const {
    if(acc.getUsername() == this->username_ && acc.getPassword() == this->password_) {
        return true;
    }

    return false;
}



/**
    @param            :   A pointer to a Post
    @return           :   True iff the Post was successfully found and removed,
                            false othewise.
    @post             :   Removes the given Post from its list
                            as well as from the Network's feed.
                            
                            Project 6: And from stacks and queues
*/
bool Account::removePost(Post* post){
    int postPosition = posts_.getIndexOf(post);

    if (postPosition > -1) {

        // remove from the vector from project 6
        for (int i = 0; i < vecPriority.size(); i++)
        {
            if (vecPriority[i] == post)
            {
                vecPriority.erase(vecPriority.begin() + i);
            }
        }

        // When removing the post, we're also going to update the NEW min/max likes
        this->sortMin();
        this->sortMax();

        posts_.remove(postPosition);
        net_->removePostFromFeed(post);


        return true;
    }

    return false;
}



/**
    @param            :   Pointer to a Post object
    @param            :   The new title of the Post (or an empty string if you do not
                          want to change it)
    @param            :   The new body of the Post (or an empty string if you do not
                          want to change it)

    @post             :   This function will take the Post and given the new title and body,
                         update the Posts title and body as appropriate. It will also update the `timestamp_` to the current time of the update. This function should then
                         update the location of the Post in its list of `posts_` to the front of the list as well as utilizing its Network pointer to do the same in the `feed_`. It will also update any data structure used to support O(1) and O(n) operations ins Task2.

    You are encouraged to create your own helper functions for this endevour.
*/
bool Account::updatePost(Post* post, std::string new_title, std::string new_body) {
    if(new_title != "") { post->setTitle(new_title); }

    if(new_body != "") { post->setBody(new_body); }

/***************************Project6: MODIFICATION********************************/
    // call remove post
    this->removePost(post);
    // call addpost
    this->addPost(post);
/***************************Project6: MODIFICATION********************************/

    post->updateTimeStamp();
    
    return net_->updateFeed(post);

}



/**
     @return           :  a pointer to the Post with least likes

    NOTE: YOU MUST DO THIS IN O(1) TIME. Use stack and or queue and add as
    many private members as you need and modify the necessary functions
    and/or add helper functions to do this in O(1) time.

    Note: If multiple Posts have the same amount of likes then it should be sorted from Newest to Oldest
        Where in this case it would be the Newest Post with the least amount of likes returned.
*/
Post* Account::getMinLikes()
{ 
    return sortMin().top(); // O(1) by calling the helper function
}



/**
    @return           :  a pointer to the Post with most likes

    NOTE: YOU MUST DO THIS IN O(1) TIME. Use stack and or queue and add as
    many private members as you need and modify the necessary functions
    and/or add helper functions to do this in O(1) time.

    Note: If multiple Posts have the same amount of likes then it should be sorted from Newest to Oldest
          Where in this case it would be the Oldest Post with the most amount of likes returned.
*/
Post* Account::getMaxLikes()
{
    return sortMax().top(); // O(1) by calling the helper function
}



/**
    @return           :  a vector of pointers to Post
    @post             :  the order of the Posts in the vector is by increasing
                         priority, and within each priority class, from oldest
                         to newest

    NOTE: use stacks and queues to do this in O(n) time

*/
std::vector<Post*> Account::increasingPriorityOldestToNewest()
{   

    queue<Post*> low, medium, high; // FIFO

    vector<Post*> output;
    
    // O(n) time
    for( int i = 0; i < vecPriority.size(); i++ )
    {
        if ( vecPriority[i]->getPriority() == Post::priority::LOW  )
        {
             low.push( vecPriority[i] ); // FIFO
        }

        if ( vecPriority[i]->getPriority() == Post::priority::MEDIUM  )
        {
            medium.push( vecPriority[i] );
        }

        if ( vecPriority[i]->getPriority() == Post::priority::HIGH )
        {
            high.push( vecPriority[i] );
        }
    }

    queueCombine(low, output);
    queueCombine(medium, output);
    queueCombine(high, output);

    return output;

} 





/**
@return           :  a vector of pointers to Post
@post             :  the order of the Posts in the vector is by increasing
                     priority, and within each priority class, from newest
                     to oldest

NOTE: use stacks and queues to do this in O(n) time

*/
std::vector<Post*> Account::increasingPriorityNewestToOldest()
{

    stack<Post*> low, medium, high; // LIFO, newest on top

    vector<Post*> output;
    
    // O(n) time
    for( int i = 0; i < vecPriority.size(); i++ )
    {
        if ( vecPriority[i]->getPriority() == Post::priority::LOW  )
        {
             low.push( vecPriority[i] ); // LIFO
        }

        if ( vecPriority[i]->getPriority() == Post::priority::MEDIUM  )
        {
            medium.push( vecPriority[i] );
        }

        if ( vecPriority[i]->getPriority() == Post::priority::HIGH )
        {
            high.push( vecPriority[i] );
        }
    }

    stackCombine(low, output);
    stackCombine(medium, output);
    stackCombine(high, output);

    return output;

}



/**
    @return           :  a vector of pointers to Post
    @post             :  the order of the Posts in the vector is by decreasing
                         priority, and within each priority class, from oldest
                         to newest

    NOTE: use stacks and queues to do this in O(n) time

*/
vector<Post*> Account::decreasingPriorityOldestToNewest()
{
    queue<Post*> low, medium, high; // FIFO

    vector<Post*> output;
    
    // O(n) time
    for( int i = 0; i < vecPriority.size(); i++ )
    {
        if ( vecPriority[i]->getPriority() == Post::priority::LOW  )
        {
             low.push( vecPriority[i] ); // FIFO
        }

        if ( vecPriority[i]->getPriority() == Post::priority::MEDIUM  )
        {
            medium.push( vecPriority[i] );
        }

        if ( vecPriority[i]->getPriority() == Post::priority::HIGH )
        {
            high.push( vecPriority[i] );
        }
    }

    queueCombine(high, output);
    queueCombine(medium, output);
    queueCombine(low, output);

    return output;
}




/**
    @return           :  a vector of pointers to Post
    @post             :  the order of the Posts in the vector is by decreasing
                        priority, and within each priority class, from newest
                        to oldest

    NOTE: use stacks and queues to do this in O(n) time
*/
std::vector<Post*> Account::decreasingPriorityNewestToOldest()
{

    stack<Post*> low, medium, high; // LIFO, newest on top

    vector<Post*> output;
    
    // O(n) time
    for( int i = 0; i < vecPriority.size(); i++ )
    {
        if ( vecPriority[i]->getPriority() == Post::priority::LOW  )
        {
             low.push( vecPriority[i] ); // LIFO
        }

        if ( vecPriority[i]->getPriority() == Post::priority::MEDIUM  )
        {
            medium.push( vecPriority[i] );
        }

        if ( vecPriority[i]->getPriority() == Post::priority::HIGH )
        {
            high.push( vecPriority[i] );
        }
    }

    stackCombine(high, output);
    stackCombine(medium, output);
    stackCombine(low, output);

    return output;

}




/***************************** helper functions starts *************************************/
/**
  @return           :  a stack of pointers to Post
  @post             :  returns a stack with the newest and minimum post on the top of the stack
*/
stack<Post*> Account::sortMin()
{
    int min = vecPriority[0]->getLikes();
    Post* minPtr = vecPriority[0];

    for (int i = 0; i < vecPriority.size(); i++)
    {
        if ( vecPriority[i]->getLikes() <= min )
        {
            min = vecPriority[i]->getLikes();
            minPtr = vecPriority[i];
        }
    }

    minLikes_.push(minPtr);

    return minLikes_;

}



/**
  @return           :  a stack of pointers to Post
  @post             :  returns a stack with the oldest and maximum post on the top of the stack
*/
stack<Post*> Account::sortMax()
{
    int max = vecPriority[0]->getLikes();
    Post* maxPtr = vecPriority[0];

    for (int i = 0; i < vecPriority.size(); i++)
    {
        if ( vecPriority[i]->getLikes() > max )
        {
            max = vecPriority[i]->getLikes();
            maxPtr = vecPriority[i];
        }
    }

    maxLikes_.push(maxPtr);

    return maxLikes_;

}



/**
 @param : a queue of post pointers
 @param : a vector of post pointers
 @post adds the elements from the input queue to the vector
*/
void Account::queueCombine( queue<Post*>& input, vector<Post*>& output )
{
    if ( input.empty() ) // base case, when there's nothing, return it
    {
        return;
    }


    else
    {
        output.push_back( input.front() ); // do what you gotta do
        input.pop(); // this is the decrement step

        queueCombine( input, output); // using recursion
    }


}




/**
 @param : a stack of post pointers
 @param : a vector of post pointers
 @post adds the elements from the input stack to the vector
*/
void Account::stackCombine( stack<Post*>& input, vector<Post*>& output )
{
    if ( input.empty() ) // base case
    {
        return;
    }

    else
    {
        output.push_back( input.top() );
        input.pop(); // reduction step 
        
        stackCombine( input, output); // recursive step, calls it again

    }

}

/***************************** helper functions ends *************************************/
