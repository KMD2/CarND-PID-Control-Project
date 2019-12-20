# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Reflection 

The choice of the final hyperparameters (P, I, D coefficients) have been done through manual tuning as will be discussed below.

The PID controller consists of three terms:

### 1) Proportional Term
In the proportional term, the steering angle is proportional by a factor of (tau_p) to the Cross Track Error (CTE). To test the effect of this term, I set the value of it to (1) and the rest of the terms to zero (1,0,0). As expected the car was oscillating very fast (Overshoots) and so a lower value of K_p would lower the oscillation of the car. After trying many values, I ended up choosing a small value (0.09).

### 2) Differential Term
In the differential term, the steering angle is proportional to the temporal derivative of the CTE (i.e. the difference between two congestive CTE over time). To test the effect of this term, I set the value of it to (1) and the rest of the components to zero (0,0,1). As expected, the change in the steering angle was very minimal (as if the car was going in a straight line). This term helps very much in reducing the error and smoothing the steering. Hence, I choose a relatively high value - in combination with the other two terms -  that was just sufficient in the cases of sharp turns (very high values negatively affect the performance around sharp turns). I used a value of (2.1).

### 3) Integral Term
In Integral term, the steering is proportional to the integral (sum) of all previously encountered CTE over time. This term helps in deriving the error down to zero (Overcoming the systematic bais). To test the effect of the integral term, I set the value of it to (1) and the rest of the components to zero (0,1,0). As expected the car was oscillating very fast. For this term, it is wise to choose a relatively small number since it accumulates with time. I choose a very low value (0.001) but it didn't perform well in sharp turns, increasing the number to (0.004) solved the problem.  