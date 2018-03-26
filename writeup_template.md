## Writeup Template
### You can use this file as a template for your writeup if you want to submit it as a markdown file, but feel free to use some other method and submit a pdf if you prefer.

---

**PID Controller**

The goals / steps of this project are the following:

* Clone/fork the project's template files from the project repository and have a look at the rubric here. (Note: Please do not submit your project as a pull request against our repo!)
* Build a PID controller and tune the PID hyperparameters by applying the general processing flow as described in the previous lessons.
* Test your solution on the simulator!
* When the vehicle is able to drive successfully around the track, submit! Remember to include a file addressing the reflection portion of the project in .txt, .md, .html, or .pdf format.
* Try to see how fast you get the vehicle to SAFELY go!

[//]: # (Image References)
[image1]: ./PID.png


### Here I will consider the rubric points individually and describe how I addressed each point in my implementation.  

---
### Your code should compile.

Done! The code compiles!

### The PID procedure follows what was taught in the lessons.

I first tried to use the twiddle algorithm for the implementation. But unfortunately I couldnt quite figure out how to implement that from the lecture and the provided Q&A. Thus I decided to follow the procedure of the Q&A

#### Describe the effect each of the P, I, D components had in your implementation.

For me P has very drastic effect on the general stability of the vehicle which makes sense when looking at the formula. Finding the right value for P almost is the key for the implementation.
Next when looking at D is smoothes the vehicle drastically. The combination of P & D already suffices to make it around the course successfully.
Unfortunately I wasnt so found of I as regardless of how big or how small i made it, it didnt make things better. Thus in my final implementation I left it at 0.


#### Describe how the final hyperparameters were chosen.

 From lectures I knew that a good initial value for Kp is between 0 and 1 and for Kd between 1 and above
 So I tuned KP so long until it made it around the first curve. 
 Afterwards I looked at Kd at tuned it starting from 1 updwards. 2.2 resulted in the best results. 
 Next it tried to find an appropriate value for Ki. 
 However no matter how I set it there werent significant improvements compared to leaving it at 0.
 So in the end I left it set to 0.0.

 ![alt text][image1]


### The vehicle must successfully drive a lap around the track.

Done!


