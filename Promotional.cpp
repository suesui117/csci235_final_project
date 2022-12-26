/****************************************************************************************************************************
Title         :   Promotional.cpp
Auhor         :   Xin Sui
Description   :   implementation file for the class Promotional
****************************************************************************************************************************/
#include "Post.hpp"
#include "Promotional.hpp"
#include <iostream>
#include <vector>
#include <regex>
using namespace std;


// Task 3 //
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

Promotional::Promotional(const string in_promo_name, const string in_promo_body, const string in_promo_username, const string in_link):Post(in_promo_name, in_promo_body, in_promo_username){
    setLink(in_link);
}



/**
     Accessor function
    @return         : Returns the post link
*/
string Promotional::getLink() const{
    return link_;
}



/**
    @param in_link: A reference to the link that is in the format 'https://www.something.something'
            or 'http://www.something.something' with the last 'something' being at least 2 characters
    @return   : true if the link is correctly formatted, false otherwise

    @post     : If the link is not correctly formatted, store "Broken Link"
            in the link member variable, otherwise store the value of the
            parameter (Hint: see <regex>)
*/
bool Promotional::setLink(const string& in_link) {
    // matches "http or https" following by : www. [^\\.] here means any character except a dot at least one character long,
    // then match a dot, then match any character except a dor at least two characters long. 
    // Reference: https://regexr.com/6un1q https://www.keycdn.com/support/regex-cheat-sheet

    regex pattern("(http|https):\\/\\/www.[^\\.]{1,}.[^\\.]{2,}"); 
    if ( regex_match(in_link, pattern) ){
        link_ = in_link; // if the format is correct, store the link, and return true and exit
        return true;
    }

    link_ = "Broken Link"; // if format is incorrect, store "Broken link"
    return false;

}








/**
 @post      : displays the entire Promotional post (example):
            \n
            {post_title_} at {time_stamp_}:
            {post_body_}
            \n
            {link}
            \n
*/
void Promotional::displayPost() const {

    //******************************************Project-4******************************************//
    // implementation only lies within its (Post)'s children class
    cout << Post::getTitle() << " at ";
    getTimeStamp();
    cout << ": " << endl << Post::getBody() << endl;
    //******************************************Project-4******************************************//


    // Removed for polymorphism abstration Post::displayPost(); // Here we can just call the base class Post::displayPost(); to print out the title, time and body.
    cout << endl;
    cout << getLink() << "\n" << endl;
}
