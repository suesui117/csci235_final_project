/****************************************************************************************************************************
Title         :   Poll.hpp
Auhor         :   Xin Sui
Description   :   implementation file for the class Poll
****************************************************************************************************************************/

#ifndef POLL_H
#define POLL_H
#include "Post.hpp"
#include <vector>

// TASK 2 //
class Poll:public Post{

private:

    vector<string> vect_option_; // A vector of strings containing the poll options
    vector<int> vect_count_; // A vector of integers containing the number of votes for each poll option

public:

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
    Poll(const string in_poll_name, const string in_poll_body, const string in_poll_username, vector<string> in_vect_option);
    
    

    /**

    @param user_input_integer: a reference to int between 0 < number of options
    @return    : True if index is within range and we can vote for a poll,
                false otherwise
    @post      : Increments the poll votes based on the index which
                will refer to the index in the poll options
    */
    bool votePoll(const int& user_input_integer);



    /**
     Mutator function used to either add a poll or change one of the poll options
    @param new_option: A reference to the new poll option
    @param new_index: A reference to int that can either represent the index of the
                existing option that will be replaced
                or if choice_number > current number of options,
                it will add this new option to the poll.

    @post       : Resets the number of votes for this option.
    */
    void changePollOption(const string& new_option, const int& new_index);



    /**
     Accessor function
    @post   : prints the reaction to the post in this format
            (example where option_n is the string at position n in the poll options vector):
            0 votes for: option_1
            5 votes for: option_2
            2 votes for: option_3
            ...
    */
    void getPollOptions() const;



    /**
     Accessor function
    @param new_index : The index of the option
    @return     : returns the number of votes for a given option
    */
    int getPollVotes(const int new_index) const;




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
    //******************************************Project-4******************************************//
    virtual void displayPost() const override; // adding keyword: virtual and override. Making child class late binding.
    // implementation does not have the keyword: virtual or override, they stay in the hpp file.
    // Reference: https://www.geeksforgeeks.org/difference-between-virtual-function-and-pure-virtual-function-in-c/
    //******************************************Project-4******************************************//

};

#endif
