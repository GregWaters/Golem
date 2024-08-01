# These aren't C strings...
You'll need to pay a lot of attention to this explanation, as you may include undefined behavior in your program if you don't! Golem's strings are very special in that they store the size of the string internally within the 4 bytes ***before*** the character pointer. The size is stored as an unsigned 32-bit integer value. For reference, use the relatively primitive diagram below:

![string_diagram](string_diagram.png)

Above, you can see a standard (dynamically allocated) string. Note the lack of a 0-byte to show that you've reached the end of the designated space. 