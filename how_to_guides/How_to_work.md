**How to work**
------------------------
This document is useful if you are interested in performing a similar analysis on your data. The general idea is this one:

1. Download the Root data (ex. <*name_file*>.root). Add it in the same code folder and write <*name_file*>.root in the Analysis_input file.

2. If you have more than one Root file, you just add all the data in the code folder and write their name in the Analysis_input file, as: 
`Mass number beam value`
`Charge beam value`
`Kinetic enenrgy value`
` <*name_file_1*>.root`
` <*name_file_2*>.root`
`<*name_file_3*>.root `

3. Open *Booking.cpp*, *Generation.cpp* and *Reconstruction.cpp* and write your plot code in *Fill_Histo* function in order to see the results of your analysis. 

4. If you need other functions, you have to add the prototype in the .h of the used class and the implementation in the corresponding .cpp. Otherwise, you just create a new class (*class_name.h*) and the corresponding *class_name.cpp*. Then, in the Analysis.cpp there is the main function, you will create a pointer to your Class Objects and recall the functions implemented in *class_name.cpp* .

5. To run the code, you' ll find the instructions in the [How_to_run](https://github.com/rotolanna/Software_and_Computing_Project/blob/master/how_to_guides/How_to_run.md) file.


