/****************************************************************************************************************************
Title         :   Promotional.hpp
Auhor         :   Xin Sui
Description   :   implementation file for the class Promotional
****************************************************************************************************************************/

#ifndef PROMOTIONAL_H
#define PROMOTIONAL_H
#include "Post.hpp"

// Task 3 //
class Promotional:public Post{

private:
    string link_; // private data member a string that represents the web link

public:
    /**
         Parameterized constructor.
            @param in_promo_name: The name of the Promotional post (a string)
            @param in_promo_body: The body of the Promotional post (a string)
            @param in_promo_username: : The username of the Account that added this post (a string)
            @param in_link: The link of the Promotional post (a string)

        @post         : Sets the title, body, username and link (if it's a proper link otherwise "Broken Link")
                        of the Promotional to the value
                        of the parameters.
                        It will also generate the current time and store it.
    */
    Promotional(const string in_promo_name, const string in_promo_body, const string in_promo_username, const string in_link);
    
    

    /**
     Accessor function
    @return         : Returns the post link
    */
    string getLink() const;


    /**
    @param in_link: A reference to the link that is in the format 'https://www.something.something'
            or 'http://www.something.something' with the last 'something' being at least 2 characters
    @return   : true if the link is correctly formatted, false otherwise

    @post     : If the link is not correctly formatted, store "Broken Link"
            in the link member variable, otherwise store the value of the
            parameter (Hint: see <regex>)
    */
    bool setLink(const string& in_link);



    /**
     @post      : displays the entire Promotional post (example):
                \n
                {post_title_} at {time_stamp_}:
                {post_body_}
                \n
                {link}
                \n
    */
    //******************************************Project-4******************************************//
    virtual void displayPost() const override; // adding keyword: virtual and override. Making child class late binding.
    // implementation does not have the keyword: virtual or override, they stay in the hpp file.
    // Reference: https://www.geeksforgeeks.org/difference-between-virtual-function-and-pure-virtual-function-in-c/
    //******************************************Project-4******************************************//

};

#endif
