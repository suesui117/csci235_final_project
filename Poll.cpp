/****************************************************************************************************************************
Title         :   Poll.cpp
Auhor         :   Xin Sui
Description   :   implementation file for the class Poll
****************************************************************************************************************************/

#include "Post.hpp"
#include "Poll.hpp"
#include <iostream>
#include <vector>
using namespace std;


// TASK 2 //
/**
     Parameterized constructor.
    @param in_poll_name: The title (name) of the Poll post (a string)
    @param in_poll_body: The question (body) of the Poll post (a string)
    @param in_poll_username: : The username of the Account that added this poll (a string)
    @param in_vect_option: A vector of options for the Poll post

    @post     :Sets the title, body and username of the Poll post to the value of the parameters.
                It will also generate the current time and store it and will initialize
                the vectors of options and their respective number of votes.
*/
Poll::Poll(const string in_poll_name, const string in_poll_body, const string in_poll_username, vector<string> in_vect_option):Post(in_poll_name, in_poll_body, in_poll_username){
        vect_option_ = in_vect_option; // set private data member to input parameter from user

        for (int i = 0; i < vect_option_.size(); i++){ // set the poll votes to 0, since vect_option and vect_count have the same size
            vect_count_.push_back(0);
        }
    }


/**

    @param user_input_integer: a reference to int between 0 < number of options
    @return    : True if index is within range and we can vote for a poll,
                false otherwise
    @post      : Increments the poll votes based on the index which
                will refer to the index in the poll options
*/
bool Poll::votePoll(const int& user_input_integer) {
    if (user_input_integer >= 0 && user_input_integer < vect_count_.size()){ // if the user input index (int) is >= 0 and less than the length of vect_count
        
        vect_count_[user_input_integer]++; // increment the vote count (element) at that index which user inputted. 

        return true;
    }
    return false;
}

/**
 Mutator function used to either add a poll or change one of the poll options
    @param new_option: A reference to the new poll option
    @param new_index: A reference to int that can either represent the index of the
                existing option that will be replaced
                or if choice_number > current number of options,
                it will add this new option to the poll.

    @post       : Resets the number of votes for this option.
*/
void Poll::changePollOption(const string& new_option, const int& new_index) { // in takes a new poll option and an input index

    if (new_index >= vect_option_.size()){ // if the new index is >= the current option vector size, then 
        vect_option_.push_back(new_option); // add the new option to the vector
        vect_count_.push_back(0); // and also have the count vector of this new option to zero. 
    }

    else{
        vect_count_[new_index] = 0; // if the input index is within the current option vector, resets the number of votes for this option.
        vect_option_[new_index] = new_option;; // also replacing the existing option with the new input option.
    }

}



/**
 Accessor function
    @post   : prints the reaction to the post in this format
            (example where option_n is the string at position n in the poll options vector):
            0 votes for: option_1
            5 votes for: option_2
            2 votes for: option_3
            ...
*/
void Poll::getPollOptions() const {
    for (int i = 0; i < vect_option_.size(); i++){
        cout << vect_count_[i] << " votes for: " << vect_option_[i] << endl;
    }
}



/**
 Accessor function
    @param new_index : The index of the option
    @return     : returns the number of votes for a given option
*/
int Poll::getPollVotes(const int new_index) const {
    return vect_count_[new_index];
}






/**
 @post   : displays the whole Poll post (example):
        \n
        {post_title_} at {time_stamp_}:
        {post_body_}
        \n
        0 votes for: option_1
        5 votes for: option_2
        2 votes for: option_3
        ...
        \n
*/
void Poll::displayPost() const{

    //******************************************Project-4******************************************//
    // implementation only lies within its (Post)'s children class
    cout << Post::getTitle() << " at ";
    getTimeStamp();
    cout << ": " << endl << Post::getBody() << endl;
    //******************************************Project-4******************************************//


    // Removed for polymorphism abstration Post::displayPost(); // Here we can just call the base class Post::displayPost(); to print out the title, time and body.
    cout << endl;
    getPollOptions();
    cout << "\n";
}
