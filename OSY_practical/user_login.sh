#!/bin/bash 
#Type your login details
 read -p "Username: " username
    read -sp "Password: " password
if(($username == "admin" && $password == "admin123"))
then
    echo -e"\nWelcome ! You have successfully logged in.\n"
else
    echo -e"\nUnsuccessful Login.\n"
fi