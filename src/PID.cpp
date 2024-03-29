#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  
  //PID Coefficients
  PID::Kp = Kp_;
  PID::Ki = Ki_;
  PID::Kd = Kd_;
  
  //PID Errors
  PID::p_error = 0.0;
  PID::i_error = 0.0;
  PID::d_error = 0.0;
  
  //CTE
  PID::prev_cte = 0.0;
  PID::int_cte = 0.0;
  PID::diff_cte = 0.0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  
  
  diff_cte = cte - prev_cte;
  int_cte += cte;
  prev_cte = cte;
  
  p_error = Kp * cte;
  i_error = Ki * int_cte;
  d_error = Kd * diff_cte;
 
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return (p_error + i_error + d_error);  // TODO: Add your total error calc here!
}