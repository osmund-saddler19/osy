#!/bin/bash
read -p "Username: " username
read -sp "Password: " password
echo

if [[ "$username" == "admin" && "$password" == "admin123" ]]
then
    echo -e "\nWelcome! You have successfully logged in.\n"
else
    echo -e "\nUnsuccessful Login.\n"
fi
