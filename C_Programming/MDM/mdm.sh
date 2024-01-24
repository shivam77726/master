#!/bin/sh
while :
do
	echo "Choose options:"
	echo "1. Checkin for rcs"
	echo "2. Checkout from rcs"
	echo "3. Checkout for developement"
	echo "4. Build program"
	echo "5. Run program"
	echo "6. Clean build program"
	echo "0. Exit"
	read option
	case $option in
		"1")
			echo "1";;
		"2")
			echo "2";;
		"4")
			($shell make);;
		"5")
			($shell ./demo);;
		"6")
			($shell make clean);;
		
		"0")
			echo "Exit"
			clear
			break;;
		
		*)
			echo "Enter Valid option";;
esac
done
