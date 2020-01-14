// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//COMMENT: Please complete these methods.
//RESPONSE: Created the size function which takes in the array
//from data and stores the size of the array in cur_size and returns it
inline
size_t Array::size (void) const
{
     size_t cur_size_ = sizeof(data_)/sizeof(data_[0]);
    return cur_size_;
}

//COMMENT: Please complete these methods.
//RESPONSE: Created the max_size function which takes in the array
//from data and stores the size of the array in max_size_ and returns it
inline
size_t Array::max_size (void) const
{
     size_t max_size_= sizeof(data_)/sizeof(data_[0]);
    return max_size_;
}
