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

P stands for Proptional. I for Integral. D for derivative.

What already can be deduced from the name Proportional is that the proportional control steers proportional to the cross track error of the vehicle. It is vital to find the right scaling factor of P in order avoid:
* low P gain
* high P gain

However with P being our own input the next problem we have is overshooting. To correct for overshooting we introduce the D scaling factor. The scaling facotr is multiplied by the cross track error rate which looks at how fast we are moving in a perpendicular direction with respect to our desired trajectory. Finding the right value for D is once again vital in order to avoid:
* low D gain (aka Underdamped)
* high D gain (aka Overdamped)

However for including environmental factors in our trajecotry planning we need one more intergral term which is multplied by the I scaling factor. The integral term sums up the cross track errors and indicates whether we spend more time on one side or the other and thus can also correct for a lane offset. Choosing the right scaling factor is once again vital in order to avoid:
* high I gain (leads to an unstable controller - as normal controller fluctuations will be exagerrated)
* low I gain (takes to long to correct the steering angle)

Thus it also makes sense to tune the P factor first and then the D factor. Furthermore it also made sense that I is 0 in my controller as no external influences have to be taken into account.


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


