# movie-ticket-booking
This question was asked in udaan coding challenge on hackerearth.

you need to write code for managing movie tickets, it must have 4 functionalities

# add-screen
 add-screen screen_name number_of_rows <size of each row> <list aisle seats>
  
  output: success/failure
  
# reserve-seat
 <reserve-seat> <screen_name> <row number> <list of seat numbers to be booked in given row>

  output: success/failure
  
# get-unreserved-seats
 <get-unreserved-seats> <screen_name> <row number>
  
  output: list of unreserved seats in given row number
  
# suggest-contiguous-seats
 <suggest-contiguous-seats> <screen_name> <row number>
  
  output: list of contiguous seats if possible / else print none
